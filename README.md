w5200-avr
=========

AVR library for Wiznet w5200 module


### Getting Started
Hooking up the WIZ820io module to your microcontroller is very straight forward. 

![alt tag](http://i.imgur.com/vQwbCDx.png)


The SPI connections will vary depending on which microcontroller/platform you use.

| Pin Function  | ATmega328p    | ATmega128   | Arduino UNO & Duemilanove |
|:---------------:|:---------------:|:------------:|:-----------------------------------:|
| CS    | PB2   | PB0  | Digital Pin 10     |
| MOSI  | PB3   | PB2  | Digital Pin 11     |
| MISO   | PB4   | PB3  | Digital Pin 12    |
| SCK   | PB5   | PB1  | Digital Pin 13     |

