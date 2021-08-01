#define TRIGGER 7 // defining trigger pin for All Ultrasonic Sensor

#define ECHO1 1 // defining echo pin for Ultrasonic Sensor 1
#define ECHO2 2 // defining echo pin for Ultrasonic Sensor 2
#define ECHO3 3 // defining echo pin for Ultrasonic Sensor 3
#define ECHO4 4 // defining echo pin for Ultrasonic Sensor 4
#define ECHO5 5 // defining echo pin for Ultrasonic Sensor 5
#define ECHO6 6 // defining echo pin for Ultrasonic Sensor 6

#define LED1 8
#define LED2 9
#define LED3 10
#define LED4 11
#define LED5 12
#define LED6 13

void setup()
{
  Serial.begin(115200);

  pinMode(TRIGGER, OUTPUT); //initializing trigger as output

  pinMode(ECHO1, INPUT); //initialing trigger as input
  pinMode(ECHO2, INPUT);
  pinMode(ECHO3, INPUT);
  pinMode(ECHO4, INPUT);
  pinMode(ECHO5, INPUT);
  pinMode(ECHO6, INPUT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);

  pinMode(LED1, LOW);
  pinMode(LED2, LOW);
  pinMode(LED3, LOW);
  pinMode(LED4, LOW);
  pinMode(LED5, LOW);
  pinMode(LED6, LOW);
}

void loop()
{
  int duration1, distance1;
  digitalWrite(TRIGGER, LOW); // make trigger low
  delayMicroseconds(2);
  digitalWrite(TRIGGER, HIGH); // make trigger high
  delayMicroseconds(10); //give 10 microsec delay
  digitalWrite(TRIGGER, LOW);

  // LAMP POST 1
  duration1 = pulseIn(ECHO1, HIGH);
  distance1 = duration1 * 0.034 / 2; // calibrate the distance using pulse
  Serial.print("Lamp Post 1 Object in cm: ");
  Serial.println(distance1); // Print the distance value
  if (distance1 < 30) {
    pinMode(LED1, HIGH);
    pinMode(LED2, HIGH);
    Serial.print("Object Detected at Lamp Post 1");
  }
  else {
    pinMode(LED1, LOW);
    pinMode(LED2, LOW);
    Serial.print("No Object at Lamp Post 1");
  }

  // LAMP POST 2
  duration2 = pulseIn(ECHO2, HIGH);
  distance2 = duration2 * 0.034 / 2; // calibrate the distance using pulse
  Serial.print("Lamp Post 2 Object in cm: ");
  Serial.println(distance2); // Print the distance value
  if (distance2 < 30) {
    pinMode(LED1, HIGH);
    pinMode(LED2, HIGH);
    pinMode(LED3, HIGH);
    Serial.print("Object Detected at Lamp Post 2");
  }
  else if (distance1 > 30) {
    pinMode(LED1, LOW);
    pinMode(LED2, LOW);
    pinMode(LED3, LOW);
    Serial.print("No Object at Lamp Post 1 & 2");
  }
  else {
    pinMode(LED2, LOW);
    pinMode(LED3, LOW);
    Serial.print("No Object at Lamp Post 2");
  }

  // LAMP POST 3
  duration3 = pulseIn(ECHO3, HIGH);
  distance3 = duration3 * 0.034 / 2; // calibrate the distance using pulse
  Serial.print("Lamp Post 3 Object in cm: ");
  Serial.println(distance3); // Print the distance value
  if (distance3 < 30) {
    pinMode(LED2, HIGH);
    pinMode(LED3, HIGH);
    pinMode(LED4, HIGH);
    Serial.print("Object Detected at Lamp Post 3");
  }
  else if (distance2 > 30) {
    pinMode(LED2, LOW);
    pinMode(LED3, LOW);
    pinMode(LED4, LOW);
    Serial.print("No Object at Lamp Post 2 & 3");
  }
  else {
    pinMode(LED3, LOW);
    pinMode(LED4, LOW);
    Serial.print("No Object at Lamp Post 3");
  }

  // LAMP POST 4
  duration4 = pulseIn(ECHO4, HIGH);
  distance4 = duration4 * 0.034 / 2; // calibrate the distance using pulse
  Serial.print("Lamp Post 4 Object in cm: ");
  Serial.println(distance4); // Print the distance value
  if (distance4 < 30) {
    pinMode(LED3, HIGH);
    pinMode(LED4, HIGH);
    pinMode(LED5, HIGH);
    Serial.print("Object Detected at Lamp Post 4");
  }
  else if (distance3 > 30) {
    pinMode(LED3, LOW);
    pinMode(LED4, LOW);
    pinMode(LED5, LOW);
    Serial.print("No Object at Lamp Post 3 & 4");
  }
  else {
    pinMode(LED4, LOW);
    pinMode(LED5, LOW);
    Serial.print("No Object at Lamp Post 4");
  }

  // LAMP POST 5
  duration5 = pulseIn(ECHO5, HIGH);
  distance5 = duration5 * 0.034 / 2; // calibrate the distance using pulse
  Serial.print("Lamp Post 5 Object in cm: ");
  Serial.println(distance5); // Print the distance value
  if (distance5 < 30) {
    pinMode(LED4, HIGH);
    pinMode(LED5, HIGH);
    pinMode(LED6, HIGH);
    Serial.print("Object Detected at Lamp Post 5");
  }
  else if (distance4 > 30) {
    pinMode(LED4, LOW);
    pinMode(LED5, LOW);
    pinMode(LED6, LOW);
    Serial.print("No Object at Lamp Post 4 & 5");
  }
  else {
    pinMode(LED5, LOW);
    pinMode(LED6, LOW);
    Serial.print("No Object at Lamp Post 5");
  }

  // LAMP POST 6
  duration6 = pulseIn(ECHO6, HIGH);
  distance6 = duration6 * 0.034 / 2; // calibrate the distance using pulse
  Serial.print("Lamp Post 6 Object in cm: ");
  Serial.println(distance6); // Print the distance value
  if (distance6 < 30) {
    pinMode(LED5, HIGH);
    pinMode(LED6, HIGH);
    Serial.print("Object Detected at Lamp Post 6");
  }
  else if (distance5 > 30) {
    pinMode(LED5, LOW);
    pinMode(LED6, LOW);
    Serial.print("No Object at Lamp Post 5 & 6");
  }
  else {
    pinMode(LED6, LOW);
    Serial.print("No Object at Lamp Post 6");
  }

  delay(1000);
}
