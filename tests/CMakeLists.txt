include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)

add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(tests_algorithms tests_algorithms.cpp
        main.cpp)

target_link_libraries(tests_algorithms
        PRIVATE
        GTest::GTest
        algorithms)

add_test(algorithms_gtests tests_algorithms)