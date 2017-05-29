cmake_minimum_required (VERSION 2.8.12)
project (Euler_futtatas LANGUAGES C)

add_executable (${PROJECT_NAME} ${PROJECT_BINARY_DIR}/Euler.c)

target_include_directories (${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries (${PROJECT_NAME} LINK_PUBLIC Eulerstep)

set_property(TARGET ${PROJECT_NAME} PROPERTY C_STANDARD)
set_property(TARGET ${PROJECT_NAME} PROPERTY C_STANDARD_REQUIRED ON)

add_custom_command (
                    COMMAND ${PROJECT_NAME}
                    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
                    OUTPUT ${CMAKE_BINARY_DIR}/kimenet.txt
                    DEPENDS ${PROJECT_NAME}
                    COMMENT "Eulerstep futtatasa"
                    )

add_custom_target(Eulerstep_futtatasa DEPENDS ${CMAKE_BINARY_DIR}/kimenet.txt)