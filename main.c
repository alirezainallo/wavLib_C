#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "wav.h"

int main (void){
    wav_handle_t hWav;
    int16_t wavSample[512][8]; //wav[len][chNum]
    char wavName[] = "wavName.wav";
    wav_openRead(&hWav, wavName, true);
    
    // WAV_SAMPLE_PER_CHANNEL
	// WAV_SAMPLE_ALIGNMENT
	// WAV_SAMPLE_RATE
	// WAV_DATA_BYTES
	// WAV_BIT_DEPTH
	// WAV_BYTE_RATE
	// WAV_CHANNELS
    uint32_t samplePerChannel = wav_getDetails(&hWav.header, WAV_SAMPLE_PER_CHANNEL);
    uint32_t sampleRate       = wav_getDetails(&hWav.header, WAV_SAMPLE_RATE);
    uint32_t channelNum       = wav_getDetails(&hWav.header, WAV_CHANNELS);
    
    wav_readSample(&hWav, 0, 512, (void**)wavSample);
    wav_close(&hWav);
    return 0;
}