#pragma once

#include<vector>
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
	void _RecursiveInorderTraversal(Node* node, vector<int>& result);
	void _RecursivePreorderTraversal(Node* node, vector<int>& result);
	void _RecursivePostorderTraversal(Node* node, vector<int>& result);
	void _MorrisInorderTraversal(Node* node, vector<int>& result);
	void _MorrisPreorderTraversal(Node* node, vector<int>& result);
	void _MorrisPostorderTraversal(Node* node, vector<int>& result);
public:
	BinarySearchTree();
	void InsertNode(int value);
	void DeleteNode(int value);
	vector<int> GetRecursiveInorderTravesalResult();
	vector<int> GetRecursivePreorderTravesalResult();
	vector<int> GetRecursivePostorderTravesalResult();
	vector<int> GetMorrisInorderTraversalResult();
	vector<int> GetMorrisPreorderTraversalResult();
	vector<int> GetMorrisPostorderTraversalResult();
};