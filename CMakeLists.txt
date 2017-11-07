cmake_minimum_required(VERSION 2.8.12)

project(SmartGlassGUI LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Core Quick SerialPort REQUIRED)
#INCLUDE(FindProtobuf)
find_package(Protobuf REQUIRED)

include_directories(cpp_src cpp_src/protobuf)
set(SOURCES main.cpp qml.qrc cpp_src/backend.cpp cpp_src/ProtocolFSM.cpp cpp_src/Protocol_Packet.cpp
    cpp_src/protobuf/Protocol_Commands.pb.cc cpp_src/protobuf/Protocol_Leds.pb.cc cpp_src/crc.cpp
    cpp_src/utils.cpp)
set(HEADERS cpp_src/backend.h cpp_src/ProtocolFSM.hpp cpp_src/Protocol_Packet.hpp cpp_src/Protocol_MTs.h
    cpp_src/crc.h cpp_src/utils.h)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
#target_link_libraries(${PROJECT_NAME) SerialPort)
#qt5_use_modules(${PROJECT_NAME} SerialPort)

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Quick Qt5::SerialPort ${PROTOBUF_LIBRARY})
