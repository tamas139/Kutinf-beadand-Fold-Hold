cmake_minimum_required (VERSION 2.8.12)
project (Doc)

include(UseLATEX.cmake REQUIRED)

find_package(LATEX)

#find_program(LATEX_EXECUTABLE
 # NAMES
  #MiKTeX
  #proTEXt
  #TeX Live
  #MacTeX
  #PATHS
  #${CYGWIN_INSTALL_PATH}/bin
#)

configure_file (
                "${PROJECT_SOURCE_DIR}/eredmenyek.png.in"
                "${CMAKE_BINARY_DIR}/eredmenyek.png"    
                )

ADD_LATEX_DOCUMENT(
                euler_projekt.tex
                INPUTS euler_projekt.tex
                IMAGES ../build/eredmenyek.png
                DEPENDS euler_projekt.tex plotter
                TARGET_NAME dokumentum
                FORCE_PDF
                )