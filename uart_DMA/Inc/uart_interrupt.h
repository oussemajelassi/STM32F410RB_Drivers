
#ifndef UART_INTERRUPT_H_
#define UART_INTERRUPT_H_

void       UART_RX_TX_interrupt_init(void);
static void set_baudrate_usart2(USART_TypeDef* usart,uint32_t freq , uint32_t baud);
#endif /* UART_INTERRUPT_H_ */
