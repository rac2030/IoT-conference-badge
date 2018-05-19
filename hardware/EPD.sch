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
Sheet 2 5
Title "IoT conference badge - mainboard"
Date ""
Rev "0.2.0"
Comp "MakeZürich (makezurich.ch) & GDG Zürich (gdgzh.ch)"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 2300 950  0    157  ~ 31
https://www.waveshare.com/wiki/2.13inch_e-Paper_HAT
Text HLabel 8300 3600 0    60   Input Italic 0
DIN
Text HLabel 8300 3400 0    60   Input Italic 0
CLK
Text HLabel 9100 3400 2    60   Input Italic 0
CS
Text HLabel 9100 3500 2    60   Input Italic 0
DC
Text HLabel 8300 4000 0    60   Input Italic 0
RST
Text HLabel 9100 3700 2    60   Output Italic 0
BUSY
Text HLabel 8300 2600 0    60   Output ~ 0
GND
Text HLabel 8300 4500 0    60   Input ~ 0
VCC
$Comp
L Conn_02x20_Top_Bottom J?
U 1 1 5AFF86AB
P 8650 3600
F 0 "J?" H 8700 4650 50  0000 C CNN
F 1 "Conn_02x40_Counter_Clockwise" H 8650 2400 50  0000 C CNN
F 2 "" H 8650 3600 50  0001 C CNN
F 3 "" H 8650 3600 50  0001 C CNN
	1    8650 3600
	1    0    0    1   
$EndComp
Wire Wire Line
	8300 4500 8450 4500
Wire Wire Line
	8300 2600 8450 2600
Wire Wire Line
	8300 4000 8450 4000
Wire Wire Line
	8300 3600 8450 3600
Wire Wire Line
	8300 3400 8450 3400
Wire Wire Line
	9100 3700 8950 3700
Wire Wire Line
	9100 3500 8950 3500
Wire Wire Line
	9100 3400 8950 3400
$EndSCHEMATC
