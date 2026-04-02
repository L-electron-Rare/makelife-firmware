add_library(hal_target STATIC hal_gpio.c hal_system.c)
target_link_libraries(hal_target PUBLIC hal)

# Pico SDK integration (active when PICO_SDK_PATH is set and SDK is imported)
# Uncomment when cross-compiling with the official Pico SDK:
#
# include(${CMAKE_SOURCE_DIR}/boards/pico.cmake)
# target_link_libraries(hal_target PRIVATE
#     pico_stdlib
#     hardware_gpio
#     hardware_timer
# )
