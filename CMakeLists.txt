cmake_minimum_required(VERSION 3.13)
project(resource_test C)

add_executable( check WIN32 main.c resource.rc )
