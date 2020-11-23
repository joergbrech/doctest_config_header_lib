cmake_minimum_required(VERSION 3.14)

project(doctest_config_header_lib VERSION 0.1.0)

option(build_tests "Build unit tests with doctest" ON)

include(GNUInstallDirs)
include(FetchContent)

set(CMAKE_CXX_STANDARD 17)
add_library(${PROJECT_NAME} INTERFACE)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

if (build_tests)

    # download doctest as thirdparty dependency
    FetchContent_Declare(doctest
            GIT_REPOSITORY "https://github.com/onqtam/doctest"
            GIT_TAG "d5130f6d95f1e2c9b29d69cb2c0e8803232fb8f5"
    )
    FetchContent_MakeAvailable(doctest)

    add_subdirectory(tests)
endif()

target_include_directories(
  ${PROJECT_NAME}
  INTERFACE $<BUILD_INTERFACE:${${PROJECT_NAME}_SOURCE_DIR}>
            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

install(TARGETS ${PROJECT_NAME}
        EXPORT ${PROJECT_NAME}_Targets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

include(CMakePackageConfigHelpers)
write_basic_package_version_file("${PROJECT_NAME}ConfigVersion.cmake"
                                 VERSION ${PROJECT_VERSION}
                                 COMPATIBILITY SameMajorVersion)

