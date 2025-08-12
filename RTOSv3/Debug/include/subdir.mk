################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../include/Button.c \
../include/KedDriver.c \
../include/Led.c 

OBJS += \
./include/Button.o \
./include/KedDriver.o \
./include/Led.o 

C_DEPS += \
./include/Button.d \
./include/KedDriver.d \
./include/Led.d 


# Each subdirectory must supply rules for building sources it contributes
include/%.o: ../include/%.c include/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -ffreestanding -g3 -I"C:\Users\shion\eclipse-workspace\RTOSv3\include" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


