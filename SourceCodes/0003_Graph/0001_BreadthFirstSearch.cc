#include "../Headers/0003_Graph/0001_BreadthFirstSearch.h"
#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#include<string>
#include<climits>
using namespace std;

namespace BreadthFirstSearch
{
	Node::Node(int value)
	{
		this->data = value;
		this->distance = INT_MAX;
		this->color = WHITE;
		this->parent = nullptr;
	}

	Node* Graph::MakeOrFindNode(int value)
	{
		Node* node = nullptr;
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
		node->parent = nullptr;

		queue<Node*> nodeQueue;
		nodeQueue.push(node);

		while (nodeQueue.empty() != true)
		{
			Node* currentNode = nodeQueue.front();
			nodeQueue.pop();

			for (auto& adjacentNode : this->_adjlist[currentNode])
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

	void Graph::PushUndirectedEdge(int valueU, int valueV)
	{
		Node* nodeU = this->MakeOrFindNode(valueU);
		Node* nodeV = this->MakeOrFindNode(valueV);

		this->_adjlist[nodeU].push_back(nodeV);
		this->_adjlist[nodeV].push_back(nodeU);
	}

	void Graph::BFS(int value)
	{
		this->BreadthFirstSearch(this->_nodeMap[value]);
	}

	vector<pair<int, int>> Graph::ShowBFSResult()
	{
		vector<pair<int, int>> result;
		for (auto& node : this->_nodeMap)
		{
			result.push_back(make_pair(node.first, node.second->distance));
		}
		return result;
	}
}