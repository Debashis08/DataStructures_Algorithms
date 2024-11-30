#include "../Headers/0003_Graph/0003_TopologicalSort.h"
#include<vector>
#include<utility>
#include<climits>
#include<stdexcept>
using namespace std;

namespace TopologicalSort
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

	void Graph::DepthFirstSearch(Node* nodeU)
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

	void Graph::PushDirectedEdge(int valueU, int valueV)
	{
		Node* nodeU = this->MakeOrFindNode(valueU);
		Node* nodeV = this->MakeOrFindNode(valueV);

		this->_adjlist[nodeU].push_back(nodeV);
	}

	void Graph::PushSingleNode(int valueU)
	{
		Node* nodeU = this->MakeOrFindNode(valueU);
	}

	void Graph::TopologicalSort()
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

	vector<pair<int, pair<int, int>>> Graph::ShowTopologicalSortResult()
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
}