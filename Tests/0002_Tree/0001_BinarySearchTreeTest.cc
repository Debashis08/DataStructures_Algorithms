#include <gtest/gtest.h>
#include<string>
#include "../Headers/0002_Tree/0001_BinarySearchTree.h"

// Demonstrate some basic assertions.
namespace BinarySearchTreeTest
{
    TEST(BSTTesting, ShowBSTResultTest)
    {
        BinarySearchTree bst;
        bst.InsertNode(50);
        bst.InsertNode(30);
        bst.InsertNode(60);


        string actualResult = bst.GetRecursiveInorderTravesalResult();
        string expectedResult = "30 50 60";

        EXPECT_EQ(actualResult, expectedResult);
    }
}