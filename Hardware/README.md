This folder contains hardware descriptions of the 'SubHarmonics' module.

The information is presented as EAGLE 'sch' and 'brd' files for the two PCBs and as a small Kicad project for the front panel.

SubHarmonics is implemented in two modules, each of which has its own PCB. There is a Main Board, hosting the majority of the electronics and
a Control Board, which contains all the front panel components including the division indicator LEDs and associated decoders.

The Main Board schematic is available [here](https://github.com/m0xpd/SubHarmonics/blob/main/Hardware/Main%20Board%20Schematic.png) (or by clicking on the graphic below)

<p align='center' width=100%>

<img width=50%, src="https://github.com/m0xpd/SubHarmonics/blob/main/Hardware/Main%20Board%20Schematic.png">
</p>

The VCO borrows directly from the 'Shapes VCO' design by Moritz Klein, subsequently used in his VCO for the [Erica Synths Edu DIY VCO](https://www.ericasynths.lv/shop/diy-kits-1/edu-diy-vco/). The output of this VCO - or the input from an external 'X' source - is 
applied to the 'Divider_In' input of the SubHarmonic Dividers, the input stages of which form a 0 - 5V pulse signal at X. 

The division is achieved by a pair of CD4015 (Decade counter) and CD4051 (Analog Mux/Demux) in conventional configuration. The divisor is set by 
a PIC microcontroller, which reads a potentiometer or a CV input signal and decodes the voltage (0-5V) into one of 8 settings for the dividers.
A further divide-by-2 stage, implemented in a CD4013 (D-type SR flip-flop) applied to the outputs of the dividers adds another octave of division, 
which implements the divide by 2 on the A channel.

The outputs of the dividers, A and B (and their complements, not_A and not_B) are fed to two modulators, implemented in a quad NOR package (CD4001).

The results of the OR and XOR operations are mixed in a voltaged-controlled mixer, implemented in an LM13700.



