cmake_minimum_required(VERSION 2.8)

include_directories(${PROJECT_SOURCE_DIR}/src)

set(TEST_LIST
  test_socket
  )

foreach(FILE ${TEST_LIST})
  add_executable(${FILE} ${FILE})
  target_link_libraries(${FILE} serv pthread)
  add_test(${FILE} ${FILE})
endforeach(FILE)
