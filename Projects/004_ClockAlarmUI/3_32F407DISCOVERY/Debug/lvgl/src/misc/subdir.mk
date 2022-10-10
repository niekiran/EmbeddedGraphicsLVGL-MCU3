################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/misc/lv_anim.c \
../lvgl/src/misc/lv_anim_timeline.c \
../lvgl/src/misc/lv_area.c \
../lvgl/src/misc/lv_async.c \
../lvgl/src/misc/lv_bidi.c \
../lvgl/src/misc/lv_color.c \
../lvgl/src/misc/lv_fs.c \
../lvgl/src/misc/lv_gc.c \
../lvgl/src/misc/lv_ll.c \
../lvgl/src/misc/lv_log.c \
../lvgl/src/misc/lv_lru.c \
../lvgl/src/misc/lv_malloc_builtin.c \
../lvgl/src/misc/lv_math.c \
../lvgl/src/misc/lv_mem.c \
../lvgl/src/misc/lv_memcpy_builtin.c \
../lvgl/src/misc/lv_printf.c \
../lvgl/src/misc/lv_style.c \
../lvgl/src/misc/lv_style_gen.c \
../lvgl/src/misc/lv_templ.c \
../lvgl/src/misc/lv_timer.c \
../lvgl/src/misc/lv_tlsf.c \
../lvgl/src/misc/lv_txt.c \
../lvgl/src/misc/lv_txt_ap.c \
../lvgl/src/misc/lv_utils.c 

OBJS += \
./lvgl/src/misc/lv_anim.o \
./lvgl/src/misc/lv_anim_timeline.o \
./lvgl/src/misc/lv_area.o \
./lvgl/src/misc/lv_async.o \
./lvgl/src/misc/lv_bidi.o \
./lvgl/src/misc/lv_color.o \
./lvgl/src/misc/lv_fs.o \
./lvgl/src/misc/lv_gc.o \
./lvgl/src/misc/lv_ll.o \
./lvgl/src/misc/lv_log.o \
./lvgl/src/misc/lv_lru.o \
./lvgl/src/misc/lv_malloc_builtin.o \
./lvgl/src/misc/lv_math.o \
./lvgl/src/misc/lv_mem.o \
./lvgl/src/misc/lv_memcpy_builtin.o \
./lvgl/src/misc/lv_printf.o \
./lvgl/src/misc/lv_style.o \
./lvgl/src/misc/lv_style_gen.o \
./lvgl/src/misc/lv_templ.o \
./lvgl/src/misc/lv_timer.o \
./lvgl/src/misc/lv_tlsf.o \
./lvgl/src/misc/lv_txt.o \
./lvgl/src/misc/lv_txt_ap.o \
./lvgl/src/misc/lv_utils.o 

C_DEPS += \
./lvgl/src/misc/lv_anim.d \
./lvgl/src/misc/lv_anim_timeline.d \
./lvgl/src/misc/lv_area.d \
./lvgl/src/misc/lv_async.d \
./lvgl/src/misc/lv_bidi.d \
./lvgl/src/misc/lv_color.d \
./lvgl/src/misc/lv_fs.d \
./lvgl/src/misc/lv_gc.d \
./lvgl/src/misc/lv_ll.d \
./lvgl/src/misc/lv_log.d \
./lvgl/src/misc/lv_lru.d \
./lvgl/src/misc/lv_malloc_builtin.d \
./lvgl/src/misc/lv_math.d \
./lvgl/src/misc/lv_mem.d \
./lvgl/src/misc/lv_memcpy_builtin.d \
./lvgl/src/misc/lv_printf.d \
./lvgl/src/misc/lv_style.d \
./lvgl/src/misc/lv_style_gen.d \
./lvgl/src/misc/lv_templ.d \
./lvgl/src/misc/lv_timer.d \
./lvgl/src/misc/lv_tlsf.d \
./lvgl/src/misc/lv_txt.d \
./lvgl/src/misc/lv_txt_ap.d \
./lvgl/src/misc/lv_utils.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/misc/%.o lvgl/src/misc/%.su: ../lvgl/src/misc/%.c lvgl/src/misc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I"F:/Workspace/git/EmbeddedGraphicsLVGL-MCU3-main/Projects/004ClockAlarmUI/3_32F407DISCOVERY" -I../Core/Inc -I"F:/Workspace/git/EmbeddedGraphicsLVGL-MCU3-main/Projects/004ClockAlarmUI/3_32F407DISCOVERY/bsp_f4x/lcd" -I"F:/Workspace/git/EmbeddedGraphicsLVGL-MCU3-main/Projects/004ClockAlarmUI/3_32F407DISCOVERY/bsp_f4x/lvgl" -I"F:/Workspace/git/EmbeddedGraphicsLVGL-MCU3-main/Projects/004ClockAlarmUI/3_32F407DISCOVERY/bsp_f4x/tsc" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-misc

