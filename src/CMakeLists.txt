cmake_minimum_required(VERSION 2.8)

project(vpaw)

# librairie
add_library(serv foo WorldChangesListener NetworkAdapter AuthenticationModule message/Message message/WorldChangeMessage UdpBroadcaster)
set_target_properties(serv PROPERTIES LINKER_LANGUAGE CXX)

# executable serveur
add_executable(exec main)
target_link_libraries(exec serv pthread)
