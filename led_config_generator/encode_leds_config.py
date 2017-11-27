#!/usr/bin/python
# -*- coding: utf-8 -*-
# Autor: Euller Borges
import time
import struct
import serial
import binascii
import serial.threaded
from CRC16 import CRC16
from protobuf import Protocol_Commands_pb2 as ptcl_cmds
from protobuf import Protocol_Leds_pb2 as ptcl_leds
from protobuf import fileconfig_pb2 as ptcl_fileCfg
from protobuf_to_dict import protobuf_to_dict
from ProtocolPacket import ProtocolPacket, decode_maxpb


def toStr(n, base):
    convertString = "0123456789ABCDEF"
    if n < base:
        return convertString[n]
    else:
        return toStr(n // base, base) + convertString[n % base]


def serialize_led_config():
    fileConfig = ptcl_fileCfg.FileConfig()
    ledsValues = fileConfig.repLedsValues.add()
    ledsValues.commandID = 20
    timeDiff = 100
    for i in range(20):
        led = ledsValues.leds.add()
        led.number = i
        led.red = ptcl_leds.STRENGTH_25
        led.green = ptcl_leds.STRENGTH_25
        led.blue = ptcl_leds.STRENGTH_25
        led.blink.enable = True
        led.blink.timeOn = timeDiff
        led.blink.timeOff = 2000 - timeDiff
        led.blink.numBlinks = 0
        timeDiff += 100
    print(fileConfig)
    return fileConfig.SerializeToString()


def serialize_repeated_led_config():
    """
    Envia configuração repetida dos LEDs.
    """
    fileConfig = ptcl_fileCfg.FileConfig()
    fileConfig.timingConfig.period = 100
    strength = 0
    # Anda por todas as cores, dando efeito de movimento dos LEDs.
    for base in range(64):
        ledno = 0
        ledsValues = fileConfig.repLedsValues.add()
        for i in range(base, base + 20):
            ledsValues.commandID = ledno
            led = ledsValues.leds.add()
            led.number = ledno
            led.red = i % 4
            led.green = (i / 4) % 4
            led.blue = (i / 16) % 4
            ledno += 1
            print("Seq: %s R:%d G:%d B:%d" % (toStr(i, 4).zfill(3)[::-1],
                                              led.red, led.green, led.blue))
        #strength += 1
    #print(fileConfig)
    return fileConfig.SerializeToString()


if __name__ == '__main__':
    #serialized_pckt = serialize_led_config()
    serialized_pckt = serialize_repeated_led_config()
    import binascii
    print(binascii.hexlify(serialized_pckt))
    with open("/home/eullerborges/encoded_leds.pro", "w") as f:
        f.write(serialized_pckt)
    print("LEN: %d" % len(serialized_pckt))
    print("LEN2: %d" % len(binascii.hexlify(serialized_pckt)))

    # leds2 = ptcl_leds.LedsValues()
    # leds2.ParseFromString(serialized_pckt)
    # print(leds2)
