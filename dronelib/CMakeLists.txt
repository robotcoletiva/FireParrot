# CMakeLists for ardrone

set(DRONELIB_VERSION_MAJOR 0)
set(DRONELIB_VERSION_MINOR 1)

set(DRONELIB_HEADERS ARDrone.h MemoryLibrary.h)
set(DRONELIB_SOURCES ARDrone.cpp)
source_group(dronelib FILES    ${DRONELIB_HEADERS} ${DRONELIB_SOURCES})

include_directories("${PROJECT_SOURCE_DIR}")

add_library(dronelib    ${DRONELIB_SOURCES} ${DRONELIB_HEADERS})

target_link_libraries(dronelib commonc++ X11 )
