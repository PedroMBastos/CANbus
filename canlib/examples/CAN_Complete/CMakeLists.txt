cmake_minimum_required(VERSION 2.8)
project(CANComplete)


include_directories(
   "${CANLIB_SOURCE_DIR}/drivers/can_socket_driver/"
)


add_executable(CANComplete complete.c)
target_link_libraries(
	CANComplete 
	${CANLIB_SOURCE_DIR}/output/lib/libcan_driver.so
)
