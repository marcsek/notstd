cmake_minimum_required(VERSION 3.14.4)

# generate compile_command.json for IDE
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

set(PROJECT_NAME notstd)
project(${PROJECT_NAME} C)

message(STATUS "Processing " ${PROJECT_NAME})

set(SrcLib
  include/hashtable.h
  include/linked_list.h
  include/vector.h
  include/vec2.h
  include/vec3.h
  include/mat3.h

  src/hashtable.c
  src/linked_list.c
  src/vector.c
  src/vec2.c
  src/vec3.c
  src/mat3.c
)

set(SrcMain
  main.c
)

set(SrcTest
  tests/hashtabletests.c
  tests/linkedlisttests.c
  tests/vectortests.c
  tests/vec2tests.c
  tests/vec3tests.c
  tests/mat3tests.c
)

option(NOTSTD_MAKE_EXE "Make an executable" FALSE)

add_library(notstd STATIC
    ${SrcLib}
)

if(NOTSTD_MAKE_EXE)    
  list(APPEND SrcLib ${SrcMain})
endif()

add_library(notstd::notstd ALIAS notstd)

target_include_directories(notstd PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
target_include_directories(notstd PRIVATE src)

link_libraries(notstd)

if(NOTSTD_MAKE_EXE)
  add_executable(main
    ${SrcMain}
  )
endif()

add_executable(test
  ${SrcTest}
)

target_link_libraries(test PRIVATE
  "-lcriterion"
)


message(STATUS "Done " ${PROJECT_NAME})
