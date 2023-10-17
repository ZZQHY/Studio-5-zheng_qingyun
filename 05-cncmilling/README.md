# PCB CNC

## Assignment's description
The goal of this task is to create a PCB version of the Arduino board previously built on a breadboard. 
The PCB design will be done using the "EasyEDA PRO" software, and it will be manufactured using the equipment at Fablab.

## PCB board engineering file viewing link:
[engineering file](https://u.easyeda.com/join?type=project&key=bdde3c9b475a499182a6a5fae1e3300d&inviter=d313de78c2a041daaf8b2a6d9e7369b5)

## Documentation
This software that is being used is an online tool, with the URL: 
[software](https://pro.easyeda.com/editor)

This software has a rich component library and a simple interface.

First, we need to search for components in the component library and place them in the interface.

![1](./images/1.jpg)

Place ATmega328 by selecting "Components" in the toolbar, shortcut: Shift+F.

To manipulate the interface, use the spacebar to rotate the components and the middle mouse button to move the interface.

![2](./images/2.jpg)

Next, follow the method previously used to build Arduino on a breadboard to gradually complete the placement and connection of the components.

First, connect the power 5V and ground GND. They are not physical components, but they are necessary when designing the PCB.

![3](./images/3.jpg)

Next, the GND, AREF, and AVCC on the right side need to be connected to power and ground.

AREF interface is used for connecting the reference voltage. If we need to connect a 24V sensor, but Arduino's voltage is only 5V, the range of analog and digital signals it can transmit is only 0-5V. 

In order for the 24V sensor to work properly, we need to provide a 24V reference to AREF.

However, in this case, we don't need to do that because most of the sensors we use are 5V. Therefore, we can merge it with AVCC and connect them to +5V.

GND should be connected to GND.

Here, to keep the wiring organized, we can directly name the connections.

![4](./images/4.jpg)

Through hole component —— DIP

Surface mount component —— SMD

Through-hole component means that even though there are no physical connections, they still need to be connected during the later routing process.

Next, we will select other components. Due to the large number of components, we need to filter them using appropriate methods. 

The left side is the component category, and the upper right section shows different specifications of components within the same category.

Different packaging methods represent different installation methods. To differentiate between the two, we will use SMD (Surface Mount Device) for this project instead of DIP (Dual In-line Package).

![5](./images/5.jpg)

Search and filter for a 16MHz crystal oscillator with an SMD package in the component library. 

Place it on the interface along with a 22pF capacitor to be used in conjunction with the crystal oscillator.

![6](./images/6.jpg)

![7](./images/7.jpg)

Please place the crystal oscillator as close as possible to the ATmega, and connect it to pins 9 and 10 of the Mega. Then, connect a 22pF capacitor to ground.

![8](./images/8.jpg)

Next, connect the onboard LED for the power indicator and pin 13. The power indicator LED should be directly connected to the power circuit and should be in series with a 499Ω resistor. 

The other LED should have its positive terminal connected to pin 13, which is pin 19 of the ATmega. Please note that the package size for the components is 1206. 1206 means that the size is 1.206 inches = 3.06mm.

![9](./images/9.jpg)

![10](./images/10.jpg)

![11](./images/11.jpg)

Next, provide a stable voltage capacitor for the power circuit. For the power circuit, use a large capacitor of 10uF, and for signal transmission, use a small capacitor of 0.1uF.

![12](./images/12.jpg)

Add power circuit: Connect the DC power interface to the power regulator. The power circuit needs to use a large capacitor of 10uF for voltage stabilization.

![13](./images/13.jpg)

Power regulator packaging: SOT223 package

![14](./images/14.jpg)

Many times, we do not fully understand the usage of every component, and we need to refer to the datasheet of the component for guidance. The datasheet provides information on various attributes. Below is the datasheet for the voltage regulator.

![15](./images/15.jpg)

![16](./images/16.jpg)

Next, we need to reserve interfaces for communication between the PCB board and the computer. Here, following our previous experience of building Arduino on a breadboard, we will name these rows of pins.

![17](./images/17.jpg)

In order to facilitate the use of the PCB board, it is necessary to arrange the pins of the ATmega according to our defined way. Set a row of analog interfaces A0-A5.

![18](./images/18.jpg)

RX TX can transmit signals to the computer when necessary. PIN2-PIN13 are digital interfaces.

![19](./images/19.jpg)

When encountering a situation where multiple formations need to be named in bulk, we can use the "Bulk Rename" tool to name the formations in bulk.

![20](./images/20.jpg)

When we have completed the above tasks, we will obtain a complete Schematic. Click on "Convert Schematic to PCB" to see the "Confirm Import Information" prompt. After clicking on Apply Changes, the PCB interface will appear.

![21](./images/21.jpg)

![22](./images/22.jpg)

![23](./images/23.jpg)

If converted to 3D mode, we can preview the effect of the PCB.

![24](./images/24.jpg)

Next, we need to set the packaging method, as the PCBs made in FabLab are single-layer boards, we will intelligently choose the SMD packaging method.

![25](./images/25.jpg)

And in order to facilitate subsequent welding, we need to enlarge the welding disc. After entering the component interface, press the motor pen-shaped button to enter the edit page.

![26](./images/26.jpg)

Complete modifications in size.

![27](./images/27.jpg)

ATmega and other pins operate in the same way.

![28](./images/28.jpg)

![29](./images/29.jpg)

Next, we need to arrange and connect the scattered components. First, place them according to the design of the PCB board, making the interfaces easy to use and the connections logical.

![30](./images/30.jpg)

Next, before proceeding with the connections, we need to establish design rules. Due to the limitations in accuracy of the PCB fabrication equipment, we need to set spacing parameters. The following settings are based on FabLab's equipment.

![31](./images/31.jpg)

![32](./images/32.jpg)

![33](./images/33.jpg)


Before the wiring, we need to do some design to make the PCB board more user-friendly.

1. Add GND and VCC pins and place them together with the data interface.
2. Add a switch in the power circuit for easier debugging and use in the future.
3. Drill a few holes on the board for easy fixing during subsequent use.
4. Thicken the wiring of the power circuit to ensure a more stable power supply for the PCB.

![34](./images/34.jpg)

During the process of routing, there may be problems with the crossing of lines. Since we are using single-layer boards, we can only solve this issue through the design of the routing. When faced with situations that cannot be resolved, we can consider the following methods:

Method 1: Adding jumpers to connect the lines.

Method 2: Adding a 0Ω resistor to act as a wire.

![35](./images/35.jpg)

When designing PCB boards, it is important to note that not all interfaces of ATmega are necessary to use. However, there are some interfaces that are essential to ensure better usability in the future.

![36](./images/36.jpg)

*RX and TX are needed for data transmission.
*SCL and SDA are necessary because some sensors require them.
*PWM pins: fake ana ana write can be used as analog outputs.

The outer frame of the PCB board can be drawn in Rhino and imported. Once all the work is completed, we will obtain a file like this.

![37](./images/37.jpg)


Next, you need to export the file for cutting.

Select the top layer, board layer, and hole layer in the selection layer. You can choose PDF or PNG as the export format.

![38](./images/38.png)

The exported image is in black and white. White represents the retained copper layer, while black represents the areas that will be cut and removed.

![39](./images/39.png)

Next step: Use this online tool to generate the processing file, tool link: [modsproject.org](http://modsproject.org/)

This is a node-based software, similar to Grasshopper.

![40](./images/40.png)

![41](./images/41.png)

Software operation is as follows:

### First step: Export internal paths

1. Start with a blank interface. Right-click on the interface and then click on "programs".

![42](./images/42.png)

![43](./images/43.png)

2. Select "open program" and then choose "PCB".

![44](./images/44.png)

![45](./images/45.png)

3. Next, import the black and white PNG image (or SVG).
   
Here, it is important to pay attention to the size of the imported image, such as 58*67mm, and compare it with the size in the software before exporting.

Before importing the image, it needs to be processed in AI (or other graphic software) to remove the border, with a resolution of 1000ppi.

![46](./images/46.png)

![47](./images/47.png)

![48](./images/48.png)

![49](./images/49.png)

4. Next, we need to set the size of the tool head. For cutting the inner traces, use 1/64 inch, and for cutting the outer frame and holes, use 1/32 inch.

Additionally, the cutting depth here is set to 0.15mm in order to remove the surface copper coating.

![50](./images/50.png)

![51](./images/51.png)

Meaning of several data

![52](./images/52.png)

5. The default value of 10 for "origin" is intended to protect the machine, but it is not necessary here, so all the values will be set to 0.

![53](./images/53.png)

6. When exporting, select the switch below.

![54](./images/54.png)

![55](./images/55.png)

### Second Step: Exporting Hole Layer

1. Process in AI by removing the black background to obtain the hole layer. Use the same method to select and export.

![56](./images/56.png)

![57](./images/57.png)

![58](./images/58.png)

Please note that the imported image dimensions have changed and need to be reprocessed.

![59](./images/59.png)

To ensure the correct size, please make sure to check "Use Artboards" when exporting and importing.

![60](./images/60.png)

![61](./images/61.png)

2. The tool size for the cavity needs to be selected as 1/32. Clicking this button will cause the subsequent data to change accordingly.

![62](./images/62.png)

![63](./images/63.png)

3. Similarly, modify the data here to 0.
Repeat the previous method, then click export, and the image viewed should be correct as shown in the figure.

![64](./images/64.png)

![65](./images/65.png)

![66](./images/66.png)

### Third Step: Exporting the box layer

1. In AI, draw a black layer and a white layer. Subtract the layers above by 2, and you will obtain the box layer.

![67](./images/67.png)

![68](./images/68.png)

2. Click on this boolean mode to check if the outer frame and the interior are too close.

![69](./images/69.png)

![70](./images/70.png)

You can also directly set it in the software before exporting.

![71](./images/71.png)

3. After obtaining the correct cut diagram, select "Export" and repeat all the previous steps to obtain the wiring file for the outer frame.

![72](./images/72.png)

![73](./images/73.png)

![74](./images/74.png)

![75](./images/75.png)

![76](./images/76.png)

Finally, obtain these three files and remember to import them into the device for manufacturing.

![77](./images/77.png)

If you need to cut out characters on the board, you need to use a small circle for inspection.

![78](./images/78.png)

![79](./images/79.png)

## The manufacturing process with the Roland milling machine

Preparation Steps: Place the board with a copper layer on the cutting table, ensuring it is absolutely flat. Switch to topology and use specialized tools to remove the original head and replace it with a 1/64 head. Before replacement, use a magnifying glass to inspect the head for any damages.

Step 1: Create a folder on your computer with your own name and place your three files in it:

* The frame
* The hole layer
* Traces

Step 2: Plan the approximate cutting positions on the board and set the X and Y coordinates. Then, manually loosen the drill bit and press it down against the copper layer near the middle. Tighten the screw and set the Z. Once done, move the Z upwards.

Step 3: Click on CUT, upload the files. Start by uploading Traces and adjust the speed slowly for observation. Keep the mouse cursor on PAUSE to quickly react in case any problems arise.

Step 4: Verify that everything is correct and wait for the cutting to complete.

Step 5: Change the cutter head to 1/32 size and repeat the above steps to cut the hole layer and the frame.

![80](./images/80.png)

![81](./images/81.png)

Subsequent steps: After cutting, use a vacuum cleaner to clean up the cutting waste. Use a tool to remove the cut board, peel off the double-sided adhesive on the back, and polish the side with a copper layer.

Next, prepare for soldering. Use a soldering iron to solder various electronic components onto the board as needed.

![82](./images/82.png)

![83](./images/83.png)
