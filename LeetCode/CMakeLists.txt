cmake_minimum_required(VERSION 3.10)
# Especifica la versión mínima requerida de CMake para este subproyecto. 
# En este caso, se requiere al menos la versión 3.10.

project(LeetCode)
# Define el nombre del subproyecto como "LeetCode".

add_executable(AddStrings AddStrings.cpp)
# Crea un ejecutable llamado "AddStrings" a partir del archivo fuente "AddStrings.cpp".

add_executable(Sudoku Sudoku.cpp)
# Crea un ejecutable llamado "Sudoku" a partir del archivo fuente "Sudoku.cpp".

add_executable(TwoSum TwoSum.cpp)
# Crea un ejecutable llamado "TwoSum" a partir del archivo fuente "TwoSum.cpp".

add_executable(DesignTwitter DesignTwitter.cpp)
# Crea un ejecutable llamado "DesignTwitter" a partir del archivo fuente "DesignTwitter.cpp".
