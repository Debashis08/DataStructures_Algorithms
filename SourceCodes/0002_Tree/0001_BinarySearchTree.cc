#include "../Headers/0002_Tree/0001_BinarySearchTree.h"
#include<iostream>
using namespace std;


Node::Node(int data, Node* parent, Node* left, Node* right)
{
	this->data = data;
	this->parent = parent;
	this->left = left;
	this->right = right;
}

BinarySearchTree::BinarySearchTree()
{
	this->_root = nullptr;
}


void BinarySearchTree::_InsertNode(Node* node)
{
	Node* nodeY = nullptr;
	Node* nodeX = this->_root;
	while (nodeX != nullptr)
	{
		nodeY = nodeX;
		if (node->data < nodeX->data)
		{
			nodeX = nodeX->left;
		}
		else
		{
			nodeX = nodeX->right;
		}
	}
	node->parent = nodeY;
	if (nodeY == nullptr)
	{
		this->_root = node;
	}
	else if (node->data < nodeY->data)
	{
		nodeY->left = node;
	}
	else
	{
		nodeY->right = node;
	}
}

Node* BinarySearchTree::_FindNode(int value)
{
	Node* node = this->_root;
	while (node != nullptr)
	{
		if (value < node->data)
		{
			node = node->left;
		}
		else if(value > node->data)
		{
			node = node->right;
		}
		else
		{
			break;
		}
	}
	return node;
}

Node* BinarySearchTree::_FindMinimumValueNode(Node* node)
{
	while (node->left != nullptr)
	{
		node = node->left;
	}
	return node;
}

Node* BinarySearchTree::_FindMaximumValueNode(Node* node)
{
	while (node->right != nullptr)
	{
		node = node->right;
	}
	return node;
}

Node* BinarySearchTree::_FindSuccessorNode(Node* node)
{
	if (node->right != nullptr)
	{
		return this->_FindMinimumValueNode(node->right);
	}
	Node* nodeY = node->parent;
	while (nodeY != nullptr && node == nodeY->right)
	{
		node = nodeY;
		nodeY = nodeY->parent;
	}
	return nodeY;
}

Node* BinarySearchTree::_FindPredecessorNode(Node* node)
{
	if (node->left != nullptr)
	{
		return this->_FindMaximumValueNode(node->left);
	}
	Node* nodeY = node->parent;
	while (nodeY != nullptr && node == nodeY->left)
	{
		node = nodeY;
		nodeY = nodeY->parent;
	}
	return nodeY;
}

void BinarySearchTree::_Transplant(Node* nodeU, Node* nodeV)
{
	if (nodeU->parent == nullptr)
	{
		this->_root = nodeV;
	}
	else if (nodeU == nodeU->parent->left)
	{
		nodeU->parent->left = nodeV;
	}
	else
	{
		nodeU->parent->right = nodeV;
	}

	if (nodeV != nullptr)
	{
		nodeV->parent = nodeU->parent;
	}
}

void BinarySearchTree::_DeleteNode(Node* node)
{
	if (node->left == nullptr)
	{
		this->_Transplant(node, node->right);
	}
	else if (node->right == nullptr)
	{
		this->_Transplant(node, node->left);
	}
	else
	{
		Node* nodeY = this->_FindMinimumValueNode(node->right);
		if (nodeY->parent != node)
		{
			this->_Transplant(nodeY, nodeY->right);
			nodeY->right = node->right;
			nodeY->right->parent = nodeY;
		}
		this->_Transplant(node, nodeY);
		nodeY->left = node->left;
		nodeY->left->parent = nodeY;
		delete node;
	}
}

