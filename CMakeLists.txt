cmake_minimum_required(VERSION 3.8.0)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

project(autoPrinter)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find the QtWidgets library
find_package(Qt5 COMPONENTS Core Widgets PrintSupport REQUIRED)
find_package(PopplerQt5)

file(GLOB_RECURSE USER_INCLUDES "includes/*.h")
include_directories("includes")

file(GLOB_RECURSE USER_SOURCES "sources/*.cpp")

# Tell CMake to create the helloworld executable
add_executable(${PROJECT_NAME} ${USER_SOURCES} ${USER_INCLUDES})

# Use the Widgets module from Qt 5.
target_link_libraries(${PROJECT_NAME} Qt5::PrintSupport ${POPPLER_LIBRARIES})
