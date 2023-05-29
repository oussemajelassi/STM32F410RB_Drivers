#include "stm32f410rx.h"
#include "ADC.h"
#include "uart.h"
uint32_t sensor_value=0;
int main(void)
{

	UART_TX_init();
	ADC_init_interrupt();
    Start_Conversion();

    while(1)
    	{

    	printf("sensor value is %d",(int)sensor_value);
    	}

}



void ADC_IRQHandler(void)
		{/*check for EOC*/
		 if ((ADC1->SR)&(1U<<1))
		 	 {/*Clear the flag*/		// we can clear it by reading the ADC DR
			  sensor_value=ADC1->DR;
			  /*do something*/

		 	 }
		}
