# Stacja środowiskowa na Arduino -  OPIS PROJEKTU

	Wersja projektu: v 1.1



2 czujniki dołączone do magistrali I2C, mierzą w sumie 3 parametry. Są one aktualizowane co ok. 15 sekund i wyświetlane na ekranie LCD, również dołączonym przez I2C.


// link do schematu elektrycznego //


## Zastosowane czujniki i niedokładności pomiarów:

- Temperatura: SHT20 // niedokladnosci
- Ciśnienie: BMP280 // niedokladnosci
- Wilgotność: SHT20 // niedokladnosci

Ekran: LCD 16x2 ze sterownikiem HD44780


## Programowanie za pomocą Arduino IDE:

- Wykorzystany programator w Arduino IDE: AVRISP mkII
- Procesor: Atmega 328P
- Płytka: Arduino Nano

## Wykorzystano zewnętrzne biblioteki: 
- NewLiquidCrystal: 
    https://bitbucket.org/fmalpartida/new-liquidcrystal;
    wersja z dnia: 04.08.2020 
- DFRobot_SHT20: 
    https://github.com/DFRobot/DFRobot_SHT20; 
    wersja z dnia: 30.09.2020 
- Adafruit_BMP280: 
    https://travis-ci.com/adafruit/Adafruit_BMP280_Library.svg?branch=master;
    wersja z dnia: 30.09.2020



## HISTORIA ZMIAN: 

#### v 1.1:
- Dodano mechanizm uśredniania pomiarów.
- Poprawione działanie pomiarów.
- Planowane rozszerzenia: 
	- Praca przerwaniowa
	- Włącznik ekranu (energooszczędność)
	- Szersze dane statystyczne (min, max, avg)

#### v 1.0:
- Pierwsza wersja programu.
- Planowane rozszerzenie o: uśrednianie pomiarów.
