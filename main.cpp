#ifndef I2C_MODE
#include "I2Cmode.h"
#endif
#if I2C_MODE == 3
#include "wiringPiI2C.h"
#else
#include <wiringPiI2C.h>
#include <wiringPi.h>
#endif
#include <iostream>
#include <errno.h>
#include "STEVAL_sensor.h"
#include "STEVAL_acc.h"
#include "STEVAL_gyr.h"
#include "STEVAL_mag.h"


struct sensor_values{
	double acc[3];
	double gyr[3];
	double mag[3];
	double time;
};
//using namespace std;
int main()
{
std::cout << I2C_MODE <<std::endl;
STEVAL_gyr gyr;
STEVAL_acc acc(400, true);
STEVAL_mag mag();
sensor_vals gyr_vals;
#if I2C_MODE == 3
int a = getchar();
#else
while(1){
	gyr_vals =gyr.readSensor();
	std::cout << "x: " << gyr_vals.val[0] << "\ty: " << gyr_vals.val[1] << "\tz " << gyr_vals.val[2] << std::endl;
	delay(200);
}
#endif

	//int fd = wiringPiI2CSetup(0x6B);
	//wiringPiI2CWriteReg8(fd, 0x20, 0x0F);
	//std::cout << std::hex << wiringPiI2CReadReg8(fd, 0x28) << std::endl;
}
