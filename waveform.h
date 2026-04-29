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

double rms_calculator( struct WaveformSample * waveformdata , int data_counter , int phase );
double voltage_peak_peak_calculator( struct WaveformSample * waveformdata , int data_counter , int phase );
double dc_offset_calculator( struct WaveformSample * waveformdata , int data_counter, int phase );
int detect_clipping( struct WaveformSample * waveformdata , int data_counter, int phase );
#endif //POWERMONITORING_WAVEFORM_H

