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
LIBS:badgeComponents
LIBS:sensors-module-board-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "IoT conference badge - sensors module board"
Date "2018-05-16"
Rev "0.1.1"
Comp "MakeZürich (makezurich.ch) & GDG Zürich (gdgzh.ch)"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L PCA9306_c U2
U 1 1 5AD395F2
P 5350 4200
F 0 "U2" H 5050 4650 50  0000 L CNN
F 1 "PCA9306" H 5550 4650 50  0000 L CNN
F 2 "PCA9306TDCURQ1:SOP50P310X90-8N" H 4950 4550 50  0001 C CNN
F 3 "" H 5050 4650 50  0001 C CNN
	1    5350 4200
	1    0    0    -1  
$EndComp
$Comp
L +1V8 #PWR01
U 1 1 5AD395F9
P 5250 3450
F 0 "#PWR01" H 5250 3300 50  0001 C CNN
F 1 "+1V8" H 5250 3590 50  0000 C CNN
F 2 "" H 5250 3450 50  0001 C CNN
F 3 "" H 5250 3450 50  0001 C CNN
	1    5250 3450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 5AD395FF
P 5350 4750
F 0 "#PWR02" H 5350 4500 50  0001 C CNN
F 1 "GND" H 5350 4600 50  0000 C CNN
F 2 "" H 5350 4750 50  0001 C CNN
F 3 "" H 5350 4750 50  0001 C CNN
	1    5350 4750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 5AD39605
P 6100 4000
F 0 "#PWR03" H 6100 3750 50  0001 C CNN
F 1 "GND" H 6100 3850 50  0000 C CNN
F 2 "" H 6100 4000 50  0001 C CNN
F 3 "" H 6100 4000 50  0001 C CNN
	1    6100 4000
	1    0    0    -1  
$EndComp
$Comp
L R_Small R1
U 1 1 5AD39611
P 6150 3550
F 0 "R1" H 6180 3570 50  0000 L CNN
F 1 "200k" H 6180 3510 50  0000 L CNN
F 2 "Resistors_SMD:R_1206" H 6150 3550 50  0001 C CNN
F 3 "" H 6150 3550 50  0001 C CNN
	1    6150 3550
	1    0    0    -1  
$EndComp
$Comp
L C_Small C2
U 1 1 5AD39618
P 6150 3900
F 0 "C2" H 6160 3970 50  0000 L CNN
F 1 "100pF" H 6160 3820 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206" H 6150 3900 50  0001 C CNN
F 3 "" H 6150 3900 50  0001 C CNN
	1    6150 3900
	1    0    0    -1  
$EndComp
$Comp
L R_Small R3
U 1 1 5AD39621
P 4800 3950
F 0 "R3" H 4830 3970 50  0000 L CNN
F 1 "200k" H 4830 3910 50  0000 L CNN
F 2 "Resistors_SMD:R_1206" H 4800 3950 50  0001 C CNN
F 3 "" H 4800 3950 50  0001 C CNN
	1    4800 3950
	1    0    0    -1  
$EndComp
$Comp
L R_Small R2
U 1 1 5AD39628
P 4500 3950
F 0 "R2" H 4530 3970 50  0000 L CNN
F 1 "200k" H 4530 3910 50  0000 L CNN
F 2 "Resistors_SMD:R_1206" H 4500 3950 50  0001 C CNN
F 3 "" H 4500 3950 50  0001 C CNN
	1    4500 3950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 5AD39636
P 4050 5050
F 0 "#PWR04" H 4050 4800 50  0001 C CNN
F 1 "GND" H 4050 4900 50  0000 C CNN
F 2 "" H 4050 5050 50  0001 C CNN
F 3 "" H 4050 5050 50  0001 C CNN
	1    4050 5050
	1    0    0    -1  
$EndComp
$Comp
L C_Small C3
U 1 1 5AD39642
P 2250 4150
F 0 "C3" H 2260 4220 50  0000 L CNN
F 1 "100nF" H 2260 4070 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206" H 2250 4150 50  0001 C CNN
F 3 "" H 2250 4150 50  0001 C CNN
	1    2250 4150
	1    0    0    -1  
$EndComp
$Comp
L C_Small C1
U 1 1 5AD39649
P 7900 2950
F 0 "C1" H 7910 3020 50  0000 L CNN
F 1 "100nF" H 7910 2870 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206" H 7900 2950 50  0001 C CNN
F 3 "" H 7900 2950 50  0001 C CNN
	1    7900 2950
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR05
U 1 1 5AD39656
P 8550 3350
F 0 "#PWR05" H 8550 3100 50  0001 C CNN
F 1 "GND" H 8550 3200 50  0000 C CNN
F 2 "" H 8550 3350 50  0001 C CNN
F 3 "" H 8550 3350 50  0001 C CNN
	1    8550 3350
	1    0    0    -1  
