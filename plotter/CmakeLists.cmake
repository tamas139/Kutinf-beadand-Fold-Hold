cmake_minimum_required (VERSION 2.8.12)
project(Plotter)

find_package (Gnuplot REQUIRED)

add_custom_command(
                COMMAND ${GNUPLOT_EXECUTABLE} ${PROJECT_SOURCE_DIR}/eulerplot.p
                WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
                OUTPUT ${CMAKE_BINARY_DIR}/euler_diagram.png
                DEPENDS ${PROJECT_SOURCE_DIR}/eulerplot.p szim_futtatas
                COMMENT "Adatok plottolasa ..."
                )

add_custom_target(plot DEPENDS ${CMAKE_BINARY_DIR}/euler_diagram.png)