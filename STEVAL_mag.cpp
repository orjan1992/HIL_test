#include "STEVAL_mag.h"


STEVAL_mag::STEVAL_mag(double dataRate, bool enableTemp)
{
#if I2C_MODE == 3
	this->GPIO = new wiringPiI2C();
	this->fd = GPIO->wiringPiI2CSetup(0x1E);
	//this->fd = GPIO->wiringPiI2CSetup(0x3C);
#else
	this->fd = wiringPiI2CSetup(0x1E);
	//this->fd = wiringPiI2CSetup(0x3C);
#endif
	this->status_reg = 0x09;
	this->control_reg = 0x00;
	this->out_x_l = 0x03;
	this->out_x_h = 0x04;
	this->out_y_l = 0x05;
	this->out_y_h = 0x06;
	this->out_z_l = 0x07;
	this->out_z_h = 0x08;
	this->setPowerMode(dataRate, enableTemp);
}

bool STEVAL_mag::setPowerMode(double dataRate, bool enableTemp){
	int rate;
	int dataRateSwitch = dataRate * 10;
	switch (dataRateSwitch){
	case 0:
		rate = 0;
		break;
	case 15:
		rate = 1;
		break;
	case 30:
		rate = 2;
		break;
	case 75:
		rate = 3;
		break;
	case 150:
		rate = 4;
		break;
	case 300:
		rate = 5;
	case 750:
		rate = 6;
		break;
	case 2200:
		rate = 7;
		break;
	default:
		rate = 4;
		break;
	}
	int regVal = (enableTemp << 7) | (rate << 2);
	writeReg(this->control_reg, regVal);
#if I2C_MODE < 3
	if (readReg(this->control_reg) == regVal){ return true; }
	else{ return false; }
#else
	return true;
#endif
}

bool STEVAL_mag::checkAvailability(void){
	int stat = readReg(status_reg);
	if ((stat >> 0) & 1){
		return true;
	}
	else{ return false; }
}