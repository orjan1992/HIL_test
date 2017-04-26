#ifndef _STEVAL_MAG
#define _STEVAL_MAG
#include "I2Cmode.h"
#include "STEVAL_sensor.h"
//#define CRA_REG_M 0x00
//#define CRB_REG_M 0x01
//#define MR_REG_M 0x02
//#define OUT_X_H_M 0x03
//#define OUT_X_L_M 0x04
//#define OUT_Z_H_M 0x05
//#define OUT_Z_L_M 0x06
//#define OUT_Y_H_M 0x07
//#define OUT_Y_L_M 0x08
//#define SR_REG_M 0x09
//#define IRA_REG_M 0x0A
//#define IRB_REG_M 0x0B
//#define IRC_REG_M 0x0C
//#define TEMP_OUT_H_M 0x31
//#define TEMP_OUT_L_M 0x32
class STEVAL_mag : STEVAL_sensor
{
public:
	STEVAL_mag(double dataRate, bool enableTemp);
private:
	bool setPowerMode(double dataRate, bool enableTemp);
	bool checkAvailability(void);
};
#endif
