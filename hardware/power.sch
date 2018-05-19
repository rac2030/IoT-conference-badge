EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:switches
LIBS:relays
LIBS:motors
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:ublox_NINA-W102
LIBS:badgeComponents
LIBS:badge-mainboard-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 5
Title "IoT conference badge - mainboard"
Date ""
Rev "0.2.0"
Comp "MakeZürich (makezurich.ch) & GDG Zürich (gdgzh.ch)"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 9250 1650 2    60   Input Italic 0
VBUS_IN
Text HLabel 9250 1850 2    60   Output Italic 0
1.8_OUT
Text HLabel 9250 2050 2    60   Output Italic 0
3.3_OUT
$Comp
L Conn_01x02 J?
U 1 1 5AE92ED9
P 3300 3400
F 0 "J?" H 3300 3500 50  0000 C CNN
F 1 "Vin" H 3300 3200 50  0000 C CNN
F 2 "" H 3300 3400 50  0001 C CNN
F 3 "" H 3300 3400 50  0001 C CNN
	1    3300 3400
	1    0    0    -1  
$EndComp
Text Notes 800  700  0    60   ~ 0
Reverse current protection paper from TI: http://www.ti.com/lit/an/slva730/slva730.pdf\nFrom Maxim: https://www.maximintegrated.com/en/app-notes/index.mvp/id/636
$EndSCHEMATC
