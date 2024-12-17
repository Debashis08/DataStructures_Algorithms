#include<gtest/gtest.h>
#include "../Headers/0003_Graph/0007_MinimumSpanningTreeKruskalAlgorithm.h"
#include "../0000_CommonUtilities/UnitTestHelper.h"

namespace MinimumSpanningTreeKruskalAlgorithm
{
	UnitTestHelper unitTestHelper;

	TEST(MST, Kruskal)
	{
		Graph graph;

		graph.PushUndirectedEdge(1, 2, 4);
		graph.PushUndirectedEdge(1, 8, 8);
		graph.PushUndirectedEdge(2, 8, 11);
		graph.PushUndirectedEdge(2, 3, 8);
		graph.PushUndirectedEdge(3, 4, 7);
		graph.PushUndirectedEdge(3, 9, 2);
		graph.PushUndirectedEdge(3, 6, 4);
		graph.PushUndirectedEdge(4, 5, 9);
		graph.PushUndirectedEdge(4, 6, 14);
		graph.PushUndirectedEdge(5, 6, 10);
		graph.PushUndirectedEdge(6, 7, 2);
		graph.PushUndirectedEdge(7, 8, 1);
		graph.PushUndirectedEdge(7, 9, 6);
		graph.PushUndirectedEdge(8, 9, 7);

		graph.FindMinimumSpanningTreeKruskalAlgorithm();

		vector<pair<pair<int,int>, int>> actualMST = graph.GetMinimumSpanningTree();
		vector<pair<pair<int, int>, int>> expectedMST =
		{
			{{7, 8}, 1},
			{{3, 9}, 2},
			{{6, 7}, 2},
			{{2, 1}, 4},
			{{3, 6}, 4},
			{{3, 4}, 7},
			{{8, 1}, 8},
			{{4, 5}, 9}
		};

		ASSERT_EQ(unitTestHelper.SortVectorOfPair(actualMST), unitTestHelper.SortVectorOfPair(expectedMST));
	}
}