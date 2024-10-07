#include<gtest/gtest.h>
#include "../Headers/0003_Graph/0002_DepthFirstSearch.h"
#include "../0000_CommonUtilities/UnitTestHelperVectorOfPair.h"

namespace DepthFirstSearchTest
{
    UnitTestHelperVectorOfPair<char, int> unitTestHelperVectorOfPair;

    TEST(DFSTesting, ShowDFSResultTest01)
    {
        DFSGraph graph;

        graph.PushDirectedEdge('u', 'v');
        graph.PushDirectedEdge('u', 'x');
        graph.PushDirectedEdge('v', 'y');
        graph.PushDirectedEdge('w', 'y');
        graph.PushDirectedEdge('w', 'z');
        graph.PushDirectedEdge('x', 'v');
        graph.PushDirectedEdge('y', 'x');
        graph.PushDirectedEdge('z', 'z');

        graph.DFS();

        string actualResult = unitTestHelperVectorOfPair.VerifyVectorOfPairOfTwo(graph.ShowDFSResult());
        string expectedResult = "u(1,8) v(2,7) w(9,12) x(4,5) y(3,6) z(10,11)";
        EXPECT_EQ(actualResult, expectedResult);
    }
}