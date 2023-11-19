################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HEEPROM_program.c \
../HKeyPad_Program.c \
../HLCD_program.c \
../HLDR_program.c \
../HLM53_program.c \
../MADC_program.c \
../MDIO_program.c \
../MGIE_program.c \
../MSPI_program.c \
../MTIMER_program.c \
../MTWI_program.c \
../MUART_program.c \
../comonFunctions.c \
../main.c \
../smart_home.c 

OBJS += \
./HEEPROM_program.o \
./HKeyPad_Program.o \
./HLCD_program.o \
./HLDR_program.o \
./HLM53_program.o \
./MADC_program.o \
./MDIO_program.o \
./MGIE_program.o \
./MSPI_program.o \
./MTIMER_program.o \
./MTWI_program.o \
./MUART_program.o \
./comonFunctions.o \
./main.o \
./smart_home.o 

C_DEPS += \
./HEEPROM_program.d \
./HKeyPad_Program.d \
./HLCD_program.d \
./HLDR_program.d \
./HLM53_program.d \
./MADC_program.d \
./MDIO_program.d \
./MGIE_program.d \
./MSPI_program.d \
./MTIMER_program.d \
./MTWI_program.d \
./MUART_program.d \
./comonFunctions.d \
./main.d \
./smart_home.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


