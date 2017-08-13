cmake_minimum_required(VERSION 2.8)
project(calcHistgram)

#set(OpenCV_DIR /usr/local/share/OpenCV)
find_package(OpenCV REQUIRED)
file(GLOB SOURCES "*.cpp" "*.c" "*.h" "*.hpp")

if(OpenCV_FOUND)
	add_executable(calcHistgram ${SOURCES})
	include_directories(${OpenCV_INCLUDE_DIRS})
	target_link_libraries(calcHistgram ${OpenCV_LIBS})
endif(OpenCV_FOUND)
