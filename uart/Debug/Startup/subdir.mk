################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Startup/startup_stm32f410rbtx.s 

OBJS += \
./Startup/startup_stm32f410rbtx.o 

S_DEPS += \
./Startup/startup_stm32f410rbtx.d 


# Each subdirectory must supply rules for building sources it contributes
Startup/startup_stm32f410rbtx.o: ../Startup/startup_stm32f410rbtx.s Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -c -I"C:/Users/ousjl/Desktop/stm/chip_headers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/ousjl/Desktop/stm/chip_headers/CMSIS/Include" -x assembler-with-cpp -MMD -MP -MF"Startup/startup_stm32f410rbtx.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

