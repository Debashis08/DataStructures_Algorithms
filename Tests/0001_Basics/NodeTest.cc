#include <gtest/gtest.h>
#include "../Headers/0001_Basics/Node.h"

// Demonstrate some basic assertions.
namespace NodeTesting
{
	TEST(TestingNodeValue, PositiveTestCase) {
		// Expect two strings not to be equal.
		Node* temp = new Node();
		EXPECT_EQ(temp->value, 8);
		EXPECT_STRNE("hello", "world");
		// Expect equality.
		EXPECT_EQ(2 * 4, 8);
	}
}