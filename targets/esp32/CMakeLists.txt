add_library(hal_target STATIC hal_gpio.c hal_system.c)
target_link_libraries(hal_target PUBLIC hal)
