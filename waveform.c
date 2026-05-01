//
// Created by ali_a on 4/8/2026.
//

#include "waveform.h"
#include <math.h>
#include <stdio.h>

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

double voltage_peak_peak_calculator( struct WaveformSample * waveformdata , int data_counter , int phase ) {
    int max = 0 ;
    int min  = 0 ;
    double Voltage_Value=0;
    double vpp=0;
    for ( int i =1 ; i <data_counter ; i++) {
        if (phase == 1) //a
        {
            Voltage_Value = (waveformdata +i)->voltageA;
            if (Voltage_Value > (waveformdata+max)->voltageA ) {
                max=i;//update max value pos
            }
            if (Voltage_Value < (waveformdata+min)->voltageA ) {
                min=i;
            }
             vpp = (waveformdata+max)->voltageA - (waveformdata+min)->voltageA;
        }
        if (phase == 2) //b
        {
            Voltage_Value = (waveformdata +i)->voltageB;
            if (Voltage_Value > (waveformdata+max)->voltageB ) {
                max=i;
            }
            if (Voltage_Value < (waveformdata+min)->voltageB ) {
                min=i;
            }
            vpp = (waveformdata+max)->voltageB - (waveformdata+min)->voltageB;
        }
        if (phase == 3) //c
        {
            Voltage_Value = (waveformdata +i)->voltageC;
            if (Voltage_Value > (waveformdata+max)->voltageC ) {
                max=i;
            }
            if (Voltage_Value < (waveformdata+min)->voltageC ) {
                min=i;
            }
            vpp = (waveformdata+max)->voltageC - (waveformdata+min)->voltageC;
        }
    }
    return vpp;

}

double dc_offset_calculator( struct WaveformSample * waveformdata , int data_counter, int phase ) {
    double sumValues = 0;
    double Voltage_Value=0;
    for (int i = 0 ; i <data_counter ; i++) {
        if (phase == 1) //a
        {
            Voltage_Value = (waveformdata +i)->voltageA;
            sumValues=sumValues+Voltage_Value;
        }
        if (phase == 2) //b
        {
            Voltage_Value = (waveformdata +i)->voltageB;
            sumValues=sumValues+Voltage_Value;
        }
        if (phase == 3) //c
        {
            Voltage_Value = (waveformdata +i)->voltageC;
            sumValues=sumValues+Voltage_Value;
        }
    }
    return sumValues/data_counter;//dc offset
}

int detect_clipping( struct WaveformSample * waveformdata , int data_counter, int phase ) {
    int clippings=0;
    double Voltage_Value=0;
    for (int i = 0 ; i <data_counter ; i++) {
        if (phase == 1) //a
        {
            Voltage_Value = (waveformdata + i)->voltageA;
            if (  fabs(Voltage_Value) >= 324.9) {
                clippings++;
            }

        }
        if (phase == 2) //b
        {
            Voltage_Value = (waveformdata +i)->voltageB;
            if (fabs(Voltage_Value) >= 324.9) {
                clippings++;
            }

        }
        if (phase == 3) //c
        {
            Voltage_Value = (waveformdata +i)->voltageC;
            if (fabs(Voltage_Value) >= 324.9) {
                clippings++;
            }

        }

    }
    return clippings;
}
char checkRmsTolerance(double rms) {
    if (rms > 206 && rms < 254)
        return 'y' ; //within correct limit
    else
        return 'n';// no in correct limit
}