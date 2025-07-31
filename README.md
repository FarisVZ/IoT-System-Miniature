# IoT-System-Miniature

 <br>

## Project Timeline

- **Project completed:** September 2024
- **Repository created:** July 2025

 <br>

## Description

This device is one of the project assigned by the school to design and build a IoT Based Device and demonstrate it **Check [Presentation](/Presentation/) to see the presentation file(PDF), it include Indonesia(original) and English version**. The final product is a replica house with three rooms, each equipped with LEDs act as smart lamps that can be controlled separately via an app, in this case using Arduino Cloud. The device is built using an ESP32 microcontroller as an main brigde to enable wireless communication between the LEDs and Arduino Cloud.

![Front View](/Photo/LookFront1.jpg)
_Front view miniature_

 <br>

![Back View](/Photo/LookBack1.jpg)
_Back view miniature_

 <br>

## Component

- **ESP32 Microcontroller**
- **LED (red) 3x**
- **Resistor 1K ohm**
- **LM2596 (5V DC-DC Stepdown)**
- **9V Battery**
- **Switch**
- **PCB Hole**
- **Jumper Wire**

<br>

## Wiring Diagram

![Wiring](/Photo/Wiring.jpg)


> Black wire mean Gnd/(-) and red wire mean Vcc/(+), Unless LEDs red wire it connect to ESP32 GPIO pin as shown in the table below.

| Component | ESP32 Pin |
| :-------- | :-------: |
| LED-1     |    D19    |
| LED-2     |    D22    |
| LED-3     |    D23    |


Check [this link](/Photo/Schematic.png) or go to `Photo/` folder to check the schematic for this project.

<br>

## Code

The source code for this project can be found in [this link](/Code/HouseMini.ino) or in the `Code/` folder.
