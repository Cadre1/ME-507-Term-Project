################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/controller.c \
../Core/Src/encoder_driver.c \
../Core/Src/main.c \
../Core/Src/motor_driver.c \
../Core/Src/photoresistor_driver.c \
../Core/Src/radio_reciever_driver.c \
../Core/Src/stm32f4xx_hal_msp.c \
../Core/Src/stm32f4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f4xx.c \
../Core/Src/vector.c 

OBJS += \
./Core/Src/controller.o \
./Core/Src/encoder_driver.o \
./Core/Src/main.o \
./Core/Src/motor_driver.o \
./Core/Src/photoresistor_driver.o \
./Core/Src/radio_reciever_driver.o \
./Core/Src/stm32f4xx_hal_msp.o \
./Core/Src/stm32f4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f4xx.o \
./Core/Src/vector.o 

C_DEPS += \
./Core/Src/controller.d \
./Core/Src/encoder_driver.d \
./Core/Src/main.d \
./Core/Src/motor_driver.d \
./Core/Src/photoresistor_driver.d \
./Core/Src/radio_reciever_driver.d \
./Core/Src/stm32f4xx_hal_msp.d \
./Core/Src/stm32f4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f4xx.d \
./Core/Src/vector.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/controller.cyclo ./Core/Src/controller.d ./Core/Src/controller.o ./Core/Src/controller.su ./Core/Src/encoder_driver.cyclo ./Core/Src/encoder_driver.d ./Core/Src/encoder_driver.o ./Core/Src/encoder_driver.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/motor_driver.cyclo ./Core/Src/motor_driver.d ./Core/Src/motor_driver.o ./Core/Src/motor_driver.su ./Core/Src/photoresistor_driver.cyclo ./Core/Src/photoresistor_driver.d ./Core/Src/photoresistor_driver.o ./Core/Src/photoresistor_driver.su ./Core/Src/radio_reciever_driver.cyclo ./Core/Src/radio_reciever_driver.d ./Core/Src/radio_reciever_driver.o ./Core/Src/radio_reciever_driver.su ./Core/Src/stm32f4xx_hal_msp.cyclo ./Core/Src/stm32f4xx_hal_msp.d ./Core/Src/stm32f4xx_hal_msp.o ./Core/Src/stm32f4xx_hal_msp.su ./Core/Src/stm32f4xx_it.cyclo ./Core/Src/stm32f4xx_it.d ./Core/Src/stm32f4xx_it.o ./Core/Src/stm32f4xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f4xx.cyclo ./Core/Src/system_stm32f4xx.d ./Core/Src/system_stm32f4xx.o ./Core/Src/system_stm32f4xx.su ./Core/Src/vector.cyclo ./Core/Src/vector.d ./Core/Src/vector.o ./Core/Src/vector.su

.PHONY: clean-Core-2f-Src

