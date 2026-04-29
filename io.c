//
// Created by ali_a on 4/8/2026.
//

#include "io.h"

#include <stdio.h>
#include <stdlib.h>
#include "waveform.h"
 struct WaveformSample * readFile(char * filename , int *data_count) {
    FILE * fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {// file not valid
        printf("Error opening file invlaid file name\n");
    }
    char data_line[500];
    int numberOfLines=0;

    fgets (data_line,500,fp);

    while (fgets (data_line,500,fp)) {
        numberOfLines++;
    }
     printf("Number of lines read %d\n", numberOfLines);
    *data_count = numberOfLines; //update number of lines in main function


    struct WaveformSample * waveform = malloc(numberOfLines * sizeof(struct WaveformSample));

    rewind(fp);

    fgets (data_line,500,fp);

    int i=0;
    while (fgets (data_line,500,fp)) {
        sscanf(data_line ,
            "%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",
            &waveform[i].time,&waveform[i].voltageA,&waveform[i].voltageB,&waveform[i].voltageC,&waveform[i].current,&waveform[i].freq,&waveform[i].factor,&waveform[i].percent);
       // printf(" time : %lf - VoltA %lf \n ",waveform[i].time , waveform[i].voltageA);
        i++;

    }
    fclose(fp);
}
