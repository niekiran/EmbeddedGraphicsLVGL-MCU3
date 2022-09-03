################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/widgets/lv_arc.c \
../lvgl/src/widgets/lv_bar.c \
../lvgl/src/widgets/lv_btn.c \
../lvgl/src/widgets/lv_btnmatrix.c \
../lvgl/src/widgets/lv_canvas.c \
../lvgl/src/widgets/lv_checkbox.c \
../lvgl/src/widgets/lv_dropdown.c \
../lvgl/src/widgets/lv_img.c \
../lvgl/src/widgets/lv_label.c \
../lvgl/src/widgets/lv_line.c \
../lvgl/src/widgets/lv_objx_templ.c \
../lvgl/src/widgets/lv_roller.c \
../lvgl/src/widgets/lv_slider.c \
../lvgl/src/widgets/lv_switch.c \
../lvgl/src/widgets/lv_table.c \
../lvgl/src/widgets/lv_textarea.c 

OBJS += \
./lvgl/src/widgets/lv_arc.o \
./lvgl/src/widgets/lv_bar.o \
./lvgl/src/widgets/lv_btn.o \
./lvgl/src/widgets/lv_btnmatrix.o \
./lvgl/src/widgets/lv_canvas.o \
./lvgl/src/widgets/lv_checkbox.o \
./lvgl/src/widgets/lv_dropdown.o \
./lvgl/src/widgets/lv_img.o \
./lvgl/src/widgets/lv_label.o \
./lvgl/src/widgets/lv_line.o \
./lvgl/src/widgets/lv_objx_templ.o \
./lvgl/src/widgets/lv_roller.o \
./lvgl/src/widgets/lv_slider.o \
./lvgl/src/widgets/lv_switch.o \
./lvgl/src/widgets/lv_table.o \
./lvgl/src/widgets/lv_textarea.o 

C_DEPS += \
./lvgl/src/widgets/lv_arc.d \
./lvgl/src/widgets/lv_bar.d \
./lvgl/src/widgets/lv_btn.d \
./lvgl/src/widgets/lv_btnmatrix.d \
./lvgl/src/widgets/lv_canvas.d \
./lvgl/src/widgets/lv_checkbox.d \
./lvgl/src/widgets/lv_dropdown.d \
./lvgl/src/widgets/lv_img.d \
./lvgl/src/widgets/lv_label.d \
./lvgl/src/widgets/lv_line.d \
./lvgl/src/widgets/lv_objx_templ.d \
./lvgl/src/widgets/lv_roller.d \
./lvgl/src/widgets/lv_slider.d \
./lvgl/src/widgets/lv_switch.d \
./lvgl/src/widgets/lv_table.d \
./lvgl/src/widgets/lv_textarea.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/widgets/%.o lvgl/src/widgets/%.su: ../lvgl/src/widgets/%.c lvgl/src/widgets/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I"D:/fastbit/courses/mcu3/git/EmbeddedGraphicsLVGL-MCU3/Projects/003_RGB_Mixer/1_32F429IDISCOVERY" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-widgets

clean-lvgl-2f-src-2f-widgets:
	-$(RM) ./lvgl/src/widgets/lv_arc.d ./lvgl/src/widgets/lv_arc.o ./lvgl/src/widgets/lv_arc.su ./lvgl/src/widgets/lv_bar.d ./lvgl/src/widgets/lv_bar.o ./lvgl/src/widgets/lv_bar.su ./lvgl/src/widgets/lv_btn.d ./lvgl/src/widgets/lv_btn.o ./lvgl/src/widgets/lv_btn.su ./lvgl/src/widgets/lv_btnmatrix.d ./lvgl/src/widgets/lv_btnmatrix.o ./lvgl/src/widgets/lv_btnmatrix.su ./lvgl/src/widgets/lv_canvas.d ./lvgl/src/widgets/lv_canvas.o ./lvgl/src/widgets/lv_canvas.su ./lvgl/src/widgets/lv_checkbox.d ./lvgl/src/widgets/lv_checkbox.o ./lvgl/src/widgets/lv_checkbox.su ./lvgl/src/widgets/lv_dropdown.d ./lvgl/src/widgets/lv_dropdown.o ./lvgl/src/widgets/lv_dropdown.su ./lvgl/src/widgets/lv_img.d ./lvgl/src/widgets/lv_img.o ./lvgl/src/widgets/lv_img.su ./lvgl/src/widgets/lv_label.d ./lvgl/src/widgets/lv_label.o ./lvgl/src/widgets/lv_label.su ./lvgl/src/widgets/lv_line.d ./lvgl/src/widgets/lv_line.o ./lvgl/src/widgets/lv_line.su ./lvgl/src/widgets/lv_objx_templ.d ./lvgl/src/widgets/lv_objx_templ.o ./lvgl/src/widgets/lv_objx_templ.su ./lvgl/src/widgets/lv_roller.d ./lvgl/src/widgets/lv_roller.o ./lvgl/src/widgets/lv_roller.su ./lvgl/src/widgets/lv_slider.d ./lvgl/src/widgets/lv_slider.o ./lvgl/src/widgets/lv_slider.su ./lvgl/src/widgets/lv_switch.d ./lvgl/src/widgets/lv_switch.o ./lvgl/src/widgets/lv_switch.su ./lvgl/src/widgets/lv_table.d ./lvgl/src/widgets/lv_table.o ./lvgl/src/widgets/lv_table.su ./lvgl/src/widgets/lv_textarea.d ./lvgl/src/widgets/lv_textarea.o ./lvgl/src/widgets/lv_textarea.su

.PHONY: clean-lvgl-2f-src-2f-widgets

