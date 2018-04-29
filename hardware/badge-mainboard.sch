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
Sheet 1 6
Title "IoT conference badge - mainboard"
Date "2018-04-09"
Rev "0.2.0"
Comp "MakeZürich (makezurich.ch) & GDG Zürich (gdgzh.ch)"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L WS2812b LED?
U 1 1 5AC27ED2
P 9600 4000
F 0 "LED?" H 10550 4300 50  0000 L CNN
F 1 "WS2812b" H 10550 4200 50  0000 L CNN
F 2 "WS2812B_1" H 10550 4100 50  0001 L CNN
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
L R_Small R?
U 1 1 5AC2AEF4
P 6250 950
F 0 "R?" H 6280 970 50  0000 L CNN
F 1 "10k" H 6280 910 50  0000 L CNN
F 2 "" H 6250 950 50  0001 C CNN
F 3 "" H 6250 950 50  0001 C CNN
	1    6250 950 
	-1   0    0    1   
$EndComp
$Comp
L WS2812b LED?
U 1 1 5AC2C475
P 9600 4600
F 0 "LED?" H 10550 4900 50  0000 L CNN
F 1 "WS2812b" H 10550 4800 50  0000 L CNN
F 2 "WS2812B_1" H 10550 4700 50  0001 L CNN
F 3 "http://www.adafruit.com/datasheets/WS2812B.pdf" H 10550 4600 50  0001 L CNN
F 4 "Intelligent control LED integrated light source, 4-pin SMD" H 10550 4500 50  0001 L CNN "Description"
F 5 "Adafruit" H 10550 4300 50  0001 L CNN "Manufacturer_Name"
F 6 "1655" H 10550 4200 50  0001 L CNN "Manufacturer_Part_Number"
F 7 "70928826" H 10550 3900 50  0001 L CNN "Allied_Number"
F 8 "http://www.alliedelec.com/adafruit-industries-1655/70928826/" H 10550 3800 50  0001 L CNN "Allied Price/Stock"
	1    9600 4600
	1    0    0    -1  
$EndComp
$Comp
L WS2812b LED?
U 1 1 5AC2C4FB
P 9600 5150
F 0 "LED?" H 10550 5450 50  0000 L CNN
F 1 "WS2812b" H 10550 5350 50  0000 L CNN
F 2 "WS2812B_1" H 10550 5250 50  0001 L CNN
F 3 "http://www.adafruit.com/datasheets/WS2812B.pdf" H 10550 5150 50  0001 L CNN
F 4 "Intelligent control LED integrated light source, 4-pin SMD" H 10550 5050 50  0001 L CNN "Description"
F 5 "Adafruit" H 10550 4850 50  0001 L CNN "Manufacturer_Name"
F 6 "1655" H 10550 4750 50  0001 L CNN "Manufacturer_Part_Number"
F 7 "70928826" H 10550 4450 50  0001 L CNN "Allied_Number"
F 8 "http://www.alliedelec.com/adafruit-industries-1655/70928826/" H 10550 4350 50  0001 L CNN "Allied Price/Stock"
	1    9600 5150
	1    0    0    -1  
$EndComp
NoConn ~ 9600 5250
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
U 1 1 5AC2E4D6
P 10800 5150
F 0 "#PWR02" H 10800 4900 50  0001 C CNN
F 1 "GND" H 10800 5000 50  0000 C CNN
F 2 "" H 10800 5150 50  0001 C CNN
F 3 "" H 10800 5150 50  0001 C CNN
	1    10800 5150
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR03
U 1 1 5AC2E56B
P 10800 4000
F 0 "#PWR03" H 10800 3750 50  0001 C CNN
F 1 "GND" H 10800 3850 50  0000 C CNN
F 2 "" H 10800 4000 50  0001 C CNN
F 3 "" H 10800 4000 50  0001 C CNN
	1    10800 4000
	0    -1   -1   0   
$EndComp
$Comp
L C_Small C?
U 1 1 5AC2E846
P 9350 4200
F 0 "C?" H 9360 4270 50  0000 L CNN
F 1 "100nF" H 9360 4120 50  0000 L CNN
F 2 "" H 9350 4200 50  0001 C CNN
F 3 "" H 9350 4200 50  0001 C CNN
	1    9350 4200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 5AC2EB3A
P 9350 4350
F 0 "#PWR04" H 9350 4100 50  0001 C CNN
F 1 "GND" H 9350 4200 50  0000 C CNN
F 2 "" H 9350 4350 50  0001 C CNN
F 3 "" H 9350 4350 50  0001 C CNN
	1    9350 4350
	1    0    0    -1  
$EndComp
$Comp
L C_Small C?
U 1 1 5AC2ECF9
P 9350 4800
F 0 "C?" H 9360 4870 50  0000 L CNN
F 1 "100nF" H 9360 4720 50  0000 L CNN
F 2 "" H 9350 4800 50  0001 C CNN
F 3 "" H 9350 4800 50  0001 C CNN
	1    9350 4800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR05
