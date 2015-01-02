#include <SimpleTimer.h>
#include <OneWire.h>
#include <DallasTemperature.h>

const int MOIST_IN = 0;
#define ONE_WIRE_BUS 2;

SimpleTimer timer;
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

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
  sensors.requestTemperatures();
  int tempLevel = sensors.getTempCByIndex(0);
  int moistLevel = analogRead(MOIST_IN);
  Serial.print(moistLevel);
  Serial.print(";");
  Serial.print(tempLevel);
  Serial.print("\r\n");
}
