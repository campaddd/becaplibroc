cmake_minimum_required(VERSION 3.5)

project(2_prove_operators LANGUAGES C)

add_executable(2_prove_operators main.c)

include(GNUInstallDirs)
install(TARGETS 2_prove_operators
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
