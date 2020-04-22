cmake_minimum_required(VERSION 3.10)

# set the project name
project(ancestor-tree-b-1)

# add the executable
add_executable(ancestor-tree-b-1  FamilyTree.hpp FamilyTree.cpp  doctest.h  Test.cpp Test_ariel.cpp Test_hila.cpp TestRunner.cpp)