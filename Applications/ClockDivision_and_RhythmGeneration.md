If you reduce the frequency of SubHarmonics' VCO or apply a clock signal to the 'Ext X In' from an LFO or similar source,
you enable a range of opportunities in **Clock Division** and **Rhythm Generation**.

## SubHarmonics as a Clock Divider 

The two divider chains of SubHarmonics will offer direct division of the X clock by ratios of:

2, 4, 6, 8, 10, 12, 14 & 16   (for the A output) 

and

4, 6, 8, 10, 12, 14, 16, & 18 (for the B output)

These divisions can be set either by the manual m & n divisor controls or by CV inputs.

Many 'secondary' divisions can be established between A and B outputs. 

For example, with m=2 and n=6 the ratio between X and A is 1:2 and the ratio between X and B is 1:6, 
making the ratio between A and B 2:6 (1:3).

Similarly, other odd integer ratios can be established via this 'secondary' approach, such that all integer ratios up 
to ten can be achieved:

<p width=100%, align="center">
<img width=25%, src="https://github.com/m0xpd/SubHarmonics/assets/3152962/3bf43167-c673-4f93-8707-54ffae79b5f1">
</p>

Similarly, even integer divisions from 10 to 18 can be achieved directly.

## Building Rhythm using SubHarmonics

Given the clock division described above, it is possible to take the divided clock signals and use them to trigger 
percussive sounds, making SubHarmonics a Rhythm Generator. 

The complexity of the rhythms generated is greatly increased if logic operations (AND, OR XOR, etc) are performed between 
the clock signals (X, A & B) to derive more interesting patterns.

Remember that SubHarmonics has it's own pair of internal logic modulators, which combine the A and B signals (through OR 
and XOR functions). These are combined at the 'ModMix' output and can be selected by the 'Mix' control (or by CV). 
This was desiged for use when the ModMix output was interpreted as an 'analog' audio signal (rather than a Boolean switching 
signal). Accorindingly, there are a couple of issues for the present 'Rhythm Generator' application:

1) Signals from the 'ModMix' output are inverted, running from 0 to -3.75V. To use as conventional (positive true) logic 
signals, they must be inverted. I use a Voltage Processor to perform this inversion ('Maths' or any capable processor can 
do the job). You can just shift the level (rather than do an inversion) but this results in a different function - interesting
as it will generate a different pattern and potentially useful if you don't have the resource to do the actual inversion.

2) There is no real meaning in the mixed signals for intermediate settings of the 'Mix' control in this context; the mix 
is only relevant to the output when used in 'analog' applications - so switching between the two modulators is best achieved 
with changes between extreme settings of the 'Mix' control (0 or 5V CV) to give either the XOR or the OR modulator.

The onsequence of changing the Mix control is illustrated in this example:

<p width=100%, align="center">
<img width=75%, src="https://github.com/m0xpd/SubHarmonics/assets/3152962/8604f31f-071f-46c7-b7de-0dbd757d9ca6">
</p>

The 'scope traces show: 
* the X signal (top trace, Yellow)
* the A subharmonic, m=8, (second trace, Cyan)
* the B subharmonic, n=16, (third trace, Blue)
* the Mix output, (bottom trace, Purple)

The left-hand image shows the response with the OR modulator (Mix control fully clockwise or 5V CV Input) and the right-hand 
trace shows the response with the XOR modulator (Mix control fully counter clockwise or 0V CV input).

Finally, AND **MOST IMPORTANTLY**, the two dividers are not locked. This allows you to deliberately change the 'phase' between 
the SubHarmonics A & B. This allows a lot of **additional variation in rhythm generation**.

Change is achieved by intentionally changing the setting of one of the divisors (m or n), which introduces a relative delay 
(or advance, depending upon if you increase of decrease the divisor) relative to the other subharmonic, thereby changing the 
'phase'. 

The process is not deterministic, but you will soon get the feel for it. 

I adjust the largest divisor (i.e. max(m,n)) by one step for a couple of seconds and listen for the result.

There is a video, demonstrating these ideas with two percussion voices, [here](https://youtu.be/6WWO7RoppK4).

You can easily set up a reasonably complex rhythm generator, with triggers from A, B, logical operations on A and B (I like to 
use an external AND gate driven by A and B, occasionally with extra inputs - as there is no AND modulator internal to SubHarmonics) 
and, of course, ModMix. 

You can set up the base pattern with m & n and introduce variation by 
* changing the 'phase' and 
* switching between the internal modulators by applying CV changes to the Mix input.


**SubHarmonics** generates 
* melody, using its VCO,
* bass, using its dividers,
* harmony, using its modulators, and
* rhythm, using the process described above.
