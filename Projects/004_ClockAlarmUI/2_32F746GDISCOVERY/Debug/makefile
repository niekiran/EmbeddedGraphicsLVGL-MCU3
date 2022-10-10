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
-include lvgl/src/others/file_explorer/subdir.mk
-include lvgl/src/misc/subdir.mk
-include lvgl/src/libs/tiny_ttf/subdir.mk
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
-include lvgl/src/draw/gd32_ipa/subdir.mk
-include lvgl/src/draw/arm2d/subdir.mk
-include lvgl/src/draw/subdir.mk
-include lvgl/src/core/subdir.mk
-include hal_stm_lvgl/touchpad/subdir.mk
-include hal_stm_lvgl/tft/subdir.mk
-include hal_stm_lvgl/STM32746G-Discovery/subdir.mk
-include hal_stm_lvgl/Components/wm8994/subdir.mk
-include hal_stm_lvgl/Components/ts3510/subdir.mk
-include hal_stm_lvgl/Components/stmpe811/subdir.mk
-include hal_stm_lvgl/Components/st7789h2/subdir.mk
-include hal_stm_lvgl/Components/st7735/subdir.mk
-include hal_stm_lvgl/Components/s5k5cag/subdir.mk
-include hal_stm_lvgl/Components/ov9655/subdir.mk
-include hal_stm_lvgl/Components/otm8009a/subdir.mk
-include hal_stm_lvgl/Components/mfxstm32l152/subdir.mk
-include hal_stm_lvgl/Components/ft6x06/subdir.mk
-include hal_stm_lvgl/Components/ft5336/subdir.mk
-include hal_stm_lvgl/Components/exc7200/subdir.mk
-include hal_stm_lvgl/Components/adv7533/subdir.mk
-include Drivers/STM32F7xx_HAL_Driver/Src/subdir.mk
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


BUILD_ARTIFACT_NAME := F746x_ClockAlarmUI
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
F746x_ClockAlarmUI.elf \

MAP_FILES += \
F746x_ClockAlarmUI.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
F746x_ClockAlarmUI.list \


# All Target
all: main-build

# Main-build Target
main-build: F746x_ClockAlarmUI.elf secondary-outputs

# Tool invocations
F746x_ClockAlarmUI.elf F746x_ClockAlarmUI.map: $(OBJS) $(USER_OBJS) F:\Workspace\git\EmbeddedGraphicsLVGL-MCU3-main\Projects\004ClockAlarmUI\2_32F746GDISCOVERY\STM32F746NGHX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "F746x_ClockAlarmUI.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m7 -T"F:\Workspace\git\EmbeddedGraphicsLVGL-MCU3-main\Projects\004ClockAlarmUI\2_32F746GDISCOVERY\STM32F746NGHX_FLASH.ld" --specs=nosys.specs -Wl,-Map="F746x_ClockAlarmUI.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

F746x_ClockAlarmUI.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "F746x_ClockAlarmUI.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) F746x_ClockAlarmUI.elf F746x_ClockAlarmUI.list F746x_ClockAlarmUI.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
