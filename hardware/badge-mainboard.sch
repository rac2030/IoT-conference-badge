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
Sheet 1 2
Title "IoT conference badge - mainboard"
Date "2018-05-26"
Rev "0.3.7"
Comp "MakeZürich (makezurich.ch) & GDG Zürich (gdgzh.ch)"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L WS2812b LED1
U 1 1 5AC27ED2
P 9600 4000
F 0 "LED1" H 10550 4300 50  0000 L CNN
F 1 "WS2812b" H 10550 4200 50  0000 L CNN
F 2 "LED:WS2812B" H 10550 4100 50  0001 L CNN
F 3 "http://www.adafruit.com/datasheets/WS2812B.pdf" H 10550 4000 50  0001 L CNN
F 4 "Intelligent control LED integrated light source, 4-pin SMD" H 10550 3900 50  0001 L CNN "Description"
F 5 "Adafruit" H 10550 3700 50  0001 L CNN "Manufacturer_Name"
F 6 "1655" H 10550 3600 50  0001 L CNN "Manufacturer_Part_Number"
F 7 "70928826" H 10550 3300 50  0001 L CNN "Allied_Number"
F 8 "http://www.alliedelec.com/adafruit-industries-1655/70928826/" H 10550 3200 50  0001 L CNN "Allied Price/Stock"
	1    9600 4000
	1    0    0    -1  
$EndComp
$Comp
L R_Small R5
U 1 1 5AC2AEF4
P 7800 700
F 0 "R5" H 7830 720 50  0000 L CNN
F 1 "4.7k" H 7830 660 50  0000 L CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" H 7800 700 50  0001 C CNN
F 3 "" H 7800 700 50  0001 C CNN
	1    7800 700 
	0    -1   -1   0   
$EndComp
NoConn ~ 9600 4700
$Comp
L GND #PWR01
U 1 1 5AC2E3CA
P 10800 4600
F 0 "#PWR01" H 10800 4350 50  0001 C CNN
F 1 "GND" H 10800 4450 50  0000 C CNN
F 2 "" H 10800 4600 50  0001 C CNN
F 3 "" H 10800 4600 50  0001 C CNN
	1    10800 4600
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR02
U 1 1 5AC2E56B
P 10800 4000
F 0 "#PWR02" H 10800 3750 50  0001 C CNN
F 1 "GND" H 10800 3850 50  0000 C CNN
F 2 "" H 10800 4000 50  0001 C CNN
F 3 "" H 10800 4000 50  0001 C CNN
	1    10800 4000
	0    -1   -1   0   
$EndComp
$Comp
L C_Small C8
U 1 1 5AC2E846
P 9350 4200
F 0 "C8" H 9360 4270 50  0000 L CNN
F 1 "100nF" H 9360 4120 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 9350 4200 50  0001 C CNN
F 3 "" H 9350 4200 50  0001 C CNN
	1    9350 4200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 5AC2EB3A
P 9350 4350
F 0 "#PWR03" H 9350 4100 50  0001 C CNN
F 1 "GND" H 9350 4200 50  0000 C CNN
F 2 "" H 9350 4350 50  0001 C CNN
F 3 "" H 9350 4350 50  0001 C CNN
	1    9350 4350
	1    0    0    -1  
$EndComp
$Comp
L C_Small C9
U 1 1 5AC2EDA7
P 9350 4850
F 0 "C9" H 9360 4920 50  0000 L CNN
F 1 "100nF" H 9360 4770 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 9350 4850 50  0001 C CNN
F 3 "" H 9350 4850 50  0001 C CNN
	1    9350 4850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 5AC2EDAD
P 9350 5100
F 0 "#PWR04" H 9350 4850 50  0001 C CNN
F 1 "GND" H 9350 4950 50  0000 C CNN
F 2 "" H 9350 5100 50  0001 C CNN
F 3 "" H 9350 5100 50  0001 C CNN
	1    9350 5100
	1    0    0    -1  
$EndComp
Text Notes 10750 3600 2    60   ~ 0
2 x RGBW LED Daisychain
Text Notes 8050 600  0    60   ~ 0
Random I2C ports, any GPIO works.
Text Notes 11000 2900 2    60   ~ 0
Random data port, can be changed if needed
$Comp
L C_Small C7
U 1 1 5ACAD80F
P 8950 4450
F 0 "C7" H 8960 4520 50  0000 L CNN
F 1 "47uF" H 8960 4370 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 8950 4450 50  0001 C CNN
F 3 "" H 8950 4450 50  0001 C CNN
	1    8950 4450
	1    0    0    -1  
$EndComp
Text Notes 3300 800  0    60   Italic 0
Pullup calculation info\nhttp://www.ti.com/lit/an/slva689/slva689.pdf
$Comp
L +3V3 #PWR05
U 1 1 5AD44887
P 4200 6900
F 0 "#PWR05" H 4200 6750 50  0001 C CNN
F 1 "+3V3" H 4200 7040 50  0000 C CNN
F 2 "" H 4200 6900 50  0001 C CNN
F 3 "" H 4200 6900 50  0001 C CNN
	1    4200 6900
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR06
U 1 1 5AD4A3AB
P 9800 700
F 0 "#PWR06" H 9800 550 50  0001 C CNN
F 1 "+3V3" H 9800 840 50  0000 C CNN
F 2 "" H 9800 700 50  0001 C CNN
F 3 "" H 9800 700 50  0001 C CNN
	1    9800 700 
	1    0    0    -1  
