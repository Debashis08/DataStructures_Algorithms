#include<gtest/gtest.h>
#include "../Headers/0003_Graph/0006_EulerianPathAndCircuit.h"
#include "../0000_CommonUtilities/UnitTestHelper.h"

namespace EulerianPathAndCircuit
{
	UnitTestHelper unitTestHelper;

	TEST(EulerianPathAndCycle, Test1)
	{
		Graph graph;

		graph.PushUndirectedEdge(1, 0);
		graph.PushUndirectedEdge(0, 2);
		graph.PushUndirectedEdge(2, 1);
		graph.PushUndirectedEdge(0, 3);
		graph.PushUndirectedEdge(3, 4);
		graph.PushUndirectedEdge(4, 0);

		graph.FindEulerianPathAndCircuit();

		bool isEulerianPathPresent = graph.IsEulerianPathPresent();
		bool isEulerianCircuitPresent = graph.IsEulerianCircuitPresent();

		vector<int> actualEulerianPath = graph.UndirectedGraphGetEulerianPath();
		vector<int> expectedEulerianPath = { 0, 1, 2, 0, 3, 4, 0};

		ASSERT_TRUE(isEulerianPathPresent);
		ASSERT_TRUE(isEulerianCircuitPresent);
		EXPECT_EQ(expectedEulerianPath, actualEulerianPath);
	}
}