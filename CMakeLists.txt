cmake_minimum_required(VERSION 2.8.12)

project(QtQuickTest LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Core Quick SerialPort REQUIRED)

include_directories(cpp_src)
set(SOURCES main.cpp qml.qrc cpp_src/backend.cpp cpp_src/ProtocolFSM.cpp cpp_src/Protocol_Packet.cpp)
set(HEADERS cpp_src/backend.h cpp_src/ProtocolFSM.hpp cpp_src/Protocol_Packet.hpp)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
#target_link_libraries(${PROJECT_NAME) SerialPort)
#qt5_use_modules(${PROJECT_NAME} SerialPort)

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Quick Qt5::SerialPort)
