cmake_minimum_required(VERSION 3.5)

project(Game)

# Use the C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Behaviortree
find_package(behaviortree_cpp REQUIRED)

# Find SFML
find_package(SFML 2 COMPONENTS graphics window system REQUIRED)

# Add the directory containing your static library to CMake's search path
link_directories(${CMAKE_SOURCE_DIR}/lib)

add_subdirectory(component)
add_subdirectory(Scene)

# Add your source file(s)
add_executable(Game main.cpp)

# Add include directories for the target
target_include_directories(Game PRIVATE ${CMAKE_SOURCE_DIR}/component)
target_include_directories(Game PRIVATE ${CMAKE_SOURCE_DIR}/include/box2d)

# Link SFML libraries to your project
target_link_libraries(Game component Scene sfml-graphics sfml-window sfml-system box2d BT::behaviortree_cpp)