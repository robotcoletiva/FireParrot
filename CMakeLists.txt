# CMakeLists for CU-ARdrone

CMAKE_MINIMUM_REQUIRED (VERSION 2.6)
PROJECT (fireparrot)

# Build the gamepad lib
ADD_SUBDIRECTORY(gamepad)
ADD_SUBDIRECTORY(dronelib)
ADD_SUBDIRECTORY(libopendrone)

IF(CMAKE_COMPILER_IS_GNUCXX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g -std=c++0x")
ENDIF(CMAKE_COMPILER_IS_GNUCXX)

LINK_DIRECTORIES (${fireparrot_BINARY_DIR}/gamepad)
LINK_DIRECTORIES (${fireparrot_BINARY_DIR}/dronelib)
LINK_DIRECTORIES (${fireparrot_BINARY_DIR}/libopendrone)

SET(DRONE_VERSION_MAJOR 1)
SET(DRONE_VERSION_MINOR 1)

SET(DRONE_HEADERS   include/DroneConfig.h
                    include/Common.h
                    include/InputDevice.h
                    include/Drone.h
                    include/XBoxDevice.h
                    include/DeviceManager.h
                    include/GLRenderFrame.h)

SET(DRONE_SOURCES   src/main.cpp
                    src/InputDevice.cpp
                    src/Drone.cpp
                    src/XBoxDevice.cpp
                    src/DeviceManager.cpp
                    src/GLRenderFrame.cpp)

SOURCE_GROUP(fireparrot FILES    ${DRONE_HEADERS} ${DRONE_SOURCES})

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/include)

CONFIGURE_FILE (
  "${PROJECT_SOURCE_DIR}/include/DroneConfig.h.in"
  "${PROJECT_SOURCE_DIR}/include/DroneConfig.h"
  )

ADD_EXECUTABLE(fireparrot    ${DRONE_SOURCES} ${DRONE_HEADERS})

TARGET_LINK_LIBRARIES(fireparrot gamepad dronelib glfw GL)