string BinarySearchTree::_RecursiveInorderTraversal(Node* node)
{
	if (node == nullptr)
	{
		return "";
	}
	string leftSubTree = this->_RecursiveInorderTraversal(node->left);
	string currentNode = to_string(node->data);
	string rightSubTree = this->_RecursiveInorderTraversal(node->right);

	string result = leftSubTree;
	if (!leftSubTree.empty())
	{
		result += " ";
	}
	result += currentNode;
	if (!rightSubTree.empty())
	{
		result += " ";
	}
	result += rightSubTree;
	return result;
}

string BinarySearchTree::_RecursivePreorderTraversal(Node* node)
{
	if (node == nullptr)
	{
		return "";
	}
	string currentNode = to_string(node->data);
	string leftSubTree = this->_RecursivePreorderTraversal(node->left);
	string rightSubTree = this->_RecursivePreorderTraversal(node->right);

	string result = currentNode;
	if (!leftSubTree.empty())
	{
		result += " ";
	}
	result += leftSubTree;
	if (!rightSubTree.empty())
	{
		result += " ";
	}
	result += rightSubTree;
	return result;
}

string BinarySearchTree::_RecursivePostorderTraversal(Node* node)
{
	if (node == nullptr)
	{
		return "";
	}
	string leftSubTree = this->_RecursivePostorderTraversal(node->left);
	string rightSubTree = this->_RecursivePostorderTraversal(node->right);
	string currentNode = to_string(node->data);

	string result = leftSubTree;
	if (!leftSubTree.empty())
	{
		result += " ";
	}
	result += rightSubTree;
	if (!rightSubTree.empty())
	{
		result += " ";
	}
	result += currentNode;
	return result;
}

string BinarySearchTree::_MorrisInorderTraversal(Node* node)
{
	string result = "";
	while (node != nullptr)
	{
		if (node->left == nullptr)
		{
			result += to_string(node->data) + " ";
			node = node->right;
		}
		else
		{
			Node* predecessor = node->left;
			while (predecessor->right != nullptr && predecessor->right != node)
			{
				predecessor = predecessor->right;
			}
			if (predecessor->right == nullptr)
			{
				predecessor->right = node;
				node = node->left;
			}
			else
			{
				predecessor->right = nullptr;
				result += to_string(node->data) + " ";
				node = node->right;
			}
		}
	}
	if (!result.empty())
	{
		result.pop_back();
	}
	return result;
}

string BinarySearchTree::_MorrisPreorderTraversal(Node* node)
{
	string result = "";
	while (node != nullptr)
	{
		if (node->left == nullptr)
		{
			result += to_string(node->data) + " ";
			node = node->right;
		}
		else
		{
			Node* predecessor = node->left;
			while (predecessor->right != nullptr && predecessor->right != node)
			{
				predecessor = predecessor->right;
			}
			if (predecessor->right == nullptr)
			{
				predecessor->right = node;
				result += to_string(node->data) + " ";
				node = node->left;
			}
			else
			{
				predecessor->right = nullptr;
				node = node->right;
			}
		}
	}
	if (!result.empty())
	{
		result.pop_back();
	}
	return result;
}

void BinarySearchTree::InsertNode(int value)
{
	Node* node = new Node(value, nullptr, nullptr, nullptr);
	this->_InsertNode(node);
}

void BinarySearchTree::DeleteNode(int value)
{
	Node* node = this->_FindNode(value);
	this->_DeleteNode(node);
}

string BinarySearchTree::GetRecursiveInorderTravesalResult()
{
	return this->_RecursiveInorderTraversal(this->_root);
}

string BinarySearchTree::GetRecursivePreorderTravesalResult()
{
	return this->_RecursivePreorderTraversal(this->_root);
}

string BinarySearchTree::GetRecursivePostorderTravesalResult()
{
	return this->_RecursivePostorderTraversal(this->_root);
}

string BinarySearchTree::GetMorrisInorderTraversalResult()
{
	return this->_MorrisInorderTraversal(this->_root);
}

string BinarySearchTree::GetMorrisPreorderTraversalResult()
{
	return this->_MorrisPreorderTraversal(this->_root);
}