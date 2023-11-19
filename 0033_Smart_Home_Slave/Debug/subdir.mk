################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../H7SEG_program.c \
../HLED_program.c \
../HServo_program.c \
../HStpper_program.c \
../MADC_program.c \
../MDIO_program.c \
../MGIE_program.c \
../MSPI_program.c \
../MTIMER_program.c \
../comonFunctions.c \
../main.c \
../smart_home.c 

OBJS += \
./H7SEG_program.o \
./HLED_program.o \
./HServo_program.o \
./HStpper_program.o \
./MADC_program.o \
./MDIO_program.o \
./MGIE_program.o \
./MSPI_program.o \
./MTIMER_program.o \
./comonFunctions.o \
./main.o \
./smart_home.o 

C_DEPS += \
./H7SEG_program.d \
./HLED_program.d \
./HServo_program.d \
./HStpper_program.d \
./MADC_program.d \
./MDIO_program.d \
./MGIE_program.d \
./MSPI_program.d \
./MTIMER_program.d \
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


