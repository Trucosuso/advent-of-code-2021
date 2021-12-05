option(BUILD_DAY_1 "Build day 1" OFF)
option(BUILD_DAY_2 "Build day 2" OFF)

# Day 1
if(BUILD_DAY_1)
  message("Building day 1")
  add_subdirectory(day1)
endif()

# Day 2
if(BUILD_DAY_2)
  message("Building day 2")
  add_subdirectory(day2)
endif()