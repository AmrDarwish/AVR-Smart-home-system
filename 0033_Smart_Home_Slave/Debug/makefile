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
0033_Smart_Home_Slave.lss \

FLASH_IMAGE += \
0033_Smart_Home_Slave.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: 0033_Smart_Home_Slave.elf secondary-outputs

# Tool invocations
0033_Smart_Home_Slave.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,0033_Smart_Home_Slave.map -mmcu=atmega32 -o "0033_Smart_Home_Slave.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

0033_Smart_Home_Slave.lss: 0033_Smart_Home_Slave.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 0033_Smart_Home_Slave.elf  >"0033_Smart_Home_Slave.lss"
	@echo 'Finished building: $@'
	@echo ' '

0033_Smart_Home_Slave.hex: 0033_Smart_Home_Slave.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 0033_Smart_Home_Slave.elf  "0033_Smart_Home_Slave.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 0033_Smart_Home_Slave.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 0033_Smart_Home_Slave.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 0033_Smart_Home_Slave.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
