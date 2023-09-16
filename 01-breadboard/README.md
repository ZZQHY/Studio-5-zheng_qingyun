# Building an Arduino on a Breadboard

## Assignment's description
This assignment is the first challenge of PCB Studio, lasting for two days. 

Under the guidance of Professor Saverio, we built a Arduino Uno board using basic components on a breadboard and uploaded the "Hello World" program of Arduino: ‘Blink’, causing the LED on the board to blink. 

We also learned some basic coding knowledge, such as digital signals, analog signals, delay, and serial functions.

Next, I will document all these work of the past two days using a ‘tutorial style’.

## Documentation
### Table of Contents:
* List of components used and their functions
* Building an Arduino on a Breadboard step by step
* First code for the board and introduction to Arduino programming

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

![Explanation of the voltage regulator pinout](./images/example.jpg)


Describe the work you did to complete the assignment

bullet point list
* item one
* item two
* item three

numbered list
1. item one
2. item two
3. item three

**bold text**

*italic text*

***italic and bold text***

example of an external link

[description of the website](https://www.https://www.example.com/)

example of a picture hosted on an external website

![picture description](https://djmag.com/sites/default/files/storyimages/Clara_Rockmore.jpg)

example of a picture hosted inside your repository (don't forget the ./ operand)

![picture description](./images/example.jpg)
