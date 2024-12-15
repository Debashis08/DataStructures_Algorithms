#include "../Headers/0003_Graph/0007_MinimumSpanningTreeKruskalAlgorithm.h"
#include<climits>
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
	
	bool Edge::CompareEdges(Edge* edgeX, Edge* edgeY)
	{
		return (edgeX->weight < edgeY->weight);
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
	void Graph::PushUndirectedEdge(int dataU, int dataV)
	{
		Node* nodeU = this->MakeOrFindNode(dataU);
		Node* nodeV = this->MakeOrFindNode(dataV);

		this->_adjlist[nodeU].push_back(nodeV);
		this->_adjlist[nodeV].push_back(nodeU);
	}
}