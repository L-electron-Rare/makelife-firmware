# targets/cosim/CMakeLists.txt
# Cosim target: HAL backed by POSIX shared memory.
# Compiled when TARGET_ARCH=cosim and COSIM_ENABLED=ON.
add_library(hal_target STATIC
    hal_gpio_cosim.c
    hal_i2c_cosim.c
)
target_link_libraries(hal_target PUBLIC hal)
target_include_directories(hal_target PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# POSIX shared memory + pthread (for spin-wait in I2C)
target_link_libraries(hal_target PUBLIC rt)
target_compile_definitions(hal_target PUBLIC COSIM_ENABLED=1)
