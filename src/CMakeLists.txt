#sources
set(SOURCES Action.cpp
	Audio.cpp
	Game.cpp
	Input.cpp
	main.cpp
	Renderer.cpp
	Systems.cpp)

#executable
set(EXECUTABLE_NAME "flygine")
add_executable(${EXECUTABLE_NAME} ${SOURCES})

#Find libs

#Find any version 2.X of SFML
find_package(SFML REQUIRED system window graphics network audio)
include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})


#Find TGUI
find_package(TGUI REQUIRED)
include_directories(${TGUI_INCLUDE_DIR})
target_link_libraries(${EXECUTABLE_NAME} ${TGUI_LIBRARY})

#Find ENTT
find_package(ENTT CONFIG REQUIRED)
target_link_libraries(${EXECUTABLE_NAME} EnTT)

#show config types
message("Generated with config types: ${CMAKE_CONFIGURATION_TYPES}")



#SET(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/Bin/${CMAKE_BUILD_TYPE} CACHE PATH "Library output path")
#SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/Bin/${CMAKE_BUILD_TYPE} CACHE PATH "Executable output path")

#install executable in same directory as the cmake lists file
#install(TARGETS ${EXECUTABLE_NAME} DESTINATION ${CMAKE_SOURCE_DIR}../)