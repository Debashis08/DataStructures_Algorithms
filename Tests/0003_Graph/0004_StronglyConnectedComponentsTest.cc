#include<gtest/gtest.h>
#include "../Headers/0003_Graph/0004_StronglyConnectedComponents.h"
#include "../0000_CommonUtilities/UnitTestHelper.h"

namespace StronglyConnectedComponentsTest
{
	UnitTestHelper  unitTestHelper;

	TEST(StronglyConnectedComponentsTesting, SimpleGraphTest)
	{
		StronglyConnectedComponentsGraph graph;

		graph.PushDirectedEdge(1, 2);
		graph.PushDirectedEdge(2, 3);
		graph.PushDirectedEdge(2, 5);
		graph.PushDirectedEdge(2, 6);
		graph.PushDirectedEdge(3, 4);
		graph.PushDirectedEdge(3, 7);
		graph.PushDirectedEdge(4, 3);
		graph.PushDirectedEdge(4, 8);
		graph.PushDirectedEdge(5, 1);
		graph.PushDirectedEdge(5, 6);
		graph.PushDirectedEdge(6, 7);
		graph.PushDirectedEdge(7, 6);
		graph.PushDirectedEdge(7, 8);
		graph.PushDirectedEdge(8, 8);

		string actualResult = unitTestHelper.VerifyVectorResult(graph.FindAllStronglyConnectedComponents());
		string expectedResult = "";
		EXPECT_EQ(actualResult, expectedResult);
	}
}