U 1 1 5AC2ECFF
P 9350 4950
F 0 "#PWR05" H 9350 4700 50  0001 C CNN
F 1 "GND" H 9350 4800 50  0000 C CNN
F 2 "" H 9350 4950 50  0001 C CNN
F 3 "" H 9350 4950 50  0001 C CNN
	1    9350 4950
	1    0    0    -1  
$EndComp
$Comp
L C_Small C?
U 1 1 5AC2EDA7
P 9350 5350
F 0 "C?" H 9360 5420 50  0000 L CNN
F 1 "100nF" H 9360 5270 50  0000 L CNN
F 2 "" H 9350 5350 50  0001 C CNN
F 3 "" H 9350 5350 50  0001 C CNN
	1    9350 5350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR06
U 1 1 5AC2EDAD
P 9350 5500
F 0 "#PWR06" H 9350 5250 50  0001 C CNN
F 1 "GND" H 9350 5350 50  0000 C CNN
F 2 "" H 9350 5500 50  0001 C CNN
F 3 "" H 9350 5500 50  0001 C CNN
	1    9350 5500
	1    0    0    -1  
$EndComp
Text Notes 10500 3850 2    60   ~ 0
3 x RGBW LED Daisychain
Text GLabel 6650 1150 1    60   BiDi ~ 0
NINA_SCL
Text GLabel 6450 1150 1    60   BiDi ~ 0
NINA_SDA
Text Notes 6150 600  0    60   ~ 0
Random I2C ports, any GPIO works.
Text Notes 11000 2900 2    60   ~ 0
Random data port, can be changed if needed
$Comp
L C_Small C?
U 1 1 5ACAD80F
P 8950 3950
F 0 "C?" H 8960 4020 50  0000 L CNN
F 1 "47uF" H 8960 3870 50  0000 L CNN
F 2 "" H 8950 3950 50  0001 C CNN
F 3 "" H 8950 3950 50  0001 C CNN
	1    8950 3950
	1    0    0    -1  
$EndComp
Text Notes 3300 800  0    60   Italic 0
Which pullups? 10k or 200k?\nhttp://www.ti.com/lit/an/slva689/slva689.pdf
Wire Notes Line
	500  6950 500  4700
Wire Wire Line
	9600 4100 9600 4450
Wire Wire Line
	9600 4450 11000 4450
Wire Wire Line
	11000 4450 11000 4700
Wire Wire Line
	11000 4700 10700 4700
Wire Wire Line
	9600 4700 9600 5000
Wire Wire Line
	9600 5000 11000 5000
Wire Wire Line
	10700 5250 11000 5250
Wire Wire Line
	10800 4600 10700 4600
Wire Wire Line
	10800 5150 10700 5150
Wire Wire Line
	10800 4000 10700 4000
Wire Wire Line
	11000 5250 11000 5000
Wire Wire Line
	9250 4000 9600 4000
Wire Wire Line
	9250 3750 9250 5150
Wire Wire Line
	9250 4600 9600 4600
Connection ~ 9250 4000
Wire Wire Line
	9250 5150 9600 5150
Connection ~ 9250 4600
Wire Wire Line
	9350 4300 9350 4350
Wire Wire Line
	9350 4100 9350 4000
Connection ~ 9350 4000
Wire Wire Line
	9350 4900 9350 4950
Wire Wire Line
	9350 4700 9350 4600
Wire Wire Line
	9350 5450 9350 5500
Wire Wire Line
	9350 5250 9350 5150
Connection ~ 9350 5150
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
	6650 1150 6650 2150
Wire Wire Line
	6450 1150 6450 2050
Wire Wire Line
	8950 3850 9250 3850
Connection ~ 9250 3850
Wire Wire Line
	8950 4050 8950 5500
Wire Wire Line
	8950 5500 9350 5500
Wire Notes Line
	8800 5750 8800 3500
Connection ~ 6450 1200
$Sheet
S 1300 3100 800  350 
U 5AD378C9
F0 "sensors" 60
F1 "sensors.sch" 60
F2 "SCL" B R 2100 3200 60 
F3 "SDA" B R 2100 3350 60 
$EndSheet
Text GLabel 2200 3350 2    60   BiDi ~ 0
NINA_SDA
Text GLabel 2200 3200 2    60   BiDi ~ 0
NINA_SCL
Wire Wire Line
	2100 3200 2200 3200
Wire Wire Line
	2100 3350 2200 3350
$Sheet
S 2250 5900 1000 900 
U 5AD3BA03
F0 "programmer" 60
F1 "programmer.sch" 60
F2 "DTR" O L 2250 6100 60 
F3 "RXD" I L 2250 6250 60 
F4 "TXD" O L 2250 6400 60 
F5 "CTS" O L 2250 6550 60 
F6 "VBUS_OUT" O R 3250 6100 60 
$EndSheet
Text GLabel 1950 6400 0    60   Input Italic 0
TXD
Text GLabel 1950 6250 0    60   Output Italic 0
RXD
Wire Wire Line
	2150 6250 1950 6250
