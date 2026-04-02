add_library(hal_target STATIC hal_gpio.c hal_system.c)
target_link_libraries(hal_target PUBLIC hal)

# Semihosting output for QEMU testing
if(QEMU_BUILD)
    target_compile_definitions(hal_target PUBLIC QEMU_BUILD=1)
    target_link_options(hal_target PUBLIC
        --specs=rdimon.specs
        -lrdimon
    )
endif()

# Pico SDK integration (active when PICO_SDK_PATH is set and SDK is imported)
# Uncomment when cross-compiling with the official Pico SDK:
#
# include(${CMAKE_SOURCE_DIR}/boards/pico.cmake)
# target_link_libraries(hal_target PRIVATE
#     pico_stdlib
#     hardware_gpio
#     hardware_timer
# )
