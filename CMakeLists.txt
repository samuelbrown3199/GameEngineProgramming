cmake_minimum_required(VERSION 2.6)
project(ENGINE)

include_directories(
	src
)

add_library(myengine
	src/Engine/Application.cpp
	src/Engine/Application.h
)

add_executable(demo
	src/TechDemo/main.cpp
)

target_link_libraries(demo myengine)