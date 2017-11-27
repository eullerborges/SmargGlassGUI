#!/usr/bin/python
# -*- coding: utf-8 -*-
# Autor: Euller Borges
import struct
from CRC16 import CRC16


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
        calccrc = CRC16().calculate(str(self.payload))
        #calccrc = 0x8888
        pct = self.START_FRAME + struct.pack('<BBHH', self.mt, self.seq_number,
                                             len(self.payload), calccrc)
        return pct + self.payload

    def decode(self, data):
        self.header, self.mt, self.seq_number, self.size, self.crc = struct.unpack(
            '<HBBHH', data[:8])
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
    if True:  #pacote_recebido.crc == calccrc:
        return pacote_recebido
    else:
        print("CRC inválido! Recebido= 0x%X, esperado= 0x%X" %
              (pacote_recebido.crc, calccrc))
        return None
