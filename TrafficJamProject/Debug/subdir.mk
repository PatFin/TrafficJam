################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../City.cpp \
../Event.cpp \
../EventList.cpp \
../Sensor.cpp \
../SensorLeaf.cpp \
../SensorRoot.cpp \
../TestsUnitaires.cpp 

OBJS += \
./City.o \
./Event.o \
./EventList.o \
./Sensor.o \
./SensorLeaf.o \
./SensorRoot.o \
./TestsUnitaires.o 

CPP_DEPS += \
./City.d \
./Event.d \
./EventList.d \
./Sensor.d \
./SensorLeaf.d \
./SensorRoot.d \
./TestsUnitaires.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include -I/usr/include/c++/4.9.2 -I/usr/include/c++/4.9 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


