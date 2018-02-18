// Accelerometer class header file
// ADXL345 3-axis accelerometer

#include "adxl345.h"

#ifndef ACCEL_h
#define ACCEL_h

#define ADXL_MEASUREMENT_RANGE_2G   0b00000000
#define ADXL_MEASUREMENT_RANGE_4G   0b00000001
#define ADXL_MEASUREMENT_RANGE_8G   0b00000010
#define ADXL_MEASUREMENT_RANGE_16G  0b00000011

class Accel
{
	public:
		char state; // used for error indication
		
		Accel();
		
		void readAccel(int *x, int *y, int *z);
		
	private:
		int fd; // file handle for writing to accelerometer
};

#endif
