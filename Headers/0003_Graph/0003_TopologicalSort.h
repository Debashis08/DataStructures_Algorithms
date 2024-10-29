#pragma once

#include<list>
#include<map>
#include<string>
#include<vector>
using namespace std;
enum color { WHITE, GRAY, BLACK };

class TopologicalSortNode
{
public:
    int data;
    int color;
    int discoveryTime;
    int finishingTime;
    TopologicalSortNode* parent;
    TopologicalSortNode(int value);
};

class TopologicalSortGraph
{
private:
    int time;
    bool hasCycle;
    map<TopologicalSortNode*, list<TopologicalSortNode*>> _adjlist;
    map<int, TopologicalSortNode*> _nodeMap;
    list<TopologicalSortNode*> _topologicalSortedNodeList;
    TopologicalSortNode* MakeOrFindNode(int value);
    void DepthFirstSearch(TopologicalSortNode* DFSNode);
public:
    void PushDirectedEdge(int valueU, int valueV);
    void PushSingleNode(int valueU);
    void TopologicalSort();
    vector<pair<int, pair<int, int>>> ShowTopologicalSortResult();
};