clean-lvgl-2f-src-2f-misc:
	-$(RM) ./lvgl/src/misc/lv_anim.d ./lvgl/src/misc/lv_anim.o ./lvgl/src/misc/lv_anim.su ./lvgl/src/misc/lv_anim_timeline.d ./lvgl/src/misc/lv_anim_timeline.o ./lvgl/src/misc/lv_anim_timeline.su ./lvgl/src/misc/lv_area.d ./lvgl/src/misc/lv_area.o ./lvgl/src/misc/lv_area.su ./lvgl/src/misc/lv_async.d ./lvgl/src/misc/lv_async.o ./lvgl/src/misc/lv_async.su ./lvgl/src/misc/lv_bidi.d ./lvgl/src/misc/lv_bidi.o ./lvgl/src/misc/lv_bidi.su ./lvgl/src/misc/lv_color.d ./lvgl/src/misc/lv_color.o ./lvgl/src/misc/lv_color.su ./lvgl/src/misc/lv_fs.d ./lvgl/src/misc/lv_fs.o ./lvgl/src/misc/lv_fs.su ./lvgl/src/misc/lv_gc.d ./lvgl/src/misc/lv_gc.o ./lvgl/src/misc/lv_gc.su ./lvgl/src/misc/lv_ll.d ./lvgl/src/misc/lv_ll.o ./lvgl/src/misc/lv_ll.su ./lvgl/src/misc/lv_log.d ./lvgl/src/misc/lv_log.o ./lvgl/src/misc/lv_log.su ./lvgl/src/misc/lv_lru.d ./lvgl/src/misc/lv_lru.o ./lvgl/src/misc/lv_lru.su ./lvgl/src/misc/lv_malloc_builtin.d ./lvgl/src/misc/lv_malloc_builtin.o ./lvgl/src/misc/lv_malloc_builtin.su ./lvgl/src/misc/lv_math.d ./lvgl/src/misc/lv_math.o ./lvgl/src/misc/lv_math.su ./lvgl/src/misc/lv_mem.d ./lvgl/src/misc/lv_mem.o ./lvgl/src/misc/lv_mem.su ./lvgl/src/misc/lv_memcpy_builtin.d ./lvgl/src/misc/lv_memcpy_builtin.o ./lvgl/src/misc/lv_memcpy_builtin.su ./lvgl/src/misc/lv_printf.d ./lvgl/src/misc/lv_printf.o ./lvgl/src/misc/lv_printf.su ./lvgl/src/misc/lv_style.d ./lvgl/src/misc/lv_style.o ./lvgl/src/misc/lv_style.su ./lvgl/src/misc/lv_style_gen.d ./lvgl/src/misc/lv_style_gen.o ./lvgl/src/misc/lv_style_gen.su ./lvgl/src/misc/lv_templ.d ./lvgl/src/misc/lv_templ.o ./lvgl/src/misc/lv_templ.su ./lvgl/src/misc/lv_timer.d ./lvgl/src/misc/lv_timer.o ./lvgl/src/misc/lv_timer.su ./lvgl/src/misc/lv_tlsf.d ./lvgl/src/misc/lv_tlsf.o ./lvgl/src/misc/lv_tlsf.su ./lvgl/src/misc/lv_txt.d ./lvgl/src/misc/lv_txt.o ./lvgl/src/misc/lv_txt.su ./lvgl/src/misc/lv_txt_ap.d ./lvgl/src/misc/lv_txt_ap.o ./lvgl/src/misc/lv_txt_ap.su ./lvgl/src/misc/lv_utils.d ./lvgl/src/misc/lv_utils.o ./lvgl/src/misc/lv_utils.su

.PHONY: clean-lvgl-2f-src-2f-misc

