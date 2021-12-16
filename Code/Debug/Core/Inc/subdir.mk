################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Inc/tm_stm32_fft.c \
../Core/Inc/tm_stm32_gpio.c \
../Core/Inc/tm_stm32_rcc.c 

C_DEPS += \
./Core/Inc/tm_stm32_fft.d \
./Core/Inc/tm_stm32_gpio.d \
./Core/Inc/tm_stm32_rcc.d 

OBJS += \
./Core/Inc/tm_stm32_fft.o \
./Core/Inc/tm_stm32_gpio.o \
./Core/Inc/tm_stm32_rcc.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/%.o: ../Core/Inc/%.c Core/Inc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xC -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Inc

clean-Core-2f-Inc:
	-$(RM) ./Core/Inc/tm_stm32_fft.d ./Core/Inc/tm_stm32_fft.o ./Core/Inc/tm_stm32_gpio.d ./Core/Inc/tm_stm32_gpio.o ./Core/Inc/tm_stm32_rcc.d ./Core/Inc/tm_stm32_rcc.o

.PHONY: clean-Core-2f-Inc

