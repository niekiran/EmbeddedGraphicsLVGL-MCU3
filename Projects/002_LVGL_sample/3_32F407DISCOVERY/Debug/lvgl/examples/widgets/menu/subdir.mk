################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/examples/widgets/menu/lv_example_menu_1.c \
../lvgl/examples/widgets/menu/lv_example_menu_2.c \
../lvgl/examples/widgets/menu/lv_example_menu_3.c \
../lvgl/examples/widgets/menu/lv_example_menu_4.c \
../lvgl/examples/widgets/menu/lv_example_menu_5.c 

OBJS += \
./lvgl/examples/widgets/menu/lv_example_menu_1.o \
./lvgl/examples/widgets/menu/lv_example_menu_2.o \
./lvgl/examples/widgets/menu/lv_example_menu_3.o \
./lvgl/examples/widgets/menu/lv_example_menu_4.o \
./lvgl/examples/widgets/menu/lv_example_menu_5.o 

C_DEPS += \
./lvgl/examples/widgets/menu/lv_example_menu_1.d \
./lvgl/examples/widgets/menu/lv_example_menu_2.d \
./lvgl/examples/widgets/menu/lv_example_menu_3.d \
./lvgl/examples/widgets/menu/lv_example_menu_4.d \
./lvgl/examples/widgets/menu/lv_example_menu_5.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/examples/widgets/menu/%.o lvgl/examples/widgets/menu/%.su lvgl/examples/widgets/menu/%.cyclo: ../lvgl/examples/widgets/menu/%.c lvgl/examples/widgets/menu/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"C:/Users/bhara/STM32CubeIDE/EmbeddedGraphicsLVGL-MCU3/Projects/002_LVGL_sample/3_32F407DISCOVERY/bsp_f4x/lcd" -I"C:/Users/bhara/STM32CubeIDE/EmbeddedGraphicsLVGL-MCU3/Projects/002_LVGL_sample/3_32F407DISCOVERY/bsp_f4x/lvgl" -I"C:/Users/bhara/STM32CubeIDE/EmbeddedGraphicsLVGL-MCU3/Projects/002_LVGL_sample/3_32F407DISCOVERY/bsp_f4x/tsc" -I"C:/Users/bhara/STM32CubeIDE/EmbeddedGraphicsLVGL-MCU3/Projects/002_LVGL_sample/3_32F407DISCOVERY" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-examples-2f-widgets-2f-menu

clean-lvgl-2f-examples-2f-widgets-2f-menu:
	-$(RM) ./lvgl/examples/widgets/menu/lv_example_menu_1.cyclo ./lvgl/examples/widgets/menu/lv_example_menu_1.d ./lvgl/examples/widgets/menu/lv_example_menu_1.o ./lvgl/examples/widgets/menu/lv_example_menu_1.su ./lvgl/examples/widgets/menu/lv_example_menu_2.cyclo ./lvgl/examples/widgets/menu/lv_example_menu_2.d ./lvgl/examples/widgets/menu/lv_example_menu_2.o ./lvgl/examples/widgets/menu/lv_example_menu_2.su ./lvgl/examples/widgets/menu/lv_example_menu_3.cyclo ./lvgl/examples/widgets/menu/lv_example_menu_3.d ./lvgl/examples/widgets/menu/lv_example_menu_3.o ./lvgl/examples/widgets/menu/lv_example_menu_3.su ./lvgl/examples/widgets/menu/lv_example_menu_4.cyclo ./lvgl/examples/widgets/menu/lv_example_menu_4.d ./lvgl/examples/widgets/menu/lv_example_menu_4.o ./lvgl/examples/widgets/menu/lv_example_menu_4.su ./lvgl/examples/widgets/menu/lv_example_menu_5.cyclo ./lvgl/examples/widgets/menu/lv_example_menu_5.d ./lvgl/examples/widgets/menu/lv_example_menu_5.o ./lvgl/examples/widgets/menu/lv_example_menu_5.su

.PHONY: clean-lvgl-2f-examples-2f-widgets-2f-menu

