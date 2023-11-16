cmake_minimum_required(VERSION 3.5)

project(2_1_bis LANGUAGES C)

add_executable(2_1_bis main.c)

include(GNUInstallDirs)
install(TARGETS 2_1_bis
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
