cmake_minimum_required(VERSION 2.8)
project(CANAsk)


include_directories(
   "${CANLIB_SOURCE_DIR}/drivers/can_socket_driver/"
)


add_executable(CANAsk ask.c)
target_link_libraries(
	CANAsk 
	${CANLIB_SOURCE_DIR}/output/lib/libcan_driver.so
)
