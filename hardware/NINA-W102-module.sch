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
Sheet 4 4
Title "IoT conference badge - mainboard"
Date "2018-04-29"
Rev "0.2.0"
Comp "MakeZürich (makezurich.ch) & GDG Zürich (gdgzh.ch)"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Conn_01x15_Female J?
U 1 1 5AE63E40
P 4500 3450
F 0 "J?" H 4500 4250 50  0000 C CNN
F 1 "NINA Module left header" H 4050 2650 50  0000 C CNN
F 2 "" H 4500 3450 50  0001 C CNN
F 3 "" H 4500 3450 50  0001 C CNN
	1    4500 3450
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x15_Female J?
U 1 1 5AE63E71
P 7100 3450
F 0 "J?" H 7100 4250 50  0000 C CNN
F 1 "Nina module right header" H 6650 2650 50  0000 C CNN
F 2 "" H 7100 3450 50  0001 C CNN
F 3 "" H 7100 3450 50  0001 C CNN
	1    7100 3450
	-1   0    0    -1  
$EndComp
Text HLabel 4150 2750 0    60   BiDi ~ 0
GPIO_28
Text HLabel 4150 2850 0    60   BiDi ~ 0
GPIO_29
Text HLabel 4150 2950 0    60   BiDi ~ 0
GPIO_32
Text HLabel 4150 3050 0    60   Output ~ 0
GND
Text HLabel 4150 3150 0    60   BiDi ~ 0
GPIO_31
Text HLabel 4150 3250 0    60   BiDi ~ 0
GPIO_1
Text HLabel 4150 3350 0    60   Input ~ 0
GPI_2
Text HLabel 4150 3450 0    60   Input ~ 0
GPI_3
Text HLabel 4150 3550 0    60   Input ~ 0
GPI_4
Text HLabel 4150 3650 0    60   BiDi ~ 0
GPIO_5
Text HLabel 4150 3750 0    60   Output ~ 0
GND
Text HLabel 4150 3850 0    60   BiDi ~ 0
GPIO_7
Text HLabel 4150 3950 0    60   BiDi ~ 0
GPIO_8
Text HLabel 4150 4150 0    60   Input ~ 0
VCC
Text Notes 3450 4550 0    60   ~ 0
VCC_IO (PIN 14) is coupled to VCC as we use 3.3v for IO
Text HLabel 7500 2750 2    60   Input ~ 0
GPI_34
Text HLabel 7500 2850 2    60   BiDi ~ 0
GPIO_27
Text HLabel 7500 2950 2    60   BiDi ~ 0
GPIO_35
Text HLabel 7500 3050 2    60   Output ~ 0
GND
Text HLabel 7500 3150 2    60   BiDi ~ 0
GPIO_36
Text HLabel 7500 3250 2    60   BiDi ~ 0
GPIO_25
Text HLabel 7500 3350 2    60   BiDi ~ 0
GPIO_24
Text HLabel 7500 3450 2    60   BiDi ~ 0
GPIO_23
Text HLabel 7500 3550 2    60   BiDi ~ 0
GPIO_22
Text HLabel 7500 3650 2    60   BiDi ~ 0
GPIO_21
Text HLabel 7500 3750 2    60   BiDi ~ 0
GPIO_20
Text HLabel 7500 3850 2    60   Input ~ 0
RESET_N
Text HLabel 7500 3950 2    60   BiDi ~ 0
GPIO_18
Text HLabel 7500 4050 2    60   BiDi ~ 0
GPIO_17
Text HLabel 7500 4150 2    60   BiDi ~ 0
GPIO_16
Text Notes 10300 1650 2    197  ~ 0
Sockets to plug-in the NINA-W102 minimal breakout board
$Comp
L Conn_01x15_Female J?
U 1 1 5AE71527
P 5000 3450
F 0 "J?" H 5000 4250 50  0000 C CNN
F 1 "Shield left header" H 5050 2650 50  0000 C CNN
F 2 "" H 5000 3450 50  0001 C CNN
F 3 "" H 5000 3450 50  0001 C CNN
	1    5000 3450
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x15_Female J?
U 1 1 5AE715D2
P 6550 3450
F 0 "J?" H 6550 4250 50  0000 C CNN
F 1 "Shield right header" H 6600 2650 50  0000 C CNN
F 2 "" H 6550 3450 50  0001 C CNN
F 3 "" H 6550 3450 50  0001 C CNN
	1    6550 3450
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4150 2750 4800 2750
Wire Wire Line
	4150 2850 4800 2850
Wire Wire Line
	4150 2950 4800 2950
Wire Wire Line
	4150 3050 4800 3050
Wire Wire Line
	4150 3150 4800 3150
Wire Wire Line
	4150 3250 4800 3250
Wire Wire Line
	4150 3350 4800 3350
Wire Wire Line
	4150 3450 4800 3450
Wire Wire Line
	4150 3550 4800 3550
Wire Wire Line
	4150 3650 4800 3650
Wire Wire Line
	4150 3750 4800 3750
Wire Wire Line
	4150 3850 4800 3850
Wire Wire Line
	4150 3950 4800 3950
Wire Wire Line
	4150 4150 4800 4150
Wire Wire Line
	4200 4050 4800 4050
Wire Wire Line
	4200 4050 4200 4150
Connection ~ 4200 4150
Wire Wire Line
	6750 2750 7500 2750
Wire Wire Line
	6750 2850 7500 2850
Wire Wire Line
	6750 2950 7500 2950
Wire Wire Line
	6750 3050 7500 3050
Wire Wire Line
	6750 3150 7500 3150
Wire Wire Line
	6750 3250 7500 3250
Wire Wire Line
	6750 3350 7500 3350
Wire Wire Line
	6750 3450 7500 3450
Wire Wire Line
	6750 3550 7500 3550
Wire Wire Line
	6750 3650 7500 3650
Wire Wire Line
	6750 3750 7500 3750
Wire Wire Line
	6750 3850 7500 3850
Wire Wire Line
	6750 3950 7500 3950
Wire Wire Line
	6750 4050 7500 4050
Wire Wire Line
	6750 4150 7500 4150
Connection ~ 4300 2750
Connection ~ 4300 2850
Connection ~ 4300 2950
Connection ~ 4300 3050
Connection ~ 4300 3150
Connection ~ 4300 3250
Connection ~ 4300 3350
Connection ~ 4300 3450
Connection ~ 4300 3550
Connection ~ 4300 3650
Connection ~ 4300 3750
Connection ~ 4300 3850
Connection ~ 4300 3950
Connection ~ 4300 4050
Connection ~ 4300 4150
Connection ~ 7300 2750
Connection ~ 7300 2850
Connection ~ 7300 2950
Connection ~ 7300 3050
Connection ~ 7300 3150
Connection ~ 7300 3250
Connection ~ 7300 3350
Connection ~ 7300 3450
Connection ~ 7300 3550
Connection ~ 7300 3650
Connection ~ 7300 3750
Connection ~ 7300 3850
Connection ~ 7300 3950
Connection ~ 7300 4050
Connection ~ 7300 4150
Text Notes 6600 2400 2    60   ~ 0
shield header will be on the outside
$EndSCHEMATC
