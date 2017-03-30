project(twse-captcha-solver)

cmake_minimum_required (VERSION 3.1)

SET(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/")

FIND_PACKAGE( Tesseract REQUIRED )
include_directories(${Tesseract_INCLUDE_DIRS})

find_package( OpenCV )
include_directories( ${OpenCV_INCLUDE_DIRS} )

# Use c++11
set (CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE( twse-captcha-solver  main.cpp )
TARGET_LINK_LIBRARIES(twse-captcha-solver
  ${Tesseract_LIBRARIES}
  ${OpenCV_LIBRARIES})
