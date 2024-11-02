#include<gtest/gtest.h>
#include "../Headers/0003_Graph/0004_StronglyConnectedComponents.h"
#include "../0000_CommonUtilities/UnitTestHelper.h"

namespace StronglyConnectedComponentsTest
{
	UnitTestHelper  unitTestHelper;

    // Test case: Testing with a simple graph.
	TEST(StronglyConnectedComponentsTesting, SimpleGraphTest)
	{
		StronglyConnectedComponentsGraph graph;

		graph.PushDirectedEdge(1, 2);
		graph.PushDirectedEdge(1, 5);
		graph.PushDirectedEdge(2, 3);
		graph.PushDirectedEdge(2, 4);
		graph.PushDirectedEdge(3, 2);
		graph.PushDirectedEdge(4, 4);
		graph.PushDirectedEdge(5, 1);
		graph.PushDirectedEdge(5, 4);
		graph.PushDirectedEdge(6, 1);
		graph.PushDirectedEdge(6, 3);
		graph.PushDirectedEdge(6, 7);
		graph.PushDirectedEdge(7, 3);
		graph.PushDirectedEdge(7, 8);
		graph.PushDirectedEdge(8, 6);

        auto actualResult = graph.FindAllStronglyConnectedComponents();
        vector<vector<int>> expectedResult = { {6, 8, 7},{1, 5},{2, 3},{4} };
        EXPECT_EQ(unitTestHelper.SortVectorOfVectors(actualResult), unitTestHelper.SortVectorOfVectors(expectedResult));
	}

    // Test case: Single Node.
    TEST(StronglyConnectedComponentsTesting, SingleNodeTest) 
    {
        StronglyConnectedComponentsGraph graph;
        graph.PushSingleNode(1);

        auto actualResult = graph.FindAllStronglyConnectedComponents();
        vector<vector<int>> expectedResult = { {1} };
        EXPECT_EQ(unitTestHelper.SortVectorOfVectors(actualResult), unitTestHelper.SortVectorOfVectors(expectedResult));
    }

    // Test case: Disconnected Graph.
    TEST(StronglyConnectedComponentsTesting, DisconnectedGraphTest)
    {
        StronglyConnectedComponentsGraph graph;
        graph.PushSingleNode(1);
        graph.PushSingleNode(2);
        graph.PushSingleNode(3);

        auto actualResult = graph.FindAllStronglyConnectedComponents();
        vector<vector<int>> expectedResult = { {1},{3},{2} };
        EXPECT_EQ(unitTestHelper.SortVectorOfVectors(actualResult), unitTestHelper.SortVectorOfVectors(expectedResult));
    }

    // Test case: Chain of Nodes.
    TEST(StronglyConnectedComponentsTesting, ChainOfNodesTest)
    {
        StronglyConnectedComponentsGraph graph;
        graph.PushDirectedEdge(1, 2);
        graph.PushDirectedEdge(2, 3);
        graph.PushDirectedEdge(3, 4);

        auto actualResult = graph.FindAllStronglyConnectedComponents();
        vector<vector<int>> expectedResult = { {2},{1},{3},{4} };
        EXPECT_EQ(unitTestHelper.SortVectorOfVectors(actualResult), unitTestHelper.SortVectorOfVectors(expectedResult));
    }

    // Test case: Bidirectional Edge.
    TEST(StronglyConnectedComponentsTesting, BidirectionalEdgeTest)
    {
        StronglyConnectedComponentsGraph graph;
        graph.PushDirectedEdge(1, 2);
        graph.PushDirectedEdge(2, 1);

        auto actualResult = graph.FindAllStronglyConnectedComponents();
        vector<vector<int>> expectedResult = { {2, 1} };
        EXPECT_EQ(unitTestHelper.SortVectorOfVectors(actualResult), unitTestHelper.SortVectorOfVectors(expectedResult));
    }

    // Test case: Complex Graph.
    TEST(StronglyConnectedComponentsTesting, ComplexGraphTest)
    {
        StronglyConnectedComponentsGraph graph;

        // Graph structure with multiple SCCs and isolated nodes.
        graph.PushDirectedEdge(1, 2);
        graph.PushDirectedEdge(2, 3);
        graph.PushDirectedEdge(3, 1);  // Cycle: 1 -> 2 -> 3 -> 1
        graph.PushDirectedEdge(4, 5);
        graph.PushDirectedEdge(5, 6);
        graph.PushDirectedEdge(6, 4);  // Cycle: 4 -> 5 -> 6 -> 4
        graph.PushDirectedEdge(7, 8);  // Single direction: 7 -> 8
        graph.PushSingleNode(9);       // Isolated node.

        auto actualResult = graph.FindAllStronglyConnectedComponents();
        vector<vector<int>> expectedResult = { {4, 6, 5},{7}, { 2, 3, 1},{8}, {9} };
        EXPECT_EQ(unitTestHelper.SortVectorOfVectors(actualResult), unitTestHelper.SortVectorOfVectors(expectedResult));
    }
}