$EndComp
Text Notes 9000 2550 2    60   ~ 0
Temp. / Humidity Sensor
Text Notes 3050 3250 2    60   ~ 0
Air Quality Sensor
$Comp
L SHTC3 U3
U 1 1 5AD39664
P 7400 3150
F 0 "U3" H 7850 3100 50  0000 L CNN
F 1 "SHTC3" H 7900 2950 50  0000 L CNN
F 2 "SHTC3:SHTC3" H 8250 3250 50  0001 L CNN
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
L SGPC3-2.5k U1
U 1 1 5AD3966F
P 2600 4200
F 0 "U1" H 3450 3700 50  0000 L CNN
F 1 "SGPC3-2.5k" H 3000 3850 50  0000 L CNN
F 2 "SGPC3-2.5k:SON80P245X245X90-7N" H 3650 4300 50  0001 L CNN
F 3 "https://componentsearchengine.com/Datasheets/2/SGPC3-2.5K.pdf" H 3650 4200 50  0001 L CNN
F 4 "SENSIRION - SGPC3-2.5K - DIGITAL LOW POWER GAS SENSOR, 1.8V, DFN" H 3650 4100 50  0001 L CNN "Description"
F 5 "0.9" H 3650 4000 50  0001 L CNN "Height"
F 6 "Sensirion" H 3650 3900 50  0001 L CNN "Manufacturer_Name"
F 7 "SGPC3-2.5k" H 3650 3800 50  0001 L CNN "Manufacturer_Part_Number"
	1    2600 4200
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR06
U 1 1 5AD43943
P 6150 3350
F 0 "#PWR06" H 6150 3200 50  0001 C CNN
F 1 "+3V3" H 6150 3490 50  0000 C CNN
F 2 "" H 6150 3350 50  0001 C CNN
F 3 "" H 6150 3350 50  0001 C CNN
	1    6150 3350
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR07
U 1 1 5AD4429B
P 7400 2750
F 0 "#PWR07" H 7400 2600 50  0001 C CNN
F 1 "+3V3" H 7400 2890 50  0000 C CNN
F 2 "" H 7400 2750 50  0001 C CNN
F 3 "" H 7400 2750 50  0001 C CNN
	1    7400 2750
	1    0    0    -1  
$EndComp
Text Notes 8200 2000 2    60   Italic 0
leave 200k pullups as TI reference design or put them to 10k as sensirion reference design or to 4.7k as we have it on the other side of the level converter?
$Comp
L GND #PWR08
U 1 1 5AFC5229
P 8700 3950
F 0 "#PWR08" H 8700 3700 50  0001 C CNN
F 1 "GND" H 8700 3800 50  0000 C CNN
F 2 "" H 8700 3950 50  0001 C CNN
F 3 "" H 8700 3950 50  0001 C CNN
	1    8700 3950
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR09
U 1 1 5AFC5301
P 9950 3750
F 0 "#PWR09" H 9950 3600 50  0001 C CNN
F 1 "+3V3" H 9950 3890 50  0000 C CNN
F 2 "" H 9950 3750 50  0001 C CNN
F 3 "" H 9950 3750 50  0001 C CNN
	1    9950 3750
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG010
U 1 1 5AFC53F0
P 10350 3750
F 0 "#FLG010" H 10350 3825 50  0001 C CNN
F 1 "PWR_FLAG" H 10350 3900 50  0000 C CNN
F 2 "" H 10350 3750 50  0001 C CNN
F 3 "" H 10350 3750 50  0001 C CNN
	1    10350 3750
	1    0    0    -1  
$EndComp
$Comp
L TPS78918DBVR PS1
U 1 1 5AFC66F7
P 2350 6300
F 0 "PS1" H 2850 6200 50  0000 L CNN
F 1 "TPS78918DBVR" H 2750 6050 50  0000 L CNN
F 2 "TPS78918DBVT:SOT95P280X145-5N" H 2400 5700 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/tps789.pdf" H 2400 5550 50  0001 L CNN
F 4 "Texas Instruments TPS78918DBVR, LDO Voltage Regulator, 0.1A, 1.8 V, 2.7  10 Vin, 5-Pin SOT-23" H 2400 5400 50  0001 L CNN "Description"
	1    2350 6300
	1    0    0    -1  
$EndComp
$Comp
L C_Small C6
U 1 1 5AFC6953
P 1900 6600
F 0 "C6" H 1910 6670 50  0000 L CNN
F 1 "1uF" H 1910 6520 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206" H 1900 6600 50  0001 C CNN
F 3 "" H 1900 6600 50  0001 C CNN
	1    1900 6600
	1    0    0    -1  
