#include "../Headers/0003_Graph/0004_StronglyConnectedComponents.h"
#include<vector>
#include<utility>
#include<climits>
using namespace std;

SCCNode::SCCNode(int value)
{
	this->data = value;
	this->discoveryTime = INT_MAX;
	this->finishingTime = INT_MAX;
	this->color = WHITE;
	this->parent = nullptr;
}

SCCNode* StronglyConnectedComponentsGraph::MakeOrFindNode(int value)
{
	SCCNode* node = nullptr;
	if (this->_nodeMap.find(value) == this->_nodeMap.end())
	{
		node = new SCCNode(value);
		this->_nodeMap[value] = node;
	}
	else
	{
		node = this->_nodeMap[value];
	}
	return node;
}

void StronglyConnectedComponentsGraph::DepthFirstSearchOnGraphG(SCCNode* nodeU)
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

void StronglyConnectedComponentsGraph::DepthFirstSearchOnGraphT(SCCNode* nodeU, vector<int>& connectedComponents)
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

void StronglyConnectedComponentsGraph::PushDirectedEdge(int valueU, int valueV)
{
	SCCNode* nodeU = this->MakeOrFindNode(valueU);
	SCCNode* nodeV = this->MakeOrFindNode(valueV);

	// Creating the actual graph.
	this->_adjlistG[nodeU].push_back(nodeV);

	// Creating the transpose of the actual graph.
	this->_adjlistT[nodeV].push_back(nodeU);
}

void StronglyConnectedComponentsGraph::PushSingleNode(int valueU)
{
	SCCNode* nodeU = this->MakeOrFindNode(valueU);
}

void StronglyConnectedComponentsGraph::DFSOnGraphG()
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

void StronglyConnectedComponentsGraph::DFSOnGraphT()
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

vector<vector<int>> StronglyConnectedComponentsGraph::FindAllStronglyConnectedComponents()
{
	this->DFSOnGraphG();
	this->DFSOnGraphT();
	return this->_allConnectedComponents;
}