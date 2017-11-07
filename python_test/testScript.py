#!/usr/bin/python
# -*- coding: utf-8 -*-
# Autor: Euller Borges
""" Header do protocolo MaxPB"""
import time
import struct
import serial
import binascii
import serial.threaded
from CRC16 import CRC16
from protobuf import Protocol_Commands_pb2 as ptcl_cmds
from protobuf import Protocol_Leds_pb2 as ptcl_leds
from protobuf_to_dict import protobuf_to_dict

# Importante usar pyserial mais recente.
# http://pyserial.readthedocs.io/en/latest/tools.html#serial.tools.list_ports.ListPortInfo

class ProcessData(serial.threaded.Protocol):
    def connection_made(self, transport):
        super(ProcessData, self).connection_made(transport)
        self.transport = transport
        print('port opened\n')

    def write(self, data):
        self.transport.write(data)

    def data_received(self, data):
        for byte in data:
            print("GOT BYTE! 0x%x" % ord(byte))
            global maqEstado
            maqEstado.parseByte(byte)

    def connection_lost(self, exc):
        if exc:
            print(exc)
        print('port closed\n')

class Estado:
    CHECK_HEADER = 0
    GET_MT = 1
    GET_SEQ_NO = 2
    GET_SIZE = 3
    GET_CRC = 4
    GET_DATA = 5

class ProtocolPacket:
    """
    Classe que define um pacote do protocolo MaxPB
    """
    START_FRAME = bytearray([0x55, 0x66])
    def __init__(self):
        self.header = 0
        self.mt = 0
        self.seq_number = 0
        self.size = 0
        self.crc = 0
        self.payload = 0

    def encode(self):
        #calccrc = CRC16().calculate(str(self.payload))
        calccrc = 0x8888
        pct = self.START_FRAME + struct.pack('<BBHH', self.mt, self.seq_number, len(self.payload), calccrc)
        return pct + self.payload

    def decode(self, data):
        self.header, self.mt, self.seq_number, self.size, self.crc = struct.unpack('<HBBHH', data[:8])
        self.payload = bytes(data[8:])

def decode_maxpb(data):
    """
    Decodifica um pacote maxpb
    :param data: dados do pacote
    :return: objeto com o pacote estruturado
    :rtype: MaxPB_Packet
    """
    pacote_recebido = ProtocolPacket()
    pacote_recebido.decode(data)
    calccrc = CRC16().calculate(str(data[8:]))
    if True: #pacote_recebido.crc == calccrc:
        return pacote_recebido
    else :
        print("CRC inválido! Recebido= 0x%X, esperado= 0x%X" % (pacote_recebido.crc, calccrc))
        return None

class MaquinaEstado:
    """
    Classe que implementa a máquina de estados de recebimento de pacotes.
    """
    header_recebido = bytearray()  # Header do pacote MaxPB recebido até o momento
    size = 0  # Tamanho do campo de dados
    corpo_pacote = bytearray()  # Corpo do pacote recebido, em bytes
    byteCount = 0  # Nùmero de bytes lidos

    def __init__(self, state = Estado.CHECK_HEADER, callback = None, reset=False):
        """
        Construtor da classe
        :param state: Estado inicial da máquina de estado, padrão CHECK_HEADER
        :param callback: callback chamado quando recebido um pacote completo
        """
        self.estado = state
        self.byteCount = 0
        self.size = 0
        self.header_recebido = bytearray()
        self.corpo_pacote = bytearray()
        if not reset:  # Evitando zerar callback no reset
            self.callback = callback

    def reset(self):
        self.__init__(reset=True)

    def parseByte(self, byte):
        """
        Método de execução da máquina de estado.

        O tratamento é feito byte a byte. Se um pacote completo for recebido,
        chama o callback com o pacote como parâmetro, se estiver definido, caso
        contrário retorna o pacote lido. Retorna None se o tratamento do byte
        atual não resulta em um pacote completo.

        :param byte: byte a ser tratado
        :return: Pacote recebido, se o tratamento foi bem sucedido
        """
        # Armazena o byte recebido no corpo do pacote
        self.corpo_pacote.append(byte)
        # Estado de checagem do header
        if self.estado == Estado.CHECK_HEADER:
            # se o header não foi inteiramente recebido
            if self.byteCount < len(ProtocolPacket.START_FRAME): 
                # Sai se o byte lido não for 0x55
                if self.byteCount == 0 and ord(byte) != ProtocolPacket.START_FRAME[0]:
                    self.reset()
                    print("Incorrect header received. Dropping packet")
                    return None
                self.header_recebido.append(byte)
                 # Se  O header inteiro foi recebido
                if self.byteCount == (len(ProtocolPacket.START_FRAME) - 1):
                    # Se o header hecebido não é o esperado
                    if self.header_recebido[:4] != ProtocolPacket.START_FRAME:
                        print("Incorrect header received. Dropping packet")
                        self.reset()
                        return None
                    # Se recebemos o header do MaxPB, muda para o estado de espera
                    # do tamanho
                    else:
                        self.estado = Estado.GET_MT
                        self.byteCount = 0
                        return None

        if self.estado == Estado.GET_MT:
            self.estado =Estado.GET_SEQ_NO
            print("GET MT")
            return None
                
        if self.estado == Estado.GET_SEQ_NO:
            print("GET SEQ_NO")
            self.estado = Estado.GET_SIZE
            return None

        # Estado que pega o tamanho
        if self.estado == Estado.GET_SIZE:
            if self.byteCount == 0:
                self.size = ord(byte)
                print("GET SIZE1")
            else: # Recebidos os dois bytes do tamanho
                self.size += ord(byte) * 256
                self.estado = Estado.GET_CRC
                print("GET SIZE2: %s" % self.size)
                self.byteCount = 0
                return None

        if self.estado == Estado.GET_CRC:
            if self.byteCount == 0:
                print("GET CRC1")
            else: # Recebidos os dois bytes do tamanho
                self.estado = Estado.GET_DATA
                print("GET CRC2")
                self.byteCount = 0
                return None

        # Estado que pega o resto
        if self.estado == Estado.GET_DATA:
            print("GET DATA %d/%d" % (self.byteCount+1, self.size))
            if self.byteCount == self.size - 1: # Hack:-1 pois vai somar um embaixo
                pacote = decode_maxpb(self.corpo_pacote)
                if self.callback:
                    self.callback(pacote)
                self.reset()  # Resetando máquina de estado
                return pacote

        # Contando o byte recebido
        self.byteCount += 1

maqEstado = None

def newPacket(packet):
    print("GOT COMPLETE PACKET! MT: 0x%X" % packet.mt)
    ledsValues = ptcl_leds.LedsValues()
    print("SZ: %d LEN: %d" % (packet.size, len(packet.payload)))
    ledsValues.ParseFromString(packet.payload)
    print(protobuf_to_dict(ledsValues))

if __name__ == '__main__':
    ser = serial.Serial("/dev/pts/7",115200)
    maqEstado = MaquinaEstado(Estado.CHECK_HEADER, callback=newPacket)
    new_thread = serial.threaded.ReaderThread(ser, ProcessData)
    new_thread.start()
    mt = 0
    while(1):
        time.sleep(2)
        # pct = ProtocolPacket()
        # pct.mt = 0x84
        # pct.seq_number = 0x22
        # pct.payload = bytearray([0xAA, 0xBB, 0xCC])
        # encoded = pct.encode()
        # print("Sending data! %s" % binascii.hexlify(encoded))
        # ser.write(encoded)
        mt += 1
    #time.sleep(5)
    #time.sleep(0.05)
    #new_thread.close()
