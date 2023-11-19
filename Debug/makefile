################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
0013_StopWatch.lss \

FLASH_IMAGE += \
0013_StopWatch.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: 0013_StopWatch.elf secondary-outputs

# Tool invocations
0013_StopWatch.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,0013_StopWatch.map -mmcu=atmega32 -o "0013_StopWatch.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

0013_StopWatch.lss: 0013_StopWatch.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 0013_StopWatch.elf  >"0013_StopWatch.lss"
	@echo 'Finished building: $@'
	@echo ' '

0013_StopWatch.hex: 0013_StopWatch.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 0013_StopWatch.elf  "0013_StopWatch.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 0013_StopWatch.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 0013_StopWatch.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 0013_StopWatch.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
