#pragma once

#include<list>
#include<map>
#include<utility>
#include<string>
#include<vector>
using namespace std;
enum color { WHITE, GRAY, BLACK };

class Node
{
public:
    char data;
    int distance;
    int color;
    Node* parent;
    Node(char value);
};

class Graph
{
private:
    map<Node*, list<Node*>> _adjlist;
    map<char, Node*> _nodeMap;
    Node* MakeOrFindNode(char value);
    void BreadthFirstSearch(Node* node);
public:
    void PushUndirectedEdge(char valueU, char valueV);
    void BFS(char value);
    vector<pair<char, int>> ShowBFSResult();
};