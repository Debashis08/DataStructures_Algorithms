#include "../Headers/0003_Graph/0006_EulerianPathAndCircuit.h"
#include<stack>
#include<algorithm>
using namespace std;

namespace EulerianPathAndCircuit
{
	Node::Node(int value)
	{
		this->data = value;
		this->degree = 0;
		this->inDegree = 0;
		this->outDegree = 0;
		this->visited = false;
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

	void Graph::DepthFirstSearch(Node* nodeU)
	{
		nodeU->visited = true;
		this->_eulerianPath.push_back(nodeU->data);
		for (auto& nodeV : this->_adjlist[nodeU])
		{
			if (nodeV->visited == false)
			{
				this->DepthFirstSearch(nodeV);
			}
		}
	}

	bool Graph::IsConnected()
	{
		// Step-1 : Make the visited property of all nodes as false. It is already done in constructor.

		// Step-2 : Find a node which do not have 0 degree.
		Node* node = nullptr;
		for (auto& iterator : this->_nodeMap)
		{
			if (iterator.second->degree != 0)
			{
				node = iterator.second;
				break;
			}
		}

		// Step-3 : If node is null, it means G.E is null, so G is connected, else call DFS to traverse the graph G.
		if (node == nullptr)
		{
			return true;
		}

		this->DepthFirstSearch(node);

		// Step-4 : Checking if all the non-zero degree vertices have been visited or not.
		for (auto& iterator : this->_nodeMap)
		{
			if (iterator.second->visited == false && iterator.second->degree != 0)
			{
				return false;
			}
		}
		return true;
	}

	void Graph::EulerianPathHierholzerAlgorithm(Node* startingNode)
	{
		stack<Node*> currentPath;
		currentPath.push(startingNode);
		while (!currentPath.empty())
		{
			Node* currentNode = currentPath.top();
			if (!this->_adjlist[currentNode].empty())
			{
				Node* nextNode = this->_adjlist[currentNode].front();
				this->_adjlist[currentNode].pop_front();
				this->_adjlist[nextNode].remove(currentNode);
				currentPath.push(nextNode);
			}
			else
			{
				currentPath.pop();
				this->_eulerianPath.push_back(currentNode->data);
			}
		}
	}

	// Graph Public Member Methods
	void Graph::PushUndirectedEdge(int valueU, int valueV)
	{
		Node* nodeU = this->MakeOrFindNode(valueU);
		Node* nodeV = this->MakeOrFindNode(valueV);

		this->_adjlist[nodeU].push_back(nodeV);
		nodeU->degree++;
		this->_adjlist[nodeV].push_back(nodeU);
		nodeV->degree++;
	}

	void Graph::PushDirectedEdge(int valueU, int valueV)
	{
		Node* nodeU = this->MakeOrFindNode(valueU);
		Node* nodeV = this->MakeOrFindNode(valueV);

		this->_adjlist[nodeU].push_back(nodeV);
		nodeU->outDegree++;
		nodeV->inDegree++;
	}

	void Graph::PushSingleNode(int valueU)
	{
		Node* nodeU = this->MakeOrFindNode(valueU);
	}

	void Graph::FindEulerianPathAndCircuit()
	{
		// If the graph is not connected then graph G is Not-Eulerian.
		if (this->IsConnected() == false)
		{
			this->_isEulerianPathPresent = false;
			this->_isEulerianCircuitPresent = false;
			return;
		}

		int oddDegreeVertexCount = 0;
		for (auto& iterator : this->_nodeMap)
		{
			if (iterator.second->degree & 1)
			{
				oddDegreeVertexCount++;
			}
		}

		// Check-1 :  When no vertex with odd degree is present, then graph G is Eulerian.
		if (oddDegreeVertexCount == 0)
		{
			this->_isEulerianPathPresent = true;
			this->_isEulerianCircuitPresent = true;
			return;
		}

		// Check-2 : When 2 vertices have odd degree, then graph G is Semi-Eulerian.
		if (oddDegreeVertexCount == 2)
		{
			this->_isEulerianPathPresent = true;
			this->_isEulerianCircuitPresent = false;
			return;
		}

		// Check-3 : When more than 2 vertices have odd degree, then graph G is Not Eulerian.
		if (oddDegreeVertexCount > 2)
		{
			this->_isEulerianPathPresent = false;
			this->_isEulerianCircuitPresent = false;
			return;
		}
	}

	bool Graph::IsEulerianPathPresent()
	{
		return this->_isEulerianPathPresent;
	}

	bool Graph::IsEulerianCircuitPresent()
	{
		return this->_isEulerianCircuitPresent;
	}

	vector<int> Graph::UndirectedGraphGetEulerianPath()
	{
		// Case-3 : When more than 2 vertices have odd degree, then the graph G is not Eulerian.
		// No Eulerian Path is posible.
		if (this->_isEulerianPathPresent == false)
		{
			return {};
		}

		// Now 2 cases remains.
		// Case-2 : When 2 vertices have odd degree. Choose any one of them.
		Node* node = nullptr;
		for (auto& iterator : this->_nodeMap)
		{
			if (iterator.second->degree & 1)
			{
				node = iterator.second;
				break;
			}
		}

		// Case-1 : When no vertex with odd degree is present. Choose any vertex as starting point.
		if (node == nullptr)
		{
			node = this->_nodeMap[0];
		}
		this->EulerianPathHierholzerAlgorithm(node);
		reverse(this->_eulerianPath.begin(), this->_eulerianPath.end());
		return this->_eulerianPath;
	}
}