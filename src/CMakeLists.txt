cmake_minimum_required(VERSION 3.0)
project(mediaorganiser)


# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find QtWidgets
find_package(Qt5Widgets)
# Find Boost
find_package(Boost 1.71 REQUIRED COMPONENTS program_options filesystem)
include_directories(${Boost_INCLUDE_DIR})
message(STATUS "Boost version: ${Boost_VERSION}")
message(STATUS "Boost libs: ${Boost_LIBRARIES}")


# This is needed if your Boost version is newer than your CMake version
# or if you have an old version of CMake (<3.5)
if(NOT TARGET Boost::filesystem)
    add_library(Boost::filesystem IMPORTED INTERFACE)
    set_property(TARGET Boost::filesystem PROPERTY
        INTERFACE_INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR})
    set_property(TARGET Boost::filesystem PROPERTY
        INTERFACE_LINK_LIBRARIES ${Boost_LIBRARIES})
endif()

# EXECUTABLES
add_executable(mediaorganiser main.cpp mediaorganiser.cpp)
#add_executable(mediaorganiserqt.o mainqt.cpp mediaorganiser.cpp)

target_link_libraries(mediaorganiser PUBLIC ${Boost_LIBRARIES})
#target_link_libraries(mediaorganiserqt Qt5::Widgets)
