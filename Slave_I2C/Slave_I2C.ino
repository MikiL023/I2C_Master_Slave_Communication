/*
  I2c Slave controler for
  controling servo 
*/
 
// Include Arduino Wire library for I2C
#include <Wire.h>
#include <Servo.h>
 
// Define Slave I2C Address
#define SLAVE_ADDR 9

 Servo myservo;
// Variable for received data
int rd;
 
 
void setup() {
 
  myservo.attach(9);
  
  // Initialize I2C communications as Slave
  Wire.begin(SLAVE_ADDR);
   
  // Function to run when data received from master
  Wire.onReceive(receiveEvent);
  
  // Setup Serial Monitor 
  Serial.begin(9600);
  Serial.println("I2C Slave Demonstration");
}
 
 
void receiveEvent() {
  // read one character from the I2C
  rd = Wire.read();
  // Print value of incoming data
  Serial.println(rd);
    
}
void loop() {
   delay(50);
 myservo.write(rd);                  // sets the servo position according to the scaled value
  delay(15);
  
 
}
