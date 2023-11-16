cmake_minimum_required(VERSION 3.5)

project(3_3 LANGUAGES C)

add_executable(3_3 main.c
    note_3_3.md)

include(GNUInstallDirs)
install(TARGETS 3_3
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
