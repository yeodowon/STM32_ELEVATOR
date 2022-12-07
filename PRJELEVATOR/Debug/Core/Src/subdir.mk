################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/BUTTON.c \
../Core/Src/INTERNAL_RTC.c \
../Core/Src/LED.c \
../Core/Src/SERVO_MOTOR.c \
../Core/Src/STEPMOTOR.c \
../Core/Src/UART0.c \
../Core/Src/buzzer.c \
../Core/Src/i2c_lcd.c \
../Core/Src/main.c \
../Core/Src/stm32f4xx_hal_msp.c \
../Core/Src/stm32f4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f4xx.c 

OBJS += \
./Core/Src/BUTTON.o \
./Core/Src/INTERNAL_RTC.o \
./Core/Src/LED.o \
./Core/Src/SERVO_MOTOR.o \
./Core/Src/STEPMOTOR.o \
./Core/Src/UART0.o \
./Core/Src/buzzer.o \
./Core/Src/i2c_lcd.o \
./Core/Src/main.o \
./Core/Src/stm32f4xx_hal_msp.o \
./Core/Src/stm32f4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f4xx.o 

C_DEPS += \
./Core/Src/BUTTON.d \
./Core/Src/INTERNAL_RTC.d \
./Core/Src/LED.d \
./Core/Src/SERVO_MOTOR.d \
./Core/Src/STEPMOTOR.d \
./Core/Src/UART0.d \
./Core/Src/buzzer.d \
./Core/Src/i2c_lcd.d \
./Core/Src/main.d \
./Core/Src/stm32f4xx_hal_msp.d \
./Core/Src/stm32f4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/BUTTON.d ./Core/Src/BUTTON.o ./Core/Src/BUTTON.su ./Core/Src/INTERNAL_RTC.d ./Core/Src/INTERNAL_RTC.o ./Core/Src/INTERNAL_RTC.su ./Core/Src/LED.d ./Core/Src/LED.o ./Core/Src/LED.su ./Core/Src/SERVO_MOTOR.d ./Core/Src/SERVO_MOTOR.o ./Core/Src/SERVO_MOTOR.su ./Core/Src/STEPMOTOR.d ./Core/Src/STEPMOTOR.o ./Core/Src/STEPMOTOR.su ./Core/Src/UART0.d ./Core/Src/UART0.o ./Core/Src/UART0.su ./Core/Src/buzzer.d ./Core/Src/buzzer.o ./Core/Src/buzzer.su ./Core/Src/i2c_lcd.d ./Core/Src/i2c_lcd.o ./Core/Src/i2c_lcd.su ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/stm32f4xx_hal_msp.d ./Core/Src/stm32f4xx_hal_msp.o ./Core/Src/stm32f4xx_hal_msp.su ./Core/Src/stm32f4xx_it.d ./Core/Src/stm32f4xx_it.o ./Core/Src/stm32f4xx_it.su ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f4xx.d ./Core/Src/system_stm32f4xx.o ./Core/Src/system_stm32f4xx.su

.PHONY: clean-Core-2f-Src

