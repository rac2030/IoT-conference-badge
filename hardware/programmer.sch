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
Sheet 3 6
Title "IoT conference badge - mainboard"
Date ""
Rev "0.2.0"
Comp "MakeZürich (makezurich.ch) & GDG Zürich (gdgzh.ch)"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 9300 2000 2    60   Output Italic 0
DTR
Text HLabel 9300 2150 2    60   Input Italic 0
RXD
Text HLabel 9300 2300 2    60   Output Italic 0
TXD
Text HLabel 9300 2450 2    60   Output Italic 0
CTS
Text Notes 1500 6100 0    157  ~ 31
TODO CP2102N circuit\nMaybe copy parts of\nhttps://github.com/watterott/CP2102N-Breakout/tree/master/hardware
$Comp
L CP2102N-A01-GQFN20 IC?
U 1 1 5AD3CA16
P 4800 3300
F 0 "IC?" H 6200 2550 50  0000 L CNN
F 1 "CP2102N-A01-GQFN20" H 5250 3450 50  0000 L CNN
F 2 "QFN50P300X300X80-21N-D" H 6450 4100 50  0001 L CNN
F 3 "https://componentsearchengine.com/Datasheets/2/CP2102N-A01-GQFN20.pdf" H 6450 4000 50  0001 L CNN
F 4 "SILICON LABS - CP2102N-A01-GQFN20 - USB-UART INTERFACE BRIDGE, QFN-20" H 6450 3900 50  0001 L CNN "Description"
F 5 "0.8" H 6450 3800 50  0001 L CNN "Height"
F 6 "Silicon Labs" H 6450 3700 50  0001 L CNN "Manufacturer_Name"
F 7 "CP2102N-A01-GQFN20" H 6450 3600 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "CP2102N-A01-GQFN20" H 6450 3300 50  0001 L CNN "Arrow Part Number"
F 9 "https://www.arrow.com/en/products/cp2102n-a01-gqfn20/silicon-labs" H 6450 3200 50  0001 L CNN "Arrow Price/Stock"
	1    4800 3300
	1    0    0    -1  
$EndComp
Text GLabel 5350 2100 1    60   Input Italic 0
TXD
Text GLabel 5500 2100 1    60   Output Italic 0
RXD
Wire Wire Line
	5500 2100 5500 2300
Wire Wire Line
	5350 2100 5350 2300
Wire Wire Line
	5350 2300 5400 2300
Text HLabel 9300 2600 2    60   Output Italic 0
VBUS_OUT
$EndSCHEMATC
