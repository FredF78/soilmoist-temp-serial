#include <SimpleTimer.h>
#include <dht11.h>

#define DHT11PIN 2
#define MOIST_IN 0

SimpleTimer timer;
dht11 DHT11;

void setup(void)
{
  Serial.begin(9600);
  sensors.begin();
  timer.setInterval(5000, measureAndSend);
}

void loop()
{
  timer.run();
}

void measureAndSend(void) 
{
  DHT11.read(DHT11PIN);
  int temp = DHT11.temperature;
  int humidity = DHT11.humidity;
  int moistLevel = analogRead(MOIST_IN);
  Serial.print(moistLevel);
  Serial.print(";");
  Serial.print(temp);
  Serial.print(";");
  Serial.print(humidity);
  Serial.print("\r\n");
}
