cmake_minimum_required(VERSION 3.5)

project(3_divisioni_integer LANGUAGES C)

add_executable(3_divisioni_integer main.c)

include(GNUInstallDirs)
install(TARGETS 3_divisioni_integer
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
