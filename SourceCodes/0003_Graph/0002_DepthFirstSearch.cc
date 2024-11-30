#include "../Headers/0003_Graph/0002_DepthFirstSearch.h"
#include<vector>
#include<utility>
#include<climits>
using namespace std;

namespace DepthFirstSearch
{
	Node::Node(int value)
	{
		this->data = value;
		this->discoveredTime = INT_MAX;
		this->finishingTime = INT_MAX;
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

	void Graph::DepthFirstSearch(Node* nodeU)
	{
		this->time++;
		nodeU->discoveredTime = this->time;
		nodeU->color = GRAY;
		for (auto nodeV : this->_adjlist[nodeU])
		{
			if (nodeV->color == WHITE)
			{
				nodeV->parent = nodeU;
				this->DepthFirstSearch(nodeV);
			}
		}
		nodeU->color = BLACK;
		this->time++;
		nodeU->finishingTime = time;
	}

	void Graph::PushDirectedEdge(int valueU, int valueV)
	{
		Node* nodeU = this->MakeOrFindNode(valueU);
		Node* nodeV = this->MakeOrFindNode(valueV);

		this->_adjlist[nodeU].push_back(nodeV);
	}

	void Graph::DFS()
	{
		this->time = 0;
		for (auto& iterator : this->_nodeMap)
		{
			if (iterator.second->color == WHITE)
			{
				this->DepthFirstSearch(iterator.second);
			}
		}
	}

	vector<pair<int, pair<int, int>>> Graph::ShowDFSResult()
	{
		vector<pair<int, pair<int, int>>> result;
		for (auto& node : this->_nodeMap)
		{
			result.push_back(make_pair(node.first, make_pair(node.second->discoveredTime, node.second->finishingTime)));
		}
		return result;
	}
}