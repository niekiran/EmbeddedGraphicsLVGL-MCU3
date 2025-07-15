################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/draw/sdl/lv_draw_sdl.c \
../lvgl/src/draw/sdl/lv_draw_sdl_arc.c \
../lvgl/src/draw/sdl/lv_draw_sdl_bg.c \
../lvgl/src/draw/sdl/lv_draw_sdl_composite.c \
../lvgl/src/draw/sdl/lv_draw_sdl_img.c \
../lvgl/src/draw/sdl/lv_draw_sdl_label.c \
../lvgl/src/draw/sdl/lv_draw_sdl_layer.c \
../lvgl/src/draw/sdl/lv_draw_sdl_line.c \
../lvgl/src/draw/sdl/lv_draw_sdl_mask.c \
../lvgl/src/draw/sdl/lv_draw_sdl_polygon.c \
../lvgl/src/draw/sdl/lv_draw_sdl_rect.c \
../lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.c \
../lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.c \
../lvgl/src/draw/sdl/lv_draw_sdl_utils.c 

OBJS += \
./lvgl/src/draw/sdl/lv_draw_sdl.o \
./lvgl/src/draw/sdl/lv_draw_sdl_arc.o \
./lvgl/src/draw/sdl/lv_draw_sdl_bg.o \
./lvgl/src/draw/sdl/lv_draw_sdl_composite.o \
./lvgl/src/draw/sdl/lv_draw_sdl_img.o \
./lvgl/src/draw/sdl/lv_draw_sdl_label.o \
./lvgl/src/draw/sdl/lv_draw_sdl_layer.o \
./lvgl/src/draw/sdl/lv_draw_sdl_line.o \
./lvgl/src/draw/sdl/lv_draw_sdl_mask.o \
./lvgl/src/draw/sdl/lv_draw_sdl_polygon.o \
./lvgl/src/draw/sdl/lv_draw_sdl_rect.o \
./lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.o \
./lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.o \
./lvgl/src/draw/sdl/lv_draw_sdl_utils.o 

C_DEPS += \
./lvgl/src/draw/sdl/lv_draw_sdl.d \
./lvgl/src/draw/sdl/lv_draw_sdl_arc.d \
./lvgl/src/draw/sdl/lv_draw_sdl_bg.d \
./lvgl/src/draw/sdl/lv_draw_sdl_composite.d \
./lvgl/src/draw/sdl/lv_draw_sdl_img.d \
./lvgl/src/draw/sdl/lv_draw_sdl_label.d \
./lvgl/src/draw/sdl/lv_draw_sdl_layer.d \
./lvgl/src/draw/sdl/lv_draw_sdl_line.d \
./lvgl/src/draw/sdl/lv_draw_sdl_mask.d \
./lvgl/src/draw/sdl/lv_draw_sdl_polygon.d \
./lvgl/src/draw/sdl/lv_draw_sdl_rect.d \
./lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.d \
./lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.d \
./lvgl/src/draw/sdl/lv_draw_sdl_utils.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/draw/sdl/%.o lvgl/src/draw/sdl/%.su lvgl/src/draw/sdl/%.cyclo: ../lvgl/src/draw/sdl/%.c lvgl/src/draw/sdl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"C:/Users/bhara/STM32CubeIDE/EmbeddedGraphicsLVGL-MCU3/Projects/003_RGB_Mixer/3_32F407DISCOVERY/bsp_f4x/lcd" -I"C:/Users/bhara/STM32CubeIDE/EmbeddedGraphicsLVGL-MCU3/Projects/003_RGB_Mixer/3_32F407DISCOVERY/bsp_f4x/lvgl" -I"C:/Users/bhara/STM32CubeIDE/EmbeddedGraphicsLVGL-MCU3/Projects/003_RGB_Mixer/3_32F407DISCOVERY/bsp_f4x/tsc" -I"C:/Users/bhara/STM32CubeIDE/EmbeddedGraphicsLVGL-MCU3/Projects/003_RGB_Mixer/3_32F407DISCOVERY" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-draw-2f-sdl

