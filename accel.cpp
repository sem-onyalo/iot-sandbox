// Accelerometer class
// ADXL345 3-axis accelerometer

#include <wiringPiI2C.h>
#include "accel.h"

Accel::Accel()
{
	int _range = ADXL_MEASUREMENT_RANGE_8G; // hard-code for now
	
	state = 0x0;
	
	fd = wiringPiI2CSetup(0x53);
	if (fd == -1)
	{
		state = 0x01;
		return;
	}
	
	int _r = wiringPiI2CWriteReg8(fd, ADXL345_POWER_CTL, 8);
	if (_r == -1) 
	{
		state = 0x02;
		return;
	}
	
	_r = wiringPiI2CReadReg8(fd, ADXL345_DATA_FORMAT);
	if (_r == -1)
	{
		state = 0x03;
		return;
	}
	
	_r = wiringPiI2CWriteReg8(fd, ADXL345_DATA_FORMAT, _range);
	if (_r == -1)
	{
		state = 0x04;
		return;
	}
}

void Accel::readAccel(int *x, int *y, int *z)
{
	// Axis data is 10 bit resolution (i.e. 2 bytes)
	// Reading 16 bits from DATAn0 is analagous to reading 8 bits from 
	// DATAn0 and 8 bits from DATAn1. 
	*x = wiringPiI2CReadReg16(fd, ADXL345_DATAX0);
	*y = wiringPiI2CReadReg16(fd, ADXL345_DATAY0);
	*z = wiringPiI2CReadReg16(fd, ADXL345_DATAZ0);
}
