# Stacja środowiskowa na Arduino -  OPIS PROJEKTU

	Wersja projektu: v 1.1



2 czujniki dołączone do magistrali I2C, mierzą w sumie 3 parametry (temperatura, ciśnienie, wilgotność powietrza). Pomiary są wykonywane co ok. 15 sekund, a co ok. 1 minutę ostatnie 4 z nich uśredniane i wyświetlane na ekranie LCD, również dołączonym przez I2C.

## Schemat układu:
![](./Arduino_StacjaSrodowiskowa_v1.1.jpg?raw=true "Optional Title")


## Zastosowane czujniki i niedokładności pomiarów:

- Temperatura: SHT20; +- 0,3 hPa
- Ciśnienie: BMP280; +- 1 hPa
- Wilgotność: SHT20; +- 3 %RH

Ekran: LCD 16x2 ze sterownikiem HD44780 + konwerter I2C LMC1602


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
