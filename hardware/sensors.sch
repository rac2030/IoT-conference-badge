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
Sheet 2 7
Title "IoT conference badge - mainboard"
Date "2018-04-30"
Rev "0.2.0"
Comp "MakeZürich (makezurich.ch) & GDG Zürich (gdgzh.ch)"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L PCA9306 U?
U 1 1 5AD395F2
P 5350 4200
F 0 "U?" H 5050 4650 50  0000 L CNN
F 1 "PCA9306" H 5550 4650 50  0000 L CNN
F 2 "" H 4950 4550 50  0001 C CNN
F 3 "" H 5050 4650 50  0001 C CNN
	1    5350 4200
	1    0    0    -1  
$EndComp
$Comp
L +1V8 #PWR014
U 1 1 5AD395F9
P 5250 3450
F 0 "#PWR014" H 5250 3300 50  0001 C CNN
F 1 "+1V8" H 5250 3590 50  0000 C CNN
F 2 "" H 5250 3450 50  0001 C CNN
F 3 "" H 5250 3450 50  0001 C CNN
	1    5250 3450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR015
U 1 1 5AD395FF
P 5350 4700
F 0 "#PWR015" H 5350 4450 50  0001 C CNN
F 1 "GND" H 5350 4550 50  0000 C CNN
F 2 "" H 5350 4700 50  0001 C CNN
F 3 "" H 5350 4700 50  0001 C CNN
	1    5350 4700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR016
U 1 1 5AD39605
P 6150 4000
F 0 "#PWR016" H 6150 3750 50  0001 C CNN
F 1 "GND" H 6150 3850 50  0000 C CNN
F 2 "" H 6150 4000 50  0001 C CNN
F 3 "" H 6150 4000 50  0001 C CNN
	1    6150 4000
	1    0    0    -1  
$EndComp
$Comp
L R_Small R?
U 1 1 5AD39611
P 6150 3650
F 0 "R?" H 6180 3670 50  0000 L CNN
F 1 "200k" H 6180 3610 50  0000 L CNN
F 2 "" H 6150 3650 50  0001 C CNN
F 3 "" H 6150 3650 50  0001 C CNN
	1    6150 3650
	1    0    0    -1  
$EndComp
$Comp
L C_Small C?
U 1 1 5AD39618
P 6150 3900
F 0 "C?" H 6160 3970 50  0000 L CNN
F 1 "100pF" H 6160 3820 50  0000 L CNN
F 2 "" H 6150 3900 50  0001 C CNN
F 3 "" H 6150 3900 50  0001 C CNN
	1    6150 3900
	1    0    0    -1  
$EndComp
$Comp
L R_Small R?
U 1 1 5AD39621
P 4800 3950
F 0 "R?" H 4830 3970 50  0000 L CNN
F 1 "200k" H 4830 3910 50  0000 L CNN
F 2 "" H 4800 3950 50  0001 C CNN
F 3 "" H 4800 3950 50  0001 C CNN
	1    4800 3950
	1    0    0    -1  
$EndComp
$Comp
L R_Small R?
U 1 1 5AD39628
P 4500 3950
F 0 "R?" H 4530 3970 50  0000 L CNN
F 1 "200k" H 4530 3910 50  0000 L CNN
F 2 "" H 4500 3950 50  0001 C CNN
F 3 "" H 4500 3950 50  0001 C CNN
	1    4500 3950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR017
U 1 1 5AD39636
P 3800 5000
F 0 "#PWR017" H 3800 4750 50  0001 C CNN
F 1 "GND" H 3800 4850 50  0000 C CNN
F 2 "" H 3800 5000 50  0001 C CNN
F 3 "" H 3800 5000 50  0001 C CNN
	1    3800 5000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR018
U 1 1 5AD3963C
P 2250 4400
F 0 "#PWR018" H 2250 4150 50  0001 C CNN
F 1 "GND" H 2250 4250 50  0000 C CNN
F 2 "" H 2250 4400 50  0001 C CNN
F 3 "" H 2250 4400 50  0001 C CNN
	1    2250 4400
	1    0    0    -1  
