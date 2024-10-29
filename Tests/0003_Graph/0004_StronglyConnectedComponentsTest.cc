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

		string actualResult = unitTestHelper.VerifyVectorResult(graph.FindAllStronglyConnectedComponents());
		string expectedResult = "[6 8 7][1 5][2 3][4]";
		EXPECT_EQ(actualResult, expectedResult);
	}
}