cmake_minimum_required(VERSION 3.0)
project(mediaorganiser)


# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find QtWidgets
find_package(Qt5Widgets)
# Find Boost
find_package(Boost COMPONENTS program_options filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

# EXECUTABLES
add_executable(mediaorganiser.o main.cpp mediaorganiser.cpp)
add_executable(mediaorganiserqt.o mainqt.cpp mediaorganiser.cpp)


target_link_libraries(mediaorganiser.o LINK_PUBLIC ${Boost_LIBRARIES})
target_link_libraries(mediaorganiserqt.o Qt5::Widgets)
