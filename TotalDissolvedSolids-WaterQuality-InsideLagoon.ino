/* Water Quality measurement code 
 * Total Dissolved Solids, EC and Water temperature
                                                    */

#include "GravityTDS.h"
#include  
#include 

#define ONE_WIRE_BUS 12 // Digitalpin where Temp sensor is connected
#define TdsSensorPin A0 // Where Analog pin of TDS sensor is connected to arduino

OneWire oneWire(ONE_WIRE_BUS); 
GravityTDS gravityTds;

DallasTemperature sensors(&oneWire);

float tdsValue = 0;
float ecValue = 0;

void setup()
{
Serial.begin(115200);
sensors.begin();
gravityTds.setPin(TdsSensorPin);
gravityTds.setAref(5.0); //reference voltage on ADC, default 5.0V on Arduino UNO
gravityTds.setAdcRange(1024); //1024 for 10bit ADC;4096 for 12bit ADC
gravityTds.begin(); //initialization
}

void loop()
{
sensors.requestTemperatures();

gravityTds.setTemperature(sensors.getTempCByIndex(0)); // executes compensation from values acquired in sensors
gravityTds.update(); // calc provided by grav library
tdsValue = gravityTds.getTdsValue(); // gets tds value from prev. data
ecValue = (tdsValue * 2)/1000.0;

Serial.print("TDS value is:");
Serial.print(tdsValue,0);
Serial.println("ppm");
Serial.print("EC value is:");
Serial.println(ecValue);
Serial.print("Temperature is: "); 
Serial.println(sensors.getTempCByIndex(0));

delay(1500);

}
