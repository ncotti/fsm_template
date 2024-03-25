cmake_minimum_required(VERSION 3.10)

project(Cotti)
add_compile_options(-g)

add_executable(main
    ${PROJECT_SOURCE_DIR}/src/main.c
    ${PROJECT_SOURCE_DIR}/src/fsm_first/fsm_first.c
    ${PROJECT_SOURCE_DIR}/src/fsm_second/fsm_second.c)

install(TARGETS main DESTINATION ${PROJECT_SOURCE_DIR}/bin)
