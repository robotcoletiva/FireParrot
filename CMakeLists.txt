# CMakeLists for CU-ARdrone

cmake_minimum_required (VERSION 2.6)
project (fireparrot)

# Build the gamepad lib
add_subdirectory(gamepad)
add_subdirectory(dronelib)
add_subdirectory(libopendrone)

link_directories (${fireparrot_BINARY_DIR}/gamepad) 
link_directories (${fireparrot_BINARY_DIR}/dronelib) 
link_directories (${fireparrot_BINARY_DIR}/libopendrone) 

set(DRONE_VERSION_MAJOR 1)
set(DRONE_VERSION_MINOR 0)

set(DRONE_HEADERS   DroneConfig.h InputDevice.h Drone.h
                    XBoxDevice.h DeviceManager.h)
set(DRONE_SOURCES   main.cpp InputDevice.cpp Drone.cpp
                    XBoxDevice.cpp DeviceManager.cpp)
source_group(fireparrot FILES    ${DRONE_HEADERS} ${DRONE_SOURCES})

include_directories("${PROJECT_SOURCE_DIR}")

configure_file (
  "${PROJECT_SOURCE_DIR}/DroneConfig.h.in"
  "${PROJECT_SOURCE_DIR}/DroneConfig.h"
  )

add_executable(fireparrot    ${DRONE_SOURCES} ${DRONE_HEADERS})

target_link_libraries(fireparrot gamepad dronelib)
