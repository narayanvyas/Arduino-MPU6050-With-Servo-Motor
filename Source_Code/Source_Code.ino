/*  MPU6050 Accelerometer With Servo Motor
 * 
 *  GitHub URL - https://github.com/narayanvyas/Arduino-MPU6050-With-Servo-Motor
 * 
 *  Developed By Web Dev Fusion
 *  URL - https://www.webdevfusion.com
 *  
 *  Components
 *  ----------
 *   - Arduino Uno
 *   - MPU6050 Module
 *   - Jumper Wires
 *   - Breadboard / PCB
 *   - Servo Motor
 *  
 *  Libraries
 *  ---------
 *  - I2CDevLib - https://github.com/jrowberg/i2cdevlib
 *  - Download ZIP From above link, Go to Arduino Folder from ZIP > Copy I2Cdev And MPU6050 Folder to your Arduino Library Folder
 *  
 */

#include <Wire.h>
#include <MPU6050.h>
#include <Servo.h>   

Servo sg90;          
int servo_pin = 9;
MPU6050 sensor ;

int16_t ax, ay, az ;
int16_t gx, gy, gz ;

void setup ( )
{ 
  sg90.attach ( servo_pin );
  Wire.begin ( );
  Serial.begin  (9600); 
  Serial.println  ( "Initializing the sensor" ); 
  sensor.initialize ( ); 
  Serial.println (sensor.testConnection ( ) ? "Successfully Connected" : "Connection failed"); 
  delay (1000); 
  Serial.println ( "Taking Values from the sensor" );
  delay (1000);
}

void loop ( ) 
{ 
  sensor.getMotion6 (&ax, &ay, &az, &gx, &gy, &gz);
  ax = map (ax, -17000, 17000, 0, 180) ;
  Serial.println (ax);
  sg90.write (ax); 
  delay (200);
}
