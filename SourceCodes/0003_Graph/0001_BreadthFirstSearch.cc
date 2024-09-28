#include "../Headers/0003_Graph/0001_BreadthFirstSearch.h"
#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#include<string>
#include<climits>
using namespace std;

Node::Node(char value)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
{
	this->data = value;
	distance = INT_MAX;
	color = WHITE;
	parent = NULL;
}

Node* Graph::MakeOrFindNode(char value)
{
	Node* node = NULL;
	if (this->_nodeMap.find(value) == this->_nodeMap.end())
	{
		node = new Node(value);
		this->_nodeMap[value] = node;
	}
	else
	{
		node = this->_nodeMap[value];
	}
	return node;
}

void Graph::BreadthFirstSearch(Node* node)
{
	node->color = WHITE;
	node->distance = 0;
	node->parent = NULL;

	queue<Node*> nodeQueue;
	nodeQueue.push(node);

	while (nodeQueue.empty()!=true)
	{
		Node* currentNode = nodeQueue.front();
		nodeQueue.pop();

		for (auto &adjacentNode : this->_adjlist[currentNode])
		{
			if (adjacentNode->color == WHITE)
			{
				adjacentNode->color = GRAY;
				adjacentNode->parent = currentNode;
				adjacentNode->distance = currentNode->distance + 1;
				nodeQueue.push(adjacentNode);
			}
		}
		currentNode->color = BLACK;
	}
}

void Graph::PushUndirectedEdge(char valueU, char valueV)
{
	Node* nodeU = this->MakeOrFindNode(valueU);
	Node* nodeV = this->MakeOrFindNode(valueV);

	this->_adjlist[nodeU].push_back(nodeV);
	this->_adjlist[nodeV].push_back(nodeU);
}

void Graph::BFS(char value)
{
	this->BreadthFirstSearch(this->_nodeMap[value]);
}

vector<pair<char, int>> Graph::ShowBFSResult()
{
	vector<pair<char, int>> result;
	for (auto& node : this->_nodeMap)
	{
		result.push_back(make_pair(node.first, node.second->distance));
	}
	return result;
}