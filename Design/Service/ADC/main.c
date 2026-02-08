#include "adc.h"

int main(void) {
    ADC_Channel_t adc_channel;
    int value;

    /* chip1 */
    adc_init(&adc_channel, "chip1");
    adc_read(&adc_channel, &value);
    printf("Value from chip1: %d\n", value);

    /* chip2 */
    adc_init(&adc_channel, "chip2");
    adc_read(&adc_channel, &value);
    printf("Value from chip2: %d\n", value);
}