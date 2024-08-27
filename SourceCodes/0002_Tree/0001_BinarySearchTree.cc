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

Node* BinarySearchTree::_FindNode(Node* node, int value)
{
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
		return node;
	}
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
}

void BinarySearchTree::_DeleteNode(Node* node)
{
	
}

void BinarySearchTree::InsertNode(int value)
{
	Node* node = new Node(value, nullptr, nullptr, nullptr);
	this->_InsertNode(node);
}