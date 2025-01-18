#include "RTClib.h"
#include "DHT.h"

#define DHTPIN 8     
#define DHTTYPE DHT22 

DHT dht(DHTPIN, DHTTYPE);

#include <LiquidCrystal_I2C.h>
#define I2C_ADDR    0x27
#define LCD_COLUMNS 20
#define LCD_LINES   4


LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_LINES);
String data;
int relay1=3;
int relay2=4;
int relay3=5;
int relay4=6;
RTC_DS1307 rtc;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
void setup()
   { {
  Serial.begin(115200);
  Serial.println(F("DHT22 example!"));

  dht.begin();
    }
{
  Serial.begin(115200);
   lcd.init();
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("welcome to");
  lcd.setCursor(2,1);
  lcd.print("SMART FARMING");
  delay(4000);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  Serial.println("welcome to my project");
  delay(500);
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    abort();
  }
  lcd.clear();
  
}
   }
 

void loop () {
   {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Check if any reads failed and exit early (to try again).
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print(F("Humidity: "));
  Serial.print(humidity);
  Serial.print(F("%  Temperature: "));
  Serial.print(temperature);
  Serial.println(F("°C "));
  lcd.setCursor(0,3);
    lcd.print("temp:");
    lcd.println(temperature);
    lcd.setCursor(10,3);
    lcd.print("hum:");
    lcd.println(humidity);
  delay(2000);
}

  
  
  DateTime now = rtc.now();
  
  Serial.print("Current time: ");
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(" (");
  Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
  Serial.print(") ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();
  Serial.println();
  delay(3000);
  lcd.setCursor(3,0);
  lcd.print("Time:");
  lcd.print(now.hour(), DEC);
  lcd.print(':');
  lcd.print(now.minute(), DEC);
  lcd.print(':');
  lcd.print(now.second(), DEC);


  if((now.second()> 1) && (now.second()<15))
  {
  lcd.setCursor(0,1);
  lcd.print("Relay1:ON ");

   Serial.println("relay1 is on");
   digitalWrite(relay1, HIGH);
  }
  else{
    lcd.setCursor(0,1);
    lcd.print("Relay1:Off");
    digitalWrite(relay1,LOW);
  }
  
   if((now.second()> 20) && (now.second()<30))
  {
  lcd.setCursor(10,1);
  lcd.print("Relay2:ON ");
   Serial.println("relay2 is on");
   digitalWrite(relay2, HIGH);
  }
  else{
   lcd.setCursor(10,1);
  lcd.print("Relay2:OFF");
  digitalWrite(relay2,LOW);
  }
  if((now.second()> 35) && (now.second()<45))
  {
   lcd.setCursor(0,2);
  lcd.print("Relay3:ON ");
   Serial.println("relay3 is on");
   digitalWrite(relay3, HIGH);
  }
  else{
    lcd.setCursor(0,2);
  lcd.print("Relay3:OFF");
  digitalWrite(relay3,LOW);
  }
   if((now.second()> 50) && (now.second()<59))
  {
    lcd.setCursor(10,2);
  lcd.print("Relay4:ON ");
   Serial.println("relay4 is on");
   digitalWrite(relay4, HIGH);
  }
  else{
    lcd.setCursor(10,2);
  lcd.print("Relay4:OFF");
  digitalWrite(relay4,LOW);
  }
 
 
 
}