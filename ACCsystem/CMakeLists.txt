Project(example)
cmake_minimum_required(VERSION 3.10)

add_executable(run ert_main.c ACCsystem.c ACCsystem_CTGACC.c)
target_link_libraries(run PUBLIC m)
target_link_libraries(run PUBLIC rt)
