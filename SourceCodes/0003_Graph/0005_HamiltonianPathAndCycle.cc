#include "../Headers/0003_Graph/0005_HamiltonianPathAndCycle.h"

using namespace std;
namespace HamiltonianPathAndCycle
{
	Node::Node(int value)
	{
		this->data = value;
		this->isVisited = false;
	}

	// Graph Private Member Methods
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

	bool Graph::IsSafe(Node* nodeU, Node* nodeV)
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

	bool Graph::HamiltonianCycleAndPathUtil(Node* nodeU)
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

	// Graph Public Member Methods
	void Graph::PushUndirectedEdge(int valueU, int valueV)
	{
		Node* nodeU = this->MakeOrFindNode(valueU);
		Node* nodeV = this->MakeOrFindNode(valueV);

		this->_adjlist[nodeU].insert(nodeV);
		this->_adjlist[nodeV].insert(nodeU);
	}

	void Graph::PushSingleNode(int valueU)
	{
		Node* nodeU = this->MakeOrFindNode(valueU);
	}

	void Graph::FindHamiltonianCycleAndPath()
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

	bool Graph::IsHamiltonianCyclePresent()
	{
		return this->_isHamiltonianCyclePresent;
	}

	bool Graph::IsHamiltonianPathPresent()
	{
		return this->_isHamiltonianPathPresent;
	}

	vector<int> Graph::GetHamiltonianPath()
	{
		return this->_hamiltonianPath;
	}
}