clean-lvgl-2f-src-2f-draw-2f-sdl:
	-$(RM) ./lvgl/src/draw/sdl/lv_draw_sdl.cyclo ./lvgl/src/draw/sdl/lv_draw_sdl.d ./lvgl/src/draw/sdl/lv_draw_sdl.o ./lvgl/src/draw/sdl/lv_draw_sdl.su ./lvgl/src/draw/sdl/lv_draw_sdl_arc.cyclo ./lvgl/src/draw/sdl/lv_draw_sdl_arc.d ./lvgl/src/draw/sdl/lv_draw_sdl_arc.o ./lvgl/src/draw/sdl/lv_draw_sdl_arc.su ./lvgl/src/draw/sdl/lv_draw_sdl_bg.cyclo ./lvgl/src/draw/sdl/lv_draw_sdl_bg.d ./lvgl/src/draw/sdl/lv_draw_sdl_bg.o ./lvgl/src/draw/sdl/lv_draw_sdl_bg.su ./lvgl/src/draw/sdl/lv_draw_sdl_composite.cyclo ./lvgl/src/draw/sdl/lv_draw_sdl_composite.d ./lvgl/src/draw/sdl/lv_draw_sdl_composite.o ./lvgl/src/draw/sdl/lv_draw_sdl_composite.su ./lvgl/src/draw/sdl/lv_draw_sdl_img.cyclo ./lvgl/src/draw/sdl/lv_draw_sdl_img.d ./lvgl/src/draw/sdl/lv_draw_sdl_img.o ./lvgl/src/draw/sdl/lv_draw_sdl_img.su ./lvgl/src/draw/sdl/lv_draw_sdl_label.cyclo ./lvgl/src/draw/sdl/lv_draw_sdl_label.d ./lvgl/src/draw/sdl/lv_draw_sdl_label.o ./lvgl/src/draw/sdl/lv_draw_sdl_label.su ./lvgl/src/draw/sdl/lv_draw_sdl_layer.cyclo ./lvgl/src/draw/sdl/lv_draw_sdl_layer.d ./lvgl/src/draw/sdl/lv_draw_sdl_layer.o ./lvgl/src/draw/sdl/lv_draw_sdl_layer.su ./lvgl/src/draw/sdl/lv_draw_sdl_line.cyclo ./lvgl/src/draw/sdl/lv_draw_sdl_line.d ./lvgl/src/draw/sdl/lv_draw_sdl_line.o ./lvgl/src/draw/sdl/lv_draw_sdl_line.su ./lvgl/src/draw/sdl/lv_draw_sdl_mask.cyclo ./lvgl/src/draw/sdl/lv_draw_sdl_mask.d ./lvgl/src/draw/sdl/lv_draw_sdl_mask.o ./lvgl/src/draw/sdl/lv_draw_sdl_mask.su ./lvgl/src/draw/sdl/lv_draw_sdl_polygon.cyclo ./lvgl/src/draw/sdl/lv_draw_sdl_polygon.d ./lvgl/src/draw/sdl/lv_draw_sdl_polygon.o ./lvgl/src/draw/sdl/lv_draw_sdl_polygon.su ./lvgl/src/draw/sdl/lv_draw_sdl_rect.cyclo ./lvgl/src/draw/sdl/lv_draw_sdl_rect.d ./lvgl/src/draw/sdl/lv_draw_sdl_rect.o ./lvgl/src/draw/sdl/lv_draw_sdl_rect.su ./lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.cyclo ./lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.d ./lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.o ./lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.su ./lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.cyclo ./lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.d ./lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.o ./lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.su ./lvgl/src/draw/sdl/lv_draw_sdl_utils.cyclo ./lvgl/src/draw/sdl/lv_draw_sdl_utils.d ./lvgl/src/draw/sdl/lv_draw_sdl_utils.o ./lvgl/src/draw/sdl/lv_draw_sdl_utils.su

.PHONY: clean-lvgl-2f-src-2f-draw-2f-sdl

