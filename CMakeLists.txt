cmake_minimum_required(VERSION 3.16)

project(tictactoe_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(tictactoe_cpp main.cpp
    TicTacToeGame.hpp TicTacToeGame.cpp
    TicTacToeField.hpp TicTacToeField.cpp
    InvalidMove.hpp InvalidMove.cpp
    README.md)

include(GNUInstallDirs)
install(TARGETS tictactoe_cpp
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
