cmake_minimum_required(VERSION 3.5)

project(2_cat LANGUAGES C)

add_executable(2_cat main.c)

include(GNUInstallDirs)
install(TARGETS 2_cat
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
