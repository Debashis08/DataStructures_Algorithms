#pragma once

#include<map>
#include<list>
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
	map<HamiltonianNode*, list<HamiltonianNode*>> _adjlist;
	map<int, HamiltonianNode*> _nodeMap;
	HamiltonianNode* MakeOrFindNode(int value);

public:
	void PushUndirectedEdge(int valueU, int valueV);
	void PushSingleNode(int valueU);
};