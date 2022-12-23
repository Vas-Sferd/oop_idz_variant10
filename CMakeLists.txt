cmake_minimum_required(VERSION 3.5)

project(oop_idz_variant10 LANGUAGES CXX)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})
include_directories(include)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(oop_idz_variant10 main.cpp)
target_link_libraries(oop_idz_variant10 ${wxWidgets_LIBRARIES})

install(TARGETS oop_idz_variant10
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
