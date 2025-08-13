################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../application/appAbst.c \
../application/inputAbst.c \
../application/outputAbst.c 

OBJS += \
./application/appAbst.o \
./application/inputAbst.o \
./application/outputAbst.o 

C_DEPS += \
./application/appAbst.d \
./application/inputAbst.d \
./application/outputAbst.d 


# Each subdirectory must supply rules for building sources it contributes
application/%.o: ../application/%.c application/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -ffreestanding -g3 -I"C:\Users\shion\eclipse-workspace\RTOSv5\include" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


