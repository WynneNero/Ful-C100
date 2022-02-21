#ifndef CRC_H_
#define CRC_H_

//#include "StdType.h"
//#include "Crc_Cfg.h"
#include "v_def.h"
#include "Platform_Types.h"


uint8 Crc_CalculateCRC8(const uint8*, uint32, uint8, boolean);

uint8 Crc_CalculateCRC8H2F(const uint8*, uint32, uint8, boolean);

uint16 Crc_CalculateCRC16(const uint8*, uint32, uint16, boolean);

uint32 Crc_CalculateCRC32(const uint8*, uint32, uint32, boolean);

#endif
