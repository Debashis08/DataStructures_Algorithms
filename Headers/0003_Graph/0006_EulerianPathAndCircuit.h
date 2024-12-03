#pragma once

#include<map>
#include<vector>
#include<unordered_set>
using namespace std;

namespace EulerianPathAndCircuit
{
	class Node
	{
	public:
		int data;
		int degree;
		bool visited;
		Node(int value);
	};

	class Graph
	{
	private:
		bool _isEulerianPathPresent;
		bool _isEulerianCircuitPresent;
		map<Node*, unordered_set<Node*>> _adjlist;
		map<int, Node*> _nodeMap;
		vector<int> _eulerianPath;
		Node* MakeOrFindNode(int value);
		void DepthFirstSearch(Node* node);
		bool IsConnected();

	public:
		void PushUndirectedEdge(int valueU, int valueV);
		void PushSingleNode(int valueU);
		void FindEulerianPathAndCircuit();
		bool IsEulerianPathPresent();
		bool IsEulerianCircuitPresent();
		vector<int> GetEulerianPath();
	};
}