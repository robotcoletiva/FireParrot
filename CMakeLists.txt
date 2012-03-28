# CMakeLists for CU-ARdrone

CMAKE_MINIMUM_REQUIRED (VERSION 2.6)
PROJECT (fireparrot)

# Build the gamepad lib
ADD_SUBDIRECTORY(gamepad)
ADD_SUBDIRECTORY(dronelib)
ADD_SUBDIRECTORY(libopendrone)

IF(CMAKE_COMPILER_IS_GNUCXX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++0x")
ENDIF(CMAKE_COMPILER_IS_GNUCXX)

LINK_DIRECTORIES (${fireparrot_BINARY_DIR}/gamepad) 
LINK_DIRECTORIES (${fireparrot_BINARY_DIR}/dronelib) 
LINK_DIRECTORIES (${fireparrot_BINARY_DIR}/libopendrone) 

SET(DRONE_VERSION_MAJOR 1)
SET(DRONE_VERSION_MINOR 0)

SET(DRONE_HEADERS   DroneConfig.h InputDevice.h Drone.h
                    XBoxDevice.h DeviceManager.h GLRenderFrame.h)
SET(DRONE_SOURCES   main.cpp InputDevice.cpp Drone.cpp
                    XBoxDevice.cpp DeviceManager.cpp GLRenderFrame.cpp)
SOURCE_GROUP(fireparrot FILES    ${DRONE_HEADERS} ${DRONE_SOURCES})

INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}")

CONFIGURE_FILE (
  "${PROJECT_SOURCE_DIR}/DroneConfig.h.in"
  "${PROJECT_SOURCE_DIR}/DroneConfig.h"
  )

ADD_EXECUTABLE(fireparrot    ${DRONE_SOURCES} ${DRONE_HEADERS})

TARGET_LINK_LIBRARIES(fireparrot gamepad dronelib glfw GL)
