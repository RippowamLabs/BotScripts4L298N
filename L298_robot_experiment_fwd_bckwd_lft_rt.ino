// connect motor controller pins to Arduino digital pins
// motor one
int enA = 10;
int in1 = 9;
int in2 = 8;
// motor two
int enB = 5;
int in3 = 7;
int in4 = 6;
void setup()
{
  // set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop()
{
  
  goStraight();
  
  takeLeft();
 
  goBackward();
  
  takeRight();

 }

void takeLeft()
{
   // set speed to 200 out of possible range 0~255
  analogWrite(enB, 75);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, 200);
  
  //set direction
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
   
  //set direction
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  
  delay(500);
}

void takeRight()
{
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, 75);
  // set speed to 200 out of possible range 0~255
  analogWrite(enB, 200);
  
  //set direction
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
    
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
   
  delay(500);
}

void goStraight()
{
  
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, 200);
  // set speed to 200 out of possible range 0~255
  analogWrite(enB, 200);
  
  //set direction
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  
  // turn on motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  
  delay(2000);
}

void goBackward()
{
  // set speed to 200 out of possible range 0~255
  analogWrite(enB, 200);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, 200);
  
  //set direction
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
    
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  
  delay(2000);
}
