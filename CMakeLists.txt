cmake_minimum_required(VERSION 3.7.1)
project(engine)

#headers
include_directories(include)

#sources
file(GLOB SOURCES "src/*.cpp")

#executable
set(EXECUTABLE_NAME "run")
add_executable(${EXECUTABLE_NAME} ${SOURCES})

#binary
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

#Module path
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules" ${CMAKE_MODULE_PATH})

#Find libs

#Find any version 2.X of SFML
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()

#Find TGUI
find_package(TGUI 0.7.2 REQUIRED)
if(TGUI_FOUND)
  include_directories(${TGUI_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${TGUI_LIBRARY})
endif()

#Find EntityX
find_package(EntityX REQUIRED)
if(ENTITYX_FOUND)
  include_directories(${ENTITYX_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} entityx) #ENTITYX_LIBRARY was not working
endif()

#show config types
message("Generated with config types: ${CMAKE_CONFIGURATION_TYPES}")

#install executable in same directory as the cmake lists file
install(TARGETS ${EXECUTABLE_NAME} DESTINATION ${CMAKE_SOURCE_DIR})