$EndComp
$Comp
L R_Small R6
U 1 1 5AD4A446
P 7800 1250
F 0 "R6" H 7830 1270 50  0000 L CNN
F 1 "4.7k" H 7830 1210 50  0000 L CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" H 7800 1250 50  0001 C CNN
F 3 "" H 7800 1250 50  0001 C CNN
	1    7800 1250
	0    1    1    0   
$EndComp
$Comp
L +3V3 #PWR07
U 1 1 5AD4B526
P 9250 3750
F 0 "#PWR07" H 9250 3600 50  0001 C CNN
F 1 "+3V3" H 9250 3890 50  0000 C CNN
F 2 "" H 9250 3750 50  0001 C CNN
F 3 "" H 9250 3750 50  0001 C CNN
	1    9250 3750
	1    0    0    -1  
$EndComp
$Sheet
S 4800 1750 1300 1500
U 5AE244D0
F0 "NINA-W102-module" 60
F1 "NINA-W102-module.sch" 60
F2 "GPIO_28" B L 4800 1850 60 
F3 "GPIO_29" B L 4800 1950 60 
F4 "GPIO_32" B L 4800 2050 60 
F5 "GND" O L 4800 2150 60 
F6 "GPIO_31" B L 4800 2250 60 
F7 "GPIO_1" B L 4800 2350 60 
F8 "GPI_2" I L 4800 2450 60 
F9 "GPI_3" I L 4800 2550 60 
F10 "GPI_4" I L 4800 2650 60 
F11 "GPIO_5" B L 4800 2750 60 
F12 "GPIO_7" B L 4800 2850 60 
F13 "GPIO_8" B L 4800 2950 60 
F14 "VCC" I L 4800 3050 60 
F15 "GPI_34" I R 6100 1850 60 
F16 "GPIO_27" B R 6100 1950 60 
F17 "GPIO_35" B R 6100 2050 60 
F18 "GPIO_36" B R 6100 2150 60 
F19 "GPIO_25" B R 6100 2250 60 
F20 "GPIO_24" B R 6100 2350 60 
F21 "GPIO_23" B R 6100 2450 60 
F22 "GPIO_22" B R 6100 2550 60 
F23 "GPIO_21" B R 6100 2650 60 
F24 "GPIO_20" B R 6100 2750 60 
F25 "RESET_N" I R 6100 2850 60 
F26 "GPIO_18" B R 6100 2950 60 
F27 "GPIO_17" B R 6100 3050 60 
F28 "GPIO_16" B R 6100 3150 60 
$EndSheet
$Comp
L +3V3 #PWR08
U 1 1 5AE6FF03
P 4550 3300
F 0 "#PWR08" H 4550 3150 50  0001 C CNN
F 1 "+3V3" H 4550 3440 50  0000 C CNN
F 2 "" H 4550 3300 50  0001 C CNN
F 3 "" H 4550 3300 50  0001 C CNN
	1    4550 3300
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR09
U 1 1 5AE70C46
P 4350 2150
F 0 "#PWR09" H 4350 1900 50  0001 C CNN
F 1 "GND" H 4350 2000 50  0000 C CNN
F 2 "" H 4350 2150 50  0001 C CNN
F 3 "" H 4350 2150 50  0001 C CNN
	1    4350 2150
	1    0    0    -1  
$EndComp
$Comp
L I2C_HEADER J4
U 1 1 5AE74CFE
P 9250 2050
F 0 "J4" H 9250 2250 50  0000 C CNN
F 1 "I2C_HEADER" H 9250 1750 50  0000 C CNN
F 2 "badgeComponents:I2C_HEADER_1X04_LOCK_LONGPADS" H 9250 2050 50  0001 C CNN
F 3 "" H 9250 2050 50  0001 C CNN
F 4 "Leave unpopulated" H 9250 2050 60  0001 C CNN "Description"
	1    9250 2050
	1    0    0    -1  
$EndComp
$Comp
L I2C_HEADER J5
U 1 1 5AE74E55
P 9800 2050
F 0 "J5" H 9800 2250 50  0000 C CNN
F 1 "I2C_HEADER" H 9800 1750 50  0000 C CNN
F 2 "badgeComponents:I2C_HEADER_1X04_LOCK_LONGPADS" H 9800 2050 50  0001 C CNN
F 3 "" H 9800 2050 50  0001 C CNN
F 4 "Leave unpopulated" H 9800 2050 60  0001 C CNN "Description"
	1    9800 2050
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR010
U 1 1 5AE75A47
P 8800 1500
F 0 "#PWR010" H 8800 1350 50  0001 C CNN
F 1 "+3V3" H 8800 1640 50  0000 C CNN
F 2 "" H 8800 1500 50  0001 C CNN
F 3 "" H 8800 1500 50  0001 C CNN
	1    8800 1500
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR011
U 1 1 5AE75B75
P 8500 1900
F 0 "#PWR011" H 8500 1650 50  0001 C CNN
F 1 "GND" H 8500 1750 50  0000 C CNN
F 2 "" H 8500 1900 50  0001 C CNN
F 3 "" H 8500 1900 50  0001 C CNN
	1    8500 1900
	1    0    0    -1  
