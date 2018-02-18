#include <iostream>
#include <unistd.h>

#include "accel.h"

#define READ_ACCEL_FREQ_MS 2000

using namespace std;

Accel accel;

int main()
{
	accel = Accel();
	
	if (accel.state != 0x0)
	{
		cout << "Error initializing accel: " << accel.state << endl;
		return -1;
	}
	
	while (true)
	{
		int _x, _y, _z;
		accel.readAccel(&_x, &_y, &_z);
		
		cout << "Axis values (x,y,z): (" << _x << "," << _y << "," << _z << ")" << endl;
		
		usleep(READ_ACCEL_FREQ_MS * 1000); // takes microseconds
	}
}
