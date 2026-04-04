cmake_minimum_required(VERSION 3.25)
project(makelife-firmware C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
if(NOT DEFINED TARGET_ARCH)
    message(FATAL_ERROR "TARGET_ARCH not defined. Use a CMake preset: cmake --preset native")
endif()
message(STATUS "Building for target: ${TARGET_ARCH}")
add_subdirectory(hal)
add_subdirectory(targets/${TARGET_ARCH})
add_subdirectory(lib/unity)
add_subdirectory(app)
if(TARGET_ARCH STREQUAL "native" OR TARGET_ARCH STREQUAL "cosim")
    enable_testing()
    add_subdirectory(tests)

    # Coverage (gcov/lcov) — only for native Debug builds
    option(ENABLE_COVERAGE "Enable gcov coverage" OFF)
    if(ENABLE_COVERAGE AND CMAKE_BUILD_TYPE STREQUAL "Debug")
        target_compile_options(hal_target PRIVATE --coverage -fprofile-arcs -ftest-coverage)
        target_link_options(hal_target PRIVATE --coverage)
        add_custom_target(coverage
            COMMAND ctest --test-dir ${CMAKE_BINARY_DIR} --output-on-failure
            COMMAND lcov --capture --directory ${CMAKE_BINARY_DIR} --output-file coverage.info --ignore-errors mismatch
            COMMAND lcov --remove coverage.info '/usr/*' '*/lib/unity/*' --output-file coverage.info
            COMMAND genhtml coverage.info --output-directory coverage-html
            COMMENT "Running tests + generating coverage report in coverage-html/"
            WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        )
    endif()
endif()