$EndComp
Text Notes 10100 1450 2    60   ~ 0
I2C Breakouts for users
$Comp
L R_Small R7
U 1 1 5AE91D89
P 7800 1800
F 0 "R7" H 7830 1820 50  0000 L CNN
F 1 "4.7k" H 7830 1760 50  0000 L CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" H 7800 1800 50  0001 C CNN
F 3 "" H 7800 1800 50  0001 C CNN
F 4 "User pullups, leave unpopulated" H 7800 1800 60  0001 C CNN "Description"
	1    7800 1800
	-1   0    0    1   
$EndComp
$Comp
L R_Small R8
U 1 1 5AE91F41
P 8150 1800
F 0 "R8" H 8180 1820 50  0000 L CNN
F 1 "4.7k" H 8180 1760 50  0000 L CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" H 8150 1800 50  0001 C CNN
F 3 "" H 8150 1800 50  0001 C CNN
F 4 "User pullups, leave unpopulated" H 8150 1800 60  0001 C CNN "Description"
	1    8150 1800
	-1   0    0    1   
$EndComp
Text Notes 7250 2400 0    60   ~ 0
User pullups to be left unpopulated
$Comp
L sensor-module-board U2
U 1 1 5AFCE10D
P 8650 900
F 0 "U2" H 8650 900 60  0000 C CNN
F 1 "sensor-module-board" H 8650 750 60  0000 C CNN
F 2 "badgeComponents:Sensors_module_board" H 8650 900 60  0001 C CNN
F 3 "" H 8650 900 60  0001 C CNN
	1    8650 900 
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR012
U 1 1 5AFCEBB7
P 9600 1000
F 0 "#PWR012" H 9600 750 50  0001 C CNN
F 1 "GND" H 9600 850 50  0000 C CNN
F 2 "" H 9600 1000 50  0001 C CNN
F 3 "" H 9600 1000 50  0001 C CNN
	1    9600 1000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR013
U 1 1 5B01D538
P 4750 6000
F 0 "#PWR013" H 4750 5750 50  0001 C CNN
F 1 "GND" H 4750 5850 50  0000 C CNN
F 2 "" H 4750 6000 50  0001 C CNN
F 3 "" H 4750 6000 50  0001 C CNN
	1    4750 6000
	1    0    0    -1  
$EndComp
Text Notes 10950 5250 2    60   ~ 0
120mA max. (60mA / LED)
Text Notes 7550 5150 2    60   ~ 0
Assume 20mA to 30mA max.
Text Notes 6250 3450 2    60   ~ 0
500mA max. power consumption
$Comp
L LM1117-3.3 U1
U 1 1 5B02845A
P 3450 6900
F 0 "U1" H 3300 7025 50  0000 C CNN
F 1 "LM1117-3.3" H 3450 7025 50  0000 L CNN
F 2 "badgeComponents:LM1117_SOT-223" H 3450 6900 50  0001 C CNN
F 3 "" H 3450 6900 50  0001 C CNN
	1    3450 6900
	1    0    0    -1  
$EndComp
$Comp
L C_Small C4
U 1 1 5B028A3F
P 2700 7150
F 0 "C4" H 2710 7220 50  0000 L CNN
F 1 "10uF (Tantalum)" H 2710 7070 50  0000 L CNN
F 2 "Capacitors_Tantalum_SMD:CP_Tantalum_Case-C_EIA-6032-28_Hand" H 2700 7150 50  0001 C CNN
F 3 "" H 2700 7150 50  0001 C CNN
F 4 "Tantalum" H 2700 7150 60  0001 C CNN "Description"
	1    2700 7150
	1    0    0    -1  
$EndComp
$Comp
L C_Small C6
U 1 1 5B029060
P 3850 7150
F 0 "C6" H 3860 7220 50  0000 L CNN
F 1 "100uF (Tantalum, ESR: 0.3 - 22 Ohm)" H 3860 7070 50  0000 L CNN
F 2 "Capacitors_Tantalum_SMD:CP_Tantalum_Case-C_EIA-6032-28_Hand" H 3850 7150 50  0001 C CNN
F 3 "" H 3850 7150 50  0001 C CNN
F 4 "Tantalum with ESR between 0.3 Ohm and 22 Ohm" H 3850 7150 60  0001 C CNN "Description"
	1    3850 7150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR014
U 1 1 5B029570
P 3450 7450
F 0 "#PWR014" H 3450 7200 50  0001 C CNN
F 1 "GND" H 3450 7300 50  0000 C CNN
F 2 "" H 3450 7450 50  0001 C CNN
F 3 "" H 3450 7450 50  0001 C CNN
	1    3450 7450
	1    0    0    -1  
$EndComp
$Comp
L Battery BT1
U 1 1 5B02C983
P 1050 7150
F 0 "BT1" H 1150 7250 50  0000 L CNN
F 1 "Battery 3x1.5V AAA" H 950 6800 50  0000 L CNN
F 2 "Battery_Holders:Keystone_2479_3xAAA" V 1050 7210 50  0001 C CNN
F 3 "" V 1050 7210 50  0001 C CNN
	1    1050 7150
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x02 J1
U 1 1 5B02CAFA
P 1500 7000
F 0 "J1" H 1500 7100 50  0000 C CNN
F 1 "Vin" V 1600 6950 50  0000 C CNN
F 2 "badgeComponents:VIN_1X02_LOCK_LONGPADS" H 1500 7000 50  0001 C CNN
F 3 "" H 1500 7000 50  0001 C CNN
	1    1500 7000
	-1   0    0    1   
