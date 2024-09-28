#pragma once

#include<list>
#include<map>
#include<string>
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

class DFSGraph
{
private:
    map<Node*, list<Node*>> _adjlist;
    map<char, Node*> _nodeMap;
    Node* MakeOrFindNode(char value);
    void DepthFirstSearch(Node* node);
public:
    void PushUndirectedEdge(char valueU, char valueV);
    void DFS(char value);
    string ShowDFSResult();
};