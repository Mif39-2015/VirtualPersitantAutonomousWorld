cmake_minimum_required(VERSION 2.8)

project(vpaw)

if(NOT WIN32)
  string(ASCII 27 Esc)
  set(ColourReset "${Esc}[m")
  set(ColourBold  "${Esc}[1m")
  set(Red         "${Esc}[31m")
  set(Green       "${Esc}[32m")
  set(Yellow      "${Esc}[33m")
  set(Blue        "${Esc}[34m")
  set(Magenta     "${Esc}[35m")
  set(Cyan        "${Esc}[36m")
  set(White       "${Esc}[37m")
  set(BoldRed     "${Esc}[1;31m")
  set(BoldGreen   "${Esc}[1;32m")
  set(BoldYellow  "${Esc}[1;33m")
  set(BoldBlue    "${Esc}[1;34m")
  set(BoldMagenta "${Esc}[1;35m")
  set(BoldCyan    "${Esc}[1;36m")
  set(BoldWhite   "${Esc}[1;37m")
endif()

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

add_library(serv ${list_src})
set_target_properties(serv PROPERTIES LINKER_LANGUAGE CXX)

# --[ Recherche des packages
find_path(SQLITE3_INCLUDE_DIR sqlite3.h)
find_library(SQLITE3_LIBRARY sqlite3)
if(NOT SQLITE3_INCLUDE_DIR)
  message(SEND_ERROR "${BoldRed}[KO] header sqlite3.h\n\t-> installer le paquet ${BoldGreen}libsqlite3-dev)${ColourReset}")
else()
  message(STATUS "${BoldGreen}[OK] header sqlite3.h${ColourReset}")
endif()

if(NOT SQLITE3_LIBRARY)
  message(SEND_ERROR "${BoldRed}[KO] lib sqlite3.h \n\t-> installer le paquet ${BoldGreen}libsqlite3-dev)${ColourReset}")
else()  
  message(STATUS "${BoldGreen}[OK] lib sqlite3${ColourReset}")
endif()

add_definitions(-DBOOST_LOG_DYN_LINK)
find_package( Boost 1.40 QUIET COMPONENTS program_options log REQUIRED )
if(${Boost_PROGRAM_OPTIONS_FOUND})
  message(STATUS "${BoldGreen}[OK] composant boost_program_options${ColourReset}")
else()
  message(FATAL_ERROR "${BoldRed}[KO] composant boost_program_options\n\t-> package à installer: installe le paquet ${BoldGreen}libboost-program-options${BoldRed} avec X >= 1.40 (cf README du dépôt)${ColourReset}")
endif()

if(${Boost_LOG_FOUND})
  message(STATUS "${BoldGreen}[OK] composant boost_log${ColourReset}")
else()
  message(FATAL_ERROR "${BoldRed}[KO] composant boost_log manquant\n\t-> package à installer : ${BoldGreen}libboost-logX-dev${BoldRed} avec X >= 1.40\n\t-> apt-cache search libboost-log\n\t-> apt-get install {libboost-log le plus récent}${ColourReset}")
endif()

# --[ Linkage
include_directories( ${Boost_INCLUDE_DIR} )
include_directories( ${SQLITE3_INCLUDE_DIR} )

target_link_libraries(serv ${Boost_LIBRARIES} ${SQLITE3_LIBRARY})

# executable serveur
add_executable(exec main)
target_link_libraries(exec serv pthread)
