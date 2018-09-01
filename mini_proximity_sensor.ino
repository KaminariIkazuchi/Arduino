/* PERSONAL PROJECT, 26/08/2018
** Name: Proximity Sensor
** Creator: Warren HYPOLITE
** Device: Arduino MEGA 2560
** Components used: Mini Breadbord, 10 wires, 1 Green LED,
** 1 Yellow LED, 1 RED LED, Ultrasonic sensor, USB Type-A
** Description: Read the README
**/

const int green_led = 7;
const int yellow_led = 6;
const int red_led = 5;
const int trig = 52;
const int echo = 53;
float duration, distance;

void setup()
{
  pinMode(green_led, OUTPUT);
  pinMode(yellow_led, OUTPUT);
  pinMode(red_led, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void g_led(float distance)
{
    if (distance > 30) {
      digitalWrite(green_led, LOW);
      digitalWrite(yellow_led, LOW);
      digitalWrite(red_led, LOW);
      
  } else if (distance <= 30 && distance > 24) {
      digitalWrite(green_led, HIGH);
      digitalWrite(yellow_led, LOW);
      digitalWrite(red_led, LOW);
  } else if (distance <= 24 && distance > 20) {
      digitalWrite(green_led, HIGH);
      delay(80);
      digitalWrite(green_led, LOW);
      delay(80);
  }
}

void y_led(float distance)
{
    if (distance > 20) {
      digitalWrite(yellow_led, LOW);
      digitalWrite(red_led, LOW);
  } else if (distance <= 20 && distance > 14) {
      digitalWrite(green_led, LOW);
      digitalWrite(yellow_led, HIGH);
      digitalWrite(red_led, LOW);
  } else if (distance <= 14 && distance > 10) {
      digitalWrite(yellow_led, HIGH);
      delay(20);
      digitalWrite(yellow_led, LOW);
      delay(20);
  }
}

void r_led(float distance)
{
    if (distance > 10) {
      digitalWrite(red_led, LOW);
  } else if (distance <= 10 && distance > 4) {
      digitalWrite(green_led, LOW);
      digitalWrite(yellow_led, LOW);
      digitalWrite(red_led, HIGH);
  } else if (distance <= 4 && distance > 0) {
      digitalWrite(red_led, HIGH);
      delay(2);
      digitalWrite(red_led, LOW);
      delay(2);
  } else if (distance < 1)
      digitalWrite(red_led, LOW);
}

void led(float distance)
{
  g_led(distance);
  y_led(distance);
  r_led(distance);
}

int us_sensor()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration * 0.0340)/2;
  return(distance);
}

void loop()
{
  distance = us_sensor();
  led(distance);
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(500);
}
