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
from protobuf_to_dict import protobuf_to_dict
from ProtocolPacket import ProtocolPacket, decode_maxpb

def serialize_led_config():
    ledsValues = ptcl_leds.LedsValues()
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
    print(ledsValues)
    return ledsValues.SerializeToString()

if __name__ == '__main__':
    serialized_pckt = serialize_led_config()
    import binascii
    print(binascii.hexlify(serialized_pckt))
    with open("/home/eullerborges/encoded_leds.pro", "w") as f:
        f.write(serialized_pckt)
    print("LEN: %d" % len(serialized_pckt))
    print("LEN2: %d" % len(binascii.hexlify(serialized_pckt)))

    # leds2 = ptcl_leds.LedsValues()
    # leds2.ParseFromString(serialized_pckt)
    # print(leds2)
