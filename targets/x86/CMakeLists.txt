add_library(hal_target STATIC hal_gpio.c hal_system.c)
target_link_libraries(hal_target PUBLIC hal)
target_include_directories(hal_target PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
