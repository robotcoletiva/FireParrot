# CMakeLists for CU-ARdrone

cmake_minimum_required (VERSION 2.6)
project (cuardrone)

# Build the gamepad lib
add_subdirectory(gamepad)
add_subdirectory(dronelib)

link_directories (${cuardrone_BINARY_DIR}/gamepad) 
link_directories (${cuardrone_BINARY_DIR}/dronelib) 

set(DRONE_VERSION_MAJOR 0)
set(DRONE_VERSION_MINOR 1)

set(DRONE_HEADERS   DroneConfig.h InputDevice.h Drone.h
                    XBoxDevice.h DeviceManager.h)
set(DRONE_SOURCES   main.cpp InputDevice.cpp Drone.cpp
                    XBoxDevice.cpp DeviceManager.cpp)
source_group(cuardrone FILES    ${DRONE_HEADERS} ${DRONE_SOURCES})

include_directories("${PROJECT_SOURCE_DIR}")

configure_file (
  "${PROJECT_SOURCE_DIR}/DroneConfig.h.in"
  "${PROJECT_SOURCE_DIR}/DroneConfig.h"
  )

add_executable(cuardrone    ${DRONE_SOURCES} ${DRONE_HEADERS}
                            ${DRONELIB_SOURCES} ${DRONELIB_HEADERS})

target_link_libraries(cuardrone gamepad dronelib)
