cmake_minimum_required(VERSION 2.8)
project(CANSender)


include_directories(
   "${CANLIB_SOURCE_DIR}/drivers/can_socket_driver/"
)


add_executable(CANSender sender.c)
target_link_libraries(
	CANSender 
	${CANLIB_SOURCE_DIR}/output/lib/libcan_driver.so
)
