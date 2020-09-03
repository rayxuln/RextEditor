

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.8.0
)
FetchContent_GetProperties(googletest)

if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    set(gtest_disable_pthreads ON CACHE BOOL "" FORCE)

    add_subdirectory(
            ${googletest_SOURCE_DIR}
            ${googletest_BINARY_DIR}
    )
endif()

add_executable(unit_tests "")
target_sources(unit_tests
        PRIVATE
            unit_tests.cpp
        )
target_link_libraries(unit_tests
        PRIVATE
            Qt5::Widgets
            gtest_main
        )
enable_testing()
add_test(
        NAME
            unit_test
        COMMAND
            $<TARGET_FILE:unit_tests>
        )