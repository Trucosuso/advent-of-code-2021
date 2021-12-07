add_subdirectory(submarine)

add_executable(day2 navigation.cpp)

target_link_libraries(
    day2
    PRIVATE project_options
            project_warnings
            helpers
            submarine)