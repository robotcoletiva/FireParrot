# CMakeLists for gamepad

set(PAD_VERSION_MAJOR 0)
set(PAD_VERSION_MINOR 1)

set(PAD_HEADERS gamepad.h)
set(PAD_SOURCES gamepad.c)
source_group(gamepad FILES    ${PAD_HEADERS} ${PAD_SOURCES})

include_directories("${PROJECT_SOURCE_DIR}")

add_library(gamepad    ${PAD_SOURCES} ${PAD_HEADERS})

IF(CMAKE_COMPILER_IS_GNUCXX)
    target_link_libraries(gamepad udev)
ENDIF(CMAKE_COMPILER_IS_GNUCXX)

IF(WIN32)
    target_link_libraries(gamepad XInput.lib)
ENDIF(WIN32)

