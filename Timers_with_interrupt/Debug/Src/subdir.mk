################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Encoder_mode.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/timerinterrupt.c \
../Src/uart.c 

OBJS += \
./Src/Encoder_mode.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/timerinterrupt.o \
./Src/uart.o 

C_DEPS += \
./Src/Encoder_mode.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/timerinterrupt.d \
./Src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F410RBTx -DSTM32 -DSTM32F4 -c -I../Inc -I"C:/Users/ousjl/Desktop/stm/chip_headers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/ousjl/Desktop/stm/chip_headers/CMSIS/Include" -I"C:/Users/ousjl/Desktop/stm/uart_sentence/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/Encoder_mode.d ./Src/Encoder_mode.o ./Src/main.d ./Src/main.o ./Src/syscalls.d ./Src/syscalls.o ./Src/sysmem.d ./Src/sysmem.o ./Src/timerinterrupt.d ./Src/timerinterrupt.o ./Src/uart.d ./Src/uart.o

.PHONY: clean-Src

