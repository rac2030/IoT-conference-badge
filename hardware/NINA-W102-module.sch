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
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 2
Title "IoT conference badge - mainboard"
Date "2018-05-20"
Rev "0.3.5"
Comp "MakeZürich (makezurich.ch) & GDG Zürich (gdgzh.ch)"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 3000 2750 0    60   BiDi ~ 0
GPIO_28
Text HLabel 3000 2850 0    60   BiDi ~ 0
GPIO_29
Text HLabel 3000 2950 0    60   BiDi ~ 0
GPIO_32
Text HLabel 3000 3050 0    60   Output ~ 0
GND
Text HLabel 3000 3150 0    60   BiDi ~ 0
GPIO_31
Text HLabel 3000 3250 0    60   BiDi ~ 0
GPIO_1
Text HLabel 3000 3350 0    60   Input ~ 0
GPI_2
Text HLabel 3000 3450 0    60   Input ~ 0
GPI_3
Text HLabel 3000 3550 0    60   Input ~ 0
GPI_4
Text HLabel 3000 3650 0    60   BiDi ~ 0
GPIO_5
Text HLabel 3000 3750 0    60   Output ~ 0
GND
Text HLabel 3000 3850 0    60   BiDi ~ 0
GPIO_7
Text HLabel 3000 3950 0    60   BiDi ~ 0
GPIO_8
Text HLabel 3000 4150 0    60   Input ~ 0
VCC
Text Notes 2250 4550 0    60   ~ 0
VCC_IO (PIN 14) is coupled to VCC as we use 3.3v for IO
Text HLabel 8000 2750 2    60   Input ~ 0
GPI_34
Text HLabel 8000 2850 2    60   BiDi ~ 0
GPIO_27
Text HLabel 8000 2950 2    60   BiDi ~ 0
GPIO_35
Text HLabel 8000 3050 2    60   Output ~ 0
GND
Text HLabel 8000 3150 2    60   BiDi ~ 0
GPIO_36
Text HLabel 8000 3250 2    60   BiDi ~ 0
GPIO_25
Text HLabel 8000 3350 2    60   BiDi ~ 0
GPIO_24
Text HLabel 8000 3450 2    60   BiDi ~ 0
GPIO_23
Text HLabel 8000 3550 2    60   BiDi ~ 0
GPIO_22
Text HLabel 8000 3650 2    60   BiDi ~ 0
GPIO_21
Text HLabel 8000 3750 2    60   BiDi ~ 0
GPIO_20
Text HLabel 8000 3850 2    60   Input ~ 0
RESET_N
Text HLabel 8000 3950 2    60   BiDi ~ 0
GPIO_18
Text HLabel 8000 4050 2    60   BiDi ~ 0
GPIO_17
Text HLabel 8000 4150 2    60   BiDi ~ 0
GPIO_16
Text Notes 10300 1650 2    197  ~ 0
Sockets to plug-in the NINA-W102 minimal breakout board
$Comp
L Conn_01x15_Female J7
U 1 1 5AE71527
P 3850 3450
F 0 "J7" H 3850 4250 50  0000 C CNN
F 1 "Shield left header" H 3900 2650 50  0000 C CNN
F 2 "badgeComponents:HEADER_1X15_LOCK" H 3850 3450 50  0001 C CNN
F 3 "" H 3850 3450 50  0001 C CNN
	1    3850 3450
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x15_Female J8
U 1 1 5AE715D2
P 7050 3450
F 0 "J8" H 7050 4250 50  0000 C CNN
F 1 "Shield right header" H 7100 2650 50  0000 C CNN
F 2 "badgeComponents:HEADER_1X15_LOCK" H 7050 3450 50  0001 C CNN
F 3 "" H 7050 3450 50  0001 C CNN
	1    7050 3450
	-1   0    0    -1  
$EndComp
Text Notes 6300 2400 2    60   ~ 0
shield header will be on the outside
$Comp
L NINA-W102minimalbreakout U3
U 1 1 5B03A795
P 5500 3300
F 0 "U3" H 5500 3250 60  0000 C CNN
F 1 "NINA-W102minimalbreakout" H 5500 4050 60  0000 C CNN
F 2 "badgeComponents:ublox_NINA-W102_minimal_breakout" H 5500 2900 60  0001 C CNN
F 3 "http://rac.su/ninab" H 5500 2900 60  0001 C CNN
	1    5500 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 2750 3650 2750
