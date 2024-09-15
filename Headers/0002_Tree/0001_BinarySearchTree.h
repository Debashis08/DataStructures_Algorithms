#pragma once

#include<string>
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
	void _InsertNode(Node* node);
	Node* _FindNode(int value);
	Node* _FindMinimumValueNode(Node* node);
	Node* _FindMaximumValueNode(Node* node);
	Node* _FindSuccessorNode(Node* node);
	Node* _FindPredecessorNode(Node* node);
	void _Transplant(Node* nodeU, Node* nodeV);
	void _DeleteNode(Node* node);
	string _RecursiveInorderTraversal(Node* node);
	string _RecursivePreorderTraversal(Node* node);
	string _RecursivePostorderTraversal(Node* node);
	string _MorrisInorderTraversal(Node* node);
	string _MorrisPreorderTraversal(Node* node);
	string _MorrisPostorderTraversal(Node* node);
public:
	BinarySearchTree();
	void InsertNode(int value);
	void DeleteNode(int value);
	string GetRecursiveInorderTravesalResult();
	string GetRecursivePreorderTravesalResult();
	string GetRecursivePostorderTravesalResult();
	string GetMorrisInorderTraversalResult();
	string GetMorrisPreorderTraversalResult();
	string GetMorrisPostorderTraversalResult();
};