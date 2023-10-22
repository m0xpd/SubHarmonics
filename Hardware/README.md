# Hardware
This folder contains hardware descriptions of the 'SubHarmonics' module.

The information is presented as EAGLE 'sch' and 'brd' files for the two PCBs (in the [PCBs folder](https://github.com/m0xpd/SubHarmonics/tree/main/Hardware/PCBs) ) and as a small Kicad project for the front panel (in
the FrontPanel folder).

SubHarmonics is implemented in two modules, each of which has its own PCB. There is a Main Board, hosting the majority of the electronics and
a Control Board, which contains all the front panel components including the division indicator LEDs and associated decoders.

## Main Board Description

The Main Board schematic is available [here](https://github.com/m0xpd/SubHarmonics/blob/main/Hardware/SubHarmonics%20Main%20Board%20Schematic%20v2.png) (or by clicking on the graphic below)

<p align='center' width=100%>

<img width=50%, src="https://github.com/m0xpd/SubHarmonics/blob/main/Hardware/SubHarmonics%20Main%20Board%20Schematic%20v2.png">
</p>

The VCO was inspired by the ['Shapes VCO' design by Moritz Klein](https://www.youtube.com/watch?v=QBatvo8bCa4), subsequently used in his VCO for the [Erica Synths Edu DIY VCO](https://www.ericasynths.lv/shop/diy-kits-1/edu-diy-vco/). Since developing 'SubHarmonics', I have learned that the core of the 40106 VCO was not a Klein original, but had been proposed earlier by Mark Shaner (a.k.a. "Synthmonger"), who published the idea [here](https://electro-music.com/forum/topic-28799.html) back in 2008.

The output of this 'Shaner' 40106 VCO - or the input from an external 'X' source - is applied to the 'Divider_In' input of the SubHarmonic Dividers, the input stages of which provide a 0 : 5V pulse at node 'X'. 

The system was designed around 'available materials' I found lying around my bench - in this case, mainly CD4000-series CMOS logic devices. 

The divisions in each of the two channels are achieved by a CD4015 (Decade counter) and a CD4051 (Analog Mux/Demux) in conventional 
configuration. The divisor is set by a PIC microcontroller, which reads a potentiometer or a CV input signal and decodes the voltage (0-5V) into 
one-of-8 settings for the dividers.

A further divide-by-2 stage, implemented in a CD4013 (D-type SR flip-flop) applied to the outputs of the dividers adds another octave of division 
(necessary to implement the m=2 setting on the A channel).

The outputs of the dividers, A and B (and their complements, not_A and not_B) are fed to two modulators, implemented in a quad NOR package (CD4001).

The results of the OR and XOR operations are mixed in a voltage-controlled crossfader, implemented in half an LM13700.

The [schematic](https://github.com/m0xpd/SubHarmonics/blob/main/Hardware/SubHarmonics%20Main%20Board%20Schematic%20v2.png) and [BoM](https://github.com/m0xpd/SubHarmonics/blob/main/Hardware/PCBs/SubHarmonics%20Main%20Board%20BoM%20v2.txt) show LM324 quad op-amps. These work fine in this application, but you can substitute the ubiquitous TL074 if you prefer. 

The Main Board includes an In-Circuit Serial Programming (ICSP) interface (JP1) to facilitate programming the PIC.

There is a [.sch](https://github.com/m0xpd/SubHarmonics/blob/main/Hardware/PCBs/SubHarmonics%20Main%20Board%20v2.sch) file, a [.brd](https://github.com/m0xpd/SubHarmonics/blob/main/Hardware/PCBs/SubHarmonics%20Main%20Board%20v2.brd) file and a [BoM](https://github.com/m0xpd/SubHarmonics/blob/main/Hardware/PCBs/SubHarmonics%20Main%20Board%20BoM%20v2.txt) for the Main Board in EAGLE format in the [PCBs folder](https://github.com/m0xpd/SubHarmonics/tree/main/Hardware/PCBs).

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

There is a [.sch](https://github.com/m0xpd/SubHarmonics/blob/main/Hardware/PCBs/SubHarmonics%20Control%20Board%20v1.sch) file, a [.brd](https://github.com/m0xpd/SubHarmonics/blob/main/Hardware/PCBs/SubHarmonics%20Control%20Board%20v1.brd) file and a [BoM](https://github.com/m0xpd/SubHarmonics/blob/main/Hardware/PCBs/SubHarmonics%20Control%20Board%20v1%20BoM.txt) for the Control Board in EAGLE format in the [PCBs folder.](https://github.com/m0xpd/SubHarmonics/tree/main/Hardware/PCBs)

The Main and Control boards are joined by two 20-way 0.1 inch pitch headers. These have been specified with electrical redundancy (several pins are 
unused) to provide mechanical stability and security in assembling the module.


The completed PCBs are seen in the photo below, which shows the Main Board from both sides and the Control Board from the 'top' side (the front panel 
components all are mounted on the 'bottom' side).
<p align='center' width=100%>

<img width=50%, src="https://user-images.githubusercontent.com/3152962/235960049-b15abeac-16ee-4c4c-b2ca-04724a21f90d.png">

</p>
 
## Front Panel

<p align='center' width=100%>
<img width=30% alt="SubHarmonics Front Panel" src="https://user-images.githubusercontent.com/3152962/236173525-1e971dc4-d22e-4279-936f-0c3533a29177.png">

</p>

A simple Kicad project defining a Front Panel for the module is available in the [FrontPanel folder.](https://github.com/m0xpd/SubHarmonics/tree/main/Hardware/FrontPanel) 
