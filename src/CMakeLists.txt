cmake_minimum_required(VERSION 3.15)
project(uav_sim)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
add_compile_options(-D__USE_W32_SOCKETS)
set(CMAKE_BUILD_TYPE DEBUG)



include_directories(${CMAKE_CURRENT_SOURCE_DIR})


set(Boost_NO_SYSTEM_PATHS ON)
set(BOOST_ROOT "C:\\Users\\johnm\\Desktop\\UAV-Network-Simulation\\libs\\boost_1_70_0")
set(BOOST_INCLUDEDIR "${BOOST_ROOT}\\boost")
find_package(Boost)

include_directories("${Boost_INCLUDE_DIRS}")
#message(STATUS "Boost include dir: ${Boost_INCLUDE_DIRS}")
message(STATUS "Boost library status: ${Boost_FOUND}")

#set(GOOGLETEST_ROOT "C:\\Users\\johnm\\CLionProjects\\uav_sim\\libs\\googletest-master\\googletest")
#set(GOOGLETEST_INCLUDEDIR "${GOOGLETEST_ROOT}\\include")
#find_package(googletest)
add_subdirectory(Missions)
add_subdirectory(Drones)
add_subdirectory(Network_Models)
add_subdirectory(Google_test)
#add_subdirectory(googletest-master)
add_executable(uav_sim main.cpp)
target_link_libraries(uav_sim MissionsCore DronesCore Network_Models_Core ${Boost_LIBRARIES})