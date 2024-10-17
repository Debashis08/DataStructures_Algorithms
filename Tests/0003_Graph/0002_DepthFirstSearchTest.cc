#include<gtest/gtest.h>
#include "../Headers/0003_Graph/0002_DepthFirstSearch.h"
#include "../0000_CommonUtilities/UnitTestHelper.h"

namespace DepthFirstSearchTest
{
    UnitTestHelper unitTestHelper;

    TEST(DFSTesting, ShowDFSResultTest01)
    {
        DFSGraph graph;

        graph.PushDirectedEdge(1, 2);
        graph.PushDirectedEdge(1, 4);
        graph.PushDirectedEdge(2, 5);
        graph.PushDirectedEdge(3, 5);
        graph.PushDirectedEdge(3, 6);
        graph.PushDirectedEdge(4, 2);
        graph.PushDirectedEdge(5, 4);
        graph.PushDirectedEdge(6, 6);

        graph.DFS();

        string actualResult = unitTestHelper.VerifyVectorResult(graph.ShowDFSResult());
        string expectedResult = "1(1,8) 2(2,7) 3(9,12) 4(4,5) 5(3,6) 6(10,11)";
        EXPECT_EQ(actualResult, expectedResult);
    }


    TEST(DFSTesting, ShowDFSResultTest_SingleVertex)
    {
        DFSGraph graph;

        graph.PushDirectedEdge(1, 1);

        graph.DFS();

        string actualResult = unitTestHelper.VerifyVectorResult(graph.ShowDFSResult());
        string expectedResult = "1(1,2)";
        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(DFSTesting, ShowDFSResultTest_DisconnectedGraph)
    {
        DFSGraph graph;

        graph.PushDirectedEdge(1, 2);
        graph.PushDirectedEdge(3, 4);

        graph.DFS();

        string actualResult = unitTestHelper.VerifyVectorResult(graph.ShowDFSResult());
        string expectedResult = "1(1,4) 2(2,3) 3(5,8) 4(6,7)";
        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(DFSTesting, ShowDFSResultTest_CyclicGraph)
    {
        DFSGraph graph;

        graph.PushDirectedEdge(1, 2);
        graph.PushDirectedEdge(2, 3);
        graph.PushDirectedEdge(3, 1);

        graph.DFS();

        string actualResult = unitTestHelper.VerifyVectorResult(graph.ShowDFSResult());
        string expectedResult = "1(1,6) 2(2,5) 3(3,4)";
        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(DFSTesting, ShowDFSResultTest_LargeGraph)
    {
        DFSGraph graph;

        // Adding 15 nodes with several edges
        graph.PushDirectedEdge(1, 2);
        graph.PushDirectedEdge(1, 3);
        graph.PushDirectedEdge(2, 4);
        graph.PushDirectedEdge(4, 5);
        graph.PushDirectedEdge(5, 6);
        graph.PushDirectedEdge(6, 7);
        graph.PushDirectedEdge(7, 8);
        graph.PushDirectedEdge(8, 9);
        graph.PushDirectedEdge(9, 10);
        graph.PushDirectedEdge(10, 11);
        graph.PushDirectedEdge(11, 12);
        graph.PushDirectedEdge(12, 13);
        graph.PushDirectedEdge(13, 14);
        graph.PushDirectedEdge(14, 15);
        graph.PushDirectedEdge(15, 16);

        graph.DFS();

        string actualResult = unitTestHelper.VerifyVectorResult(graph.ShowDFSResult());
        string expectedResult = "1(1,32) 2(2,29) 3(30,31) 4(3,28) 5(4,27) 6(5,26) 7(6,25) 8(7,24) 9(8,23) 10(9,22) 11(10,21) 12(11,20) 13(12,19) 14(13,18) 15(14,17) 16(15,16)";
        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(DFSTesting, ShowDFSResultTest_NoEdges)
    {
        DFSGraph graph;

        // Adding isolated nodes
        graph.PushDirectedEdge(1, 1);
        graph.PushDirectedEdge(2, 2);
        graph.PushDirectedEdge(3, 3);

        graph.DFS();

        string actualResult = unitTestHelper.VerifyVectorResult(graph.ShowDFSResult());
        string expectedResult = "1(1,2) 2(3,4) 3(5,6)";
        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(DFSTesting, ShowDFSResultTest_CyclicGraphWithBackEdges)
    {
        DFSGraph graph;

        // Creating a cycle with back edges
        graph.PushDirectedEdge(1, 2);
        graph.PushDirectedEdge(2, 3);
        graph.PushDirectedEdge(3, 1); // Cycle back to 'a'
        graph.PushDirectedEdge(2, 4); // Back edge

        graph.DFS();

        string actualResult = unitTestHelper.VerifyVectorResult(graph.ShowDFSResult());
        string expectedResult = "1(1,8) 2(2,7) 3(3,4) 4(5,6)";
        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(DFSTesting, ShowDFSResultTest_DenseGraph)
    {
        DFSGraph graph;

        // Complete graph of 4 nodes
        graph.PushDirectedEdge(1, 2);
        graph.PushDirectedEdge(1, 3);
        graph.PushDirectedEdge(1, 4);
        graph.PushDirectedEdge(2, 1);
        graph.PushDirectedEdge(2, 3);
        graph.PushDirectedEdge(2, 4);
        graph.PushDirectedEdge(3, 1);
        graph.PushDirectedEdge(3, 2);
        graph.PushDirectedEdge(3, 4);
        graph.PushDirectedEdge(4, 1);
        graph.PushDirectedEdge(4, 2);
        graph.PushDirectedEdge(4, 3);

        graph.DFS();

        string actualResult = unitTestHelper.VerifyVectorResult(graph.ShowDFSResult());
        string expectedResult = "1(1,8) 2(2,7) 3(3,6) 4(4,5)";
        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(DFSTesting, ShowDFSResultTest_SelfLoopsAndParallelEdges)
    {
        DFSGraph graph;

        // Adding self-loops and parallel edges
        graph.PushDirectedEdge(1, 1);
        graph.PushDirectedEdge(1, 2);
        graph.PushDirectedEdge(2, 2);
        graph.PushDirectedEdge(2, 3);
        graph.PushDirectedEdge(2, 3); // Parallel edge
        graph.PushDirectedEdge(3, 3); // Self-loop

        graph.DFS();

        string actualResult = unitTestHelper.VerifyVectorResult(graph.ShowDFSResult());
        string expectedResult = "1(1,6) 2(2,5) 3(3,4)";
        EXPECT_EQ(actualResult, expectedResult);
    }

}