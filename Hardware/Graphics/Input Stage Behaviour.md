# SubHarmonics' X Input Stage behaviour

The pulses applied to the harmonic divider chains is derived from either the internal VCO or the External input 
via the input stage formed of Q4 & Q5, Q6 and IC6C.

These active stages amplify the input and form it into a pulse signal, which is saturated at levels of the +/- 12V 
power rails (at the collectro of Q6) and subsequently half-wave rectified, inverted and attenuated (by D6 and IC6C)
to a pulse a little over 5V.

The Q4, Q5 stage is a stripped-down version of a conventional transistor [Schmitt Trigger](https://en.wikipedia.org/wiki/Schmitt_trigger) stage. 

In this applcation, the stage is required to have high sensitivity (a low value of 'HIGH THRESHOLD'), as the output 
of the VCO is rather small (~1.5 V). Accordingly, a low magnitude of the emitter resistor R19 = 10R was initially 
chosen, which gave a switching threshold of 0.85V.

Unfortunately, this 10R resistor destroys almost all the hysteresis which is the defining property of the Schmitt Trigger.

The images below show the switching behaviour of SubHarmonics with R19 at values of 10R and 470R.

<p width=100%, align="center">
<img src="Original%20Switching%20Labelled.png" width="500"> 
</p>
<p width=100%, align="center">
<img src="Modified%20Switching%20Labelled.png" width="500"> 
</p>

You can see that the 10 Ohm resistor results in swithing (of the  (Blue) output at the same (0.85V) point on the upward 
and downward transistions of the (Cyan) input - i.e. the HIGH and LOW THRESHOLDS are equal and there is no hysteresis.

The 470 Ohm resistor results in switching at 1.4V on upward transitions of the input (HIGH THRESHOLD = 1.4V) whilst swithing
on the downward transition occurs at the lower input voltage of ~1.05V (LOW THRESHOLD = 1.05V). There is now approximatey 
0.35V of hysteresis.

Although it is possible to further increse the emitter resistor magnitude in other applications (and achieve greater hysteresis),
this is won at the expense of still greater increases in the value of HIGH THRESHOLD. I have found that 470R is the greatest 
value that can be used in SubHarmonics in order that the signal from the internal VCO is still detected. 

If we deliberately add 350mV of noise:

<p width=100%, align="center">
<img src="Noise%202.png" width="500"> 
</p>
to the input, the potential benefits of this Schmitt Trigger action become clear.


The modified (R19=470R) circuit operates well in the presence of the noise,

<p width=100%, align="center">
<img src="Modified%20Switching%20in%20Noise%20Labelled.png" width="500"> 
</p>

with nice, clear, regular yransitions of the (Blue) output trace.

However, the circuit in original configuration (R19 = 10R) suffers visible disruption of the (Blue) output 
with the same input
<p width=100%, align="center">
<img src="Original%20Switching%20in%20Same%20Noise%20Labelled.png" width="500"> 
</p>

This can be made to LOOK more dramatic by reducing the input signal (and keeping the noise amplitude the same). 
<p width=100%, align="center">
<img src="Original%20Switching%20in%20Same%20Noise%20Near%20Threshold%20Labelled.png" width="500"> 
</p>

Note that it is not the peak 'signal' to noise ratio that is important; rather it is the THRESHOLD to noise ratio. 
What we did most significantly in the figure above was change the GRADIENT of the input signal around the 
threshold voltage, so we changed the effective timescale; the system spent more time around the decision point
and there was more opportunity for the noise to cause false triggers, which showed up as visible lines on the 'scope.

So, if you build a 'SubHarmonics' module you have a choice.
* you could opt for the original R19 = 10R value, with the best possible input sensitivity (switching threshold = 0.85V), 
but NO Schmitt Trigger action, or
* you could opt for the maximum R19 = 470R value, with a loss of input sensitivity (HIGH THSRESHOLD = 1.4V) and ~0.35V 
Schmitt Trigger 'hysteresis', or
* you could opt for a mid-point compromise.

I have built both versions.

I used the original (R19=10R) for six months and never noticed any problem with noise immunity on the 'Ext X In' input 
which made me wish there was Schmitt Trigger action. However, we are used to having high amplitude, noise-free signals
avaialble from our oscillators, so that's hardly surprising.

On the other hand, now I've added the extra Schmitt Trigger functionality, the same high amplitude oscillator and clock 
signals can still trigger the SubHarmonics input but I get the "extra insurance" of 0.35V of noise immunity at no additional
expense (a 470R resistor is no more expensive than a 10R resistor - or even a wire link!).

So - all things considered - I guess I prefer the revised version with R19 = 470R. You must make your own choice.
 
# Acknowledgement

All this interest in the magnitude of R19 and the reinstatement of Schmitt Trigger action was prompted by a question raised
by Yves Chartier, and subsequent discussion. I am grateful for Yves' valuable contribution and support. 
