SubHarmonics' X Input Stage behaviour

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
<img height="100",src="Original%20Switching%20Labelled.png" &nbsp &nbsp &nbsp &nbsp <img height="100", src="Modified%20Switching%20Labelled.png">, height="400"> 
</p>

