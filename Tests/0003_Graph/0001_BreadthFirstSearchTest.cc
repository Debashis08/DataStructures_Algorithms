#include <gtest/gtest.h>
#include<string>
#include "../Headers/0003_Graph/0001_BreadthFirstSearch.h"
#include "../0000_CommonUtilities/UnitTestHelper.h"

namespace BreadthFirstSearch
{
    UnitTestHelper unitTestHelper;


	TEST(BFSTesting, ShowBFSResultTest01) 
    {
		Graph graph;

        graph.PushUndirectedEdge(1, 2);
        graph.PushUndirectedEdge(1, 3);
        graph.PushUndirectedEdge(2, 4);
        graph.PushUndirectedEdge(3, 5);
        graph.PushUndirectedEdge(3, 6);
        graph.PushUndirectedEdge(5, 6);
        graph.PushUndirectedEdge(5, 7);
        graph.PushUndirectedEdge(6, 7);
        graph.PushUndirectedEdge(6, 8);
        graph.PushUndirectedEdge(7, 8);

        graph.BFS(1);
        
        string actualResult = unitTestHelper.SerializeVectorToString(graph.ShowBFSResult());
        string expectedResult = "1(0) 2(1) 3(1) 4(2) 5(2) 6(2) 7(3) 8(3)";
        EXPECT_EQ(actualResult, expectedResult);
	}

    TEST(BFSTesting, ShowBFSResultTest02) 
    {
        Graph graph;

        graph.PushUndirectedEdge(1, 2);

        graph.BFS(1);

        string actualResult = unitTestHelper.SerializeVectorToString(graph.ShowBFSResult());
        string expectedResult = "1(0) 2(1)";
        EXPECT_EQ(actualResult, expectedResult);
    }
}