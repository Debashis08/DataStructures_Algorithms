#include "../Headers/0003_Graph/0004_StronglyConnectedComponents.h"
#include<vector>
#include<utility>
#include<climits>
using namespace std;

namespace StronglyConnectedComponents
{
	Node::Node(int value)
	{
		this->data = value;
		this->discoveryTime = INT_MAX;
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

	void Graph::DepthFirstSearchOnGraphG(Node* nodeU)
	{
		this->time++;
		nodeU->discoveryTime = this->time;
		nodeU->color = GRAY;
		for (auto nodeV : this->_adjlistG[nodeU])
		{
			if (nodeV->color == WHITE)
			{
				nodeV->parent = nodeU;
				this->DepthFirstSearchOnGraphG(nodeV);
			}
		}
		nodeU->color = BLACK;
		this->time++;
		nodeU->finishingTime = time;
		this->_nodesFinishingTimeOrder.push_front(nodeU);
	}

	void Graph::DepthFirstSearchOnGraphT(Node* nodeU, vector<int>& connectedComponents)
	{
		nodeU->color = GRAY;
		connectedComponents.push_back(nodeU->data);
		for (auto nodeV : this->_adjlistT[nodeU])
		{
			if (nodeV->color == WHITE)
			{
				nodeV->parent = nodeU;
				this->DepthFirstSearchOnGraphT(nodeV, connectedComponents);
			}
		}
		nodeU->color = BLACK;
	}

	void Graph::PushDirectedEdge(int valueU, int valueV)
	{
		Node* nodeU = this->MakeOrFindNode(valueU);
		Node* nodeV = this->MakeOrFindNode(valueV);

		// Creating the actual graph.
		this->_adjlistG[nodeU].push_back(nodeV);

		// Creating the transpose of the actual graph.
		this->_adjlistT[nodeV].push_back(nodeU);
	}

	void Graph::PushSingleNode(int valueU)
	{
		Node* nodeU = this->MakeOrFindNode(valueU);
	}

	void Graph::DFSOnGraphG()
	{
		this->time = 0;
		for (auto& iterator : this->_nodeMap)
		{
			if (iterator.second->color == WHITE)
			{
				this->DepthFirstSearchOnGraphG(iterator.second);
			}
		}
	}

	void Graph::DFSOnGraphT()
	{
		for (auto& iterator : this->_nodeMap)
		{
			iterator.second->color = WHITE;
			iterator.second->parent = nullptr;
		}

		for (auto& iterator : this->_nodesFinishingTimeOrder)
		{
			if (iterator->color == WHITE)
			{
				vector<int> connectedComponents;
				this->DepthFirstSearchOnGraphT(iterator, connectedComponents);
				this->_allConnectedComponents.push_back(connectedComponents);
			}
		}
	}

	vector<vector<int>> Graph::FindAllStronglyConnectedComponents()
	{
		this->DFSOnGraphG();
		this->DFSOnGraphT();
		return this->_allConnectedComponents;
	}
}