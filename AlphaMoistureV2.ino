const int dry=820;
const int wet=437;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  int sensorVal = analogRead(A0);

  int percentageHumidity = map(sensorVal, wet, dry, 100, 0);

  Serial.print(percentageHumidity);
  Serial.println("%");
  
  delay(500);
}

// PRE-ALPHA CODE TO GRAPHICALLY MEASURE SOIL MOISTURE IN %.
