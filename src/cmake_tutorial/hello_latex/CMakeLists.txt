cmake_minimum_required(VERSION 3.5)
project(mydoc NONE)

find_package(LATEX REQUIRED COMPONENTS XELATEX)
set(PDFLATEX_COMPILER ${XELATEX_COMPILER})
include(UseLATEX.cmake)

add_latex_document(src/mini_xelatex.tex)
