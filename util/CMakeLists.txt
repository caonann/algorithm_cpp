add_library(comm_niuke common_define.cpp)

add_executable(common_unittest common_unittest.cpp)
target_link_libraries(common_unittest ${gtest} ${gtest_main} comm_niuke pthread)