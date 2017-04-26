#include "STEVAL_acc.h"
/*****************************************
TODO
-add other register functions
-status check
***************************************************/


/*Constructor*/
STEVAL_acc::STEVAL_acc(int freq, bool lPmode)
{
#if I2C_MODE == 3
	this->GPIO = new wiringPiI2C();
	this->fd = GPIO->wiringPiI2CSetup(0x19);
	//this->fd = GPIO->wiringPiI2CSetup((ACC_ADDRESS << 1) | 0);
#else
	this->fd = wiringPiI2CSetup(0x19);
	//this->fd = wiringPiI2CSetup((ACC_ADDRESS << 1) | 0);
#endif
	this->status_reg = 0x27;
	this->control_reg = 0x20;
	this->out_x_l = 0x28;
	this->out_x_h = 0x29;
	this->out_y_l = 0x2A;
	this->out_y_h = 0x2B;
	this->out_z_l = 0x2C;
	this->out_z_h = 0x2D;
	int error;
	error = this->setPowerMode(freq, lPmode);
#if I2C_Mode < 3
	if(error){
		std::cout << "Connection error acc" << std::endl;
	}
#endif

}

bool STEVAL_acc::setPowerMode(int freq, bool lPmode){
	int freq_val, reg_val;
	switch (freq){
	case 0:
		freq_val = 0;
		break;
	case 1:
		freq_val = 1;
		break;
	case 10:
		freq_val = 0x2;
		break;
	case 25:
		freq_val = 0x3;
		break;
	case 50:
		freq_val = 0x4;
		break;
	case 100:
		freq_val = 0x5;
		break;
	case 200:
		freq_val = 0x6;
		break;
	case 400:
		freq_val = 0x7;
		break;
	case 1344:
		freq_val = 0x9;
		break;
	case 1620:
		freq_val = 0x8;
		break;
	case 5376:
		freq_val = 0x9;
		break;
	default:
		freq_val = 0x7;
		break;
	}
	int enable = 0x7;
	int LPen = 0;
	if(lPmode){
		int LPen = 1; //0 is normal mode, 1 is low power mode
	}
	reg_val = ((freq_val<<1)|LPen)<<3|enable;
	writeReg(this->control_reg, reg_val);
#if I2C_MODE < 3
	if(readReg(this->control_reg)==reg_val){ return true;}
	else{return false;}
#else
	return true;
#endif
}

sensor_vals STEVAL_acc::readSensor(void){
	this->readRawSensor();
	this->val.val[0] = ((this->val.raw[0])>>4) * ACCEL_MG_LSB*SENSORS_GRAVITY_STANDARD;
	this->val.val[1] = ((this->val.raw[1])>>4) * ACCEL_MG_LSB*SENSORS_GRAVITY_STANDARD;
	this->val.val[2] = ((this->val.raw[2])>>4) * ACCEL_MG_LSB*SENSORS_GRAVITY_STANDARD;
	return this->val;
}