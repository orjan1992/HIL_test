#include "STEVAL_sensor.h"
STEVAL_sensor::STEVAL_sensor(void){
	fd = -1;
	fd = -1;
	status_reg = -1;
	control_reg = -1;

	out_x_h = -1;
	out_x_l = -1;
	out_y_h = -1;
	out_y_l = -1;
	out_z_h = -1;
	out_z_l = -1;
#if I2C_MODE == 3
	GPIO = new wiringPiI2C();
#endif
}

bool STEVAL_sensor::writeReg(int reg, int data){
	int result;
#if I2C_MODE == 3
	result = GPIO->wiringPiI2CWriteReg8(fd, ((reg << 1) | 0), data);
#else
	//result = wiringPiI2CWriteReg8(fd, ((reg << 1) | 0), data);
	//result = wiringPiI2CWriteReg8(fd, reg|0x80, data);
	result = wiringPiI2CWriteReg8(fd, reg, data);
#endif
	if(result==-1){
		return false;
		std::cout << "Error. Errno is: " <<errno <<std::endl;
	} else {
		return true;
	}
}

int STEVAL_sensor::readReg(int reg){
	int result;
#if I2C_MODE == 3
	result = GPIO->wiringPiI2CReadReg8(fd, ((reg << 1) | 0));
#else
	//result = wiringPiI2CReadReg8(fd, ((reg << 1) | 0));
	//result = wiringPiI2CReadReg8(fd, reg|0x80);
	result = wiringPiI2CReadReg8(fd, reg);
#endif
	if(result==-1){
		std::cout << "Error. Errno is: " <<errno <<std::endl;
	}
	return result;
}

bool STEVAL_sensor::checkAvailability(void){
	int stat = readReg(status_reg);
	if(((stat >> 0) & 1)&&((stat >> 1) & 1)&&((stat >> 2) & 1)){
		return true;
	}else{return false;}
}
bool STEVAL_sensor::readRawSensor(void){
	if(checkAvailability()){
		uint8_t xl = readReg(out_x_l);
		uint8_t xh = readReg(out_x_h);
		uint8_t yl = readReg(out_y_l);
		uint8_t yh = readReg(out_y_h);
		uint8_t zl = readReg(out_z_l);
		uint8_t zh = readReg(out_z_h);
		this->val.raw[0] = (xl | (xh << 8));
		this->val.raw[1] = (yl | (yh << 8));
		this->val.raw[2] = (zl | (zh << 8));
		return true;
	} else {
		return false;
	}
}

sensor_vals STEVAL_sensor::readSensor(void){
	this->readRawSensor();
	return this->val;
}