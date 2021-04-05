#include <SoftwareSerial.h> 

//Initializing pins for bluetooth Module
int bluetoothTx = 2; 
int bluetoothRx = 3; 
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

//Front Motor Pins  
int frontMotorPinA = 11;  
int frontMotorPinB = 10;  

//Back Motor Pins      
int backMotorPinA = 6; 
int backMotorPinB = 5;

char received ; //Receive the data from bluetooth

void setup() 
{       
  //Set the baud rate of serial communication and bluetooth module at same rate.
  Serial.begin(9600);  
  bluetooth.begin(9600);

  //Setting the L298N.
  pinMode(frontMotorPinA, OUTPUT);  
  pinMode(frontMotorPinB, OUTPUT);
  
  pinMode(backMotorPinA, OUTPUT);  
  pinMode(backMotorPinB, OUTPUT);
}

void loop(){
  if(bluetooth.available()){  //Checking if there is some data available or not
    received = bluetooth.read();   
    Serial.println(received);      //Printing it on the serial monitor
  }
    
    switch(received){
    case 'F':  //Moving the Car Forward
      forward();
      stopFrontMotor();
      break;
    case 'B':  //Moving the Car Backward
      backward();
      stopFrontMotor();
      break;
    case 'L':  //Moving the Car Left
      left();
      break;
    case 'R':   //Moving the Car Right
      right();
      break;
    case 'S':   //Stop
      stopFrontMotor();
      stopBackMotor();
      break; 
    case 'I':  //Moving the Car Forward right
      forwardRight();
      break; 
    case 'G':  //Moving the Car Forward left
      forwardLeft();
      break; 
    case 'J':  //Moving the Car backward right
      backwardRight();
      break;        
    case 'H':  //Moving the Car backward left
      backwardLeft();
      break;
    case 'v':
      
      break;
    default:  
      stopFrontMotor();
      stopBackMotor();
    }
}

void forward(){
  digitalWrite(backMotorPinA,HIGH);
  digitalWrite(backMotorPinB,LOW);
}

void backward(){
  digitalWrite(backMotorPinA,LOW);
  digitalWrite(backMotorPinB,HIGH);
}

void left(){
  digitalWrite(frontMotorPinA,HIGH);
  digitalWrite(frontMotorPinB,LOW);
}

void right(){
  digitalWrite(frontMotorPinA,LOW);
  digitalWrite(frontMotorPinB,HIGH);
}

void forwardLeft(){
  forward();
  left();
}

void forwardRight(){
  forward();
  right();
}

void backwardLeft(){
  backward();
  left();
}

void backwardRight(){
  backward();
  left();
}

void stopFrontMotor(){
  digitalWrite(frontMotorPinA,LOW);
  digitalWrite(frontMotorPinB,LOW);
}

void stopBackMotor(){
  digitalWrite(backMotorPinA,LOW);
  digitalWrite(backMotorPinB,LOW);
}
