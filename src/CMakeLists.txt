cmake_minimum_required(VERSION 2.8)

project(vpaw)

add_definitions( -DPATH_DATA="${PROJECT_SOURCE_DIR}/../data" )
include_directories(${PROJECT_SOURCE_DIR}/../includes)

# ${list_src} contiendra toutes les .cpp du repertoire courant ( src/ )
file(GLOB_RECURSE list_src
  "*.cpp"
  "*.hpp"
  )

# on enlève main.cpp contenu dans ${list_src}
file(GLOB to_remove main.cpp)
list(REMOVE_ITEM list_src ${to_remove})

# librairie serveur
add_library(serv ${list_src})
set_target_properties(serv PROPERTIES LINKER_LANGUAGE CXX)

find_path(SQLITE3_INCLUDE_DIR sqlite3.h)
find_library(SQLITE3_LIBRARY sqlite3)
if(NOT SQLITE3_INCLUDE_DIR)
  message(SEND_ERROR "Impossible de trouver sqlite3.h (hint: installer le paquet libsqlite3-dev)")
endif()
if(NOT SQLITE3_LIBRARY)
  message(SEND_ERROR "Impossible de trouver la librairie sqlite3 (hint: installer le paquet libsqlite3-dev)")
endif()

target_link_libraries(serv ${SQLITE3_LIBRARY})
include_directories( ${SQLITE3_INCLUDE_DIR} )

find_package( Boost 1.40 COMPONENTS program_options REQUIRED )
include_directories( ${Boost_INCLUDE_DIR} )

# executable serveur
add_executable(exec main)
target_link_libraries(exec serv pthread ${Boost_LIBRARIES})
