project(lab2)

add_executable(lab2
  ./lab2.cpp
  ./angle.cpp)

set(CMAKE_CXX_FLAGS
  "${CMAKE_CXX_FLAGS} -Wall -Wextra")
