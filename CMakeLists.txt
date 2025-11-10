cmake_minimum_required(VERSION 3.30)

set(PROJECT_NAME_STR MPFR_GMP_MPIR_test)
set(CMAKE_CXX_STANDARD 11)

project(${PROJECT_NAME_STR})

# include_directories(
	# ${CMAKE_CURRENT_SOURCE_DIR}/mpfr/src
	# ${CMAKE_CURRENT_SOURCE_DIR}/mpir
	# ${CMAKE_CURRENT_SOURCE_DIR}/gmp/lib
	# ${CMAKE_CURRENT_SOURCE_DIR}/build/gmp	
# )
link_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/build/mpfr/$<CONFIG>
	${CMAKE_CURRENT_SOURCE_DIR}/build/mpir$<CONFIG>
	${CMAKE_CURRENT_SOURCE_DIR}/build/lib/$<CONFIG>
)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/gmp)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/mpir)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/mpfr)
#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src)

file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)					

add_executable(${PROJECT_NAME_STR} ${SRC_FILES})

target_link_libraries(${PROJECT_NAME_STR} 
	mpfr
	mpir
	gmp
)
