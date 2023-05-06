# Controller Code for SubHarmonics

Code for the PIC 16F676 microcontroller is found [here.](https://github.com/m0xpd/SubHarmonics/blob/main/Controller/Divide_Controller.c)

It was developed in C in Microchip's [MPLAB IDE](https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide).

The [code](https://github.com/m0xpd/SubHarmonics/blob/main/Controller/Divide_Controller.c) should be placed within an MPLAB project for the 16F676, built and programmed into the device using a suitable programmer.

I programmed the first PIC using my [PICKit 3](https://www.microchip.com/en-us/development-tool/PG164130) and my old [k1el PIC Programming Adapter](https://hamcrafters2.com/PICPGM.html), but I designed an In-Circuit Serial Programming 
Interface into the SubHarmonics Main Board, so you can program directly on the module:
<p align='center', width=100%>
<img width=40%, src="https://user-images.githubusercontent.com/3152962/236197306-bf2e7ddb-bf9c-495e-948b-5d6adda1a3b3.png">
</p>

The PICKit3 supplies easily enough current to power the module; no special setting or modifications needs to be made to the module during programming.

I will try to post a complete MPLAB project (rather than just the C code) and a .hex file in this repository once I've figured out how to do it.
