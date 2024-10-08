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

    TEST(DFSTesting, ShowDFSResultTest_SingleVertex)
    {
        DFSGraph graph;

        graph.PushDirectedEdge('a', 'a');

        graph.DFS();

        string actualResult = unitTestHelperVectorOfPair.VerifyVectorOfPairOfTwo(graph.ShowDFSResult());
        string expectedResult = "a(1,2)";
        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(DFSTesting, ShowDFSResultTest_DisconnectedGraph)
    {
        DFSGraph graph;

        graph.PushDirectedEdge('a', 'b');
        graph.PushDirectedEdge('c', 'd');

        graph.DFS();

        string actualResult = unitTestHelperVectorOfPair.VerifyVectorOfPairOfTwo(graph.ShowDFSResult());
        string expectedResult = "a(1,4) b(2,3) c(5,8) d(6,7)";
        EXPECT_EQ(actualResult, expectedResult);
    }
    
    TEST(DFSTesting, ShowDFSResultTest_CyclicGraph)
    {
        DFSGraph graph;

        graph.PushDirectedEdge('a', 'b');
        graph.PushDirectedEdge('b', 'c');
        graph.PushDirectedEdge('c', 'a');

        graph.DFS();

        string actualResult = unitTestHelperVectorOfPair.VerifyVectorOfPairOfTwo(graph.ShowDFSResult());
        string expectedResult = "a(1,6) b(2,5) c(3,4)";
        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(DFSTesting, ShowDFSResultTest_LargeGraph)
    {
        DFSGraph graph;

        // Adding 15 nodes with several edges
        graph.PushDirectedEdge('a', 'b');
        graph.PushDirectedEdge('a', 'c');
        graph.PushDirectedEdge('b', 'd');
        graph.PushDirectedEdge('d', 'e');
        graph.PushDirectedEdge('e', 'f');
        graph.PushDirectedEdge('f', 'g');
        graph.PushDirectedEdge('g', 'h');
        graph.PushDirectedEdge('h', 'i');
        graph.PushDirectedEdge('i', 'j');
        graph.PushDirectedEdge('j', 'k');
        graph.PushDirectedEdge('k', 'l');
        graph.PushDirectedEdge('l', 'm');
        graph.PushDirectedEdge('m', 'n');
        graph.PushDirectedEdge('n', 'o');
        graph.PushDirectedEdge('o', 'p');

        graph.DFS();

        string actualResult = unitTestHelperVectorOfPair.VerifyVectorOfPairOfTwo(graph.ShowDFSResult());
        string expectedResult = "a(1,32) b(2,29) c(30,31) d(3,28) e(4,27) f(5,26) g(6,25) h(7,24) i(8,23) j(9,22) k(10,21) l(11,20) m(12,19) n(13,18) o(14,17) p(15,16)";
        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(DFSTesting, ShowDFSResultTest_NoEdges)
    {
        DFSGraph graph;

        // Adding isolated nodes
        graph.PushDirectedEdge('a', 'a');
        graph.PushDirectedEdge('b', 'b');
        graph.PushDirectedEdge('c', 'c');

        graph.DFS();

        string actualResult = unitTestHelperVectorOfPair.VerifyVectorOfPairOfTwo(graph.ShowDFSResult());
        string expectedResult = "a(1,2) b(3,4) c(5,6)";
        EXPECT_EQ(actualResult, expectedResult);
    }
    
    TEST(DFSTesting, ShowDFSResultTest_CyclicGraphWithBackEdges)
    {
        DFSGraph graph;

        // Creating a cycle with back edges
        graph.PushDirectedEdge('a', 'b');
        graph.PushDirectedEdge('b', 'c');
        graph.PushDirectedEdge('c', 'a'); // Cycle back to 'a'
        graph.PushDirectedEdge('b', 'd'); // Back edge

        graph.DFS();

        string actualResult = unitTestHelperVectorOfPair.VerifyVectorOfPairOfTwo(graph.ShowDFSResult());
        string expectedResult = "a(1,8) b(2,7) c(3,4) d(5,6)";
        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(DFSTesting, ShowDFSResultTest_DenseGraph)
    {
        DFSGraph graph;

        // Complete graph of 4 nodes
        graph.PushDirectedEdge('a', 'b');
        graph.PushDirectedEdge('a', 'c');
        graph.PushDirectedEdge('a', 'd');
        graph.PushDirectedEdge('b', 'a');
        graph.PushDirectedEdge('b', 'c');
        graph.PushDirectedEdge('b', 'd');
        graph.PushDirectedEdge('c', 'a');
        graph.PushDirectedEdge('c', 'b');
        graph.PushDirectedEdge('c', 'd');
        graph.PushDirectedEdge('d', 'a');
        graph.PushDirectedEdge('d', 'b');
        graph.PushDirectedEdge('d', 'c');

        graph.DFS();

        string actualResult = unitTestHelperVectorOfPair.VerifyVectorOfPairOfTwo(graph.ShowDFSResult());
        string expectedResult = "a(1,8) b(2,7) c(3,6) d(4,5)";
        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(DFSTesting, ShowDFSResultTest_SelfLoopsAndParallelEdges)
    {
        DFSGraph graph;

        // Adding self-loops and parallel edges
        graph.PushDirectedEdge('a', 'a');
        graph.PushDirectedEdge('a', 'b');
        graph.PushDirectedEdge('b', 'b');
        graph.PushDirectedEdge('b', 'c');
        graph.PushDirectedEdge('b', 'c'); // Parallel edge
        graph.PushDirectedEdge('c', 'c'); // Self-loop

        graph.DFS();

        string actualResult = unitTestHelperVectorOfPair.VerifyVectorOfPairOfTwo(graph.ShowDFSResult());
        string expectedResult = "a(1,6) b(2,5) c(3,4)";
        EXPECT_EQ(actualResult, expectedResult);
    }

}