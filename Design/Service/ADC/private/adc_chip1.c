#include "adc_types.h"

static int chip1_init(ADC_Channel_t *channel) {
    printf("Initializing chip1 for channel %d\n", channel->channel_id);
    channel->name = "chip1";
    return 0;
}

static int chip1_read(ADC_Channel_t *channel, int *value) {
    printf("Reading from chip1 on channel %d\n", channel->channel_id);
    *value = 123;
    return 0;
}

ADC_Driver_t adc_chip2_driver = {
    .init = chip1_init,
    .read = chip1_read,
};
