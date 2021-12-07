add_executable(day1 sonar.cpp)
target_link_libraries(
    day1
    PRIVATE project_options
            project_warnings
            helpers)
