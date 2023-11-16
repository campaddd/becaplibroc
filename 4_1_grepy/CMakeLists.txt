cmake_minimum_required(VERSION 3.5)

project(4_1_grepy LANGUAGES C)

add_executable(4_1_grepy main.c
    note_4_1.md
    4_1_tobecontinued.md)

include(GNUInstallDirs)
install(TARGETS 4_1_grepy
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
