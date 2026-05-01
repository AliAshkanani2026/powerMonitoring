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
     return waveform;
}

void ExportResultToFile(char * filename , struct WaveformSample * waveformdata,int data_counter) {
     FILE * fp;
     fp = fopen(filename, "w"); // in write mode
     if (fp == NULL) {// file not valid
         printf("Error opening file invlaid file name\n");
     }
     //compute metrics values rms , vpp , dc offset , clipping and tolerance
     double RMS_A_voltage = rms_calculator(waveformdata,data_counter,1);
     double RMS_B_voltage = rms_calculator(waveformdata,data_counter,2);
     double RMS_C_voltage = rms_calculator(waveformdata,data_counter,3);

     fprintf(fp,"RMS_A_voltage = %lf  \n",RMS_A_voltage);
     fprintf(fp,"RMS_B_voltage = %lf  \n",RMS_B_voltage);
     fprintf(fp,"RMS_C_voltage = %lf  \n",RMS_C_voltage);

     double VPP_A_voltage = voltage_peak_peak_calculator(waveformdata,data_counter,1);
     double VPP_B_voltage = voltage_peak_peak_calculator(waveformdata,data_counter,2);
     double VPP_C_voltage = voltage_peak_peak_calculator(waveformdata,data_counter,3);

     fprintf(fp,"VPP_A_voltage = %lf  \n",VPP_A_voltage);
     fprintf(fp,"VPP_B_voltage = %lf  \n",VPP_B_voltage);
     fprintf(fp,"VPP_C_voltage = %lf  \n",VPP_C_voltage);

     double OFFSET_A_voltage = dc_offset_calculator(waveformdata,data_counter,1);
     double OFFSET_B_voltage = dc_offset_calculator(waveformdata,data_counter,2);
     double OFFSET_C_voltage = dc_offset_calculator(waveformdata,data_counter,3);

     fprintf(fp,"DC offset A = %lf  \n",OFFSET_A_voltage);
     fprintf(fp,"DC offset B = %lf  \n",OFFSET_B_voltage);
     fprintf(fp,"DC offset C = %lf  \n",OFFSET_C_voltage);

     int Clipping_A_voltage = detect_clipping(waveformdata,data_counter,1);
     int Clipping_B_voltage = detect_clipping(waveformdata,data_counter,2);
     int Clipping_C_voltage= detect_clipping(waveformdata,data_counter,3);
     int total_clipping = Clipping_A_voltage+Clipping_B_voltage+Clipping_C_voltage;

     fprintf(fp,"total_clipping = %d\n",total_clipping);
     fprintf(fp,"Clipping detected in phase A  = %d\n",Clipping_A_voltage);
     fprintf(fp,"Clipping detected in phase B  = %d\n",Clipping_B_voltage);
     fprintf(fp,"Clipping detected in phase C  = %d\n",Clipping_C_voltage);

     char RmsA_tolerance = checkRmsTolerance(RMS_A_voltage);
     char RmsB_tolerance = checkRmsTolerance(RMS_B_voltage);
     char RmsC_tolerance = checkRmsTolerance(RMS_C_voltage);

     if (RmsA_tolerance == 'y')
         fprintf(fp,"Rms in phase A is in normal range \n");
     else
         fprintf(fp,"Rms in phase A is outside the normal range \n");

     if (RmsB_tolerance == 'y')
         fprintf(fp,"Rms in phase B is in normal range \n");
     else
         fprintf(fp,"Rms in phase B is outside the normal range \n");

     if (RmsC_tolerance == 'y')
         fprintf(fp,"Rms in phase C is in normal range \n");
     else
         fprintf(fp,"Rms in phase C is outside the normal range \n");




     fclose(fp);




 }
