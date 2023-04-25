# SubHarmonics 

'SubHarmonics' is a 12 HP Eurorack module which generates two squarewave outputs ('A' and 'B') which are sub-harmonics of another signal, 'X'.

The signal X is either generated by the module's internal Voltage Controlled Oscillator or is an external signal applied to the module's clock input.

The sub-harmonics are generated by hardware dividers, which divide the frequency of X by integer divisors (m, n) of 2, 4, 6, 10, 12, 14, 16 or 18,
giving the unit a range of a little over four octaves. 

These divisors (m := fX/fA, n := fx/fB) can be controlled by potentiometers or by control voltages applied from external sources.

The signals A and B are themselves related in frequency by 'the ratio of two small integers' (m/n). So, in addition to each being sub-harmonics of X, 
the interval between A and B usually falls at a useful musical interval; 'SubHarmonics' generates harmony as well as bass and waveforms!

The module also includes a pair of internal modulators, which combine the A and B signals together (through an OR and an Exclusive OR operation). 
These two different modulation results are combined in a crossfader circuit (controlled by a potentiometer or an external CV input) to give a 
choice OR A MIX of the modulation types at the 'Mod Mix' output.

The sub-harmonic generation and all signal processing is performed in hardware. 
A small (PIC) microcontroller is used to read the potentiometers and CV inputs that set the dividers. 
