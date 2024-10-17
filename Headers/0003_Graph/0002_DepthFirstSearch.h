#pragma once

#include<list>
#include<map>
#include<string>
#include<vector>
using namespace std;
enum color { WHITE, GRAY, BLACK };

class DFSNode
{
public:
    int data;
    int color;
    int discoveredTime;
    int finishingTime;
    DFSNode* parent;
    DFSNode(int value);
};

class DFSGraph
{
private:
    int time;
    map<DFSNode*, list<DFSNode*>> _adjlist;
    map<int, DFSNode*> _nodeMap;
    DFSNode* MakeOrFindNode(int value);
    void DepthFirstSearch(DFSNode* DFSNode);
public:
    void PushDirectedEdge(int valueU, int valueV);
    void DFS();
    vector<pair<int,pair<int,int>>> ShowDFSResult();
};