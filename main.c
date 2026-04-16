#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "waveform.h"
void getFileName(char *filename);
int main(void) {
    //main function
    int data_counter;
    char filename[50]; //array of char 50 char max
    getFileName(filename);

    struct WaveformSample *waveformdata= readFile(filename, &data_counter);
    return 0;
}

void getFileName(char * filename) {
    printf("Enter your csv file name including the extension \n");
    scanf("%s",filename);
}
