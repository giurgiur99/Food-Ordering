cmake_minimum_required(VERSION 3.15)
project(Hm C)

set(CMAKE_C_STANDARD 99)

add_executable(Hm main.c users.c users.h getchoice.c getchoice.h displyInfo.c displyInfo.h)