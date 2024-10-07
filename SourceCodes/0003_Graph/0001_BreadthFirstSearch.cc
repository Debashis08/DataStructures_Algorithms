#include "../Headers/0003_Graph/0001_BreadthFirstSearch.h"
#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#include<string>
#include<climits>
using namespace std;

BFSNode::BFSNode(char value)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
{
	this->data = value;
	this->distance = INT_MAX;
	this->color = WHITE;
	this->parent = nullptr;
}

BFSNode* BFSGraph::MakeOrFindNode(char value)
{
	BFSNode* node = nullptr;
	if (this->_nodeMap.find(value) == this->_nodeMap.end())
	{
		node = new BFSNode(value);
		this->_nodeMap[value] = node;
	}
	else
	{
		node = this->_nodeMap[value];
	}
	return node;
}

void BFSGraph::BreadthFirstSearch(BFSNode* node)
{
	node->color = WHITE;
	node->distance = 0;
	node->parent = nullptr;

	queue<BFSNode*> nodeQueue;
	nodeQueue.push(node);

	while (nodeQueue.empty()!=true)
	{
		BFSNode* currentNode = nodeQueue.front();
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

void BFSGraph::PushUndirectedEdge(char valueU, char valueV)
{
	BFSNode* nodeU = this->MakeOrFindNode(valueU);
	BFSNode* nodeV = this->MakeOrFindNode(valueV);

	this->_adjlist[nodeU].push_back(nodeV);
	this->_adjlist[nodeV].push_back(nodeU);
}

void BFSGraph::BFS(char value)
{
	this->BreadthFirstSearch(this->_nodeMap[value]);
}

vector<pair<char, int>> BFSGraph::ShowBFSResult()
{
	vector<pair<char, int>> result;
	for (auto& node : this->_nodeMap)
	{
		result.push_back(make_pair(node.first, node.second->distance));
	}
	return result;
}