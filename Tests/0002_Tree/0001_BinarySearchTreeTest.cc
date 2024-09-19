#include <gtest/gtest.h>
#include<string>
#include "../Headers/0002_Tree/0001_BinarySearchTree.h"
#include "../0000_CommonUtilities/UnitTestHelper.h"

// Demonstrate some basic assertions.
namespace BinarySearchTreeTest
{
    TEST(BSTInsertData, RecursiveInorderTest)
    {
        UnitTestHelper<int> unitTestHelper;
        BinarySearchTree bst;
        bst.InsertNode(50);
        bst.InsertNode(30);
        bst.InsertNode(60);


        string actualResult = bst.GetRecursiveInorderTravesalResult();
        string r = unitTestHelper.VerifyVectorResult({30, 50, 60});
        string expectedResult = "30 50 60";

        EXPECT_EQ(actualResult, r);
    }

    TEST(BSTInsertData, RecursivePreorderTest)
    {
        BinarySearchTree bst;
        bst.InsertNode(50);
        bst.InsertNode(30);
        bst.InsertNode(60);

        string actualResult = bst.GetRecursivePreorderTravesalResult();
        string expectedResult = "50 30 60";

        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(BSTInsertData, RecursivePostorderTest)
    {
        BinarySearchTree bst;
        bst.InsertNode(50);
        bst.InsertNode(30);
        bst.InsertNode(60);

        string actualResult = bst.GetRecursivePostorderTravesalResult();
        string expectedResult = "30 60 50";

        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(BSTInsertData, MorrisInorderTest)
    {
        BinarySearchTree bst;
        bst.InsertNode(50);
        bst.InsertNode(30);
        bst.InsertNode(60);
        

        string actualResult = bst.GetMorrisInorderTraversalResult();
        string expectedResult = "30 50 60";

        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(BSTInsertData, MorrisPreorderTest)
    {
        BinarySearchTree bst;
        bst.InsertNode(50);
        bst.InsertNode(30);
        bst.InsertNode(60);


        string actualResult = bst.GetMorrisPreorderTraversalResult();
        string expectedResult = "50 30 60";

        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(BSTInsertData, MorrisPostorderTest)
    {
        BinarySearchTree bst;
        bst.InsertNode(50);
        bst.InsertNode(30);
        bst.InsertNode(60);


        string actualResult = bst.GetMorrisPostorderTraversalResult();
        string expectedResult = "30 60 50";

        EXPECT_EQ(actualResult, expectedResult);
    }
}