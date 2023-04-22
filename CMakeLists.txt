cmake_minimum_required(VERSION 3.25)

set(PROJECT_NAME logreader)
set(PROJECT_SOURCE_DIR src)
set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MAJOR 1)
set(PROJECT_BINARY_DIR cmake-build-debug)
set(PROJECT_DESCRIPTION README.md)

project(${PROJECT_NAME} LANGUAGES CXX DESCRIPTION README.md)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_DEFAULT 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_FLAGS "")

add_executable(${PROJECT_NAME}
        src/app/main_001.cpp
        src/app/readconfig.cpp
        src/objects/commandvalidation.hpp
        src/utils/stringutils.hpp
        src/exceptions/exceptions.hpp
        src/resource/logresource.hpp


        )
