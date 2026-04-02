# Board config: Nucleo-F446RE (STM32F446RE, Cortex-M4 + FPU)

set(MCU_FLAGS "-mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard")

# Passed to the STM32 HAL to select the correct register headers
# Uncomment when compiling with STM32CubeF4 or libopencm3
# add_definitions(-DSTM32F446xx)

# Linker script (provided by CubeF4 or a custom one in the project)
# set(LINKER_SCRIPT ${CMAKE_CURRENT_LIST_DIR}/../targets/stm32/STM32F446RETx_FLASH.ld)

string(APPEND CMAKE_C_FLAGS " ${MCU_FLAGS}")
string(APPEND CMAKE_EXE_LINKER_FLAGS " ${MCU_FLAGS}")
