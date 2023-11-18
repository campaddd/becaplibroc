cmake_minimum_required(VERSION 3.5)

project(4_3_stack LANGUAGES C)

add_executable(4_3_stack main.c)

include(GNUInstallDirs)
install(TARGETS 4_3_stack
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
