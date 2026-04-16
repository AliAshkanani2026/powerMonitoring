//
// Created by ali_a on 4/8/2026.
//

#ifndef POWERMONITORING_WAVEFORM_H
#define POWERMONITORING_WAVEFORM_H

// create waveform struct
struct WaveformSample {
     double time ;
     double voltageA;
     double voltageB;
     double voltageC;
     double current;
     double freq;
     double factor;
     double percent ;
};
#endif //POWERMONITORING_WAVEFORM_H