$EndComp
$Comp
L C_Small C?
U 1 1 5AD39642
P 2250 4150
F 0 "C?" H 2260 4220 50  0000 L CNN
F 1 "100nF" H 2260 4070 50  0000 L CNN
F 2 "" H 2250 4150 50  0001 C CNN
F 3 "" H 2250 4150 50  0001 C CNN
	1    2250 4150
	1    0    0    -1  
$EndComp
$Comp
L C_Small C?
U 1 1 5AD39649
P 7900 2950
F 0 "C?" H 7910 3020 50  0000 L CNN
F 1 "100nF" H 7910 2870 50  0000 L CNN
F 2 "" H 7900 2950 50  0001 C CNN
F 3 "" H 7900 2950 50  0001 C CNN
	1    7900 2950
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR019
U 1 1 5AD39656
P 8550 3250
F 0 "#PWR019" H 8550 3000 50  0001 C CNN
F 1 "GND" H 8550 3100 50  0000 C CNN
F 2 "" H 8550 3250 50  0001 C CNN
F 3 "" H 8550 3250 50  0001 C CNN
	1    8550 3250
	1    0    0    -1  
$EndComp
Text Notes 9000 2550 2    60   ~ 0
Temp. / Humidity Sensor
Text Notes 3050 3250 2    60   ~ 0
Air Quality Sensor
$Comp
L SHTC3 IC?
U 1 1 5AD39664
P 7400 3150
F 0 "IC?" H 7850 3100 50  0000 L CNN
F 1 "SHTC3" H 7900 2950 50  0000 L CNN
F 2 "SHTC3" H 8250 3250 50  0001 L CNN
F 3 "https://www.glynshop.com/erp/owweb/Daten/Datenblaetter/Sensirion/SHTC3.pdf" H 8250 3150 50  0001 L CNN
F 4 "Humidity and Temperature Sensor IC" H 8250 3050 50  0001 L CNN "Description"
F 5 "0" H 8250 2950 50  0001 L CNN "Height"
F 6 "Sensirion" H 8250 2850 50  0001 L CNN "Manufacturer_Name"
F 7 "SHTC3" H 8250 2750 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "SHTC3" H 8250 2450 50  0001 L CNN "Arrow Part Number"
	1    7400 3150
	1    0    0    -1  
$EndComp
$Comp
L SGPC3-2.5k U?
U 1 1 5AD3966F
P 2600 4200
F 0 "U?" H 3450 3700 50  0000 L CNN
F 1 "SGPC3-2.5k" H 3000 3850 50  0000 L CNN
F 2 "SON80P245X245X90-7N" H 3650 4300 50  0001 L CNN
F 3 "https://componentsearchengine.com/Datasheets/2/SGPC3-2.5K.pdf" H 3650 4200 50  0001 L CNN
F 4 "SENSIRION - SGPC3-2.5K - DIGITAL LOW POWER GAS SENSOR, 1.8V, DFN" H 3650 4100 50  0001 L CNN "Description"
F 5 "0.9" H 3650 4000 50  0001 L CNN "Height"
F 6 "Sensirion" H 3650 3900 50  0001 L CNN "Manufacturer_Name"
F 7 "SGPC3-2.5k" H 3650 3800 50  0001 L CNN "Manufacturer_Part_Number"
	1    2600 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 3450 5250 3600
Wire Wire Line
	5250 3600 5250 3700
Wire Wire Line
	5450 3700 5950 3700
Wire Wire Line
	5950 3700 5950 3800
Wire Wire Line
	5950 3800 5950 4100
Wire Wire Line
	5950 4100 5750 4100
Wire Wire Line
	6150 3750 6150 3800
Wire Wire Line
	6150 3800 5950 3800
Connection ~ 5950 3800
Connection ~ 6150 3800
Wire Wire Line
	5750 4200 7200 4200
Wire Wire Line
	7200 4200 7450 4200
Wire Wire Line
	6450 4400 7200 4400
Wire Wire Line
	7200 4400 7450 4400
Wire Wire Line
	6450 4400 6450 4300
Wire Wire Line
	4500 3850 4500 3600
Wire Wire Line
	2600 3600 4150 3600
Wire Wire Line
	4150 3600 4250 3600
