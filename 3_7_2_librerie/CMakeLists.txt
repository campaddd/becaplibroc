cmake_minimum_required(VERSION 3.5)

project(3_7_2_librerie LANGUAGES C)

add_executable(3_7_2_librerie main.c)

include(GNUInstallDirs)
install(TARGETS 3_7_2_librerie
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
