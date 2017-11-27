#!/usr/bin/python
# -*- coding: utf-8 -*-
# Autor: Euller Borges
import time

import serial
import serial.threaded
import Protocol_MTs as mts
#from protobuf_to_dict import protobuf_to_dict

from protobuf import Protocol_Leds_pb2 as ptcl_leds
from ProtocolPacket import ProtocolPacket, decode_maxpb

# Importante usar pyserial mais recente.
# http://pyserial.readthedocs.io/en/latest/tools.html#serial.tools.list_ports.ListPortInfo

DEBUG_FSM = False


def print_debug_fsm(msg):
    if DEBUG_FSM:
        print(msg)


class ProcessData(serial.threaded.Protocol):
    def connection_made(self, transport):
        super(ProcessData, self).connection_made(transport)
        self.transport = transport
        print('port opened\n')

    def write(self, data):
        self.transport.write(data)

    def data_received(self, data):
        for byte in data:
            #print("GOT BYTE! 0x%x" % ord(byte))
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


class MaquinaEstado:
    """
    Classe que implementa a máquina de estados de recebimento de pacotes.
    """
    header_recebido = bytearray(
    )  # Header do pacote MaxPB recebido até o momento
    size = 0  # Tamanho do campo de dados
    corpo_pacote = bytearray()  # Corpo do pacote recebido, em bytes
    byteCount = 0  # Nùmero de bytes lidos

    def __init__(self, state=Estado.CHECK_HEADER, callback=None, reset=False):
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
                if self.byteCount == 0 and ord(
                        byte) != ProtocolPacket.START_FRAME[0]:
                    self.reset()
                    print_debug_fsm(
                        "Incorrect header received. Dropping packet")
                    return None
                self.header_recebido.append(byte)
                # Se  O header inteiro foi recebido
                if self.byteCount == (len(ProtocolPacket.START_FRAME) - 1):
                    # Se o header hecebido não é o esperado
                    if self.header_recebido[:4] != ProtocolPacket.START_FRAME:
                        print_debug_fsm(
                            "Incorrect header received. Dropping packet")
                        self.reset()
                        return None
                    # Se recebemos o header do MaxPB, muda para o estado de espera
                    # do tamanho
                    else:
                        self.estado = Estado.GET_MT
                        self.byteCount = 0
                        return None

        if self.estado == Estado.GET_MT:
            self.estado = Estado.GET_SEQ_NO
            print_debug_fsm("GET MT")
            return None

        if self.estado == Estado.GET_SEQ_NO:
            print_debug_fsm("GET SEQ_NO")
            self.estado = Estado.GET_SIZE
            return None

        # Estado que pega o tamanho
        if self.estado == Estado.GET_SIZE:
            if self.byteCount == 0:
                self.size = ord(byte)
                print_debug_fsm("GET SIZE1")
            else:  # Recebidos os dois bytes do tamanho
                self.size += ord(byte) * 256
                self.estado = Estado.GET_CRC
                print_debug_fsm("GET SIZE2: %s" % self.size)
                self.byteCount = 0
                return None

        if self.estado == Estado.GET_CRC:
            if self.byteCount == 0:
                print_debug_fsm("GET CRC1")
            else:  # Recebidos os dois bytes do tamanho
                self.estado = Estado.GET_DATA
                print_debug_fsm("GET CRC2")
                self.byteCount = 0
                return None

        # Estado que pega o resto
        if self.estado == Estado.GET_DATA:
            print_debug_fsm("GET DATA %d/%d" % (self.byteCount + 1, self.size))
            if self.byteCount == self.size - 1:  # Hack:-1 pois vai somar um embaixo
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
    print("PAYLOAD: %s " % ledsValues)
    if (packet.mt == mts.MSG_SET_LEDS_VALUE):
        pct = ProtocolPacket()
        pct.mt = mts.MSG_LEDS_STATUS
        pct.payload = packet.payload
        ser.write(pct.encode())


if __name__ == '__main__':
    ser = serial.Serial("/dev/pts/13", 115200)
    maqEstado = MaquinaEstado(Estado.CHECK_HEADER, callback=newPacket)
    new_thread = serial.threaded.ReaderThread(ser, ProcessData)
    new_thread.start()
    mt = 0
    while True:
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
