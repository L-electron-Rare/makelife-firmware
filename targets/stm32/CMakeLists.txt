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

# STM32 HAL integration (active when STM32CubeF4 sysroot is present)
# Uncomment when cross-compiling with CubeF4 + arm-none-eabi toolchain:
#
# include(${CMAKE_SOURCE_DIR}/boards/nucleo-f446re.cmake)
# target_include_directories(hal_target PRIVATE
#     ${STM32CUBEF4_PATH}/Drivers/CMSIS/Include
#     ${STM32CUBEF4_PATH}/Drivers/CMSIS/Device/ST/STM32F4xx/Include
#     ${STM32CUBEF4_PATH}/Drivers/STM32F4xx_HAL_Driver/Inc
# )
# target_compile_definitions(hal_target PRIVATE STM32F446xx USE_HAL_DRIVER)
