add_library(helpers helpers.cpp)

target_link_libraries(
    helpers
    PRIVATE project_options
            project_warnings
            )