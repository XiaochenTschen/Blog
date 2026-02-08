#include "adc_types.h"

static int chip2_init(ADC_Channel_t *channel) {
    printf("Initializing chip1 for channel %d\n", channel->channel_id);
    channel->name = "chip2";
    return 0;
}

static int chip2_read(ADC_Channel_t *channel, int *value) {
    printf("Reading from chip2 on channel %d\n", channel->channel_id);
    *value = 456;
    return 0;
}

ADC_Driver_t adc_chip1_driver = {
    .init = chip2_init,
    .read = chip2_read,
};
