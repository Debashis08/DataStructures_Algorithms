#include "../Headers/0003_Graph/0005_HamiltonianPathAndCycle.h"

using namespace std;

HamiltonianNode::HamiltonianNode(int value)
{
	this->data = value;
	this->isVisited = false;
}

// HamiltonianGraph Private Member Methods
HamiltonianNode* HamiltonianGraph::MakeOrFindNode(int value)
{
	HamiltonianNode* node = nullptr;
	if (this->_nodeMap.find(value) == this->_nodeMap.end())
	{
		node = new HamiltonianNode(value);
		this->_nodeMap[value] = node;
	}
	else
	{
		node = this->_nodeMap[value];
	}
	return node;
}

bool HamiltonianGraph::IsSafe(HamiltonianNode* nodeU, HamiltonianNode* nodeV)
{
	if (this->_adjlist[nodeU].find(nodeV) == this->_adjlist[nodeU].end())
	{
		return false;
	}
	if (nodeV->isVisited == true)
	{
		return false;
	}
	return true;
}

bool HamiltonianGraph::HamiltonianCycleAndPathUtil(HamiltonianNode* nodeU)
{
	if (this->visitedNodeCount == this->_nodeMap.size()-1)
	{
		if (this->_adjlist[nodeU].find(this->_hamiltonianPath[0]) != this->_adjlist[nodeU].end())
		{
			this->isHamiltonianCyclePresent = true;
			return true;
		}
		this->isHamiltonianPathPresent = true;
		return false;
	}
	for (auto& iterator : this->_nodeMap)
	{
		if (this->IsSafe(nodeU, iterator.second))
		{
			this->_hamiltonianPath.push_back(iterator.second);
			iterator.second->isVisited = true;
			this->visitedNodeCount++;
			if (this->HamiltonianCycleAndPathUtil(iterator.second))
			{
				return true;
			}
			this->visitedNodeCount--;
			iterator.second->isVisited = false;
			this->_hamiltonianPath.pop_back();
		}
	}
	return false;
}

// HamiltonianGraph Public Member Methods
void HamiltonianGraph::PushUndirectedEdge(int valueU, int valueV)
{
	HamiltonianNode* nodeU = this->MakeOrFindNode(valueU);
	HamiltonianNode* nodeV = this->MakeOrFindNode(valueV);

	this->_adjlist[nodeU].insert(nodeV);
	this->_adjlist[nodeV].insert(nodeU);
}

void HamiltonianGraph::PushSingleNode(int valueU)
{
	HamiltonianNode* nodeU = this->MakeOrFindNode(valueU);
}

void HamiltonianGraph::FindHamiltonianCycleAndPath()
{
	this->isHamiltonianCyclePresent = false;
	this->isHamiltonianPathPresent = false;
	this->_hamiltonianPath = {};
	HamiltonianNode* node = this->_nodeMap[0];
	this->_hamiltonianPath.push_back(node);
	node->isVisited = true;
	this->visitedNodeCount = 1;
	this->HamiltonianCycleAndPathUtil(node);
}

bool HamiltonianGraph::IsHamiltonianCyclePresent()
{
	return this->isHamiltonianCyclePresent;
}

bool HamiltonianGraph::IsHamiltonianPathPresent()
{
	return this->isHamiltonianPathPresent;
}

vector<HamiltonianNode*> HamiltonianGraph::GetHamiltonianCycle()
{
	if (this->isHamiltonianCyclePresent)
	{
		this->_hamiltonianPath.push_back(this->_nodeMap[0]);
	}
	return this->_hamiltonianPath;
}

vector<HamiltonianNode*> HamiltonianGraph::GetHamiltonianPath()
{
	return this->_hamiltonianPath;
}