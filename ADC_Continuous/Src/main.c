
#include "ADC.h"
#include "uart.h"

int main(void)
{   uint32_t sensor_value=0;

	UART_TX_init();
    ADC_init();
    Start_Conversion();

    while(1)
    	{
    	sensor_value=read_ADC();
    	printf("sensor value is %d",(int)sensor_value);
    	}

}
