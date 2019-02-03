set(target ${MP2_TESTS})
set(CMAKE_CXX_STANDARD 11)

file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty")

add_executable(${target} ${srcs} ${hdrs})
target_link_libraries(${target} gtest)
#target_link_libraries(${target} gtest ${MP2_LIBRARY})
