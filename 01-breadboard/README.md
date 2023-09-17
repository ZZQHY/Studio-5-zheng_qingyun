# Building an Arduino on a Breadboard

## Assignment's description
This assignment is the first challenge of PCB Studio, lasting for two days. 

Under the guidance of Professor Saverio, we built a Arduino Uno board using basic components on a breadboard and uploaded the "Hello World" program of Arduino: ‘Blink’, causing the LED on the board to blink. 

We also learned some basic coding knowledge, such as digital signals, analog signals, delay, and serial functions.

Next, I will document all these work of the past two days using a ‘tutorial style’.

## Documentation
### Table of Contents:
1. List of components used and their functions
2. Building an Arduino on a Breadboard step by step
3. First code for the board and introduction to Arduino programming

### Component List and Their Functions
* A breadboard
* Atmega328 (Microchip used in various applications such as 3D printers, etc., on the Arduino Uno R3)
* 7805 Voltage regulator (Converts excess voltage into heat through a large heat sink, reducing the voltage to 5V)
* 16 MHz clock crystal (Determines the speed at which the microprocessor program runs)
* 220 Ohm resistor *2 (Reduces current size)
* 10k Ohm resistor
* 10uF capacitor *2 (Functions similar to a battery, in situations where the circuit voltage is unstable, such as voltage fluctuations of 5V that may produce voltages like 4.9V or 5.1V. Stores excess voltage when the voltage is above 5V and discharges it when the voltage is below 5V, compensating for the missing voltage)
* 22pF capacitor *2
* some jumpers

### Building an Arduino on a Breadboard

**STEP 1: Adding Power Circuit**

***1. Regulating the Voltage to 5V***

To ensure the stable operation of the Atmega328 microchip, it is necessary to first build a regulated circuit to reduce the circuit voltage to 5V.

For the power circuit, the voltage fluctuations are significant, so it is important to place large capacitors (10uF) at the input and output of the voltage regulator to ensure the stability of the entire power circuit.

![Explanation of the voltage regulator pinout](./images/voltage_regulator.jpg)

Connect Capacitor 1 to VOUT & GND

![Connect Capacitor 1 to VOUT & GND](./images/capacitor_1_to_VOUT_GND.jpg)

Connect capacitor 2 to VIN & GND

![Connect capacitor 2 to VIN & GND](./images/capacitor_2_to_VIN_GND.jpg)

***2. Expand the power circuit to the left side of the breadboard using jumpers***

![Expand the power circuit to the left side of the breadboard using jumpers](./images/jumpers.jpg)

***3. Add an LED to the power circuit***

In the power circuit, connect an LED as an indicator light when the board is powered on, and quickly check if the circuit board is short-circuited.

The power circuit has a high current, so it is necessary to connect a 220-ohm resistor.

![Connect LED to the circuit](./images/Connect_LED_to_the_circuit.jpg)


**STEP 2: Connecting the ATmega328**

![DIP Pinout](./images/DIP_Pinout.jpg)

***1. Connecting Atmega328 Microcontroller to Power Circuit***

To facilitate uniformity, install the ATmega on the right side at position 11. 

Connect VCC and GND to the positive and negative terminals of the power circuit respectively. 

Connect AREF (analog reference) to the positive terminal. Connect AVCC (VCC) to the positive terminal.

![Atmega Wiring](./images/Atmega_Wiring.jpg)

***2. Adding an external clock to ATmega***

Add an external clock of 16MHz between pins 9 and 10 of the ATmega, connect two 22pF capacitors to the negative terminal.

Use 16MHz crystal oscillator & 22pF capacitors * 2

![Use 16MHz crystal oscillator & 22pF capacitors](./images/crystal_oscillator_and_capacitor.jpg)
![Crystal Oscillator Wiring](./images/Crystal_Oscillator_Wiring.jpg)

***3. Onboard Pin 13***

The Arduino Uno board is equipped with an LED connected to pin 13. It will be used when running the Blink example program later.

![Pin13 LED](./images/Pin13_LED.jpg)


**STEP 3: Connect the USB-serial Connector**

***1. Module Pin Connection Method***

* DTR — Reset
* RXI — TX
* TXO — RX
* VCC — VCC
* CTS — Do not use
* GND — GND

![USB-serial Connector_1](./images/USB_serial_Connector_1.jpg)

![USB-serial Connector_2](./images/USB_serial_Connector_2.jpg)

The computer data transmitted through the USB-serial connector is too fast for ATmega, so it is necessary to connect a capacitor between DTR and Reset to slow down the speed. The capacitor should be of size 0.1uF (micro microfarads).

![capacitor between DTR and Reset](./images/capacitor_between_DTR_and_Reset.jpg)

Arduino Uno board completed!

![Arduino Uno board completed!](./images/Arduino_Uno_board_completed!.jpg)


### First Code for Development Board and Introduction to Arduino Programming

Connect the USB interface to the computer.

Check if the green light is on.

Smell the circuit board for any burnt smell.

Touch it with your hand to see if it's overheating.

Eliminate short circuits and other wiring errors to ensure the circuit is running properly.

1. Select the development board - Arduino Uno.
2. Choose the interface number for connecting to the computer.
3. Load the example program (File-Examples-Basics-Blink).
4. Click on compile and upload, and the LED on pin 13 will blink.

![Coding_1](./images/Coding_1.jpg)

![Coding_2](./images/Coding_2.jpg)

![Coding_3](./images/Coding_3.jpg)

![Lignt Blink](./images/Lignt_Blink.jpg)


