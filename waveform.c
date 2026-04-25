//
// Created by ali_a on 4/8/2026.
//

#include "waveform.h"
#include <math.h>
double rms_calculator( struct WaveformSample * waveformdata , int data_counter , int phase ) {
    double sumValues = 0;
    double Voltage_Value=0;
    // we need for loop
    for ( int i =0 ; i <data_counter; i++) {
        if (phase == 1) //a
        {
            Voltage_Value = (waveformdata +i)->voltageA;
            double square=Voltage_Value*Voltage_Value;
            sumValues=sumValues+square;
        }
        if (phase == 2) //b
        {
            Voltage_Value = (waveformdata +i)->voltageB;
            double square=Voltage_Value*Voltage_Value;
            sumValues=sumValues+square;
        }
        if (phase == 3) //c
        {
            Voltage_Value = (waveformdata +i)->voltageC;
            double square=Voltage_Value*Voltage_Value;
            sumValues=sumValues+square;
        }
    }
    double avg=sumValues/data_counter;
    double rms = sqrt(avg);
    return rms;
}
