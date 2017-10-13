cmake_minimum_required(VERSION 3.8.0)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

project(autoPrinter)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find the QtWidgets library
find_package(Qt5Widgets)

file(GLOB_RECURSE USER_INCLUDES "includes/*.h")
include_directories("includes")

file(GLOB_RECURSE USER_SOURCES "sources/*.cpp")

# Tell CMake to create the helloworld executable
add_executable(${PROJECT_NAME} WIN32 ${USER_SOURCES} ${USER_INCLUDES})

# Use the Widgets module from Qt 5.
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
