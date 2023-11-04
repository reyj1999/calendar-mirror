cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
# root cmake file
project(caspercalendar)

set(BUILD_MAJOR "0")
set(BUILD_MINOR "3")
set(BUILD_MICRO "0")

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

#Need to specify the PREFIX path for cmake to find copperspice libraries and definitions
#In example below which assumes you built CS with my guide on github replace user with your username
set(CMAKE_PREFIX_PATH "/home/user/copperspice/cs_lib/lib/cmake/CopperSpice")

#include following macros built into cmake
include(CheckCXXCompilerFlag)
include(CheckCXXSourceCompiles)
include(CheckIncludeFile)
include(CheckIncludeFiles)
include(CheckTypeSize)
 
 #findpackage call will look into the default system directory and the specified PREFIX PATH for
 # the copperspice package to instantiate the cs macros and cs functionality 
find_package(CopperSpice REQUIRED)
 
 if(CMAKE_SYSTEM_NAME MATCHES "(Linux|OpenBSD|FreeBSD|NetBSD|DragonFly)")
 include(GNUInstallDirs)
 set(CMAKE_INSTALL_RPATH "\$ORIGIN")
 endif()
 
 #set package meta data
set(PACKAGE "caspercalendar")
set(PACKAGE_NAME "caspercalendar")
set(PACKAGE_VERSION   "${BUILD_MAJOR}.${BUILD_MINOR}.${BUILD_MICRO}")
set(PACKAGE_VERSION   "${BUILD_MAJOR}.${BUILD_MINOR}.${BUILD_MICRO}")
set(PACKAGE_URL       "https://github.com/crispinalan/caspercalendar")
 
#Configure cmake options
#INCLUDE _CURRENT_DIR ON means source files and header files in same directory
#CMAKE_CXX_STANDARD_REQUIRED means use a standard compliant compiler
# CMAKE_CXX_STANDARD make available the C++ 17 standard

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_INCLUDE_DIRECTORIES_BEFORE ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
 
# location for building binary files
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
 
 #enable the cmake file in the source directory to be read
add_subdirectory(src)
