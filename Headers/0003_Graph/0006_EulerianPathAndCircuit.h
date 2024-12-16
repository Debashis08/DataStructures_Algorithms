#pragma once

#include<map>
#include<vector>
#include<list>
using namespace std;

namespace EulerianPathAndCircuit
{
	class Node
	{
	public:
		int data;
		int degree;
		int inDegree;
		int outDegree;
		bool visited;
		Node(int value);
	};

	class Graph
	{
	private:
		bool _isEulerianPathPresent;
		bool _isEulerianCircuitPresent;
		map<Node*, list<Node*>> _adjlist;
		map<int, Node*> _nodeMap;
		vector<int> _eulerianPath;
		Node* MakeOrFindNode(int value);
		void DepthFirstSearch(Node* node);
		bool IsConnected();
		void EulerianPathHierholzerAlgorithm(Node* startingNode);

	public:
		void PushUndirectedEdge(int valueU, int valueV);
		void PushDirectedEdge(int valueU, int valueV);
		void PushSingleNode(int valueU);
		void FindEulerianPathAndCircuit();
		bool IsEulerianPathPresent();
		bool IsEulerianCircuitPresent();
		vector<int> UndirectedGraphGetEulerianPath();
	};
}