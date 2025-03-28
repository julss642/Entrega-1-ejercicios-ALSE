cmake_minimum_required(VERSION 3.10)
# Establecer la versión mínima de CMake requerida

project(TareaClases)
# Nombre del proyecto

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# Establecer el estándar de C++

add_executable(point2d point2d.cpp)
# Añadir el ejecutable