################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/core/lv_disp.c \
../lvgl/src/core/lv_event.c \
../lvgl/src/core/lv_group.c \
../lvgl/src/core/lv_indev.c \
../lvgl/src/core/lv_indev_scroll.c \
../lvgl/src/core/lv_obj.c \
../lvgl/src/core/lv_obj_class.c \
../lvgl/src/core/lv_obj_draw.c \
../lvgl/src/core/lv_obj_pos.c \
../lvgl/src/core/lv_obj_scroll.c \
../lvgl/src/core/lv_obj_style.c \
../lvgl/src/core/lv_obj_style_gen.c \
../lvgl/src/core/lv_obj_tree.c \
../lvgl/src/core/lv_refr.c \
../lvgl/src/core/lv_theme.c 

OBJS += \
./lvgl/src/core/lv_disp.o \
./lvgl/src/core/lv_event.o \
./lvgl/src/core/lv_group.o \
./lvgl/src/core/lv_indev.o \
./lvgl/src/core/lv_indev_scroll.o \
./lvgl/src/core/lv_obj.o \
./lvgl/src/core/lv_obj_class.o \
./lvgl/src/core/lv_obj_draw.o \
./lvgl/src/core/lv_obj_pos.o \
./lvgl/src/core/lv_obj_scroll.o \
./lvgl/src/core/lv_obj_style.o \
./lvgl/src/core/lv_obj_style_gen.o \
./lvgl/src/core/lv_obj_tree.o \
./lvgl/src/core/lv_refr.o \
./lvgl/src/core/lv_theme.o 

C_DEPS += \
./lvgl/src/core/lv_disp.d \
./lvgl/src/core/lv_event.d \
./lvgl/src/core/lv_group.d \
./lvgl/src/core/lv_indev.d \
./lvgl/src/core/lv_indev_scroll.d \
./lvgl/src/core/lv_obj.d \
./lvgl/src/core/lv_obj_class.d \
./lvgl/src/core/lv_obj_draw.d \
./lvgl/src/core/lv_obj_pos.d \
./lvgl/src/core/lv_obj_scroll.d \
./lvgl/src/core/lv_obj_style.d \
./lvgl/src/core/lv_obj_style_gen.d \
./lvgl/src/core/lv_obj_tree.d \
./lvgl/src/core/lv_refr.d \
./lvgl/src/core/lv_theme.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/core/%.o lvgl/src/core/%.su lvgl/src/core/%.cyclo: ../lvgl/src/core/%.c lvgl/src/core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"C:/Users/bhara/STM32CubeIDE/EmbeddedGraphicsLVGL-MCU3/Projects/003_RGB_Mixer/3_32F407DISCOVERY/bsp_f4x/lcd" -I"C:/Users/bhara/STM32CubeIDE/EmbeddedGraphicsLVGL-MCU3/Projects/003_RGB_Mixer/3_32F407DISCOVERY/bsp_f4x/lvgl" -I"C:/Users/bhara/STM32CubeIDE/EmbeddedGraphicsLVGL-MCU3/Projects/003_RGB_Mixer/3_32F407DISCOVERY/bsp_f4x/tsc" -I"C:/Users/bhara/STM32CubeIDE/EmbeddedGraphicsLVGL-MCU3/Projects/003_RGB_Mixer/3_32F407DISCOVERY" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-core

clean-lvgl-2f-src-2f-core:
	-$(RM) ./lvgl/src/core/lv_disp.cyclo ./lvgl/src/core/lv_disp.d ./lvgl/src/core/lv_disp.o ./lvgl/src/core/lv_disp.su ./lvgl/src/core/lv_event.cyclo ./lvgl/src/core/lv_event.d ./lvgl/src/core/lv_event.o ./lvgl/src/core/lv_event.su ./lvgl/src/core/lv_group.cyclo ./lvgl/src/core/lv_group.d ./lvgl/src/core/lv_group.o ./lvgl/src/core/lv_group.su ./lvgl/src/core/lv_indev.cyclo ./lvgl/src/core/lv_indev.d ./lvgl/src/core/lv_indev.o ./lvgl/src/core/lv_indev.su ./lvgl/src/core/lv_indev_scroll.cyclo ./lvgl/src/core/lv_indev_scroll.d ./lvgl/src/core/lv_indev_scroll.o ./lvgl/src/core/lv_indev_scroll.su ./lvgl/src/core/lv_obj.cyclo ./lvgl/src/core/lv_obj.d ./lvgl/src/core/lv_obj.o ./lvgl/src/core/lv_obj.su ./lvgl/src/core/lv_obj_class.cyclo ./lvgl/src/core/lv_obj_class.d ./lvgl/src/core/lv_obj_class.o ./lvgl/src/core/lv_obj_class.su ./lvgl/src/core/lv_obj_draw.cyclo ./lvgl/src/core/lv_obj_draw.d ./lvgl/src/core/lv_obj_draw.o ./lvgl/src/core/lv_obj_draw.su ./lvgl/src/core/lv_obj_pos.cyclo ./lvgl/src/core/lv_obj_pos.d ./lvgl/src/core/lv_obj_pos.o ./lvgl/src/core/lv_obj_pos.su ./lvgl/src/core/lv_obj_scroll.cyclo ./lvgl/src/core/lv_obj_scroll.d ./lvgl/src/core/lv_obj_scroll.o ./lvgl/src/core/lv_obj_scroll.su ./lvgl/src/core/lv_obj_style.cyclo ./lvgl/src/core/lv_obj_style.d ./lvgl/src/core/lv_obj_style.o ./lvgl/src/core/lv_obj_style.su ./lvgl/src/core/lv_obj_style_gen.cyclo ./lvgl/src/core/lv_obj_style_gen.d ./lvgl/src/core/lv_obj_style_gen.o ./lvgl/src/core/lv_obj_style_gen.su ./lvgl/src/core/lv_obj_tree.cyclo ./lvgl/src/core/lv_obj_tree.d ./lvgl/src/core/lv_obj_tree.o ./lvgl/src/core/lv_obj_tree.su ./lvgl/src/core/lv_refr.cyclo ./lvgl/src/core/lv_refr.d ./lvgl/src/core/lv_refr.o ./lvgl/src/core/lv_refr.su ./lvgl/src/core/lv_theme.cyclo ./lvgl/src/core/lv_theme.d ./lvgl/src/core/lv_theme.o ./lvgl/src/core/lv_theme.su

.PHONY: clean-lvgl-2f-src-2f-core

