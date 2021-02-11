CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(spreadsheet
    main.cpp
    spreadsheet.cpp
    select_contains.hpp
    select_or.hpp
    select_and.hpp
    select_not.hpp
)

ADD_EXECUTABLE(test
    spreadsheet.cpp
    test.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
