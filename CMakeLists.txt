cmake_minimum_required(VERSION 3.10)

project(Cotti)
add_compile_options(-g)

add_executable(main
    ${PROJECT_SOURCE_DIR}/src/fsm.c
    ${PROJECT_SOURCE_DIR}/src/states.c
    ${PROJECT_SOURCE_DIR}/src/transitions.c)

target_include_directories(main
    PUBLIC ${PROJECT_SOURCE_DIR}/inc)

install(TARGETS main DESTINATION ${PROJECT_SOURCE_DIR}/bin)
