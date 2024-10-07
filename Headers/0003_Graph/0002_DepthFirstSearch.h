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
    char data;
    int color;
    int discoveredTime;
    int finishingTime;
    DFSNode* parent;
    DFSNode(char value);
};

class DFSGraph
{
private:
    int time;
    map<DFSNode*, list<DFSNode*>> _adjlist;
    map<char, DFSNode*> _nodeMap;
    DFSNode* MakeOrFindNode(char value);
    void DepthFirstSearch(DFSNode* DFSNode);
public:
    void PushDirectedEdge(char valueU, char valueV);
    void DFS();
    vector<pair<char,pair<int,int>>> ShowDFSResult();
};