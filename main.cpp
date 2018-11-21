#include <msp430.h> 
#include "SparkFunLSM9DS1.h"

LSM9DS1 imu;

#define LSM9DS1_M   0x1E // Would be 0x1C if SDO_M is LOW
#define LSM9DS1_AG  0x6B // Would be 0x6A if SDO_AG is LOW

#define DECLINATION -8.58 // Declination (degrees) in

int setup();
/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	if (!setup()){
	    while (1);
	}

	return 0;
}

int setup()
{
    imu.settings.device.commInterface = IMU_MODE_I2C;
    imu.settings.device.mAddress = LSM9DS1_M;
    imu.settings.device.agAddress = LSM9DS1_AG;

    if (!imu.begin())
      {
//        Serial.println("Failed to communicate with LSM9DS1.");
//        Serial.println("Double-check wiring.");
//        Serial.println("Default settings in this sketch will " \
//                      "work for an out of the box LSM9DS1 " \
//                      "Breakout, but may need to be modified " \
//                      "if the board jumpers are.");
        return 0;
      }
    return 1;
}
