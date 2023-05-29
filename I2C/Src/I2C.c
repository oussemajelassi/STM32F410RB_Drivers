#include "I2C.h"

#include "stm32f410rx.h"
#define RESET_STATE  (1U<<15)
#define FREQ         (1U<<4)
#define I2C_100KHZ   80
#define Rise_Time    17
#define busy_flag    (1U<<1)
#define start_Bit    (1U<<8)
#define start_flag   (1U<<0)
#define ADDR         (1U<<1)
#define ACK 	     (1U<<10)
#define RxNE		 (1U<<6)
#define STOP_bit	 (1U<<9)
#define BTF			 (1U<<2)


void I2C_init(void)
{  /*allow clock access to GPIOB*/
	RCC->AHB1ENR|=(1U<<1);
   /*Allow clock access to I2C1*/
	RCC->APB1ENR|=(1U<<21);
    /*set pb8 and pb9 to alternate function */
	GPIOB->MODER|=(1u<<17);
	GPIOB->MODER|=(1U<<19);
    /*set pb8 and pb9 alternate function to AF4*/
    GPIOB->AFR[1]|=(1U<<2);
    GPIOB->AFR[1]|=(1U<<6);
    /*set pb8 and pb9 to open drain*/
    GPIOB->OTYPER|=(1U<<8);
    GPIOB->OTYPER|=(1U<<9);
    /*set pb8 and pb9 to pull up*/
    GPIOB->PUPDR|=(1U<<16);
    GPIOB->PUPDR|=(1U<<18);
    /*enter reset mode*/
    I2C1->CR1|=RESET_STATE;
    /*leave reset mode*/
    I2C1->CR1&=~RESET_STATE;
    /*set periph frequency*/
    I2C1->CR2|=FREQ;
    /*Set I2C TO SM , 100KH freq*/
    I2C1->CCR=I2C_100KHZ;
    /*Set rise time*/
    I2C1->TRISE=Rise_Time;
    /*Enable I2C1*/
    I2C1->CR1|=(1U<<0);
}

void I2C_Read(char slaveadr,char memadr,char* data){
           volatile int tmp;

	       /*make sure the I2C is not busy*/
	       while(( I2C1->SR2)&busy_flag){}

	       /*Generate a start condition*/
	       I2C1->CR1|=start_Bit;

	       /*wait until the start flag is set*/
	       while(!(I2C1->SR2&start_flag)){}

	       /*Transmit Slave address + write*/
	       I2C1->DR=(slaveadr<<1);

	       /*wait until address flag is set*/
	       while(!(I2C1->SR1)&ADDR){}

	       /*clear the addr flag by reading sr1 and sr2*/
	       tmp=I2C1->SR1;
	       tmp=I2C1->SR2;

	       /*transmit the memory address related to what we want to read */
	       I2C1->DR=memadr;

	       /*wait until transmit complete */
	       while(!I2C1->SR1&(1U<<7)){}

	       /*generate a restart condition*/
	       I2C1->CR1|=start_Bit;

	       /*wait until the start flag is set*/
	       while(!(I2C1->SR2&start_flag)){}

	       /*transmit slave address + read*/
	       I2C1->DR=(slaveadr<<1|1);

	       /*wait until address flag is set*/
	       while(!(I2C1->SR1)&ADDR){}

	       /*disable the  Acknowledge*/
	       I2C1->CR1&=~ACK;

	       /*clear the addr flag by reading sr1 and sr2*/
	       tmp=I2C1->SR1;
	       tmp=I2C1->SR2;

	       /*Generate a STOP condition*/
	       I2C1->CR1|=STOP_bit;

	       /*wait until Data register not empty*/
	       while(!(I2C1->SR1)&RxNE){}

	       /*Read the data */ // ++= means put DR in *Data and then increment Data
	       *data ++=I2C1->DR;

}


			void I2C_Burst_read(char slaveadr,char memadr,int n ,char* data)
			{volatile int tmp;

		    /*make sure the I2C is not busy*/
			while(( I2C1->SR2)&busy_flag){}

			/*Generate a start condition*/
		    I2C1->CR1|=start_Bit;

		    /*wait until the start flag is set*/
		    while(!(I2C1->SR2&start_flag)){}

		    /*Transmit Slave address + write*/
		    I2C1->DR=(slaveadr<<1);

		    /*wait until address flag is set*/
		    while(!(I2C1->SR1)&ADDR){}

		    /*clear the addr flag by reading sr2*/
		    tmp=I2C1->SR2;

		    /*transmit the memory address related to what we want to read */
		    I2C1->DR=memadr;

		    /*wait until transmit complete */
		    while(!(I2C1->SR1&(1U<<7))){}

		    /*generate a restart condition*/
		    I2C1->CR1|=start_Bit;

		    /*wait until the start flag is set*/
		    while(!(I2C1->SR2&start_flag)){}

		    /*transmit slave address + read*/
		    I2C1->DR=(slaveadr<<1|1);

		    /*wait until address flag is set*/
		    while(!(I2C1->SR1)&ADDR){}
		    /*clear the addr flag by reading sr2*/
		    tmp=I2C1->SR2;

		    /*enable the  Acknowledge*/
		    I2C1->CR1|=ACK;

			while (n>0)
			   {/*IF ONE BYTE*/
				           if (n == 1)
				  {/*disable the  Acknowledge*/
				    I2C1->CR1&=~ACK;

				     /*Generate a STOP condition*/
				     I2C1->CR1|=STOP_bit;

				     /*wait until Data register not empty*/
				     while(!(I2C1->SR1)&RxNE){}

				     /*Read the data */ // ++= means put DR in *Data and then increment Data
				     *data ++=I2C1->DR;
				     break;
				  }
				          else
				     {  /*wait until Data register not empty*/
					    while(!(I2C1->SR1&RxNE)){}
				     	/*Read the data */ // ++= means put DR in *Data and then increment Data
				     	(*data++)=I2C1->DR;
				        /*decrement N */
				     	n--;
				     }
			   }

			}


void I2C_Burst_WRITE(char slaveadr,char memadr,int n ,char* data)
				{
	            volatile int tmp;
				/*make sure the I2C is not busy*/
				while(( I2C1->SR2)&busy_flag){}

				/*Generate a start condition*/
				I2C1->CR1|=start_Bit;

				/*wait until the start flag is set*/
				while(!(I2C1->SR2&start_flag)){}

				/*Transmit Slave address + write*/
				I2C1->DR=(slaveadr<<1);

			    /*wait until address flag is set*/
			    while(!(I2C1->SR1)&ADDR){}

			    /*clear the addr flag by reading sr1 and sr2*/
			    tmp=I2C1->SR1;
			    tmp=I2C1->SR2;

			    /*wait until transmit complete */
			    while(!I2C1->SR1&(1U<<7)){}

			    /*transmit the memory address related to what we want to write */
			    I2C1->DR=memadr;

			    for (int i=0 ;i<n;i++)
			    		{/*wait until transmit complete */
				    	 while(!I2C1->SR1&(1U<<7)){}

				    	 /*Transmit data*/
			    		I2C1->DR=*data++;
			    		}

			    /*Wait until byte transfer complete*/
			    while(!(I2C1->SR1)&BTF){}

			    /*Generate a STOP condition*/
			    I2C1->CR1|=STOP_bit;


				}



