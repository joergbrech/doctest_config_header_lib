project(tests)

if (NOT TARGET "doctest_config_header_lib")
    find_package(doctest_config_header_lib CONFIG REQUIRED)
endif()

add_library(default SHARED default.cpp)
target_link_libraries(default PUBLIC doctest doctest_config_header_lib)
set_target_properties(default PROPERTIES CXX_VISIBILITY_PRESET hidden)

add_library(return42 SHARED return42.cpp)
target_link_libraries(return42 PUBLIC doctest doctest_config_header_lib)
set_target_properties(return42 PROPERTIES CXX_VISIBILITY_PRESET hidden)

add_executable(tests main.cpp)
target_link_libraries(tests PUBLIC default return42 doctest)

