#include "../Headers/0003_Graph/0003_TopologicalSort.h"
#include<vector>
#include<utility>
#include<climits>
#include<stdexcept>
using namespace std;

TopologicalSortNode::TopologicalSortNode(int value)
{
	this->data = value;
	this->discoveryTime = INT_MAX;
	this->finishingTime = INT_MAX;
	this->color = WHITE;
	this->parent = nullptr;
}

TopologicalSortNode* TopologicalSortGraph::MakeOrFindNode(int value)
{
	TopologicalSortNode* node = nullptr;
	if (this->_nodeMap.find(value) == this->_nodeMap.end())
	{
		node = new TopologicalSortNode(value);
		this->_nodeMap[value] = node;
	}
	else
	{
		node = this->_nodeMap[value];
	}
	return node;
}

void TopologicalSortGraph::DepthFirstSearch(TopologicalSortNode* nodeU)
{
	this->time++;
	nodeU->discoveryTime = this->time;
	nodeU->color = GRAY;
	for (auto nodeV : this->_adjlist[nodeU])
	{
		if (nodeV->color == WHITE)
		{
			nodeV->parent = nodeU;
			this->DepthFirstSearch(nodeV);
		}
		else if (nodeV->color == GRAY)
		{
			this->hasCycle = true;
			return;
		}
	}
	nodeU->color = BLACK;
	this->time++;
	nodeU->finishingTime = time;
	this->_topologicalSortedNodeList.push_front(nodeU);
}

void TopologicalSortGraph::PushDirectedEdge(int valueU, int valueV)
{
	TopologicalSortNode* nodeU = this->MakeOrFindNode(valueU);
	TopologicalSortNode* nodeV = this->MakeOrFindNode(valueV);

	this->_adjlist[nodeU].push_back(nodeV);
}

void TopologicalSortGraph::PushSingleNode(int valueU)
{
	TopologicalSortNode* nodeU = this->MakeOrFindNode(valueU);
}

void TopologicalSortGraph::TopologicalSort()
{
	this->time = 0;
	for (auto& iterator : this->_nodeMap)
	{
		if (iterator.second->color == WHITE)
		{
			this->DepthFirstSearch(iterator.second);
			if (this->hasCycle == true)
			{
				break;
			}
		}
	}
}

vector<pair<int, pair<int, int>>> TopologicalSortGraph::ShowTopologicalSortResult()
{
	if (this->hasCycle == true)
	{
		throw runtime_error("Cycle Detected");
	}
	vector<pair<int, pair<int, int>>> result;
	for (auto& node : this->_topologicalSortedNodeList)
	{
		result.push_back(make_pair(node->data, make_pair(node->discoveryTime, node->finishingTime)));
	}
	return result;
}