cmake_minimum_required(VERSION 3.11)
project(nucleus)

file(GLOB SRC
     "src/*.hxx"
     "src/*.cxx"
)

find_package(PkgConfig)

pkg_check_modules(GTKMM gtkmm-4.0)

link_directories(${GTKMM_LIBRARY_DIRS})
include_directories(${GTKMM_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SRC})
target_link_libraries(${PROJECT_NAME} ${GTKMM_LIBRARIES})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 23)
