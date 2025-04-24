################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/widgets/calendar/lv_calendar.c \
../lvgl/src/widgets/calendar/lv_calendar_header_arrow.c \
../lvgl/src/widgets/calendar/lv_calendar_header_dropdown.c 

OBJS += \
./lvgl/src/widgets/calendar/lv_calendar.o \
./lvgl/src/widgets/calendar/lv_calendar_header_arrow.o \
./lvgl/src/widgets/calendar/lv_calendar_header_dropdown.o 

C_DEPS += \
./lvgl/src/widgets/calendar/lv_calendar.d \
./lvgl/src/widgets/calendar/lv_calendar_header_arrow.d \
./lvgl/src/widgets/calendar/lv_calendar_header_dropdown.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/widgets/calendar/%.o lvgl/src/widgets/calendar/%.su lvgl/src/widgets/calendar/%.cyclo: ../lvgl/src/widgets/calendar/%.c lvgl/src/widgets/calendar/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"C:/Users/shrey/STM32CubeIDE/EmbeddedGraphicsLVGL-MCU3/Projects/003_RGB_Mixer/3_32F407DISCOVERY/bsp_f4x/lcd" -I"C:/Users/shrey/STM32CubeIDE/EmbeddedGraphicsLVGL-MCU3/Projects/003_RGB_Mixer/3_32F407DISCOVERY/bsp_f4x/lvgl" -I"C:/Users/shrey/STM32CubeIDE/EmbeddedGraphicsLVGL-MCU3/Projects/003_RGB_Mixer/3_32F407DISCOVERY/bsp_f4x/tsc" -I"C:/Users/shrey/STM32CubeIDE/EmbeddedGraphicsLVGL-MCU3/Projects/003_RGB_Mixer/3_32F407DISCOVERY" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-widgets-2f-calendar

clean-lvgl-2f-src-2f-widgets-2f-calendar:
	-$(RM) ./lvgl/src/widgets/calendar/lv_calendar.cyclo ./lvgl/src/widgets/calendar/lv_calendar.d ./lvgl/src/widgets/calendar/lv_calendar.o ./lvgl/src/widgets/calendar/lv_calendar.su ./lvgl/src/widgets/calendar/lv_calendar_header_arrow.cyclo ./lvgl/src/widgets/calendar/lv_calendar_header_arrow.d ./lvgl/src/widgets/calendar/lv_calendar_header_arrow.o ./lvgl/src/widgets/calendar/lv_calendar_header_arrow.su ./lvgl/src/widgets/calendar/lv_calendar_header_dropdown.cyclo ./lvgl/src/widgets/calendar/lv_calendar_header_dropdown.d ./lvgl/src/widgets/calendar/lv_calendar_header_dropdown.o ./lvgl/src/widgets/calendar/lv_calendar_header_dropdown.su

.PHONY: clean-lvgl-2f-src-2f-widgets-2f-calendar

