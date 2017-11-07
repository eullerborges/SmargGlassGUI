/*
 * crc.h
 *
 *  Created on: Sep 29, 2017
 *      Author: pedromedeiros
 */

#ifndef UTILS_CRC_H_
#define UTILS_CRC_H_

#include <stdint.h>

#define CRC16_DNP	0x3D65		// DNP, IEC 870, M-BUS, wM-BUS, ...
#define CRC16_CCITT	0x1021		// X.25, V.41, HDLC FCS, Bluetooth, ...


#define CRC16_POLYNOM		CRC16_CCITT   // Define the used polynom from one of the aboves


uint16_t Crc_crc16Calc(uint8_t *data, uint16_t dataSize);
#endif /* UTILS_CRC_H_ */
