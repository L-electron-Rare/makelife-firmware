add_executable(firmware main.c)
target_link_libraries(firmware PRIVATE hal_target)
