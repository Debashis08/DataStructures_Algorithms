# Specify the source files
set(0003GRAPH_SOURCES
    0001_BreadthFirstSearch.cc
    0002_DepthFirstSearch.cc
    0003_TopologicalSort.cc
    0004_StronglyConnectedComponents.cc
)

# Create a library target
add_library(0003GRAPH ${0003GRAPH_SOURCES})