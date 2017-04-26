#ifndef _STEVAL_SENSOR
#define _STEVAL_SENSOR
#include "I2Cmode.h"
#if I2C_MODE == 3
#include "wiringPiI2C.h"
#else
#include <wiringPiI2C.h>
#endif
#include <iostream>
#include <errno.h>
#include <stdint.h>

/* Constants */
#define SENSORS_GRAVITY_EARTH             (9.80665F)              /**< Earth's gravity in m/s^2 */
#define SENSORS_GRAVITY_MOON              (1.6F)                  /**< The moon's gravity in m/s^2 */
#define SENSORS_GRAVITY_SUN               (275.0F)                /**< The sun's gravity in m/s^2 */
#define SENSORS_GRAVITY_STANDARD          (SENSORS_GRAVITY_EARTH)
#define SENSORS_MAGFIELD_EARTH_MAX        (60.0F)                 /**< Maximum magnetic field on Earth's surface */
#define SENSORS_MAGFIELD_EARTH_MIN        (30.0F)                 /**< Minimum magnetic field on Earth's surface */
#define SENSORS_PRESSURE_SEALEVELHPA      (1013.25F)              /**< Average sea level pressure is 1013.25 hPa */
#define SENSORS_DPS_TO_RADS               (0.017453293F)          /**< Degrees/s to rad/s multiplier */
#define SENSORS_GAUSS_TO_MICROTESLA       (100)   


struct sensor_vals{
			float val[3];
			int16_t raw[3];
			double time;
		};
class STEVAL_sensor{
	public:
		
		STEVAL_sensor(void);
		//bool init(void);
		sensor_vals readSensor(void);
		sensor_vals sensor_readings;
		
		bool checkAvailability(void);
	protected:
		int readReg(int reg);
		bool writeReg(int reg, int data);
		bool readRawSensor(void);

#if I2C_MODE == 3
		wiringPiI2C* GPIO;
#endif		
		int fd;
		int status_reg, control_reg, out_x_h, out_x_l, out_y_h, out_y_l, out_z_h, out_z_l;
		//sensor_vals raw_vals;
		sensor_vals val;
		
		
};
#endif //_STEVAL_SENSOR