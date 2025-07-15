################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/examples/widgets/obj/lv_example_obj_1.c \
../lvgl/examples/widgets/obj/lv_example_obj_2.c 

OBJS += \
./lvgl/examples/widgets/obj/lv_example_obj_1.o \
./lvgl/examples/widgets/obj/lv_example_obj_2.o 

C_DEPS += \
./lvgl/examples/widgets/obj/lv_example_obj_1.d \
./lvgl/examples/widgets/obj/lv_example_obj_2.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/examples/widgets/obj/%.o lvgl/examples/widgets/obj/%.su lvgl/examples/widgets/obj/%.cyclo: ../lvgl/examples/widgets/obj/%.c lvgl/examples/widgets/obj/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"C:/Users/bhara/STM32CubeIDE/EmbeddedGraphicsLVGL-MCU3/Projects/002_LVGL_sample/3_32F407DISCOVERY/bsp_f4x/lcd" -I"C:/Users/bhara/STM32CubeIDE/EmbeddedGraphicsLVGL-MCU3/Projects/002_LVGL_sample/3_32F407DISCOVERY/bsp_f4x/lvgl" -I"C:/Users/bhara/STM32CubeIDE/EmbeddedGraphicsLVGL-MCU3/Projects/002_LVGL_sample/3_32F407DISCOVERY/bsp_f4x/tsc" -I"C:/Users/bhara/STM32CubeIDE/EmbeddedGraphicsLVGL-MCU3/Projects/002_LVGL_sample/3_32F407DISCOVERY" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-examples-2f-widgets-2f-obj

clean-lvgl-2f-examples-2f-widgets-2f-obj:
	-$(RM) ./lvgl/examples/widgets/obj/lv_example_obj_1.cyclo ./lvgl/examples/widgets/obj/lv_example_obj_1.d ./lvgl/examples/widgets/obj/lv_example_obj_1.o ./lvgl/examples/widgets/obj/lv_example_obj_1.su ./lvgl/examples/widgets/obj/lv_example_obj_2.cyclo ./lvgl/examples/widgets/obj/lv_example_obj_2.d ./lvgl/examples/widgets/obj/lv_example_obj_2.o ./lvgl/examples/widgets/obj/lv_example_obj_2.su

.PHONY: clean-lvgl-2f-examples-2f-widgets-2f-obj

