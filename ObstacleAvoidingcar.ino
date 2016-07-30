
/*
Author: Ajmain
Code modified: April 27, 2016
Feel free to email me if you run into any questions: Naqibprio10@gmail.com
*/

//code starts
#include <NewPing.h> // for distance sensor library
#include <AFMotor.h> // for motor shield library

#define TRIGGER_PIN  14 // telling the arduino that a0 is trigger pin.
#define ECHO_PIN     15 // telling the ardiono that a1 is echo pin
#define MAX_DISTANCE 200 // telling the arduino that my distance will never be over 200cm. If it does, its false. 
AF_DCMotor Motor1(2); // in motor shield, connection for right motor. M2
AF_DCMotor Motor2(1); // in motor shield, connection for left motor. M1


NewPing DistanceSensor(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // distance sensor library needs these value

void setup()  
{
  Serial.begin(9600); // start a screen of sort to show values in laptop; debug

}

void loop(){

  checkobs(); // goes to the function to check for obstacles


}


void turnright(){  //a function which turns right
  int lspeed = 255;    // max :255   test: 
  int rspeed = 150;    // max :160   test: 

  Motor1.setSpeed(rspeed);
  Motor2.setSpeed(lspeed);
  Motor1.run(BACKWARD);
  Motor2.run(FORWARD);
  Serial.println("Done Right");
  delay(500); 
  Motor1.setSpeed(0);
  Motor2.setSpeed(0);
  Motor1.run(BRAKE);
  Motor2.run(BRAKE);
  delay(1000);
  checkobs();   
}

void driveforward(){   // a function which drives foorward
  int lspeed = 255;    // max :255   test: 
  int rspeed = 150;    // max :160   test: 

  Motor1.setSpeed(rspeed);
  Motor2.setSpeed(lspeed);
  Motor1.run(FORWARD);
  Motor2.run(FORWARD);
  delay(100);
  Serial.println("Done Forward ");
  checkobs();
}

void checkobs(){  // a function that checks if distance is less than 20 or more than 0. If so, turns right, otherwise drives forward.
  unsigned int cm = DistanceSensor.ping_cm();   
  Serial.print("Distance: "); // prints the word "Distance" to laptop screen
  Serial.print(cm); // prints Distance in cm to laptop screen
  Serial.println("cm"); // prints the word "cm" to laptop screen

    if (cm < 15 && cm>0){
    turnright();  // if the distance is less than 20 cm, and more than 0, turns right
  }
  else{
    driveforward();  // if the distance is more than 20 cm, drives forward
  }
}
//code ends
