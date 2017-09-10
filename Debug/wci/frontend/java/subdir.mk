################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../wci/frontend/java/JavaError.cpp \
../wci/frontend/java/JavaErrorHandler.cpp \
../wci/frontend/java/JavaParserTD.cpp \
../wci/frontend/java/JavaScanner.cpp \
../wci/frontend/java/JavaToken.cpp 

OBJS += \
./wci/frontend/java/JavaError.o \
./wci/frontend/java/JavaErrorHandler.o \
./wci/frontend/java/JavaParserTD.o \
./wci/frontend/java/JavaScanner.o \
./wci/frontend/java/JavaToken.o 

CPP_DEPS += \
./wci/frontend/java/JavaError.d \
./wci/frontend/java/JavaErrorHandler.d \
./wci/frontend/java/JavaParserTD.d \
./wci/frontend/java/JavaScanner.d \
./wci/frontend/java/JavaToken.d 


# Each subdirectory must supply rules for building sources it contributes
wci/frontend/java/%.o: ../wci/frontend/java/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -std=gnu++11 -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


