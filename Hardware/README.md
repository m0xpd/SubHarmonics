# Hardware
This folder contains hardware descriptions of the 'SubHarmonics' module.

The information is presented as EAGLE 'sch' and 'brd' files for the two PCBs and as a small Kicad project for the front panel.

SubHarmonics is implemented in two modules, each of which has its own PCB. There is a Main Board, hosting the majority of the electronics and
a Control Board, which contains all the front panel components including the division indicator LEDs and associated decoders.

## Main Board Description

The Main Board schematic is available [here](https://github.com/m0xpd/SubHarmonics/blob/main/Hardware/Main%20Board%20Schematic.png) (or by clicking on the graphic below)

<p align='center' width=100%>

<img width=50%, src="https://github.com/m0xpd/SubHarmonics/blob/main/Hardware/Main%20Board%20Schematic.png">
</p>

The VCO borrows directly from the ['Shapes VCO' design by Moritz Klein](https://www.youtube.com/watch?v=QBatvo8bCa4), subsequently used in his VCO for the [Erica Synths Edu DIY VCO](https://www.ericasynths.lv/shop/diy-kits-1/edu-diy-vco/). The output of this VCO - or the input from an external 'X' source - is 
applied to the 'Divider_In' input of the SubHarmonic Dividers, the input stages of which provide a 0 : 5V pulse at node 'X'. 

The division is achieved by a pair of CD4015 (Decade counter) and CD4051 (Analog Mux/Demux) in conventional configuration. The divisor is set by 
a PIC microcontroller, which reads a potentiometer or a CV input signal and decodes the voltage (0-5V) into one of 8 settings for the dividers.
A further divide-by-2 stage, implemented in a CD4013 (D-type SR flip-flop) applied to the outputs of the dividers adds another octave of division, 
which completes the divide by 2 on the A channel.

The outputs of the dividers, A and B (and their complements, not_A and not_B) are fed to two modulators, implemented in a quad NOR package (CD4001).

The results of the OR and XOR operations are mixed in a voltaged-controlled crossfader, implemented in an LM13700.

The Main Board includes an In-Circuit Serial Programming (ICSP) interface to facilitate programming the PIC (JP1).

## Control Board Description

The Control Board schematic is available [here](https://github.com/m0xpd/SubHarmonics/blob/main/Hardware/Control%20Board%20Schematic.png) (or by clicking on the graphic below)
<p align='center' width=100%>

<img width=50%, src="https://github.com/m0xpd/SubHarmonics/blob/main/Hardware/Control%20Board%20Schematic.png">
</p>

In addition to controls, inputs and outputs, the Control Board hosts the division indicator LEDs and decoders to control these (which again use 
CD4051 analog demuxers).

As well as to CV inputs for Pitch and FM, there are CV inputs for the divisors m and n and for the modulation mix. These last three are designed 
to operate over a range of 0 to 5V, but are protected such that voltages outside these limits will cause no damage.

A 0V input on the modulation mix CV input gives the XOR modulation and a 5V input gives the OR modulation (which is spectrally richer, as it includes the
harmonics of A and B as well as the sum and difference harmonics). An intermediate control voltage gives a mix of both modulation types.

The Main and Control boards are joined by two 20-way 0.1 inch pitch headers. These have been specified with electrical redundancy (several pins are 
unused) to provide mechanical stability and security in assembling the module.



