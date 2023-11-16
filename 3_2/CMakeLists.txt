cmake_minimum_required(VERSION 3.5)

project(3_2 LANGUAGES C)

add_executable(3_2 main.c
    note_per_continuare.md)

include(GNUInstallDirs)
install(TARGETS 3_2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
