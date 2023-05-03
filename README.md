# SubHarmonics 


'SubHarmonics' is a 12 HP Eurorack module which generates two squarewaves ('A' and 'B') which are sub-harmonics of another signal, 'X'.

<p align="center">
  ![SubHarmonics Front](https://user-images.githubusercontent.com/3152962/235910644-7287523d-f6e4-4646-8f2e-4d9a3b19b405.png)
    <img width="336" height="681" src=("https://user-images.githubusercontent.com/3152962/235910644-7287523d-f6e4-4646-8f2e-4d9a3b19b405.png)/336/681">
</p>


The signal X is either i) generated by the module's internal Voltage Controlled Oscillator or ii) is derived from an external signal applied to the 
module's 'Ext X In' input.

The sub-harmonics are generated by hardware dividers, which divide the frequency of X by integer divisors (m, n) of 2, 4, 6, 10, 12, 14, 16 or 18,
giving the unit a range of a little over four octaves. 

These divisors (m := fX/fA, n := fx/fB) are voltage controlled - they can be set by potentiometers or by control voltages applied from external sources.

It is seen that the signals A and B are themselves related in frequency by 'the ratio of two small integers' (m/n). So, in addition to each being 
sub-harmonics of X, the interval between A and B usually falls at a useful musical interval; 'SubHarmonics' generates harmony as well as bass and
waveforms.

The module also includes a pair of internal modulators, which combine the A and B signals together (through an OR and an Exclusive OR operation). 
The OR modulation is equivalent (for these signals A,B) to simple unbalanced modulation, as performed by (e.g.) an AND gate, whilst the Exclusive OR
modulation implements the balanced modulation of A & B (as in a 'ring modulator'). I described the equivalence of OR and AND gates as modulators for 
the special class of 'antipalindromic' inputs (such as the present A and B signals) at tedious length [here](http://m0xpd.blogspot.com/2023/03/logic-gates-and-modulation-curiosity.html)

The two different modulation results are combined in a crossfader circuit (controlled by a potentiometer or an external CV input) to give a single 
output which offers a choice OR A MIX of the modulation types at the 'Mod Mix' output.

The sub-harmonic generation and all signal processing is performed in hardware. 

A small (PIC) microcontroller is used to read the potentiometers and CV inputs that set the dividers. 

Details of the two PCBs and front panel are provided in the [Hardware](https://github.com/m0xpd/SubHarmonics/tree/main/Hardware) folder. Code for the 16F676 PIC is presented in the Controller folder.

The design is published under the Creative Commons CC BY-SA 4.0 License.  
