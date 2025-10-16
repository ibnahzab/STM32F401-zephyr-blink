cmake_minimum_required(VERSION 3.20.0)
set(PRJNAME blink)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(${PRJNAME})

message(STATUS "ZEPHYR_BASE = $ENV{ZEPHYR_BASE}")

set_target_properties(app PROPERTIES OUTPUT_NAME "${PRJNAME}")
target_sources(app PRIVATE src/main.c)
