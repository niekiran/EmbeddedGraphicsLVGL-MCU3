################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Core/Src/Startup/startup_stm32f407vgtx.s 

OBJS += \
./Core/Src/Startup/startup_stm32f407vgtx.o 

S_DEPS += \
./Core/Src/Startup/startup_stm32f407vgtx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Startup/%.o: ../Core/Src/Startup/%.s Core/Src/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Core-2f-Src-2f-Startup

clean-Core-2f-Src-2f-Startup:
	-$(RM) ./Core/Src/Startup/startup_stm32f407vgtx.d ./Core/Src/Startup/startup_stm32f407vgtx.o

.PHONY: clean-Core-2f-Src-2f-Startup

