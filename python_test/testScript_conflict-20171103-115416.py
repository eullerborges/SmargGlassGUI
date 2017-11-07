#!/usr/bin/python
# -*- coding: utf-8 -*-
# Autor: Euller Borges
""" Header do protocolo MaxPB"""
MAXPB_HEADER = bytearray([0x55,0xAA,0x55,0xAA])

class Ptcl_Packet:
    """
    Classe que define um pacote do protocolo MaxPB
    """
    def __init__(self):
        self.header = 0
        self.size = 0
        self.crc = 0
        self.mt = 0
        self.pf = 0
        self.payload = 0

def decode_maxpb(data):
    """
    Decodifica um pacote maxpb
    :param data: dados do pacote
    :return: objeto com o pacote estruturado
    :rtype: MaxPB_Packet
    """
    pacote_recebido = MaxPB_Packet()
    header, size, crc, mt, pf = struct.unpack('<LHHHH', data[:12])
    payload = data[12:]
    calccrc = CRC16().calculate(str(data[8:]))
    if crc == calccrc:
        pacote_recebido.header = header
        pacote_recebido.size = size
        pacote_recebido.crc = crc
        pacote_recebido.mt = mt
        pacote_recebido.pf = pf
        pacote_recebido.payload = bytes(payload)
        return pacote_recebido
    else :
        print("CRC inválido! Recebido= 0x%X, esperado= 0x%X" % (crc, calccrc))
        return None

class Estado:
    """
    Classe com estados da máquina de estados de recebimento do pacote maxpb.
    """
    CHECK_HEADER = 0  # Estado de recebimento do header do pacote maxpb.
    GET_SIZE = 1  # Estado de recebimento do tamanho do pacote maxpb.
    GET_REST = 2  # Estado de recebimento do restante do pacote maxpb.
