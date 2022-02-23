cmake_minimum_required(VERSION 2.8)
project(CANSimple)


include_directories(
   "${CANLIB_SOURCE_DIR}/drivers/can_socket_driver/"
)


add_executable(CANSimple simple.c)
target_link_libraries(
	CANSimple 
	${CANLIB_SOURCE_DIR}/output/lib/libcan_driver.so
)
