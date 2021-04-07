/* STACJA METEO v1.1 (30.09.2020)
 *  
 *  Wykorzystane elementy:
 *  - Ekran LCD 2x16 + I2C 
 *  - Termo/higrometr SHT20 (I2C)
 *  - BAROMETR BMP280 (I2C) - z nieuzyta funkcja termometru
 *  
 *  Kabelki:
 *  - SDA fioletowy (A4)
 *  - SCL pomarańczowy (A5)
 *    
 *  Zasada działania:
 *  - Po uruchomieniu, od razu wykonuje pomiar temperatury, cisnienia i wilgotnosci. Wyswietla je.
 *  - Nastepnie wykonuje co 15s po 4 pomiary w/w wielkosci i usrednia wynik. Wyswietla.
 */

#include "LiquidCrystal_I2C.h"
#include "DFRobot_SHT20.h"
#include "Adafruit_BMP280.h"

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
DFRobot_SHT20 sht20;
Adafruit_BMP280 bmp;

float tempTemp;
float temp;
float tempHum;
float hum;
float tempPres;
float pres;

void setup() {  
  lcd.begin(16,2);
  lcd.clear();
  lcd.backlight();

  sht20.initSHT20();
  sht20.checkSHT20();

  bmp.begin();
  /* Default settings from datasheet. */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */

  // ZBADAĆ CZAS REAKCJI CZUJNIKÓW //

  measure();
  screen();
  delay (15000); // nie za długi?
}

void loop() {
  measureAvg();
  screen();

}

// funkcja mierzy jednorazowo temperature, wilgotnosc, cisnienie
void measure() {
  temp = sht20.readTemperature(); 
  hum = sht20.readHumidity();
  pres = bmp.readPressure()/100;
}

// funkcja mierzy 4-krotnie na przestrzeni 1 minuty temperature, wilgontosc i cisnienie; usrednia
void measureAvg() {
  tempTemp = 0.0;
  tempHum = 0.0;
  tempPres = 0.0;
  temp = 0.0;
  hum = 0.0;
  pres = 0.0;
  for (int i = 0; i < 4; i++) {
    tempTemp += sht20.readTemperature();
    tempHum += sht20.readHumidity();
    tempPres += bmp.readPressure()/100;
    delay(15000);
  }
  temp = tempTemp/4.0;
  hum = tempHum/4.0;
  pres = tempPres/4.0;
}

void screen() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(temp);
  lcd.print("*C");
  lcd.setCursor(8,0);
  lcd.print(hum);
  lcd.print("%RH");
  lcd.setCursor(0,1);
  lcd.print(pres);
  lcd.print(" hPa");
  lcd.setCursor(12,1);
  lcd.print("v1.1"); // wersja oprogramowania
}
