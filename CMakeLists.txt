cmake_minimum_required(VERSION 3.10)

project(Euclid)

set(SFML_INCLUDE_DIR "C:\\Program Files\\SFML\\include")
set(SFML_LIBRARY_DIR "C:\\Program Files\\SFML\\lib")

set(SRC
	${PROJECT_SOURCE_DIR}/Block.cpp
	${PROJECT_SOURCE_DIR}/Block.hpp
	${PROJECT_SOURCE_DIR}/Main.cpp
)

add_executable(Euclid ${SRC})

target_include_directories(Euclid PUBLIC ${SFML_INCLUDE_DIR})
target_link_libraries(Euclid 
						PUBLIC "${SFML_LIBRARY_DIR}\\sfml-graphics.lib"
						PUBLIC "${SFML_LIBRARY_DIR}\\sfml-window.lib"
						PUBLIC "${SFML_LIBRARY_DIR}\\sfml-system.lib"
)
