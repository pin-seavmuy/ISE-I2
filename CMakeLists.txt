cmake_minimum_required(VERSION 3.28)
project(clubhub VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Library: Contains all application logic except main()
add_library(clubhub_core src/banner.cpp)
target_include_directories(clubhub_core PUBLIC include)
target_compile_definitions(clubhub_core PRIVATE CLUBHUB_VERSION="${PROJECT_VERSION}")

# Strict compiler warnings (treat warnings as quality gates)
if(MSVC)
    target_compile_options(clubhub_core PRIVATE /W4)
else()
    target_compile_options(clubhub_core PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Executable: Command-line interface frontend
add_executable(clubhub src/main.cpp)
target_link_libraries(clubhub PRIVATE clubhub_core)
