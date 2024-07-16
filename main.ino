#define trigPin 9
#define echoPin 10
#define led 3

long duration;
long distance;

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH); // bir pinin low ile high arasındaki süreyi hesaplar (ya da tam tersi)

  // Mesafeyi hesapla (Ses hızı = 343 m/s veya 0.0343 cm/mikrosaniye)
  distance = duration * 0.0343 / 2;

  int brightness = calculateBrightness(distance);

  if (brightness < 255)
  {
    analogWrite(led, brightness);
  }

  analogWrite(led, brightness);

  Serial.print("Mesafe: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(1000);
}

int calculateBrightness(float mesafe) {
  if (mesafe < 0) mesafe = 0;
  if (mesafe > 25) mesafe = 25;
  return max(0, min(255, -10.2 * mesafe + 255));
}