Wire Wire Line
	4250 3600 4500 3600
Wire Wire Line
	4500 3600 4800 3600
Wire Wire Line
	4800 3600 5250 3600
Connection ~ 5250 3600
Wire Wire Line
	4800 3850 4800 3600
Connection ~ 4800 3600
Wire Wire Line
	4800 4200 4950 4200
Wire Wire Line
	4800 4200 4800 4050
Wire Wire Line
	4950 4300 4500 4300
Wire Wire Line
	4500 4050 4500 4300
Wire Wire Line
	4500 4300 4500 5250
Connection ~ 4800 4200
Wire Wire Line
	4500 5250 2350 5250
Wire Wire Line
	2350 5250 2350 4400
Wire Wire Line
	2350 4400 2600 4400
Connection ~ 4500 4300
Connection ~ 4500 3600
Wire Wire Line
	3800 4300 4150 4300
Wire Wire Line
	4150 4300 4150 3600
Wire Wire Line
	3800 4400 3800 5000
Wire Wire Line
	2600 4300 2250 4300
Wire Wire Line
	2250 4250 2250 4300
Wire Wire Line
	2250 4300 2250 4400
Connection ~ 2250 4300
Wire Wire Line
	2600 3600 2600 4050
Wire Wire Line
	2600 4050 2600 4200
Wire Wire Line
	2600 4050 2250 4050
Connection ~ 4150 3600
Connection ~ 2600 4050
Wire Wire Line
	6150 3450 6150 3550
Wire Wire Line
	7800 2950 7400 2950
Wire Wire Line
	7400 2750 7400 2950
Wire Wire Line
	7400 2950 7400 3150
Connection ~ 7400 2950
Wire Wire Line
	7400 3250 7200 3250
Connection ~ 7200 4200
Wire Wire Line
	8000 2950 8550 2950
Connection ~ 8550 3150
Wire Wire Line
	8400 3150 8550 3150
Wire Wire Line
	8400 4300 7200 4300
Wire Wire Line
	7200 4300 7200 4400
Connection ~ 7200 4400
Wire Notes Line
	7050 2450 7050 3800
Wire Notes Line
	7050 3800 9050 3800
Wire Notes Line
	9050 3800 9050 2450
Wire Notes Line
	9050 2450 7050 2450
Wire Notes Line
	7000 3100 7000 5350
Wire Notes Line
	7000 5350 2150 5350
Wire Notes Line
	2150 5350 2150 3100
Wire Notes Line
	2150 3100 7000 3100
Wire Wire Line
	6450 4300 5750 4300
Wire Wire Line
	7200 3250 7200 4200
Wire Wire Line
	7400 3350 7400 4050
Wire Wire Line
	7400 4050 8400 4050
Wire Wire Line
	8400 4050 8400 4300
Text HLabel 7450 4200 2    60   BiDi Italic 0
SCL
Text HLabel 7450 4400 2    60   BiDi Italic 0
SDA
Wire Wire Line
	8550 2950 8550 3150
Wire Wire Line
	8550 3150 8550 3250
Wire Wire Line
	3800 5000 3200 5000
Wire Wire Line
	8550 3250 8400 3250
$Comp
L +3V3 #PWR020
U 1 1 5AD43943
P 6150 3450
F 0 "#PWR020" H 6150 3300 50  0001 C CNN
F 1 "+3V3" H 6150 3590 50  0000 C CNN
F 2 "" H 6150 3450 50  0001 C CNN
F 3 "" H 6150 3450 50  0001 C CNN
	1    6150 3450
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR021
U 1 1 5AD4429B
P 7400 2750
F 0 "#PWR021" H 7400 2600 50  0001 C CNN
F 1 "+3V3" H 7400 2890 50  0000 C CNN
F 2 "" H 7400 2750 50  0001 C CNN
F 3 "" H 7400 2750 50  0001 C CNN
	1    7400 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 4200 4800 4200
Wire Wire Line
	3800 4200 4250 4200
Text Notes 8200 2000 2    60   Italic 0
leave 200k pullups as TI reference design or put them to 10k as sensirion reference design or to 4.7k as we have it on the other side of the level converter?
$EndSCHEMATC
