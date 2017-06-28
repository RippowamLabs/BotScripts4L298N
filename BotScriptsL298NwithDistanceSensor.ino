#include <Wire.h>
#include <NewPing.h> // http://playground.arduino.cc/Code/NewPing

#define TRIGGER_PIN  11  // Arduino pin tied to trigger pin on the ultrasonic sensor. Must be a PWM pin
#define ECHO_PIN  4      // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 140 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define LED 13

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

// connect motor controller pins to Arduino digital pins
// motor one
int enA = 10;
int in1 = 9;
int in2 = 8;
// motor two
int enB = 5;
int in3 = 7;
int in4 = 6;

int in11 = 11;
int in4sensor = 4;
void setup()
{
  // set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(in11, OUTPUT);
  pinMode(in4sensor, INPUT);
  
  Serial.begin(9600); // Open serial monitor at 9600 baud to see ping results.
}

void loop()
{
   delay(50);                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  Serial.print("Ping: ");
  //Serial.print(uS / US_ROUNDTRIP_CM); // Convert ping time to distance in cm and print result (0 = outside set distance range)
  Serial.print(uS ); // Convert ping time to distance in cm and print result (0 = outside set distance range)

  Serial.println("cm");
  if( uS > 100 && uS < 935 ){
    goBackward();
    delay(1000);
    takeLeft();
    digitalWrite(LED,HIGH);
    delay(1000);
  } else {
    goStraight();
    digitalWrite(LED,LOW);
  }
  
//  goStraight();
//  
//  takeLeft();
// 
//  goBackward();
//  
//  takeRight();

 }

void takeLeft()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);   
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, 200);
   digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
   // set speed to 200 out of possible range 0~255
  analogWrite(enB, 75);
  
  //delay(500);
}

void takeRight()
{
     digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, 75);
   
    digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
   // set speed to 200 out of possible range 0~255
  analogWrite(enB, 200);
  
  //delay(500);
}

void goStraight()
{
     digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, 200);
  // turn on motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  // set speed to 200 out of possible range 0~255
  analogWrite(enB, 200);
  
 // delay(2000);
}

void goBackward()
{
   digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, 200);
  // turn on motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enB, 200);
  
 // delay(2000);
}

