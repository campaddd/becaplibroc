cmake_minimum_required(VERSION 3.5)

project(3_0 LANGUAGES C)

add_executable(3_0 main.c
    note_3_0.md)

include(GNUInstallDirs)
install(TARGETS 3_0
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