Wire Wire Line
	1950 6400 2150 6400
$Sheet
S 1250 1150 1700 800 
U 5AD3E430
F0 "EPD" 60
F1 "EPD.sch" 60
F2 "DIN" I L 1250 1300 60 
F3 "CLK" I L 1250 1400 60 
F4 "CS" I L 1250 1500 60 
F5 "DC" I L 1250 1600 60 
F6 "RST" I L 1250 1700 60 
F7 "BUSY" O L 1250 1800 60 
$EndSheet
$Sheet
S 3750 5950 1200 550 
U 5AD42326
F0 "power" 60
F1 "power.sch" 60
F2 "VBUS_IN" I L 3750 6100 60 
F3 "1.8_OUT" O R 4950 6100 60 
F4 "3.3_OUT" O R 4950 6300 60 
$EndSheet
Wire Wire Line
	3250 6100 3750 6100
$Comp
L +1V8 #PWR08
U 1 1 5AD43521
P 5050 5900
F 0 "#PWR08" H 5050 5750 50  0001 C CNN
F 1 "+1V8" H 5050 6040 50  0000 C CNN
F 2 "" H 5050 5900 50  0001 C CNN
F 3 "" H 5050 5900 50  0001 C CNN
	1    5050 5900
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR09
U 1 1 5AD44887
P 5350 5900
F 0 "#PWR09" H 5350 5750 50  0001 C CNN
F 1 "+3V3" H 5350 6040 50  0000 C CNN
F 2 "" H 5350 5900 50  0001 C CNN
F 3 "" H 5350 5900 50  0001 C CNN
	1    5350 5900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 6100 5050 6100
Wire Wire Line
	5050 6100 5050 5900
Wire Wire Line
	4950 6300 5350 6300
Wire Wire Line
	5350 6300 5350 5900
$Comp
L +3V3 #PWR010
U 1 1 5AD49812
P 6250 800
F 0 "#PWR010" H 6250 650 50  0001 C CNN
F 1 "+3V3" H 6250 940 50  0000 C CNN
F 2 "" H 6250 800 50  0001 C CNN
F 3 "" H 6250 800 50  0001 C CNN
	1    6250 800 
	1    0    0    -1  
$EndComp
Wire Wire Line
	6450 1200 6250 1200
Wire Wire Line
	6250 1200 6250 1050
Wire Wire Line
	6250 850  6250 800 
$Comp
L +3V3 #PWR011
U 1 1 5AD4A3AB
P 6850 800
F 0 "#PWR011" H 6850 650 50  0001 C CNN
F 1 "+3V3" H 6850 940 50  0000 C CNN
F 2 "" H 6850 800 50  0001 C CNN
F 3 "" H 6850 800 50  0001 C CNN
	1    6850 800 
	1    0    0    -1  
$EndComp
$Comp
L R_Small R?
U 1 1 5AD4A446
P 6850 950
F 0 "R?" H 6880 970 50  0000 L CNN
F 1 "10k" H 6880 910 50  0000 L CNN
F 2 "" H 6850 950 50  0001 C CNN
F 3 "" H 6850 950 50  0001 C CNN
	1    6850 950 
	1    0    0    -1  
$EndComp
Wire Wire Line
	6850 800  6850 850 
Wire Wire Line
	6850 1050 6850 1200
Wire Wire Line
	6850 1200 6650 1200
Connection ~ 6650 1200
$Comp
L +3V3 #PWR012
U 1 1 5AD4B526
P 9250 3750
F 0 "#PWR012" H 9250 3600 50  0001 C CNN
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
Wire Wire Line
	6100 2950 11100 2950
Wire Wire Line
	11100 2950 11100 4100
Wire Wire Line
	6450 2050 6100 2050
Wire Wire Line
	6650 2150 6100 2150
$Comp
L +3V3 #PWR?
U 1 1 5AE6FF03
P 4550 3300
F 0 "#PWR?" H 4550 3150 50  0001 C CNN
F 1 "+3V3" H 4550 3440 50  0000 C CNN
F 2 "" H 4550 3300 50  0001 C CNN
F 3 "" H 4550 3300 50  0001 C CNN
	1    4550 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 3050 4700 3050
Wire Wire Line
	4700 3050 4700 3350
Wire Wire Line
	4700 3350 4550 3350
Wire Wire Line
	4550 3350 4550 3300
$Comp
L GND #PWR?
U 1 1 5AE70C46
P 4200 2200
F 0 "#PWR?" H 4200 1950 50  0001 C CNN
F 1 "GND" H 4200 2050 50  0000 C CNN
F 2 "" H 4200 2200 50  0001 C CNN
F 3 "" H 4200 2200 50  0001 C CNN
	1    4200 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 2150 4200 2150
Wire Wire Line
	4200 2150 4200 2200
$EndSCHEMATC
