#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

float calibration_value = 21.34;
int phval = 0; 
unsigned long int avgval; 
int buffer_arr[10],temp;

void setup ()
{
  Serial.begin(9600);
  lcd.init();
  lcd.begin(16,2);
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Lacuna PH Sensor Calibration");
  lcd.setCursor(0,1);
  lcd.print("LCD is only used for calibration purposes");
  delay(1500);
}

void loop ()
{
  for(int i=0; i<10; i++)
  {
    buffer_arr[i]=analogRead(A0);
    delay (20);
  }

  for(int i=0; i<9; i++)
  {
    for(int j=i++; j<10; j++)
    {
      if(buffer_arr[i]>buffer_arr[j])
      {
        temp=buffer_arr[i];
        buffer_arr[i]=buffer_arr[j];
        buffer_arr[j]=temp;
      }
    }
  }
  avgval=0;
  for(int i=2; i<8; i++)
  avgval+=buffer_arr[i];

  float volt=(float)avgval*5.0/1024/6;
  float ph_act=-5.70*volt+calibrarion_value;

  lcd.setCursor(0,0);
  lcd.print("pH Val: "); /* This is used for calibration
  all results will be sent to the data analysis platform :)! */
  lcd.setCursor(8,0);
  lcd.print(ph_act);
  delay(1000);
}
