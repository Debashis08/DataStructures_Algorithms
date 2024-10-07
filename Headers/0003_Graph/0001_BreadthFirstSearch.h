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
    char data;
    int distance;
    int color;
    BFSNode* parent;
    BFSNode(char value);
};

class BFSGraph
{
private:
    map<BFSNode*, list<BFSNode*>> _adjlist;
    map<char, BFSNode*> _nodeMap;
    BFSNode* MakeOrFindNode(char value);
    void BreadthFirstSearch(BFSNode* node);
public:
    void PushUndirectedEdge(char valueU, char valueV);
    void BFS(char value);
    vector<pair<char, int>> ShowBFSResult();
};