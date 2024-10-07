#include "../Headers/0003_Graph/0002_DepthFirstSearch.h"
#include<vector>
#include<utility>
#include<climits>
using namespace std;

DFSNode::DFSNode(char value)
{
	this->data = value;
	this->discoveredTime = INT_MAX;
	this->finishingTime = INT_MAX;
	this->color = WHITE;
	this->parent = nullptr;
}

DFSNode* DFSGraph::MakeOrFindNode(char value)
{
	DFSNode* node = nullptr;
	if (this->_nodeMap.find(value) == this->_nodeMap.end())
	{
		node = new DFSNode(value);
		this->_nodeMap[value] = node;
	}
	else
	{
		node = this->_nodeMap[value];
	}
	return node;
}
void DFSGraph::DepthFirstSearch(DFSNode* nodeU)
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

void DFSGraph::PushDirectedEdge(char valueU, char valueV)
{
	DFSNode* nodeU = this->MakeOrFindNode(valueU);
	DFSNode* nodeV = this->MakeOrFindNode(valueV);

	this->_adjlist[nodeU].push_back(nodeV);
}

void DFSGraph::DFS()
{
	this->time = 0;
	for (auto& iterator:this->_nodeMap)
	{
		if (iterator.second->color == WHITE)
		{
			this->DepthFirstSearch(iterator.second);
		}
	}
}

vector<pair<char, pair<int, int>>> DFSGraph::ShowDFSResult()
{
	vector<pair<char, pair<int, int>>> result;
	for (auto& node : this->_nodeMap)
	{
		result.push_back(make_pair(node.first, make_pair(node.second->discoveredTime, node.second->finishingTime)));
	}
	return result;
}