$EndComp
Text Notes 1250 6550 2    60   ~ 0
Power circuit
$Comp
L WS2812b LED2
U 1 1 5AC2C4FB
P 9600 4600
F 0 "LED2" H 10550 4900 50  0000 L CNN
F 1 "WS2812b" H 10550 4800 50  0000 L CNN
F 2 "LED:WS2812B" H 10550 4700 50  0001 L CNN
F 3 "http://www.adafruit.com/datasheets/WS2812B.pdf" H 10550 4600 50  0001 L CNN
F 4 "Intelligent control LED integrated light source, 4-pin SMD" H 10550 4500 50  0001 L CNN "Description"
F 5 "Adafruit" H 10550 4300 50  0001 L CNN "Manufacturer_Name"
F 6 "1655" H 10550 4200 50  0001 L CNN "Manufacturer_Part_Number"
F 7 "70928826" H 10550 3900 50  0001 L CNN "Allied_Number"
F 8 "http://www.alliedelec.com/adafruit-industries-1655/70928826/" H 10550 3800 50  0001 L CNN "Allied Price/Stock"
	1    9600 4600
	1    0    0    -1  
$EndComp
Text Notes 8650 6100 2    60   ~ 0
https://www.waveshare.com/wiki/2.13inch_e-Paper_HAT
Text Notes 6100 5950 0    60   ~ 0
DIN => GPIO1 => ESP32: 23 => Arduino: MOSI\nCLK => GPIO29 => ESP32: 18 => Arduino: SCK\nCS => GPIO28 => ESP32: 5 => Arduino: SS\nDC => GPIO20 => ESP32: 22 => Arduino: D6\nRST => GPIO8 => ESP32: 21 => Arduino: D18\nBUSY => GPIO24 => ESP32: 4 => Arduino: A10
$Comp
L Rpi_02x20_WaveShareEPD J3
U 1 1 5B03DD3A
P 5350 4850
F 0 "J3" H 5400 5850 50  0000 C CNN
F 1 "Rpi_02x20_WaveShareEPD" H 5400 3750 50  0000 C CNN
F 2 "badgeComponents:Rpi_WaveShare_EPD_2X20_NOSILK" H 5350 4850 50  0001 C CNN
F 3 "" H 5350 4850 50  0001 C CNN
	1    5350 4850
	1    0    0    -1  
$EndComp
Text Notes 8600 3850 2    60   ~ 0
EPD connector
$Comp
L SW_Push SW2
U 1 1 5B045196
P 1600 1600
F 0 "SW2" H 1650 1700 50  0000 L CNN
F 1 "User Button 1" H 1600 1540 50  0000 C CNN
F 2 "badgeComponents:2-PIN-TACTILE_SWITCH_SMD_6.0X6.0MM" H 1600 1800 50  0001 C CNN
F 3 "" H 1600 1800 50  0001 C CNN
	1    1600 1600
	0    -1   -1   0   
$EndComp
$Comp
L C_Small C2
U 1 1 5B04519D
P 1800 1600
F 0 "C2" H 1810 1670 50  0000 L CNN
F 1 "1uF" H 1810 1520 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 1800 1600 50  0001 C CNN
F 3 "" H 1800 1600 50  0001 C CNN
	1    1800 1600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR015
U 1 1 5B0451A4
P 1700 1950
F 0 "#PWR015" H 1700 1700 50  0001 C CNN
F 1 "GND" H 1700 1800 50  0000 C CNN
F 2 "" H 1700 1950 50  0001 C CNN
F 3 "" H 1700 1950 50  0001 C CNN
	1    1700 1950
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR016
U 1 1 5B0451AA
P 1700 750
F 0 "#PWR016" H 1700 600 50  0001 C CNN
F 1 "+3V3" H 1700 890 50  0000 C CNN
F 2 "" H 1700 750 50  0001 C CNN
F 3 "" H 1700 750 50  0001 C CNN
	1    1700 750 
	1    0    0    -1  
$EndComp
$Comp
L R_Small R2
U 1 1 5B0451B0
P 1700 950
F 0 "R2" H 1730 970 50  0000 L CNN
F 1 "10k" H 1730 910 50  0000 L CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" H 1700 950 50  0001 C CNN
F 3 "" H 1700 950 50  0001 C CNN
	1    1700 950 
	1    0    0    -1  
$EndComp
$Comp
L SW_Push SW1
U 1 1 5B0451C5
P 1300 3850
F 0 "SW1" H 1350 3950 50  0000 L CNN
F 1 "User Button 2" H 1300 3790 50  0000 C CNN
F 2 "badgeComponents:2-PIN-TACTILE_SWITCH_SMD_6.0X6.0MM" H 1300 4050 50  0001 C CNN
F 3 "" H 1300 4050 50  0001 C CNN
	1    1300 3850
	0    -1   -1   0   
$EndComp
$Comp
L C_Small C1
U 1 1 5B0451CC
P 1500 3850
F 0 "C1" H 1510 3920 50  0000 L CNN
F 1 "1uF" H 1510 3770 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 1500 3850 50  0001 C CNN
F 3 "" H 1500 3850 50  0001 C CNN
	1    1500 3850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR017
