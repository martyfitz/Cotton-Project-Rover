#define pi 3.1415926535
const byte encoderPin = 2; // Interrupt pin
const byte motor1Pin = 9; // PWM output
const byte motor2Pin = 10; // PWM output
volatile long pulseCounter = 0;

void setup() {
  Serial.begin(115200);
  pinMode(encoderPin, INPUT_PULLUP);
  pinMode(motor1Pin, OUTPUT);
  pinMode(motor2Pin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(encoderPin), counter, RISING);
}

void loop() {
  float distance;
  float avgSpeed;
  const int distConst = 0.0018;
  
  analogWrite(motor1Pin, 191); // 75% duty cycle at 490 Hz
  analogWrite(motor2Pin, 191); // 75% duty cycle at 490 Hz
  delay(1000);
  distance = distConst * pi * pulseCounter;
  Serial.print("Distance Covered: ")
  Serial.print(distance)
  Serial.print(" m.\n");
  delay(1000);
  distance = distConst * pi * pulseCounter;
  Serial.print("Distance Covered: ")
  Serial.print(distance)
  Serial.print(" m.\n");
  delay(1000);
  distance = distConst * pi * pulseCounter;
  Serial.print("Distance Covered: ")
  Serial.print(distance)
  Serial.print(" m.\n");
  delay(1000);
  distance = distConst * pi * pulseCounter;
  Serial.print("Distance Covered: ")
  Serial.print(distance)
  Serial.print(" m.\n");
  delay(1000);
  distance = distConst * pi * pulseCounter;
  Serial.print("Distance Covered: ")
  Serial.print(distance)
  Serial.print(" m.\n");
  
  analogWrite(motor1Pin, 0);
  analogWrite(motor2Pin, 0);
  delay(2000);
  
  distance = distConst * pi * pulseCounter;
  Serial.print("Total Distance Covered: ")
  Serial.print(distance)
  Serial.print(" m.\n");
  avgSpeed = distance / 5.0;
  Serial.print("Average Speed: ")
  Serial.print(avgSpeed)
  Serial.print(" m/s.\n");
}

void counter() {
  pulseCounter++;
}
