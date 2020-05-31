# BiquadFilter

A C++ implementation of (Audio EQ Cookbok)[https://www.w3.org/2011/audio/audio-eq-cookbook.html].

## Usage

```cpp
#include "Biquad.h"
#include <cmath> // not required

double fs = 44100; // sample rate
double f0 = 1000; // center (cutoff) frequency
double Q = 1 / std::sqrt(2);

// dbGain parameter is required in Peaking, LowShelf, HighShelf
Biquad filter(FilterType::Lowpass, fs, f0, Q);

// calculate output sample in processing loop
for (int i = 0; i < numSample; i++) 
    double sample = filter.process(buffer[i])
```