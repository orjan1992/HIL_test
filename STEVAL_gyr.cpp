#include "STEVAL_gyr.h"
/*Constructor*/
STEVAL_gyr::STEVAL_gyr(void)
{
#if I2C_MODE == 3
	GPIO = new wiringPiI2C();
	fd = GPIO->wiringPiI2CSetup(0x6B);
	//fd = GPIO->wiringPiI2CSetup((GYR_ADDRESS << 1) | 0);
#else
	fd = wiringPiI2CSetup(0x6B);
	//fd = wiringPiI2CSetup((GYR_ADDRESS << 1) | 0);
#endif
	status_reg = 0x27;
	control_reg = 0x20;
	out_x_l = 0x28;
	out_x_h = 0x29;
	out_y_l = 0x2A;
	out_y_h = 0x2B;
	out_z_l = 0x2C;
	out_z_h = 0x2D;
	setPowerMode();
#if I2C_MODE < 3
	if(readReg(WHO_AM_I)!=L3GD20_ID){std::cout<<"Connection error gyr"<<std::endl;}
#endif

}



/*Private methods*/

bool STEVAL_gyr::setPowerMode(void){
	writeReg(control_reg, 0x00); //turn off
	writeReg(control_reg, 0x3F); //Normal mode, enable all

	return 1;
}

sensor_vals STEVAL_gyr::readSensor(void){
	this->readRawSensor();
	this->val.val[0] = this->val.raw[0]*GYRO_SENSITIVITY_250DPS*SENSORS_DPS_TO_RADS;
	this->val.val[1] = this->val.raw[1]*GYRO_SENSITIVITY_250DPS*SENSORS_DPS_TO_RADS;
	this->val.val[2] = this->val.raw[2]*GYRO_SENSITIVITY_250DPS*SENSORS_DPS_TO_RADS;
	return this->val;
}