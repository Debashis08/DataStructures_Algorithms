#pragma once

#include<list>
#include<map>
#include<utility>
#include<string>
#include<vector>
using namespace std;
enum color { WHITE, GRAY, BLACK };

class BFSNode
{
public:
    int data;
    int distance;
    int color;
    BFSNode* parent;
    BFSNode(int value);
};

class BFSGraph
{
private:
    map<BFSNode*, list<BFSNode*>> _adjlist;
    map<int, BFSNode*> _nodeMap;
    BFSNode* MakeOrFindNode(int value);
    void BreadthFirstSearch(BFSNode* node);
public:
    void PushUndirectedEdge(int valueU, int valueV);
    void BFS(int value);
    vector<pair<int, int>> ShowBFSResult();
};