$EndComp
$Comp
L C_Small C5
U 1 1 5AFC69EB
P 3700 6550
F 0 "C5" H 3710 6620 50  0000 L CNN
F 1 "4.7uF (0.2-10 Ohm ESR)" H 3710 6470 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206" H 3700 6550 50  0001 C CNN
F 3 "" H 3700 6550 50  0001 C CNN
	1    3700 6550
	1    0    0    -1  
$EndComp
$Comp
L C_Small C4
U 1 1 5AFC6AFE
P 4750 6500
F 0 "C4" H 4760 6570 50  0000 L CNN
F 1 "0.01uF" H 4760 6420 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206" H 4750 6500 50  0001 C CNN
F 3 "" H 4750 6500 50  0001 C CNN
	1    4750 6500
	1    0    0    -1  
$EndComp
$Comp
L +1V8 #PWR011
U 1 1 5AFC7051
P 4250 6500
F 0 "#PWR011" H 4250 6350 50  0001 C CNN
F 1 "+1V8" H 4250 6640 50  0000 C CNN
F 2 "" H 4250 6500 50  0001 C CNN
F 3 "" H 4250 6500 50  0001 C CNN
	1    4250 6500
	1    0    0    -1  
$EndComp
Text Notes 4650 6000 0    60   ~ 0
1v8 LDO
$Comp
L +3V3 #PWR012
U 1 1 5AFCCEBE
P 1900 6150
F 0 "#PWR012" H 1900 6000 50  0001 C CNN
F 1 "+3V3" H 1900 6290 50  0000 C CNN
F 2 "" H 1900 6150 50  0001 C CNN
F 3 "" H 1900 6150 50  0001 C CNN
	1    1900 6150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR013
U 1 1 5AFCED75
P 3100 6800
F 0 "#PWR013" H 3100 6550 50  0001 C CNN
F 1 "GND" H 3100 6650 50  0000 C CNN
F 2 "" H 3100 6800 50  0001 C CNN
F 3 "" H 3100 6800 50  0001 C CNN
	1    3100 6800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR014
U 1 1 5AD3963C
P 2250 4400
F 0 "#PWR014" H 2250 4150 50  0001 C CNN
F 1 "GND" H 2250 4250 50  0000 C CNN
F 2 "" H 2250 4400 50  0001 C CNN
F 3 "" H 2250 4400 50  0001 C CNN
	1    2250 4400
	1    0    0    -1  
$EndComp
$Comp
L I2C_HEADER J1
U 1 1 5AFCC73D
P 9700 4100
F 0 "J1" H 9700 4300 50  0000 C CNN
F 1 "I2C_HEADER" H 9700 3800 50  0000 C CNN
F 2 "badgeComponents:I2C_header_Pitch2.54mm" H 9700 4100 50  0001 C CNN
F 3 "" H 9700 4100 50  0001 C CNN
	1    9700 4100
	1    0    0    -1  
$EndComp
$Comp
L I2C_HEADER J2
U 1 1 5AFF6355
P 10350 4100
F 0 "J2" H 10350 4300 50  0000 C CNN
F 1 "I2C_boardconnector" H 10350 3800 50  0000 C CNN
F 2 "badgeComponents:I2C_header_halfround_Pitch2.54mm" H 10350 4100 50  0001 C CNN
F 3 "" H 10350 4100 50  0001 C CNN
	1    10350 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 3450 5250 3700
Wire Wire Line
	5450 3700 6150 3700
Wire Wire Line
	5950 3700 5950 4100
Wire Wire Line
	5950 4100 5750 4100
Wire Wire Line
	4500 3600 4500 3850
Wire Wire Line
	2600 3600 5250 3600
Connection ~ 5250 3600
Wire Wire Line
	4800 3850 4800 3600
Connection ~ 4800 3600
Wire Wire Line
	3800 4200 4950 4200
Wire Wire Line
	4800 4200 4800 4050
Wire Wire Line
	4950 4300 4500 4300
Wire Wire Line
	4500 4050 4500 5250
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
	2600 4300 2250 4300
Wire Wire Line
	2600 3600 2600 4200
Wire Wire Line
	2600 4050 2250 4050
Connection ~ 4150 3600
Connection ~ 2600 4050
Wire Wire Line
	6150 3350 6150 3450
Wire Wire Line
	7800 2950 7400 2950
Wire Wire Line
	7400 2750 7400 3150
Connection ~ 7400 2950
Wire Wire Line
	7400 3250 7200 3250
Connection ~ 7200 4200
Wire Wire Line
	8000 2950 8550 2950
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
	5750 4300 10150 4300
