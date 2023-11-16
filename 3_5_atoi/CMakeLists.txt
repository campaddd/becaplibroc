cmake_minimum_required(VERSION 3.5)

project(3_5_atoi LANGUAGES C)

add_executable(3_5_atoi main.c)

include(GNUInstallDirs)
install(TARGETS 3_5_atoi
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
