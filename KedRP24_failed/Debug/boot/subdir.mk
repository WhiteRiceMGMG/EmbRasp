################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../boot/boot2.c \
../boot/init.c 

OBJS += \
./boot/boot2.o \
./boot/init.o 

C_DEPS += \
./boot/boot2.d \
./boot/init.d 


# Each subdirectory must supply rules for building sources it contributes
boot/%.o: ../boot/%.c boot/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -ffreestanding -g3 -I"C:\Users\shion\eclipse-workspace\KedRP24\include" -I"C:\Users\shion\eclipse-workspace\KedRP24\boot" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