Wire Wire Line
	7200 3250 7200 4200
Wire Wire Line
	8550 2950 8550 3350
Wire Wire Line
	8550 3250 8400 3250
Wire Wire Line
	2350 6300 1900 6300
Wire Wire Line
	1900 6150 1900 6500
Connection ~ 1900 6300
Wire Wire Line
	1900 6750 4750 6750
Wire Wire Line
	4750 6750 4750 6600
Connection ~ 2200 6750
Wire Wire Line
	3550 6300 4750 6300
Wire Wire Line
	4750 6300 4750 6400
Wire Wire Line
	3550 6400 4050 6400
Wire Wire Line
	3700 6400 3700 6450
Wire Wire Line
	3700 6650 3700 6750
Connection ~ 3700 6750
Wire Wire Line
	4050 6400 4050 6550
Wire Wire Line
	4050 6550 4250 6550
Wire Wire Line
	4250 6550 4250 6500
Connection ~ 3700 6400
Wire Notes Line
	1700 5900 1700 7100
Wire Notes Line
	1700 7100 5050 7100
Wire Notes Line
	5050 7100 5050 5900
Wire Notes Line
	5050 5900 1700 5900
Wire Wire Line
	1900 6700 1900 6750
Wire Wire Line
	6100 4000 6150 4000
Wire Wire Line
	2350 6400 2200 6400
Wire Wire Line
	2350 6500 2350 6750
Connection ~ 2350 6750
Wire Wire Line
	2200 6400 2200 6750
Wire Wire Line
	3100 6800 3100 6750
Connection ~ 3100 6750
Wire Wire Line
	2250 4250 2250 4400
Connection ~ 2250 4300
Wire Wire Line
	3800 4400 4050 4400
Wire Wire Line
	4050 4400 4050 5050
Wire Wire Line
	3200 5000 3200 5050
Wire Wire Line
	3200 5050 3800 5050
Wire Wire Line
	3800 5050 3800 4950
Wire Wire Line
	3800 4950 4050 4950
Connection ~ 4050 4950
Connection ~ 8550 3250
Wire Wire Line
	5350 4750 5350 4700
Wire Wire Line
	8400 3150 8550 3150
Connection ~ 8550 3150
Wire Wire Line
	5750 4200 10150 4200
Wire Wire Line
	7400 3550 10800 3550
Wire Wire Line
	9350 4700 10800 4700
Wire Wire Line
	9350 4700 9350 4300
Connection ~ 9350 4300
Wire Wire Line
	8900 4100 10150 4100
Wire Wire Line
	8900 4100 8900 3850
Wire Wire Line
	8900 3850 8700 3850
Wire Wire Line
	8700 3850 8700 3950
Wire Wire Line
	9350 4000 10150 4000
Wire Wire Line
	9350 4000 9350 3800
Wire Wire Line
	6150 3800 6150 3650
Connection ~ 6150 3700
Connection ~ 5950 3700
Wire Wire Line
	9950 3750 9950 3800
Wire Wire Line
	9350 3800 10350 3800
Wire Wire Line
	10350 3800 10350 3750
Connection ~ 9950 3800
Wire Wire Line
	10800 4700 10800 3550
Connection ~ 9500 4000
Connection ~ 9500 4100
Connection ~ 9500 4200
Connection ~ 9500 4300
$Comp
L BOARD_CONNECTOR J3
U 1 1 5AFF6F3A
P 10400 5150
F 0 "J3" H 10400 5350 50  0000 C CNN
F 1 "BOARD_CONNECTOR" H 10400 4850 50  0000 C CNN
F 2 "badgeComponents:GND_BOARD_CONNECTOR_halfround_Pitch2.54mm" H 10400 5150 50  0001 C CNN
F 3 "" H 10400 5150 50  0001 C CNN
	1    10400 5150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR015
U 1 1 5AFF7026
P 9850 5600
F 0 "#PWR015" H 9850 5350 50  0001 C CNN
F 1 "GND" H 9850 5450 50  0000 C CNN
F 2 "" H 9850 5600 50  0001 C CNN
F 3 "" H 9850 5600 50  0001 C CNN
	1    9850 5600
	1    0    0    -1  
$EndComp
Wire Wire Line
	9850 5050 9850 5600
Wire Wire Line
	9850 5350 10200 5350
Wire Wire Line
	10200 5250 9850 5250
Connection ~ 9850 5350
Wire Wire Line
	10200 5150 9850 5150
Connection ~ 9850 5250
Wire Wire Line
	10200 5050 9850 5050
Connection ~ 9850 5150
Wire Wire Line
	7400 3350 7400 3550
$EndSCHEMATC