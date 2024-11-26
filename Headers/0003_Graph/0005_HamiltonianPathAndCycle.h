#pragma once

#include<map>
#include<unordered_set>
#include<vector>
using namespace std;

class HamiltonianNode
{
public:
	int data;
	bool isVisited;
	HamiltonianNode(int value);
};

class HamiltonianGraph
{
private:
	bool isHamiltonianCyclePresent;
	bool isHamiltonianPathPresent;
	int visitedNodeCount;
	map<HamiltonianNode*, unordered_set<HamiltonianNode*>> _adjlist;
	map<int, HamiltonianNode*> _nodeMap;
	vector<HamiltonianNode*> _hamiltonianPath;
	HamiltonianNode* MakeOrFindNode(int value);
	bool IsSafe(HamiltonianNode* nodeU, HamiltonianNode* nodeV);
	bool HamiltonianCycleAndPathUtil(HamiltonianNode* node);

public:
	void PushUndirectedEdge(int valueU, int valueV);
	void PushSingleNode(int valueU);
	void FindHamiltonianCycleAndPath();
	bool IsHamiltonianCyclePresent();
	bool IsHamiltonianPathPresent();
	vector<HamiltonianNode*> GetHamiltonianCycle();
	vector<HamiltonianNode*> GetHamiltonianPath();
};