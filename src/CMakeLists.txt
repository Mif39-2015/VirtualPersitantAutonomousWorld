cmake_minimum_required(VERSION 2.8)

project(vpaw)

# ${list_src} contiendra toutes les .cpp du repertoire courant ( src/ )
file(GLOB_RECURSE list_src
  "*.cpp"
  "*.hpp"
  )

# on enlève main.cpp contenu dans ${list_src}
file(GLOB to_remove main.cpp)
list(REMOVE_ITEM list_src ${to_remove})

# librairie
add_library(serv ${list_src})
set_target_properties(serv PROPERTIES LINKER_LANGUAGE CXX)

find_package( Boost 1.40 COMPONENTS program_options REQUIRED )
include_directories( ${Boost_INCLUDE_DIR} )

# executable serveur
add_executable(exec main)
target_link_libraries(exec serv pthread ${Boost_LIBRARIES})
