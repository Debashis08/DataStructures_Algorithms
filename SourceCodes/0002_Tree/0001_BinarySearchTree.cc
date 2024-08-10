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
	this->_root = NULL;
}


void BinarySearchTree::_InsertNode(Node* node, int value)
{
	if (value < node->data)
	{
		if (node->left == NULL)
		{
			node->left = new Node(value, NULL, NULL, NULL);
		}
		else
		{
			this->_InsertNode(node->left, value);
		}
	}
	else
	{
		if (node->right == NULL)
		{
			node->right = new Node(value, NULL, NULL, NULL);
		}
		else
		{
			this->_InsertNode(node->right, value);
		}
	}
}

Node* BinarySearchTree::_FindNode(Node* node, int value)
{
	while (node != NULL)
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
	while (node->left != NULL)
	{
		node = node->left;
	}
	return node;
}

void BinarySearchTree::_DeleteNode(Node* node)
{

}

void BinarySearchTree::InsertNode(int value)
{
	if (this->_root == NULL)
	{
		this->_root = new Node(value, NULL, NULL, NULL);
	}
	else
	{
		this->_InsertNode(this->_root, value);
	}
}