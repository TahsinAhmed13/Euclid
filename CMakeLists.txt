cmake_minimum_required(VERSION 3.10)

project(Euclid)

set(SFML_INCLUDE_DIR "C:\\Program Files\\SFML\\include")
set(SFML_LIBRARY_DIR "C:\\Program Files\\SFML\\lib")

set(SRC
	${PROJECT_SOURCE_DIR}/Block.cpp
	${PROJECT_SOURCE_DIR}/Block.hpp
	${PROJECT_SOURCE_DIR}/Euclid.cpp
	${PROJECT_SOURCE_DIR}/Euclid.hpp
	${PROJECT_SOURCE_DIR}/Main.cpp
	${PROJECT_BINARY_DIR}/Main.hpp
)

set(ASSETS_DIR "${PROJECT_SOURCE_DIR}/Assets/")

configure_file(Main.hpp.in Main.hpp)

add_executable(Euclid ${SRC})

target_include_directories(Euclid 
						PUBLIC ${PROJECT_BINARY_DIR}
						PUBLIC ${SFML_INCLUDE_DIR}
)
target_link_libraries(Euclid 
						PUBLIC "${SFML_LIBRARY_DIR}\\sfml-graphics.lib"
						PUBLIC "${SFML_LIBRARY_DIR}\\sfml-window.lib"
						PUBLIC "${SFML_LIBRARY_DIR}\\sfml-system.lib"
)