U 1 1 5B0451D3
P 1400 4200
F 0 "#PWR017" H 1400 3950 50  0001 C CNN
F 1 "GND" H 1400 4050 50  0000 C CNN
F 2 "" H 1400 4200 50  0001 C CNN
F 3 "" H 1400 4200 50  0001 C CNN
	1    1400 4200
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR018
U 1 1 5B0451D9
P 1400 3000
F 0 "#PWR018" H 1400 2850 50  0001 C CNN
F 1 "+3V3" H 1400 3140 50  0000 C CNN
F 2 "" H 1400 3000 50  0001 C CNN
F 3 "" H 1400 3000 50  0001 C CNN
	1    1400 3000
	1    0    0    -1  
$EndComp
$Comp
L R_Small R1
U 1 1 5B0451DF
P 1400 3200
F 0 "R1" H 1430 3220 50  0000 L CNN
F 1 "10k" H 1430 3160 50  0000 L CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" H 1400 3200 50  0001 C CNN
F 3 "" H 1400 3200 50  0001 C CNN
	1    1400 3200
	1    0    0    -1  
$EndComp
$Comp
L SW_Push SW3
U 1 1 5B0451F4
P 2300 3850
F 0 "SW3" H 2350 3950 50  0000 L CNN
F 1 "User Button 3" H 2300 3790 50  0000 C CNN
F 2 "badgeComponents:2-PIN-TACTILE_SWITCH_SMD_6.0X6.0MM" H 2300 4050 50  0001 C CNN
F 3 "" H 2300 4050 50  0001 C CNN
	1    2300 3850
	0    -1   -1   0   
$EndComp
$Comp
L C_Small C3
U 1 1 5B0451FB
P 2500 3850
F 0 "C3" H 2510 3920 50  0000 L CNN
F 1 "1uF" H 2510 3770 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 2500 3850 50  0001 C CNN
F 3 "" H 2500 3850 50  0001 C CNN
	1    2500 3850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR019
U 1 1 5B045202
P 2400 4200
F 0 "#PWR019" H 2400 3950 50  0001 C CNN
F 1 "GND" H 2400 4050 50  0000 C CNN
F 2 "" H 2400 4200 50  0001 C CNN
F 3 "" H 2400 4200 50  0001 C CNN
	1    2400 4200
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR020
U 1 1 5B045208
P 2400 3000
F 0 "#PWR020" H 2400 2850 50  0001 C CNN
F 1 "+3V3" H 2400 3140 50  0000 C CNN
F 2 "" H 2400 3000 50  0001 C CNN
F 3 "" H 2400 3000 50  0001 C CNN
	1    2400 3000
	1    0    0    -1  
$EndComp
$Comp
L R_Small R3
U 1 1 5B04520E
P 2400 3200
F 0 "R3" H 2430 3220 50  0000 L CNN
F 1 "10k" H 2430 3160 50  0000 L CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" H 2400 3200 50  0001 C CNN
F 3 "" H 2400 3200 50  0001 C CNN
	1    2400 3200
	1    0    0    -1  
$EndComp
$Comp
L SW_Push SW4
U 1 1 5B045223
P 3350 3850
F 0 "SW4" H 3400 3950 50  0000 L CNN
F 1 "User Button 4" H 3350 3790 50  0000 C CNN
F 2 "badgeComponents:2-PIN-TACTILE_SWITCH_SMD_6.0X6.0MM" H 3350 4050 50  0001 C CNN
F 3 "" H 3350 4050 50  0001 C CNN
	1    3350 3850
	0    -1   -1   0   
$EndComp
$Comp
L C_Small C5
U 1 1 5B04522A
P 3550 3850
F 0 "C5" H 3560 3920 50  0000 L CNN
F 1 "1uF" H 3560 3770 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 3550 3850 50  0001 C CNN
F 3 "" H 3550 3850 50  0001 C CNN
	1    3550 3850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR021
U 1 1 5B045231
P 3450 4200
F 0 "#PWR021" H 3450 3950 50  0001 C CNN
F 1 "GND" H 3450 4050 50  0000 C CNN
F 2 "" H 3450 4200 50  0001 C CNN
F 3 "" H 3450 4200 50  0001 C CNN
	1    3450 4200
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR022
U 1 1 5B045237
P 3450 3000
F 0 "#PWR022" H 3450 2850 50  0001 C CNN
F 1 "+3V3" H 3450 3140 50  0000 C CNN
F 2 "" H 3450 3000 50  0001 C CNN
F 3 "" H 3450 3000 50  0001 C CNN
	1    3450 3000
	1    0    0    -1  
$EndComp
$Comp
L R_Small R4
U 1 1 5B04523D
P 3450 3200
F 0 "R4" H 3480 3220 50  0000 L CNN
F 1 "10k" H 3480 3160 50  0000 L CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" H 3450 3200 50  0001 C CNN
F 3 "" H 3450 3200 50  0001 C CNN
	1    3450 3200
	1    0    0    -1  
$EndComp
$Comp
L +BATT #PWR023
U 1 1 5B061B9C
P 800 6800
F 0 "#PWR023" H 800 6650 50  0001 C CNN
F 1 "+BATT" H 800 6940 50  0000 C CNN
F 2 "" H 800 6800 50  0001 C CNN
F 3 "" H 800 6800 50  0001 C CNN
	1    800  6800
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG024
U 1 1 5B0633B4
P 2200 6850
F 0 "#FLG024" H 2200 6925 50  0001 C CNN
F 1 "PWR_FLAG" H 2200 7000 50  0000 C CNN
F 2 "" H 2200 6850 50  0001 C CNN
F 3 "" H 2200 6850 50  0001 C CNN
	1    2200 6850
	1    0    0    -1  
