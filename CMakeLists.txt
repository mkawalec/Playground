cmake_minimum_required(VERSION 2.8)
project(goog)
include_directories(src include)

set(STACK_FILES
    src/stack.cpp
    include/Stack.h
    )

set(QUEUE_FILES
    src/queue.cpp
    include/Queue.h
    )

set(TREE_FILES
    src/tree.cpp
    include/BST.h
    include/TreeElement.hpp
    )

set(DIJKSTRA_FILES
    src/dijkstra.cpp
    include/GraphNode.hpp
    include/Dijkstra.hpp
    include/NaiveMPQ.hpp
    )

set(KNAPSACK_FILES
    src/knapsack.cpp
    )

set(QUICKSORT_FILES
    src/quicksort.cpp
    )

set(MERGESORT_FILES
    src/mergesort.cpp
    )

set(RADIXSORT_FILES
    src/radixsort.cpp
    )

message(status "${CMAKE_CURRENT_SOURCE_DIR}")
add_executable(stack ${STACK_FILES})
add_executable(queue ${QUEUE_FILES})
add_executable(tree ${TREE_FILES})
add_executable(dijkstra ${DIJKSTRA_FILES})
add_executable(knapsack ${KNAPSACK_FILES})
add_executable(quicksort ${QUICKSORT_FILES})
add_executable(mergesort ${MERGESORT_FILES})
add_executable(radixsort ${RADIXSORT_FILES})

set(MARCH native)
if (CMAKE_COMPILER_IS_GNUCXX)
    message(status "Setting GCC flags")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -march=${MARCH} -ffast-math -ftree-vectorize -O3 -Wall -Wextra -Wno-ignored-qualifiers -pedantic -W -std=c++0x")
else()
    message(status "gcc not found!")
    return()
endif()

target_link_libraries(stack -lm)
target_link_libraries(queue -lm)
target_link_libraries(tree -lm)
target_link_libraries(dijkstra -lm)

