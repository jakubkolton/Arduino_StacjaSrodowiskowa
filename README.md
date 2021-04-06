﻿Arduino - stacja środowiskowa mierząca temperaturę, ciśnienie, wilgotność powietrza - uśredniająca pomiary na ekranie LCD 16x2.

// OPIS PROJEKTU \ -- Wersja projektu: v 1.0 --

2 czujniki dołączone do magistrali I2C, mierzą w sumie 3 parametry. Są one aktualizowane co ok. 15 sekund i wyświetlane na ekranie LCD, również dołączonym przez I2C.

// link do schematu elektrycznego //

Zastosowane czujniki i niedokładności pomiarów:

Temperatura: SHT20
Ciśnienie: BMP280
Wilgotność: SHT20
Ekran: LCD 16x2 ze sterownikiem HD44780

PROGRAMOWANIE za pomocą Arduino IDE:

Wykorzystany programator w Arduino IDE: AVRISP mkII
Procesor: Atmega 328P
Płytka: Arduino Nano
Wykorzystano zewnętrzne biblioteki: NewLiquidCrystal https://bitbucket.org/fmalpartida/new-liquidcrystal wersja z dnia: 04.08.2020 DFRobot_SHT20 https://github.com/DFRobot/DFRobot_SHT20 wersja z dnia: 30.09.2020 Adafruit_BMP280 https://travis-ci.com/adafruit/Adafruit_BMP280_Library.svg?branch=master wersja z dnia: 30.09.2020
// HISTORIA ZMIAN \

*v 1.0:

Pierwsza wersja programu.
Planowane rozszerzenie o: uśrednianie pomiarów.