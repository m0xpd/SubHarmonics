# SubHarmonics 


'SubHarmonics' is a Eurorack module which generates two squarewaves ('A' and 'B') which are sub-harmonics of another signal, 'X'.

<p width=100%, align="center">
<img width=25%, src="https://user-images.githubusercontent.com/3152962/235910644-7287523d-f6e4-4646-8f2e-4d9a3b19b405.png">
</p>


The signal X is either i) generated by the module's internal Voltage Controlled Oscillator or ii) is derived from an external signal applied to the 
module's 'Ext X In' input.

The sub-harmonics are generated by hardware dividers, which divide the frequency of X by integer divisors (m, n) of 2, 4, 6, 8, 10, 12, 14, 16 or 18,
giving the unit a range of a little over four octaves (18 ≈ 2 <sup> 4.17 </sup> ). 

These divisors (m := f <sub> x </sub> / f <sub> A </sub>, n := f <sub> x </sub> / f <sub> B </sub>) are voltage controlled - they can be set by potentiometers or by control voltages applied from external sources.

It is seen that the signals A and B are themselves related in frequency by 'the ratio of two small integers' (m/n). So, in addition to each being 
sub-harmonics of X, the interval between A and B usually falls at a useful musical interval; 
<p align="center">
'SubHarmonics' generates harmony as well as bass and waveforms.
</p>

### Internal Modulators

SubHarmonics also includes a pair of internal modulators, which combine the A and B signals together (through an OR and an Exclusive OR operation) to
exploit and develop the harmonic relationship between A and B into a richer sound. The OR modulation is equivalent (for these signals A, B) to simple
amplitude modulation, as performed by (e.g.) an AND gate, whilst the Exclusive OR modulation implements the balanced modulation of A with B (as in a 
'ring modulator'). I described the equivalence of OR and AND gates as modulators for the special class of 'antipalindromic' inputs (such as the present 
A and B signals) at tedious length [here.](http://m0xpd.blogspot.com/2023/03/logic-gates-and-modulation-curiosity.html)

The two different modulation results are combined in a voltage-controlled crossfader circuit (controlled by a potentiometer or an external CV input) 
to give a single output which offers a choice OR A MIX of the modulation types at the 'Mod Mix' output.

### Setup

There are two presets that need adjustment on completion of the module to commision and setup for use. Both are located on the topside of the Main Board.

TR2 (a multi-turn 1k preset) controls the 1V/Octave tracking. It should be set by connecting the module to a reliable source of pitch CV signals and monitoring the outputs. I use octave outputs from a BeatStep Pro - you can use a keyboard with CV pitch outputs or simply a known voltage source - and listen to the pitch change. I find it easy to tune octaves by ear but, if you are uncertain, use a tuner or frequency counter.

TR1 (a single turn 100k preset) controls the balance of the modulation mix crossfader. To set it properly requires access to an oscilloscope to see the 'Mod Mix' output waveform.

Set the divisors to m=2, n=6 using the front panel controls and the frequency to an arbitrary value (around 300Hz). View the 'A' and 'Mod Mix' outputs. Adjust TR1 until you see these waveforms at the extreme ends of the Mix control:

<p align="center", width=100%>
<img width=70%, src="https://user-images.githubusercontent.com/3152962/236217616-001e9e9f-921f-4f88-9135-332b86309243.png">
</p>

(the yellow trace is the 'A' output, which stays the same in this setup process, the blue trace is the 'Mod Mix' output, which will change when you adjust TR1)

Note that the 'Mod Mix' output is inverted (it runs 0 to approx -4V); there wasn't a spare op-amp stage to restore polarity after the crossfader. 
This doesn't matter in ordinary applications; the ear is insensitive to the inversion and it will sound the same!


### Miscellaneous Details

The sub-harmonic generation and all signal processing is performed in hardware. 

A small (PIC) microcontroller is used to read the potentiometers and CV inputs and set the dividers. 

Details of the two PCBs and front panel are provided in the [Hardware](https://github.com/m0xpd/SubHarmonics/tree/main/Hardware) folder. Code for 
the 16F676 PIC is presented in the [Controller](https://github.com/m0xpd/SubHarmonics/tree/main/Controller) folder.

SubHarmonics is:  
12HP wide,   
requires 38mm behind the front panel (with the power header fitted) and  
draws 13.5mA from the 12V rail and 5mA from the -12V rail.  

The design is published under a Creative Commons CC BY-SA 4.0 [License](https://github.com/m0xpd/SubHarmonics/blob/main/LICENSE.txt).  
