#include <gtest/gtest.h>
#include<string>
#include "../Headers/0003_Graph/0001_BreadthFirstSearch.h"

// Demonstrate some basic assertions.
namespace BreadthFirstSearchTest
{
	TEST(BFSTesting, ShowBFSResultTest) {
		BFSGraph graph;

        graph.PushUndirectedEdge('s', 'r');
        graph.PushUndirectedEdge('s', 'w');
        graph.PushUndirectedEdge('r', 'v');
        graph.PushUndirectedEdge('w', 't');
        graph.PushUndirectedEdge('w', 'x');
        graph.PushUndirectedEdge('t', 'x');
        graph.PushUndirectedEdge('t', 'u');
        graph.PushUndirectedEdge('x', 'u');
        graph.PushUndirectedEdge('x', 'y');
        graph.PushUndirectedEdge('u', 'y');

        graph.BFS('s');
        
        string actualResult = graph.ShowBFSResult();
        string expectedResult = " r(1) s(0) t(2) u(3) v(2) w(1) x(2) y(3)";
        EXPECT_EQ(actualResult, expectedResult);
	}
}