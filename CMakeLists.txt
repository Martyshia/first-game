cmake_minimum_required(VERSION 3.10)
project(GraSFML)
find_package(SFML REQUIRED COMPONENTS window graphics system) 

add_executable(gra
	"${CMAKE_SOURCE_DIR}/gra.cpp"
)

target_link_libraries(gra PRIVATE
	sfml-system
	sfml-window
	sfml-graphics
	sfml-audio
)

configure_file("${CMAKE_SOURCE_DIR}/spritesheet-org.png" "${CMAKE_BINARY_DIR}/spritesheet-org.png" COPYONLY)

