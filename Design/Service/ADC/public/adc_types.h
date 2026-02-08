#ifndef ADC_TYPES_H
#define ADC_TYPES_H

#include "common_inc.h"

typedef struct
{
    int channel_id;
    const char *name;
    void *private_data;
} ADC_Channel_t;

typedef struct {
    int (*init)(ADC_Channel_t* channel);
    int (*read)(ADC_Channel_t* channel, int* value);
} ADC_Driver_t;

#endif /* ADC_TYPES_H */