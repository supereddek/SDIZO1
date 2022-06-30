cmake_minimum_required(VERSION 3.22)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp MyArray.cpp MyArray.h MyList.cpp MyList.h BinaryHeap.cpp BinaryHeap.h AVLTree.cpp AVLTree.h RBTree.cpp RBTree.h Tester.cpp Tester.h Menu.h Menu.cpp)
