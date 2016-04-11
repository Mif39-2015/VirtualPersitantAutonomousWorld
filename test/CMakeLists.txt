cmake_minimum_required(VERSION 3.0)

include_directories(${PROJECT_SOURCE_DIR}/src)

set(TEST_LIST
  test_foo
  )

foreach(FILE ${TEST_LIST})
  add_executable(${FILE} ${FILE})
  target_link_libraries(${FILE} serv)
  add_test(${FILE} ${FILE})
endforeach(FILE)
