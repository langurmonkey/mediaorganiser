cmake_minimum_required(VERSION 3.0)
project(mediaorganiser)


# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find the QtWidgets library
find_package(Qt5Widgets)

add_executable(mediaorganiserqt mainqt.cpp)
add_executable(mediaorganiser main.cpp)

# Use the Widgets module from Qt 5.
target_link_libraries(mediaorganiserqt Qt5::Widgets)
