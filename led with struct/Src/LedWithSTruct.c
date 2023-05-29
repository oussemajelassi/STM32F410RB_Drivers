#include "stdint.h"

#define periph_base       (0x40000000UL)
#define AHB1_offset       (0x00020000)
#define AHB1_base         (periph_base + AHB1_offset)
#define GPIOA_offset      (0x00000000UL)
#define GPIOA_base        ( GPIOA_offset + AHB1_base)
#define RCC_offset        (0x00003800UL)
#define RCC_base          (RCC_offset+AHB1_base)

#define AHB1ENR_offset    (0x30UL)

#define RCC_AHB1ENR_base  (AHB1ENR_offset + RCC_base)
#define GPIOEN            (1U<<0)


#define GPIOA_moder_offset      (0x00)

#define PIN5_output       (1U<<10)


#define GPIOA_odr_offset  (0x14UL)   // odr = output data register

#define PIN5_enable       (1U<<5)

int i=0;



typedef struct {
	volatile uint32_t   moder;
	volatile uint32_t   outputtype;
	volatile uint32_t   output_speed;
	volatile uint32_t   pull_up_down;
	volatile uint32_t   input_data;
	volatile uint32_t   ODR;
	volatile uint32_t   bit_set_reset;
	volatile uint32_t   lock;
	volatile uint32_t   alternate_low;
	volatile uint32_t   alternate_high;

}GPIOA_typedef ;
typedef struct
{
	volatile uint32_t RCC_enable_ABH1;
}RCC_typedef;



#define GPIOA ((GPIOA_typedef*) GPIOA_base)
#define RCC ((RCC_typedef*) RCC_AHB1ENR_base)
int main(void)
{
	RCC->RCC_enable_ABH1=GPIOEN;//enable clock
	//  | khater momken nest7akou enou ikounou fama 1 fi blayes okhrina donc naamlou OR

	//set pa5 as output
	GPIOA->moder |= PIN5_output; //set bit 10 to 1
	GPIOA->moder &=~(1U<<11);//set bit 11 to 0
	while(1){
		//put the high value to pin 5
             GPIOA->ODR|=PIN5_enable;

	        }



}
