cmake_minimum_required(VERSION 2.8)
project(CANExercise)


include_directories(
   "${CANLIB_SOURCE_DIR}/drivers/can_socket_driver/"
)


add_executable(CANExercise exercise.c)
target_link_libraries(
	CANExercise 
	${CANLIB_SOURCE_DIR}/output/lib/libcan_driver.so
)
