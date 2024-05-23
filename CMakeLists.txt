cmake_minimum_required(VERSION 3.27)
project(Projet_Langage_C C)

set(CMAKE_C_STANDARD 11)

add_executable(Projet_Langage_C main.c
        column.h
        column.c  "cdata_informations.c" "cdata_creation.c" "cdata_alteration.c" "cdata_value_set.c"
        cdata_display.c "cdata_console_menu.c")