$EndComp
Text Notes 3850 1000 2    60   ~ 0
User interactions
$Comp
L R_Small R9
U 1 1 5B00DCEE
P 4900 1200
F 0 "R9" H 4930 1220 50  0000 L CNN
F 1 "100k" H 4930 1160 50  0000 L CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" H 4900 1200 50  0001 C CNN
F 3 "" H 4900 1200 50  0001 C CNN
	1    4900 1200
	0    1    1    0   
$EndComp
$Comp
L R_Small R10
U 1 1 5B00DF64
P 5500 1200
F 0 "R10" H 5530 1220 50  0000 L CNN
F 1 "470k" H 5500 1100 50  0000 L CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" H 5500 1200 50  0001 C CNN
F 3 "" H 5500 1200 50  0001 C CNN
	1    5500 1200
	0    1    1    0   
$EndComp
Text Label 1050 6700 0    60   ~ 0
+BATT
Text Label 1050 7350 0    60   ~ 0
-BATT
Text Label 5700 1200 0    60   ~ 0
+BATT
Text Label 4700 1200 2    60   ~ 0
-BATT
Text Notes 4400 1050 0    60   ~ 0
Voltage divider for battery measurement
$Comp
L JUMPER-SMT_2_NC JP1
U 1 1 5B0140EF
P 5800 1400
F 0 "JP1" H 5700 1500 45  0000 L BNN
F 1 "JUMPER-disable-batt-measurement" H 5000 1250 45  0000 L BNN
F 2 "badgeComponents:SMT-JUMPER_2_NC_TRACE_SILK" H 5800 1600 20  0001 C CNN
F 3 "" H 5800 1400 60  0001 C CNN
	1    5800 1400
	1    0    0    -1  
$EndComp
$Comp
L D_Zener_Small D1
U 1 1 5B0199E5
P 4700 1450
F 0 "D1" H 4700 1350 50  0000 C CNN
F 1 "D_Zener_3v3" H 4700 1550 50  0000 C CNN
F 2 "Diodes_SMD:D_SOD-123" V 4700 1450 50  0001 C CNN
F 3 "" V 4700 1450 50  0001 C CNN
	1    4700 1450
	-1   0    0    1   
$EndComp
Text Notes 2500 5700 0    60   ~ 0
VCC is the upper right pin (towards inside the module)\nthe connector is at the bottom of the display\nthe cable is at the right side
$Comp
L D_Schottky D2
U 1 1 5B07EAD9
P 1550 6700
F 0 "D2" H 1550 6800 50  0000 C CNN
F 1 "D" H 1550 6600 50  0000 C CNN
F 2 "Diodes_SMD:D_1206" H 1550 6700 50  0001 C CNN
F 3 "" H 1550 6700 50  0001 C CNN
	1    1550 6700
	-1   0    0    1   
$EndComp
$Comp
L PWR_FLAG #FLG025
U 1 1 5B0805F9
P -1550 6700
F 0 "#FLG025" H -1550 6775 50  0001 C CNN
F 1 "PWR_FLAG" H -1550 6850 50  0000 C CNN
F 2 "" H -1550 6700 50  0001 C CNN
F 3 "" H -1550 6700 50  0001 C CNN
	1    -1550 6700
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9600 4100 9600 4450
Wire Wire Line
	9600 4450 11000 4450
Wire Wire Line
	11000 4450 11000 4700
Wire Wire Line
	11000 4700 10700 4700
Wire Wire Line
	10800 4000 10700 4000
Wire Wire Line
	9250 4000 9600 4000
Wire Wire Line
	9250 4600 9600 4600
Connection ~ 9250 4000
Wire Wire Line
	9350 4300 9350 4350
Wire Wire Line
	9350 4100 9350 4000
Connection ~ 9350 4000
Connection ~ 9350 4600
Wire Wire Line
	11100 4100 10700 4100
Wire Notes Line
	8800 3500 11150 3500
Wire Notes Line
	11150 3500 11150 5750
Wire Notes Line
	11150 5750 8800 5750
Wire Wire Line
	8950 3850 9250 3850
Connection ~ 9250 3850
Wire Notes Line
	8800 5750 8800 3500
Wire Wire Line
	6100 2950 11100 2950
Wire Wire Line
	11100 2950 11100 4100
Wire Wire Line
	4800 3050 4700 3050
Wire Wire Line
	4700 3050 4700 3350
Wire Wire Line
	4700 3350 4550 3350
Wire Wire Line
	4550 3300 4550 3950
Wire Wire Line
	6100 2150 9600 2150
Connection ~ 9050 2250
Connection ~ 9050 2150
Wire Wire Line
	8800 1950 9600 1950
Wire Wire Line
	8800 1500 8800 1950
Wire Wire Line
	8650 2050 9600 2050
Wire Wire Line
	8650 2050 8650 1800
Wire Wire Line
	8650 1800 8500 1800
Wire Wire Line
	8500 1800 8500 1900
Connection ~ 9050 2050
Connection ~ 9050 1950
Wire Notes Line
	10150 1300 10150 2450
Wire Notes Line
	10150 2450 8950 2450
Wire Wire Line
	1700 2450 4800 2450
Wire Wire Line
	2700 2550 4800 2550
Wire Wire Line
	7800 1900 7800 2150
Connection ~ 7800 2150
Wire Wire Line
	8150 1900 8150 2250
Connection ~ 8150 2250
Wire Wire Line
	8150 1700 8150 1600
