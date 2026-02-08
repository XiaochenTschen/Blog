#include "adc.h"

extern ADC_Driver_t adc_chip1_driver;
extern ADC_Driver_t adc_chip2_driver;

/*
 * Get ADC driver with chip name
 */
static ADC_Driver_t *get_adc_driver(const char* chip_name) {
    if(strcmp(chip_name, "chip1") == 0) {
        return &adc_chip1_driver;
    }
    else if(strcmp(chip_name, "chip2") == 0) {
        return &adc_chip2_driver;
    }
    else {
        return NULL;
    }
}

/*
 * Initialize the ADC 
 */
int adc_init(ADC_Channel_t* channel, const char* chip_name) {
    ADC_Driver_t* adc_driver = get_adc_driver(channel->name);
    if(!adc_driver || !adc_driver->init) {
        return -1;
    }
    return adc_driver->init(channel);
}

/*
 * Read value from ADC
 */
int adc_read(ADC_Channel_t* channel, int* value) {
    ADC_Driver_t* adc_driver = get_adc_driver(channel->name);
    if(!adc_driver || !adc_driver->read) {
        return -1;
    }
    return adc_driver->read(channel, value);
}
