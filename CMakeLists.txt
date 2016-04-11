cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(${PROJECT_SOURCE_DIR}/src)
add_subdirectory(${PROJECT_SOURCE_DIR}/test)

#
# Doxygen
#

option(BUILD_DOCUMENTATION_ALL "Compiler la documentation" OFF)
FIND_PACKAGE(Doxygen)
if(DOXYGEN_FOUND)
  if(BUILD_DOCUMENTATION_ALL)
    add_custom_target(doc ALL
      ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/doc/Doxyfile
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/doc
      )
  else()
    add_custom_target(doc
      ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/doc/Doxyfile
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/doc
      )    
  endif()
endif()
