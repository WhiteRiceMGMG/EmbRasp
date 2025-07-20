################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
../startup.S 

OBJS += \
./startup.o 

S_UPPER_DEPS += \
./startup.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.S subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross Assembler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -ffreestanding -g3 -x assembler-with-cpp -I"C:\Users\shion\eclipse-workspace\KedRP24_failed" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


