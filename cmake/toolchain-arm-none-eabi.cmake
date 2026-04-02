# Toolchain file for arm-none-eabi (Cortex-M, bare-metal)
# Used by STM32 and RP2040 presets

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

# Expect arm-none-eabi-gcc on PATH (installed via apt arm-none-eabi or Homebrew)
find_program(ARM_CC arm-none-eabi-gcc REQUIRED)
find_program(ARM_CXX arm-none-eabi-g++ REQUIRED)
find_program(ARM_OBJCOPY arm-none-eabi-objcopy REQUIRED)
find_program(ARM_SIZE arm-none-eabi-size REQUIRED)

set(CMAKE_C_COMPILER   ${ARM_CC})
set(CMAKE_CXX_COMPILER ${ARM_CXX})
set(CMAKE_ASM_COMPILER ${ARM_CC})

# Skip compiler identification tests (requires hardware / QEMU)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# Default bare-metal flags (board cmake files may add MCU-specific flags)
set(CMAKE_C_FLAGS_INIT   "-ffunction-sections -fdata-sections -fno-common")
set(CMAKE_EXE_LINKER_FLAGS_INIT "-Wl,--gc-sections -specs=nosys.specs")

# Search only in the sysroot, not on the host
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
