cmake_minimum_required(VERSION 2.8)


include(FRCDeploy)
project(Robot)
file(GLOB_RECURSE SOURCE_CODE *.cpp)
find_package(WPILib)
include_directories(${WPILib_INCLUDE_DIRS})
message(STATUS "wpi at ${WPILib_INCLUDE_DIRS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I${WPILib_INCLUDE_DIRS} -I${CMAKE_SOURCE_DIR} -mcpu=603 -mstrict-align -mlongcall -DTOOL=gnu")
add_executable(FRC_UserProgram.out ${SOURCE_CODE})
target_link_libraries(FRC_UserProgram.out ${WPILib_LIBRARY})
add_make_deploy(FRC_UserProgram.out 10.2.25.2)