cmake_minimum_required(VERSION 2.8)
project(can)


include_directories(
   "${CANLIB_SOURCE_DIR}/drivers/can_socket_driver/"
)



add_library(${PROJECT_NAME}_driver SHARED 
   can_socket_driver/can_driver.c
)

