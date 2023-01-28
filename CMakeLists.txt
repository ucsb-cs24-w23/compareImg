cmake_minimum_required(VERSION 3.14)
project(CompareImg)
set(CMAKE_CXX_STANDARD 14)
find_package( OpenCV REQUIRED )
#link_directories(${CMAKE_CURRENT_LIST_DIR}/lib)
include_directories(${OpenCV_INCLUDE_DIRS})
# add_executable(CompareImg main.cpp)
add_library(compare-img SHARED
    main.cpp
)
target_link_libraries(compare-img ${OpenCV_LIBS})