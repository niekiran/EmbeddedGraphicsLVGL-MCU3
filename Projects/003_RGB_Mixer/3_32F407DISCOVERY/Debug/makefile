################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include lvgl/src/widgets/win/subdir.mk
-include lvgl/src/widgets/tileview/subdir.mk
-include lvgl/src/widgets/textarea/subdir.mk
-include lvgl/src/widgets/tabview/subdir.mk
-include lvgl/src/widgets/table/subdir.mk
-include lvgl/src/widgets/switch/subdir.mk
-include lvgl/src/widgets/spinner/subdir.mk
-include lvgl/src/widgets/spinbox/subdir.mk
-include lvgl/src/widgets/span/subdir.mk
-include lvgl/src/widgets/slider/subdir.mk
-include lvgl/src/widgets/roller/subdir.mk
-include lvgl/src/widgets/objx_templ/subdir.mk
-include lvgl/src/widgets/msgbox/subdir.mk
-include lvgl/src/widgets/meter/subdir.mk
-include lvgl/src/widgets/menu/subdir.mk
-include lvgl/src/widgets/list/subdir.mk
-include lvgl/src/widgets/line/subdir.mk
-include lvgl/src/widgets/led/subdir.mk
-include lvgl/src/widgets/label/subdir.mk
-include lvgl/src/widgets/keyboard/subdir.mk
-include lvgl/src/widgets/imgbtn/subdir.mk
-include lvgl/src/widgets/img/subdir.mk
-include lvgl/src/widgets/dropdown/subdir.mk
-include lvgl/src/widgets/colorwheel/subdir.mk
-include lvgl/src/widgets/checkbox/subdir.mk
-include lvgl/src/widgets/chart/subdir.mk
-include lvgl/src/widgets/canvas/subdir.mk
-include lvgl/src/widgets/calendar/subdir.mk
-include lvgl/src/widgets/btnmatrix/subdir.mk
-include lvgl/src/widgets/btn/subdir.mk
-include lvgl/src/widgets/bar/subdir.mk
-include lvgl/src/widgets/arc/subdir.mk
-include lvgl/src/widgets/animimg/subdir.mk
-include lvgl/src/themes/mono/subdir.mk
-include lvgl/src/themes/default/subdir.mk
-include lvgl/src/themes/basic/subdir.mk
-include lvgl/src/others/snapshot/subdir.mk
-include lvgl/src/others/msg/subdir.mk
-include lvgl/src/others/monkey/subdir.mk
-include lvgl/src/others/imgfont/subdir.mk
-include lvgl/src/others/ime/subdir.mk
-include lvgl/src/others/gridnav/subdir.mk
-include lvgl/src/others/fragment/subdir.mk
-include lvgl/src/misc/subdir.mk
-include lvgl/src/libs/sjpg/subdir.mk
-include lvgl/src/libs/rlottie/subdir.mk
-include lvgl/src/libs/qrcode/subdir.mk
-include lvgl/src/libs/png/subdir.mk
-include lvgl/src/libs/gif/subdir.mk
-include lvgl/src/libs/fsdrv/subdir.mk
-include lvgl/src/libs/freetype/subdir.mk
-include lvgl/src/libs/ffmpeg/subdir.mk
-include lvgl/src/libs/bmp/subdir.mk
-include lvgl/src/layouts/grid/subdir.mk
-include lvgl/src/layouts/flex/subdir.mk
-include lvgl/src/hal/subdir.mk
-include lvgl/src/font/subdir.mk
-include lvgl/src/draw/swm341_dma2d/subdir.mk
-include lvgl/src/draw/sw/subdir.mk
-include lvgl/src/draw/stm32_dma2d/subdir.mk
-include lvgl/src/draw/sdl/subdir.mk
-include lvgl/src/draw/nxp/vglite/subdir.mk
-include lvgl/src/draw/nxp/pxp/subdir.mk
-include lvgl/src/draw/nxp/subdir.mk
-include lvgl/src/draw/arm2d/subdir.mk
-include lvgl/src/draw/subdir.mk
-include lvgl/src/core/subdir.mk
-include bsp_f4x/tsc/subdir.mk
-include bsp_f4x/lvgl/subdir.mk
-include bsp_f4x/lcd/subdir.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := F407x_RGB_Mixer
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
F407x_RGB_Mixer.elf \

MAP_FILES += \
F407x_RGB_Mixer.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
F407x_RGB_Mixer.list \


# All Target
all: main-build

# Main-build Target
main-build: F407x_RGB_Mixer.elf secondary-outputs

# Tool invocations
F407x_RGB_Mixer.elf F407x_RGB_Mixer.map: $(OBJS) $(USER_OBJS) D:\fastbit\courses\mcu3\git\EmbeddedGraphicsLVGL-MCU3\Projects\003_RGB_Mixer\3_32F407DISCOVERY\STM32F407VGTX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "F407x_RGB_Mixer.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"D:\fastbit\courses\mcu3\git\EmbeddedGraphicsLVGL-MCU3\Projects\003_RGB_Mixer\3_32F407DISCOVERY\STM32F407VGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="F407x_RGB_Mixer.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

F407x_RGB_Mixer.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "F407x_RGB_Mixer.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) F407x_RGB_Mixer.elf F407x_RGB_Mixer.list F407x_RGB_Mixer.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