Wire Wire Line
	7800 1600 8800 1600
Connection ~ 8800 1600
Wire Wire Line
	7800 1700 7800 1600
Connection ~ 8150 1600
Wire Wire Line
	9400 950  9600 950 
Wire Wire Line
	9600 950  9600 1000
Wire Wire Line
	9800 850  9800 700 
Wire Wire Line
	9400 850  9800 850 
Wire Wire Line
	6400 850  7900 850 
Wire Wire Line
	6600 950  7900 950 
Wire Wire Line
	7700 700  7550 700 
Wire Wire Line
	7550 700  7550 850 
Connection ~ 7550 850 
Wire Wire Line
	7900 700  9550 700 
Wire Wire Line
	9550 700  9550 850 
Connection ~ 9550 850 
Wire Wire Line
	7700 1250 7550 1250
Wire Wire Line
	7550 1250 7550 950 
Connection ~ 7550 950 
Wire Wire Line
	7900 1250 9750 1250
Wire Wire Line
	9750 1250 9750 850 
Connection ~ 9750 850 
Wire Wire Line
	3450 7200 3450 7450
Wire Wire Line
	3750 6900 4200 6900
Wire Wire Line
	3850 7050 3850 6900
Connection ~ 3850 6900
Wire Wire Line
	2250 7400 3850 7400
Connection ~ 3450 7400
Wire Wire Line
	3850 7400 3850 7250
Wire Wire Line
	2700 6900 2700 7050
Connection ~ 2700 6900
Wire Wire Line
	1700 7000 2250 7000
Wire Wire Line
	2250 7000 2250 7400
Wire Wire Line
	1050 6700 1050 6950
Wire Wire Line
	1050 7350 1750 7350
Wire Wire Line
	1750 7350 1750 7000
Connection ~ 1750 7000
Wire Wire Line
	1700 6900 3150 6900
Wire Wire Line
	1750 6700 1750 6900
Connection ~ 1750 6900
Wire Notes Line
	600  6450 600  7700
Wire Notes Line
	600  7700 4600 7700
Wire Notes Line
	4600 7700 4600 6450
Wire Notes Line
	4600 6450 600  6450
Wire Wire Line
	8950 5050 9350 5050
Wire Wire Line
	9250 3750 9250 4600
Wire Wire Line
	9350 4950 9350 5100
Connection ~ 9350 5050
Wire Wire Line
	9350 4750 9350 4600
Wire Wire Line
	6100 2750 6900 2750
Wire Wire Line
	6100 2250 9600 2250
Wire Wire Line
	1050 2350 4800 2350
Wire Wire Line
	5650 4750 6700 4750
Wire Wire Line
	6700 4750 6700 2350
Wire Wire Line
	6700 2350 6100 2350
Wire Wire Line
	5650 4950 6900 4950
Wire Wire Line
	6900 4950 6900 2750
Wire Wire Line
	5650 5050 6000 5050
Wire Wire Line
	6000 5050 6000 6200
Wire Wire Line
	6000 6200 650  6200
Wire Wire Line
	3250 1850 4800 1850
Wire Wire Line
	5150 5050 850  5050
Wire Wire Line
	1050 4850 5150 4850
Wire Wire Line
	5150 4450 4350 4450
Wire Wire Line
	4350 4450 4350 2950
Wire Wire Line
	4350 2950 4800 2950
Wire Wire Line
	4550 3950 5150 3950
Connection ~ 4550 3350
Wire Wire Line
	5150 5850 4750 5850
Wire Wire Line
	4750 5850 4750 6000
Wire Notes Line
	4100 6350 8700 6350
Wire Notes Line
	8700 6350 8700 3750
Wire Notes Line
	8700 3750 4100 3750
Wire Wire Line
	1700 850  1700 750 
Wire Wire Line
	1800 1900 1800 1700
Wire Wire Line
	1600 1900 1800 1900
Wire Wire Line
	1700 1900 1700 1950
Wire Wire Line
	1600 1800 1600 1900
Connection ~ 1700 1900
Wire Wire Line
	1600 1400 1600 1250
Wire Wire Line
	1600 1250 1800 1250
Wire Wire Line
	1700 1050 1700 1250
Wire Wire Line
	1800 1250 1800 1500
Connection ~ 1700 1250
Connection ~ 1700 1150
Wire Wire Line
	1400 3100 1400 3000
Wire Wire Line
	1500 4150 1500 3950
Wire Wire Line
	1300 4150 1500 4150
Wire Wire Line
	1300 4050 1300 4150
Wire Wire Line
	1300 3650 1300 3500
Wire Wire Line
	1300 3500 1500 3500
Wire Wire Line
	1400 3300 1400 3500
Wire Wire Line
	1500 3500 1500 3750
Connection ~ 1400 3500
Wire Wire Line
	1700 3400 1400 3400
Connection ~ 1400 3400
Wire Wire Line
	2400 3100 2400 3000
Wire Wire Line
	2500 4150 2500 3950
Wire Wire Line
	2300 4150 2500 4150
Wire Wire Line
	2300 4050 2300 4150
Connection ~ 2400 4150
Wire Wire Line
	2300 3650 2300 3500
Wire Wire Line
	2300 3500 2500 3500
Wire Wire Line
	2400 3300 2400 3500
Wire Wire Line
	2500 3500 2500 3750
Connection ~ 2400 3500
Wire Wire Line
	2700 3400 2400 3400
