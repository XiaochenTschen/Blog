#ifndef ADC_H
#define ADC_H

#include "adc_types.h"

/* Public API */
int adc_init(ADC_Channel_t* channel, const char* chip_name);
int adc_read(ADC_Channel_t* channel, int* value);

#endif