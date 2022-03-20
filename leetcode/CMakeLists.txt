aux_source_directory(. LeetCodeSourceFile)
#message(STATUS "LeetCodeSourceFile: ${LeetCodeSourceFile}")

foreach(target_bin ${LeetCodeSourceFile})
    string(REPLACE "/" ";" file_name ${target_bin})
    list(GET file_name 1 BIN_FILE_NAME)

    string(REPLACE ".cpp" "" BIN_FILE_NAME "${BIN_FILE_NAME}")
   #message(STATUS "target_bin: ${BIN_FILE_NAME}")
    add_executable(${BIN_FILE_NAME} ${target_bin})
    target_link_libraries(${BIN_FILE_NAME} pthread ${gtest} ${gtest_main})
endforeach(target_bin)