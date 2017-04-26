#ifndef _STEVAL_GYR
#define _STEVAL_GYR
#include "I2Cmode.h"
#if I2C_MODE == 3
#include "wiringPiI2C.h"
#else
#include <wiringPiI2C.h>
#endif
#include <iostream>
#include <errno.h>
#include "STEVAL_sensor.h"

#define GYR_ADDRESS		0x6B
#define L3GD20_ID       0xD4

#define WHO_AM_I 		0x0F
// #define CTRL_REG1 		0x20
// #define CTRL_REG2 		0x21
// #define CTRL_REG3 		0x22
// #define CTRL_REG4 		0x23
// #define CTRL_REG5 		0x24
// #define REFERENCE 		0x25
// #define OUT_TEMP 		0x26
// #define STATUS_REG 		0x27
// #define OUT_X_L 		0x28
// #define OUT_X_H 		0x29
// #define OUT_Y_L 		0x2A
// #define OUT_Y_H 		0x2B
// #define OUT_Z_L 		0x2C
// #define OUT_Z_H 		0x2D
// #define FIFO_CTRL_REG 	0x2E
// #define FIFO_SRC_REG 	0x2F
// #define INT1_CFG 		0x30
// #define INT1_SRC 		0x31
// #define INT1_TSH_XH 	0x32
// #define INT1_TSH_XL 	0x33
// #define INT1_TSH_YH 	0x34
// #define INT1_TSH_YL 	0x35
// #define INT1_TSH_ZH 	0x36
// #define INT1_TSH_ZL 	0x37
// #define INT1_DURATION 	0x38

#define GYRO_SENSITIVITY_250DPS  (0.00875F)    // Roughly 22/256 for fixed point match
#define GYRO_SENSITIVITY_500DPS  (0.0175F)     // Roughly 45/256
#define GYRO_SENSITIVITY_2000DPS (0.070F)      // Roughly 18/256

class STEVAL_gyr : public STEVAL_sensor
{
public:
	STEVAL_gyr(void);
	sensor_vals readSensor(void);
private:
	bool setPowerMode(void);
};

#endif // _STEVAL_GYR