Connection ~ 2400 3400
Wire Wire Line
	3450 3100 3450 3000
Wire Wire Line
	3550 4150 3550 3950
Wire Wire Line
	3350 4150 3550 4150
Wire Wire Line
	3450 4150 3450 4200
Wire Wire Line
	3350 4050 3350 4150
Connection ~ 3450 4150
Wire Wire Line
	3350 3650 3350 3500
Wire Wire Line
	3350 3500 3550 3500
Wire Wire Line
	3450 3300 3450 3500
Wire Wire Line
	3550 3500 3550 3750
Connection ~ 3450 3500
Wire Wire Line
	3750 3400 3450 3400
Connection ~ 3450 3400
Wire Wire Line
	1050 4850 1050 2350
Wire Wire Line
	1700 3400 1700 2450
Wire Wire Line
	2700 3400 2700 2550
Wire Wire Line
	3750 3400 3750 2650
Wire Wire Line
	3750 2650 4800 2650
Wire Wire Line
	4800 1950 3350 1950
Wire Wire Line
	3350 1950 3350 2300
Wire Wire Line
	3350 2300 850  2300
Wire Wire Line
	850  2300 850  5050
Wire Wire Line
	3250 1850 3250 2200
Wire Wire Line
	3250 2200 650  2200
Wire Wire Line
	650  2200 650  6200
Wire Wire Line
	6400 850  6400 1950
Wire Wire Line
	6400 1950 6100 1950
Wire Wire Line
	6600 950  6600 2050
Wire Wire Line
	6600 2050 6100 2050
Wire Notes Line
	9000 2450 7200 2450
Wire Notes Line
	7200 2450 7200 1500
Wire Notes Line
	7200 1500 8550 1500
Wire Notes Line
	8550 1500 8550 1300
Wire Notes Line
	8550 1300 10150 1300
Wire Wire Line
	10700 4600 10800 4600
Wire Wire Line
	800  6800 800  6900
Wire Wire Line
	800  6900 1050 6900
Connection ~ 1050 6900
Wire Wire Line
	800  7400 1100 7400
Wire Wire Line
	1100 7400 1100 7350
Connection ~ 1100 7350
Wire Wire Line
	4350 2150 4800 2150
Wire Notes Line
	600  550  2150 550 
Wire Notes Line
	600  550  600  4500
Wire Notes Line
	600  4500 3900 4500
Wire Notes Line
	3900 4500 3900 900 
Wire Notes Line
	3900 900  2150 900 
Wire Notes Line
	2150 900  2150 550 
Wire Wire Line
	1700 1150 3550 1150
Wire Wire Line
	3550 1150 3550 2050
Wire Wire Line
	3550 2050 4800 2050
Wire Wire Line
	5000 1200 5400 1200
Wire Wire Line
	6100 1850 6300 1850
Connection ~ 5200 1200
Wire Wire Line
	5600 1200 5700 1200
Wire Wire Line
	4700 1200 4800 1200
Wire Notes Line
	4350 950  4350 1600
Wire Notes Line
	4350 950  6350 950 
Wire Wire Line
	5200 1200 5200 1450
Wire Wire Line
	5200 1400 5650 1400
Wire Wire Line
	5950 1400 6300 1400
Wire Wire Line
	6300 1400 6300 1850
Wire Notes Line
	6350 950  6350 1600
Wire Notes Line
	6350 1600 4350 1600
Connection ~ 5200 1400
Wire Wire Line
	5200 1450 4800 1450
Wire Wire Line
	4600 1450 4600 1250
Wire Wire Line
	4600 1250 4750 1250
Wire Wire Line
	4750 1250 4750 1200
Connection ~ 4750 1200
Wire Notes Line
	4100 5200 2450 5200
Wire Notes Line
	2450 5200 2450 6350
Wire Notes Line
	2450 6350 4150 6350
Wire Notes Line
	4100 3750 4100 5200
Wire Wire Line
	1050 6700 1400 6700
Wire Wire Line
	1700 6700 1750 6700
Wire Wire Line
	2200 6850 2200 6900
Connection ~ 2200 6900
Wire Wire Line
	2400 4200 2400 4150
Wire Wire Line
	800  7350 800  7400
Wire Wire Line
	1400 4200 1400 4150
Connection ~ 1400 4150
Wire Wire Line
	8950 3850 8950 4350
Wire Wire Line
	8950 4550 8950 5050
$Comp
L -BATT #PWR026
U 1 1 5B062427
P 800 7350
F 0 "#PWR026" H 800 7200 50  0001 C CNN
F 1 "-BATT" H 800 7490 50  0000 C CNN
F 2 "" H 800 7350 50  0001 C CNN
F 3 "" H 800 7350 50  0001 C CNN
	1    800  7350
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG027
U 1 1 5B0A20E9
P -1550 7250
F 0 "#FLG027" H -1550 7325 50  0001 C CNN
F 1 "PWR_FLAG" H -1550 7400 50  0000 C CNN
F 2 "" H -1550 7250 50  0001 C CNN
F 3 "" H -1550 7250 50  0001 C CNN
	1    -1550 7250
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2700 7250 2700 7400
Connection ~ 2700 7400
Text Label -1550 6700 0    60   ~ 0
+BATT
Text Label -1550 7250 0    60   ~ 0
-BATT
Text Notes -2200 7000 0    60   Italic 0
Power flags for ERC check run
$EndSCHEMATC
