cmake_minimum_required(VERSION 3.2)

project(lynxgame DESCRIPTION "Example Game For Testing LynxEngine")

include_directories(
  contrib/lynxengine/lynxengine
)

add_subdirectory(contrib/lynxengine)

add_executable(lynxgame
  src/main.cpp
)

target_link_libraries(lynxgame
  PRIVATE
    
  PUBLIC
    lynxengine
)
