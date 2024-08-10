#pragma once
using namespace std;

class Node
{
public:
	int data;
	Node* parent;
	Node* left;
	Node* right;

	Node(int data, Node* parent, Node* left, Node* right);
};

class BinarySearchTree
{
private:
	Node* _root;
	void _InsertNode(Node* node, int value);
	Node* _FindNode(Node* node, int value);
	Node* _FindMinimumValueNode(Node* node);
	void _DeleteNode(Node* node);
	void _RecursiveInorderTraversal(Node* node);
	void _RecursivePreorderTraversal(Node* node);
	void _RecursivePostorderTraversal(Node* node);
	void _MorrisInorderTraversal(Node* node);
	void _MorrisPreorderTraversal(Node* node);
	void _MorrisPostorderTraversal(Node* node);
public:
	BinarySearchTree();
	void InsertNode(int value);
};