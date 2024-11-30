#include<gtest/gtest.h>
#include "../Headers/0003_Graph/0005_HamiltonianPathAndCycle.h"
#include "../0000_CommonUtilities/UnitTestHelper.h"

namespace HamiltonianPathAndCycle
{
	UnitTestHelper unitTestHelper;

	TEST(HamiltonianCycleAndPathTest, ShowResult)
	{
		Graph graph;

		graph.PushUndirectedEdge(0, 1);
		graph.PushUndirectedEdge(0, 3);
		graph.PushUndirectedEdge(1, 2);
		graph.PushUndirectedEdge(1, 3);
		graph.PushUndirectedEdge(1, 4);
		graph.PushUndirectedEdge(2, 4);
		graph.PushUndirectedEdge(3, 4);

		graph.FindHamiltonianCycleAndPath();

		bool isHamiltonianCyclePresent = graph.IsHamiltonianCyclePresent();
		bool isHamiltonianPathPresent = graph.IsHamiltonianPathPresent();

		vector<int> hamiltonianPathActualResult = graph.GetHamiltonianPath();
		vector<int> hamiltonianPathExpectedResult = { 4, 3, 0, 1, 2 };
		
		ASSERT_TRUE(isHamiltonianCyclePresent);
		ASSERT_TRUE(isHamiltonianPathPresent);
		ASSERT_TRUE(unitTestHelper.NormalizeCyclesAnCompare(hamiltonianPathActualResult, hamiltonianPathExpectedResult));
	}
}