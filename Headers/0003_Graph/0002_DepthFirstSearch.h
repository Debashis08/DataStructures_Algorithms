#pragma once

#include<list>
#include<map>
#include<string>
#include<vector>
using namespace std;

namespace DepthFirstSearch
{
    enum color { WHITE, GRAY, BLACK };

    class Node
    {
    public:
        int data;
        int color;
        int discoveredTime;
        int finishingTime;
        Node* parent;
        Node(int value);
    };

    class Graph
    {
    private:
        int time;
        map<Node*, list<Node*>> _adjlist;
        map<int, Node*> _nodeMap;
        Node* MakeOrFindNode(int value);
        void DepthFirstSearch(Node* Node);
    public:
        void PushDirectedEdge(int valueU, int valueV);
        void DFS();
        vector<pair<int, pair<int, int>>> ShowDFSResult();
    };
}