################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS :=  \
../drivers \
../controller


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../drivers/Communication.cpp \
../drivers/Input.cpp \
../drivers/LED.cpp \
../drivers/Output.cpp \
../drivers/ParallelTextLCD.cpp \
../drivers/Storage.cpp \
../drivers/Timer.cpp \
../main.cpp


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
drivers/Communication.o \
drivers/Input.o \
drivers/LED.o \
drivers/Output.o \
drivers/ParallelTextLCD.o \
drivers/Storage.o \
drivers/Timer.o \
main.o

OBJS_AS_ARGS +=  \
drivers/Communication.o \
drivers/Input.o \
drivers/LED.o \
drivers/Output.o \
drivers/ParallelTextLCD.o \
drivers/Storage.o \
drivers/Timer.o \
main.o

C_DEPS +=  \
drivers/Communication.d \
drivers/Input.d \
drivers/LED.d \
drivers/Output.d \
drivers/ParallelTextLCD.d \
drivers/Storage.d \
drivers/Timer.d \
main.d

C_DEPS_AS_ARGS +=  \
drivers/Communication.d \
drivers/Input.d \
drivers/LED.d \
drivers/Output.d \
drivers/ParallelTextLCD.d \
drivers/Storage.d \
drivers/Timer.d \
main.d

OUTPUT_FILE_PATH +=MicrocontrollerSystem.elf

OUTPUT_FILE_PATH_AS_ARGS +=MicrocontrollerSystem.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler

















drivers/%.o: ../drivers/%.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 4.9.2
	$(QUOTE)E:\Microsoft Visual Studio\Atmel Studio 7.0\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DNDEBUG  -I"E:\Microsoft Visual Studio\Atmel Studio 7.0\7.0\Packs\atmel\ATmega_DFP\1.0.98\include"  -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -mmcu=atmega32 -B "E:\Microsoft Visual Studio\Atmel Studio 7.0\7.0\Packs\atmel\ATmega_DFP\1.0.98\gcc\dev\atmega32" -c -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

./%.o: .././%.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 4.9.2
	$(QUOTE)E:\Microsoft Visual Studio\Atmel Studio 7.0\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DNDEBUG  -I"E:\Microsoft Visual Studio\Atmel Studio 7.0\7.0\Packs\atmel\ATmega_DFP\1.0.98\include"  -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -mmcu=atmega32 -B "E:\Microsoft Visual Studio\Atmel Studio 7.0\7.0\Packs\atmel\ATmega_DFP\1.0.98\gcc\dev\atmega32" -c -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR8/GNU Linker : 4.9.2
	$(QUOTE)E:\Microsoft Visual Studio\Atmel Studio 7.0\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="MicrocontrollerSystem.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=atmega32 -B "E:\Microsoft Visual Studio\Atmel Studio 7.0\7.0\Packs\atmel\ATmega_DFP\1.0.98\gcc\dev\atmega32"  
	@echo Finished building target: $@
	"E:\Microsoft Visual Studio\Atmel Studio 7.0\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "MicrocontrollerSystem.elf" "MicrocontrollerSystem.hex"
	"E:\Microsoft Visual Studio\Atmel Studio 7.0\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "MicrocontrollerSystem.elf" "MicrocontrollerSystem.eep" || exit 0
	"E:\Microsoft Visual Studio\Atmel Studio 7.0\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "MicrocontrollerSystem.elf" > "MicrocontrollerSystem.lss"
	"E:\Microsoft Visual Studio\Atmel Studio 7.0\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "MicrocontrollerSystem.elf" "MicrocontrollerSystem.srec"
	"E:\Microsoft Visual Studio\Atmel Studio 7.0\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "MicrocontrollerSystem.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "MicrocontrollerSystem.elf" "MicrocontrollerSystem.a" "MicrocontrollerSystem.hex" "MicrocontrollerSystem.lss" "MicrocontrollerSystem.eep" "MicrocontrollerSystem.map" "MicrocontrollerSystem.srec" "MicrocontrollerSystem.usersignatures"
	