################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../wci/frontend/java/tokens/JavaErrorToken.cpp \
../wci/frontend/java/tokens/JavaNumberToken.cpp \
../wci/frontend/java/tokens/JavaSpecialSymbolToken.cpp \
../wci/frontend/java/tokens/JavaStringToken.cpp \
../wci/frontend/java/tokens/JavaWordToken.cpp 

OBJS += \
./wci/frontend/java/tokens/JavaErrorToken.o \
./wci/frontend/java/tokens/JavaNumberToken.o \
./wci/frontend/java/tokens/JavaSpecialSymbolToken.o \
./wci/frontend/java/tokens/JavaStringToken.o \
./wci/frontend/java/tokens/JavaWordToken.o 

CPP_DEPS += \
./wci/frontend/java/tokens/JavaErrorToken.d \
./wci/frontend/java/tokens/JavaNumberToken.d \
./wci/frontend/java/tokens/JavaSpecialSymbolToken.d \
./wci/frontend/java/tokens/JavaStringToken.d \
./wci/frontend/java/tokens/JavaWordToken.d 


# Each subdirectory must supply rules for building sources it contributes
wci/frontend/java/tokens/%.o: ../wci/frontend/java/tokens/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -std=gnu++11 -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


