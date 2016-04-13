cmake_minimum_required(VERSION 2.8)

include_directories(${PROJECT_SOURCE_DIR}/src)

set(curdir ${PROJECT_SOURCE_DIR}/test)

message(STATUS "${curdir}")
# recupere la liste des sous dossiers
MACRO(SUBDIRLIST result curdir)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
      LIST(APPEND dirlist ${child})
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO()

SUBDIRLIST(SUBDIRS ${curdir})

message(STATUS "## List")
FOREACH(subdir ${SUBDIRS})
  set(addsub "${curdir}/${subdir}")
  ADD_SUBDIRECTORY(${addsub})
ENDFOREACH()
