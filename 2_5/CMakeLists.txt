cmake_minimum_required(VERSION 3.5)

project(2_5 LANGUAGES C)

add_executable(2_5 main.c
    2_5_note.md)

include(GNUInstallDirs)
install(TARGETS 2_5
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
