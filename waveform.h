//
// Created by ali_a on 4/8/2026.
//

#ifndef POWERMONITORING_WAVEFORM_H
#define POWERMONITORING_WAVEFORM_H

// create waveform struct
struct WaveformSample {
     double timestamp ;
     double voltageA;
     double voltageB;
     double voltageC;
     double current;
     double frequency;
     double power_factor;
     double thd_percent ;

};
#endif //POWERMONITORING_WAVEFORM_H
