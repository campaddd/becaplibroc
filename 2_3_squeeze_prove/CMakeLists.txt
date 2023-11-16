cmake_minimum_required(VERSION 3.5)

project(2_3_squeeze_prove LANGUAGES C)

add_executable(2_3_squeeze_prove main.c)

include(GNUInstallDirs)
install(TARGETS 2_3_squeeze_prove
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
