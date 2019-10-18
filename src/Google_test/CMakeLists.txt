project(Google_tests)

add_subdirectory(libs)
include_directories(${gtest_SOURCE_DIR}\\include ${gtest_SOURCE_DIR})

add_executable(Google_Tests_run Test_Class_Link.cpp)

target_link_libraries(Google_Tests_run Network_Models_Core DronesCore)

target_link_libraries(Google_Tests_run gtest gtest_main)