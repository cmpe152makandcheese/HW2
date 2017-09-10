################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../wci/backend/Backend.cpp \
../wci/backend/BackendFactory.cpp 

OBJS += \
./wci/backend/Backend.o \
./wci/backend/BackendFactory.o 

CPP_DEPS += \
./wci/backend/Backend.d \
./wci/backend/BackendFactory.d 


# Each subdirectory must supply rules for building sources it contributes
wci/backend/%.o: ../wci/backend/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -std=gnu++11 -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


