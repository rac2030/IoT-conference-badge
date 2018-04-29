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
Sheet 6 6
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
L Conn_01x15_Female M_J?
U 1 1 5AE63E40
P 2650 3450
F 0 "M_J?" H 2650 4250 50  0000 C CNN
F 1 "Conn_01x15_Female" H 2350 2650 50  0000 C CNN
F 2 "" H 2650 3450 50  0001 C CNN
F 3 "" H 2650 3450 50  0001 C CNN
	1    2650 3450
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x15_Female M_J?
U 1 1 5AE63E71
P 8550 3450
F 0 "M_J?" H 8550 4250 50  0000 C CNN
F 1 "Conn_01x15_Female" H 8250 2650 50  0000 C CNN
F 2 "" H 8550 3450 50  0001 C CNN
F 3 "" H 8550 3450 50  0001 C CNN
	1    8550 3450
	-1   0    0    -1  
$EndComp
Text HLabel 2300 2750 0    60   BiDi ~ 0
GPIO_28
Text HLabel 2300 2850 0    60   BiDi ~ 0
GPIO_29
Text HLabel 2300 2950 0    60   BiDi ~ 0
GPIO_32
Text HLabel 2300 3050 0    60   Output ~ 0
GND
Text HLabel 2300 3150 0    60   BiDi ~ 0
GPIO_31
Text HLabel 2300 3250 0    60   BiDi ~ 0
GPIO_1
Text HLabel 2300 3350 0    60   Input ~ 0
GPI_2
Text HLabel 2300 3450 0    60   Input ~ 0
GPI_3
Text HLabel 2300 3550 0    60   Input ~ 0
GPI_4
Text HLabel 2300 3650 0    60   BiDi ~ 0
GPIO_5
Text HLabel 2300 3750 0    60   Output ~ 0
GND
Text HLabel 2300 3850 0    60   BiDi ~ 0
GPIO_7
Text HLabel 2300 3950 0    60   BiDi ~ 0
GPIO_8
Text HLabel 2300 4150 0    60   Input ~ 0
VCC
Text Notes 1600 4550 0    60   ~ 0
VCC_IO (PIN 14) is coupled to VCC as we use 3.3v for IO
Text HLabel 8950 2750 2    60   Input ~ 0
GPI_34
Text HLabel 8950 2850 2    60   BiDi ~ 0
GPIO_27
Text HLabel 8950 2950 2    60   BiDi ~ 0
GPIO_35
Text HLabel 8950 3050 2    60   Output ~ 0
GND
Text HLabel 8950 3150 2    60   BiDi ~ 0
GPIO_36
Text HLabel 8950 3250 2    60   BiDi ~ 0
GPIO_25
Text HLabel 8950 3350 2    60   BiDi ~ 0
GPIO_24
Text HLabel 8950 3450 2    60   BiDi ~ 0
GPIO_23
Text HLabel 8950 3550 2    60   BiDi ~ 0
GPIO_22
Text HLabel 8950 3650 2    60   BiDi ~ 0
GPIO_21
Text HLabel 8950 3750 2    60   BiDi ~ 0
GPIO_20
Text HLabel 8950 3850 2    60   Input ~ 0
RESET_N
Text HLabel 8950 3950 2    60   BiDi ~ 0
GPIO_18
Text HLabel 8950 4050 2    60   BiDi ~ 0
GPIO_17
Text HLabel 8950 4150 2    60   BiDi ~ 0
GPIO_16
Text Notes 10300 1650 2    197  ~ 0
Sockets to plug-in the NINA-W102 minimal breakout board
$Comp
L Conn_01x15_Female S_J?
U 1 1 5AE71527
P 3150 3450
F 0 "S_J?" H 3150 4250 50  0000 C CNN
F 1 "Conn_01x15_Female" H 3300 2650 50  0000 C CNN
F 2 "" H 3150 3450 50  0001 C CNN
F 3 "" H 3150 3450 50  0001 C CNN
	1    3150 3450
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x15_Female S_J?
U 1 1 5AE715D2
P 8000 3450
F 0 "S_J?" H 8000 4250 50  0000 C CNN
F 1 "Conn_01x15_Female" H 8100 2650 50  0000 C CNN
F 2 "" H 8000 3450 50  0001 C CNN
F 3 "" H 8000 3450 50  0001 C CNN
	1    8000 3450
	-1   0    0    -1  
$EndComp
Wire Wire Line
	2300 2750 2950 2750
Wire Wire Line
	2300 2850 2950 2850
Wire Wire Line
	2300 2950 2950 2950
Wire Wire Line
	2300 3050 2950 3050
Wire Wire Line
	2300 3150 2950 3150
Wire Wire Line
	2300 3250 2950 3250
Wire Wire Line
	2300 3350 2950 3350
Wire Wire Line
	2300 3450 2950 3450
Wire Wire Line
	2300 3550 2950 3550
Wire Wire Line
	2300 3650 2950 3650
Wire Wire Line
	2300 3750 2950 3750
Wire Wire Line
	2300 3850 2950 3850
Wire Wire Line
	2300 3950 2950 3950
Wire Wire Line
	2300 4150 2950 4150
Wire Wire Line
	2350 4050 2950 4050
Wire Wire Line
	2350 4050 2350 4150
Connection ~ 2350 4150
Wire Wire Line
	8200 2750 8950 2750
Wire Wire Line
	8200 2850 8950 2850
Wire Wire Line
	8200 2950 8950 2950
Wire Wire Line
	8200 3050 8950 3050
Wire Wire Line
	8200 3150 8950 3150
Wire Wire Line
	8200 3250 8950 3250
Wire Wire Line
	8200 3350 8950 3350
Wire Wire Line
	8200 3450 8950 3450
Wire Wire Line
	8200 3550 8950 3550
Wire Wire Line
	8200 3650 8950 3650
Wire Wire Line
	8200 3750 8950 3750
Wire Wire Line
	8200 3850 8950 3850
Wire Wire Line
	8200 3950 8950 3950
Wire Wire Line
	8200 4050 8950 4050
Wire Wire Line
	8200 4150 8950 4150
Connection ~ 2450 2750
Connection ~ 2450 2850
Connection ~ 2450 2950
Connection ~ 2450 3050
Connection ~ 2450 3150
Connection ~ 2450 3250
Connection ~ 2450 3350
Connection ~ 2450 3450
Connection ~ 2450 3550
Connection ~ 2450 3650
Connection ~ 2450 3750
Connection ~ 2450 3850
Connection ~ 2450 3950
Connection ~ 2450 4050
Connection ~ 2450 4150
Connection ~ 8750 2750
Connection ~ 8750 2850
Connection ~ 8750 2950
Connection ~ 8750 3050
Connection ~ 8750 3150
Connection ~ 8750 3250
Connection ~ 8750 3350
Connection ~ 8750 3450
Connection ~ 8750 3550
Connection ~ 8750 3650
Connection ~ 8750 3750
Connection ~ 8750 3850
Connection ~ 8750 3950
Connection ~ 8750 4050
Connection ~ 8750 4150
Text Notes 6150 3150 2    60   ~ 0
M_Jx are the module connector\nJx are the shield breakouts
$EndSCHEMATC
