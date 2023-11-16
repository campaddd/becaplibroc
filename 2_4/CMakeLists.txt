cmake_minimum_required(VERSION 3.5)

project(2_4 LANGUAGES C)

add_executable(2_4 main.c)

include(GNUInstallDirs)
install(TARGETS 2_4
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
