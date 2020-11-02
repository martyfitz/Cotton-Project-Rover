#define pi 3.1415926535

const byte encoderPin = 2; // Interrupt pin
const byte motor1Pin = 9; // PWM output
const byte motor2Pin = 10; // PWM output
volatile long pulseCounter = 0;

void setup() {
  Serial.begin(115200);
  pinMode(encoderPin, INPUT);
  pinMode(motor1Pin, OUTPUT);
  pinMode(motor2Pin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(encoderPin), counter, RISING);
}

void loop() {
  float distance;
  float avgSpeed;
  
  analogWrite(motor1Pin, 63); // 25% duty (0-255)
  analogWrite(motor2Pin, 63); // 25% duty (0-255)
  delay(5000); // 5 seconds of motor movement
  
  analogWrite(motor1Pin, 0);
  analogWrite(motor2Pin, 0);
  delay(2000);
  
  distance = 0.0018 * pi * pulseCounter;
  Serial.print("Total Distance Covered: ");
  Serial.print(distance);
  Serial.print(" m.\n");
  
  avgSpeed = distance / 5.0;
  Serial.print("Average Speed: ");
  Serial.print(avgSpeed);
  Serial.print(" m/s.\n");
  
  Serial.print("Counter: ");
  Serial.print(pulseCounter);
  Serial.print("\n");
  pulseCounter = 0;
}

void counter() {
  pulseCounter++;
}
