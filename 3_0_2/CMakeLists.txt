cmake_minimum_required(VERSION 3.5)

project(3_0_2 LANGUAGES C)

add_executable(3_0_2 main.c)

include(GNUInstallDirs)
install(TARGETS 3_0_2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
