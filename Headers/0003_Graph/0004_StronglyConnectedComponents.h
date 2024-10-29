#pragma once

#include<list>
#include<map>
#include<string>
#include<vector>
using namespace std;
enum color { WHITE, GRAY, BLACK };

class SCCNode
{
public:
    int data;
    int color;
    int discoveryTime;
    int finishingTime;
    SCCNode* parent;
    SCCNode(int value);
};

class StronglyConnectedComponentsGraph
{
private:
    int time;
    map<SCCNode*, list<SCCNode*>> _adjlistG;
    map<SCCNode*, list<SCCNode*>> _adjlistT;
    map<int, SCCNode*> _nodeMap;
    list<SCCNode*> _nodesFinishingTimeOrder;
    vector<vector<int>> _allConnectedComponents;
    SCCNode* MakeOrFindNode(int value);
    void DepthFirstSearchOnGraphG(SCCNode* DFSNode);
    void DepthFirstSearchOnGraphT(SCCNode* DFSNode, vector<int>& connectedComponents);
public:
    void PushDirectedEdge(int valueU, int valueV);
    void PushSingleNode(int valueU);
    void DFSOnGraphG();
    void DFSOnGraphT();
    vector<vector<int>> FindAllStronglyConnectedComponents();
};