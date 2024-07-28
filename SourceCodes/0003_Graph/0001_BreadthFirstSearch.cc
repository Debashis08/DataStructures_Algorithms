#include "../Headers/0003_Graph/0001_BreadthFirstSearch.h"
#include<queue>
using namespace std;

Node::Node(char value)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
{
	this->data = value;
	distance = INT_MAX;
	color = WHITE;
	parent = NULL;
}

Node* BFSGraph::MakeOrFindNode(char value)
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

void BFSGraph::BreadthFirstSearch(Node* node)
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

		for (auto adjacentNode : this->_adjlist[currentNode])
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
	Node* nodeU = this->MakeOrFindNode(valueU);
	Node* nodeV = this->MakeOrFindNode(valueV);

	this->_adjlist[nodeU].push_back(nodeV);
	this->_adjlist[nodeV].push_back(nodeU);
}

void BFSGraph::BFS(char value)
{
	this->BreadthFirstSearch(this->_nodeMap[value]);
}