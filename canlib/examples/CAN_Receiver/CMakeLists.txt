cmake_minimum_required(VERSION 2.8)
project(CANReceiver)


include_directories(
   "${CANLIB_SOURCE_DIR}/drivers/can_socket_driver/"
)


add_executable(CANReceiver receiver.c)
target_link_libraries(
	CANReceiver 
	${CANLIB_SOURCE_DIR}/output/lib/libcan_driver.so
)
