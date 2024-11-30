#pragma once

#include<map>
#include<unordered_set>
#include<vector>
using namespace std;

namespace HamiltonianPathAndCycle
{
	class Node
	{
	public:
		int data;
		bool isVisited;
		Node(int value);
	};

	class Graph
	{
	private:
		bool _isHamiltonianCyclePresent;
		bool _isHamiltonianPathPresent;
		int _visitedNodeCount;
		Node* _startingNode;
		map<Node*, unordered_set<Node*>> _adjlist;
		map<int, Node*> _nodeMap;
		vector<int> _hamiltonianPath;
		Node* MakeOrFindNode(int value);
		bool IsSafe(Node* nodeU, Node* nodeV);
		bool HamiltonianCycleAndPathUtil(Node* node);

	public:
		void PushUndirectedEdge(int valueU, int valueV);
		void PushSingleNode(int valueU);
		void FindHamiltonianCycleAndPath();
		bool IsHamiltonianCyclePresent();
		bool IsHamiltonianPathPresent();
		vector<int> GetHamiltonianPath();
	};
}