cmake_minimum_required(VERSION 3.5)

project(2_5_giusta_consegna LANGUAGES C)

add_executable(2_5_giusta_consegna main.c)

include(GNUInstallDirs)
install(TARGETS 2_5_giusta_consegna
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
