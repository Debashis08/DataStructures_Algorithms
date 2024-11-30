#include<gtest/gtest.h>
#include "../Headers/0003_Graph/0003_TopologicalSort.h"
#include "../0000_CommonUtilities/UnitTestHelper.h"

namespace TopologicalSort
{
	UnitTestHelper unitTestHelper;

	TEST(TopoSortTesting, ShowTopoSortResult)
	{
		Graph graph;

        graph.PushDirectedEdge(1, 2);
        graph.PushDirectedEdge(1, 4);
        graph.PushDirectedEdge(2, 3);
        graph.PushDirectedEdge(4, 3);
        graph.PushSingleNode(5);
        graph.PushDirectedEdge(6, 7);
        graph.PushDirectedEdge(6, 8);
        graph.PushDirectedEdge(7, 4);
        graph.PushDirectedEdge(7, 8);
        graph.PushDirectedEdge(9, 8);

        graph.TopologicalSort();

        string actualResult = unitTestHelper.SerializeVectorToString(graph.ShowTopologicalSortResult());
        string expectedResult = "9(17,18) 6(11,16) 7(12,15) 8(13,14) 5(9,10) 1(1,8) 4(6,7) 2(2,5) 3(3,4)";

        EXPECT_EQ(actualResult, expectedResult);
	}

    // Test with a larger graph and multiple paths between nodes
    TEST(TopoSortTesting, LargeGraphMultiplePaths)
    {
        Graph graph;
        graph.PushDirectedEdge(1, 2);
        graph.PushDirectedEdge(1, 3);
        graph.PushDirectedEdge(2, 4);
        graph.PushDirectedEdge(3, 4);
        graph.PushDirectedEdge(4, 5);
        graph.PushDirectedEdge(5, 6);
        graph.PushDirectedEdge(6, 7);

        graph.TopologicalSort();
        string actualResult = unitTestHelper.SerializeVectorToString(graph.ShowTopologicalSortResult());
        string expectedResult = "1(1,14) 3(12,13) 2(2,11) 4(3,10) 5(4,9) 6(5,8) 7(6,7)";

        EXPECT_EQ(actualResult, expectedResult);
    }

    // Test with a graph containing disconnected components
    TEST(TopoSortTesting, DisconnectedGraph)
    {
        Graph graph;
        graph.PushDirectedEdge(1, 2);
        graph.PushDirectedEdge(3, 4);
        graph.PushDirectedEdge(5, 6);

        graph.TopologicalSort();
        string actualResult = unitTestHelper.SerializeVectorToString(graph.ShowTopologicalSortResult());
        string expectedResult = "5(9,12) 6(10,11) 3(5,8) 4(6,7) 1(1,4) 2(2,3)";

        EXPECT_EQ(actualResult, expectedResult);
    }

    // Test with a graph that has multiple nodes pointing to the same node
    TEST(TopoSortTesting, MultipleIncomingEdges)
    {
        Graph graph;
        graph.PushDirectedEdge(1, 3);
        graph.PushDirectedEdge(2, 3);
        graph.PushDirectedEdge(3, 4);

        graph.TopologicalSort();
        string actualResult = unitTestHelper.SerializeVectorToString(graph.ShowTopologicalSortResult());
        string expectedResult = "2(7,8) 1(1,6) 3(2,5) 4(3,4)";

        EXPECT_EQ(actualResult, expectedResult);
    }

    // Test for a single-node graph to check the base case
    TEST(TopoSortTesting, SingleNodeGraph)
    {
        Graph graph;
        graph.PushSingleNode(1);

        graph.TopologicalSort();
        string actualResult = unitTestHelper.SerializeVectorToString(graph.ShowTopologicalSortResult());
        string expectedResult = "1(1,2)";

        EXPECT_EQ(actualResult, expectedResult);
    }

    // Test with a cyclic graph to verify it can detect cycles (assuming cycle detection is implemented)
    TEST(TopoSortTesting, CyclicGraph)
    {
        Graph graph;
        graph.PushDirectedEdge(1, 2);
        graph.PushDirectedEdge(2, 3);
        graph.PushDirectedEdge(3, 1);  // Cycle: 1 -> 2 -> 3 -> 1

        graph.TopologicalSort();
         
        // Expected output if cycle detection is implemented
        EXPECT_THROW(graph.ShowTopologicalSortResult(), runtime_error);
    }
}