Wire Wire Line
	3000 2850 3650 2850
Wire Wire Line
	3000 2950 3650 2950
Wire Wire Line
	3000 3050 3650 3050
Wire Wire Line
	3000 3150 3650 3150
Wire Wire Line
	3000 3250 3650 3250
Wire Wire Line
	3000 3350 3650 3350
Wire Wire Line
	3000 3450 3650 3450
Wire Wire Line
	3000 3550 3650 3550
Wire Wire Line
	3000 3650 3650 3650
Wire Wire Line
	3000 3750 3650 3750
Wire Wire Line
	3000 3850 3650 3850
Wire Wire Line
	3000 3950 3650 3950
Wire Wire Line
	3000 4150 3650 4150
Wire Wire Line
	3050 4050 3650 4050
Wire Wire Line
	3050 4050 3050 4150
Connection ~ 3050 4150
Wire Wire Line
	7250 2750 8000 2750
Wire Wire Line
	7250 2850 8000 2850
Wire Wire Line
	7250 2950 8000 2950
Wire Wire Line
	7250 3050 8000 3050
Wire Wire Line
	7250 3150 8000 3150
Wire Wire Line
	7250 3250 8000 3250
Wire Wire Line
	7250 3350 8000 3350
Wire Wire Line
	7250 3450 8000 3450
Wire Wire Line
	7250 3550 8000 3550
Wire Wire Line
	7250 3650 8000 3650
Wire Wire Line
	7250 3750 8000 3750
Wire Wire Line
	7250 3850 8000 3850
Wire Wire Line
	7250 3950 8000 3950
Wire Wire Line
	7250 4050 8000 4050
Wire Wire Line
	7250 4150 8000 4150
Connection ~ 3150 2750
Connection ~ 3150 2850
Connection ~ 3150 2950
Connection ~ 3150 3050
Connection ~ 3150 3150
Connection ~ 3150 3250
Connection ~ 3150 3350
Connection ~ 3150 3450
Connection ~ 3150 3550
Connection ~ 3150 3650
Connection ~ 3150 3750
Connection ~ 3150 3850
Connection ~ 3150 3950
Connection ~ 3150 4050
Connection ~ 3150 4150
Connection ~ 7800 2750
Connection ~ 7800 2850
Connection ~ 7800 2950
Connection ~ 7800 3050
Connection ~ 7800 3150
Connection ~ 7800 3250
Connection ~ 7800 3350
Connection ~ 7800 3450
Connection ~ 7800 3550
Connection ~ 7800 3650
Connection ~ 7800 3750
Connection ~ 7800 3850
Connection ~ 7800 3950
Connection ~ 7800 4050
Connection ~ 7800 4150
Wire Wire Line
	4600 2750 3150 2750
Wire Wire Line
	4600 2850 3150 2850
Wire Wire Line
	4600 2950 3150 2950
Wire Wire Line
	4600 3050 3150 3050
Wire Wire Line
	4600 3150 3150 3150
Wire Wire Line
	3150 3250 4600 3250
Wire Wire Line
	4600 3350 3150 3350
Wire Wire Line
	4600 3450 3150 3450
Wire Wire Line
	3150 3550 4600 3550
Wire Wire Line
	4600 3650 3150 3650
Wire Wire Line
	3150 3750 4600 3750
Wire Wire Line
	4600 3850 3150 3850
Wire Wire Line
	3150 3950 4600 3950
Wire Wire Line
	4600 4050 3150 4050
Wire Wire Line
	3150 4150 4600 4150
Wire Wire Line
	6400 4150 7800 4150
Wire Wire Line
	7800 4050 6400 4050
Wire Wire Line
	6400 3950 7800 3950
Wire Wire Line
	7800 3850 6400 3850
Wire Wire Line
	6400 3750 7800 3750
Wire Wire Line
	7800 3650 6400 3650
Wire Wire Line
	6400 3550 7800 3550
Wire Wire Line
	7800 3450 6400 3450
Wire Wire Line
	6400 3350 7800 3350
Wire Wire Line
	7800 3250 6400 3250
Wire Wire Line
	6400 3150 7800 3150
Wire Wire Line
	7800 3050 6400 3050
Wire Wire Line
	6400 2950 7800 2950
Wire Wire Line
	7800 2850 6400 2850
Wire Wire Line
	6400 2750 7800 2750
$EndSCHEMATC
