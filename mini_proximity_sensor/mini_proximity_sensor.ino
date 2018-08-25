/* PERSONAL PROJECT, 25/08/2018
** Name: Proximity Sensor
** Creator: Warren HYPOLITE
** Device: Arduino MEGA 2560
** Components used: Mini Breadbord, 6 wires, 1 Green LED (5V), 1 Resistence, Ultrasonic sensor, USB Type-A
** Description: Read the README
**/

const int led_green = 2;
const int trig = 52;
const int echo = 53;
float duration, distance;

void setup()
{
  pinMode(led_green, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void led(float distance)
{
  if (distance <= 10)
    digitalWrite(led_green, HIGH);
  else
    digitalWrite(led_green, LOW);
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
  Serial.print("cm");
  delay(500);
}
