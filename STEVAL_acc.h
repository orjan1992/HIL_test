#ifndef _STEVAL_ACC
#define _STEVAL_ACC
#ifndef I2C_MODE
#include "I2Cmode.h"
#endif
#if I2C_MODE == 3
#ifndef _WIRINGPII2C
#include "wiringPiI2C.h"
#endif
#else
#include <wiringPiI2C.h>
#endif
#ifndef _IOSTREAM_
#include <iostream>
#endif
#ifndef _INC_ERRNO
#include <errno.h>
#endif
#ifndef _STEVAL_SENSOR
#include "STEVAL_sensor.h"
#endif

/* Constants */
#define ACC_ADDRESS 	0x1e

// register addresses
//#define CTRL_REG1_A 		0x20 //poower mode and enable
//#define CTRL_REG2_A 		0x21
//#define CTRL_REG3_A 		0x22
//#define CTRL_REG4_A 		0x23
//#define CTRL_REG5_A 		0x24
//#define CTRL_REG6_A 		0x25
//#define REFERENCE_A 		0x26
//#define STATUS_REG_A 		0x27
//#define OUT_X_L_A 			0x28
//#define OUT_X_H_A 			0x29
//#define OUT_Y_L_A 			0x2A
//#define OUT_Y_H_A 			0x2B
//#define OUT_Z_L_A 			0x2C
//#define OUT_Z_H_A 			0x2D
//#define FIFO_CTRL_REG_A 	0x2E
//#define FIFO_SRC_REG_A 		0x2F
//#define INT1_CFG_A 			0x30
//#define INT1_SRC_A 			0x31
//#define INT1_THS_A 			0x32
//#define INT1_DURATION_A 	0x33
//#define INT2_CFG_A 			0x34
//#define INT2_SRC_A 			0x35
//#define INT2_THS_A 			0x36
//#define INT2_DURATION_A 	0x37
//#define CLICK_CFG_A 		0x38
//#define CLICK_SRC_A 		0x39
//#define CLICK_THS_A 		0x3A

#define ACCEL_MG_LSB (0.001F)

class STEVAL_acc : STEVAL_sensor
{
public:
	STEVAL_acc(int freq, bool lPmode);
	sensor_vals readSensor(void);
private:
	bool setPowerMode(int freq, bool lPmode);
};

#endif //_STEVAL_ACC