#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "waveform.h"
int main(int argc, char *argv[]) {
    //main function
    int data_counter;
    char * filename =argv[1];
    struct WaveformSample *waveformdata= readFile(filename, &data_counter);
    ExportResultToFile("result.txt",waveformdata,data_counter);
    return 0;
}
