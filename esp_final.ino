#include "DHT.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <SD.h>

#define DHTPIN 4
#define DHTTYPE DHT11
#define SD_CS 5

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

File dataFile;

void setup() {
  Serial.begin(115200);

  dht.begin();

  Wire.begin(21, 22);

  lcd.init();
  lcd.backlight();

  lcd.print("Initializing...");

  if (!SD.begin(SD_CS)) {
    lcd.setCursor(0,1);
    lcd.print("SD Fail");
    return;
  }

  lcd.clear();
  lcd.print("SD Ready");
  delay(2000);
  lcd.clear();

  // File header
  dataFile = SD.open("/data.txt", FILE_APPEND);
  if (dataFile) {
    dataFile.println("Time,Temp(C),Humidity(%)");
    dataFile.close();
  }
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    lcd.setCursor(0,0);
    lcd.print("Sensor Error");
    delay(2000);
    return;
  }

  // ⏱️ Convert millis to HH:MM:SS
  unsigned long totalSeconds = millis() / 1000;
  int hours = totalSeconds / 3600;
  int minutes = (totalSeconds % 3600) / 60;
  int seconds = totalSeconds % 60;

  char timeString[9];
  sprintf(timeString, "%02d:%02d:%02d", hours, minutes, seconds);

  // LCD display
  lcd.setCursor(0,0);
  
  lcd.print(temperature);
  lcd.print((char)223);
  lcd.print("C ");
  lcd.print(humidity);
  lcd.print((char)223);
  lcd.print("% ");
  

  lcd.setCursor(0,1);
  lcd.print(timeString);

  // Save to SD
  dataFile = SD.open("/data.txt", FILE_APPEND);
  if (dataFile) {
    dataFile.print(timeString);
    dataFile.print(",");
    dataFile.print(temperature);
    dataFile.print(",");
    dataFile.println(humidity);
    dataFile.close();
  }

  delay(2000); // ✅ every 2 seconds
}
