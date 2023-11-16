cmake_minimum_required(VERSION 3.5)

project(2_1 LANGUAGES C)

add_executable(2_1 main.c)

include(GNUInstallDirs)
install(TARGETS 2_1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
