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
	if (this->_visitedNodeCount == this->_nodeMap.size())
	{
		if (this->_adjlist[nodeU].find(this->_startingNode) != this->_adjlist[nodeU].end())
		{
			this->_isHamiltonianCyclePresent = true;
			this->_isHamiltonianPathPresent = true;
			return true;
		}
		this->_isHamiltonianPathPresent = true;
		return false;
	}
	for (auto& nodeV : this->_adjlist[nodeU])
	{
		if (this->IsSafe(nodeU, nodeV))
		{
			this->_hamiltonianPath.push_back(nodeV->data);
			nodeV->isVisited = true;
			this->_visitedNodeCount++;
			if (this->HamiltonianCycleAndPathUtil(nodeV))
			{
				return true;
			}
			this->_visitedNodeCount--;
			nodeV->isVisited = false;
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
	this->_isHamiltonianCyclePresent = false;
	this->_isHamiltonianPathPresent = false;
	this->_hamiltonianPath = {};
	this->_startingNode = this->_nodeMap[0];
	this->_hamiltonianPath.push_back(this->_startingNode->data);
	this->_startingNode->isVisited = true;
	this->_visitedNodeCount = 1;
	this->HamiltonianCycleAndPathUtil(this->_startingNode);
}

bool HamiltonianGraph::IsHamiltonianCyclePresent()
{
	return this->_isHamiltonianCyclePresent;
}

bool HamiltonianGraph::IsHamiltonianPathPresent()
{
	return this->_isHamiltonianPathPresent;
}

vector<int> HamiltonianGraph::GetHamiltonianPath()
{
	return this->_hamiltonianPath;
}