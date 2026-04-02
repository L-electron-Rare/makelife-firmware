# Board config: Raspberry Pi Pico (RP2040, dual Cortex-M0+)

set(MCU_FLAGS "-mcpu=cortex-m0plus -mthumb")

# Pico SDK CMake integration
# When PICO_SDK_PATH is set, include the SDK before project() in the root CMakeLists:
#
#   if(TARGET_ARCH STREQUAL "rp2040" AND DEFINED ENV{PICO_SDK_PATH})
#       include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)
#   endif()
#
# The SDK then provides pico_stdlib, hardware_gpio, hardware_timer targets.

string(APPEND CMAKE_C_FLAGS " ${MCU_FLAGS}")
string(APPEND CMAKE_EXE_LINKER_FLAGS " ${MCU_FLAGS}")
