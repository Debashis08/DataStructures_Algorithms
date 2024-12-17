#include "../Headers/0003_Graph/0007_MinimumSpanningTreeKruskalAlgorithm.h"
#include<climits>
#include<algorithm>
using namespace std;

namespace MinimumSpanningTreeKruskalAlgorithm
{
	Node::Node(int data)
	{
		this->data = data;
		this->parent = nullptr;
		this->rank = INT_MAX;
	}

	Edge::Edge(Node* nodeU, Node* nodeV, int weight)
	{
		this->nodeU = nodeU;
		this->nodeV = nodeV;
		this->weight = weight;
	}

	// Graph Private Member Methods
	Node* Graph::MakeOrFindNode(int data)
	{
		Node* node = nullptr;
		if (this->_nodeMap.find(data) == this->_nodeMap.end())
		{
			node = new Node(data);
			this->_nodeMap[data] = node;
		}
		else
		{
			node = this->_nodeMap[data];
		}
		return node;
	}

	void Graph::MakeSet(Node* node)
	{
		node->parent = node;
		node->rank = 0;
	}

	void Graph::Union(Node* nodeU, Node* nodeV)
	{
		this->Link(this->FindSet(nodeU), this->FindSet(nodeV));
	}

	void Graph::Link(Node* nodeU, Node* nodeV)
	{
		if (nodeV->rank > nodeU->rank)
		{
			nodeU->parent = nodeV;
		}
		else
		{
			nodeV->parent = nodeU;
			if (nodeU->rank == nodeV->rank)
			{
				nodeU->rank += 1;
			}
		}
	}

	Node* Graph::FindSet(Node* node)
	{
		if (node != node->parent)
		{
			node->parent = this->FindSet(node->parent);
		}
		return node->parent;
	}

	// Graph Public Member Methods
	void Graph::PushUndirectedEdge(int dataU, int dataV, int weight)
	{
		Node* nodeU = this->MakeOrFindNode(dataU);
		Node* nodeV = this->MakeOrFindNode(dataV);

		this->_adjlist[nodeU].push_back(nodeV);
		this->_adjlist[nodeV].push_back(nodeU);
		this->_edgeList.push_back(new Edge(nodeU, nodeV, weight));
	}

	void Graph::FindMinimumSpanningTreeKruskalAlgorithm()
	{
		for (auto& iterator : this->_nodeMap)
		{
			this->MakeSet(iterator.second);
		}
		
		sort(this->_edgeList.begin(), this->_edgeList.end(), [](Edge* edgeX, Edge* edgeY) { return edgeX->weight < edgeY->weight; });

		for (auto& edge : this->_edgeList)
		{
			if (this->FindSet(edge->nodeU) != this->FindSet(edge->nodeV))
			{
				this->Union(edge->nodeU, edge->nodeV);
				this->_minimumSpanningTree.push_back({ {edge->nodeU->data, edge->nodeV->data}, edge->weight });
			}
		}
	}

	vector<pair<pair<int, int>, int>> Graph::GetMinimumSpanningTree()
	{
		return this->_minimumSpanningTree;
	}
}