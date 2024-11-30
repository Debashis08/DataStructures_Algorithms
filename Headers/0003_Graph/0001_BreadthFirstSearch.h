#pragma once

#include<list>
#include<map>
#include<utility>
#include<string>
#include<vector>
using namespace std;

namespace BreadthFirstSearch
{
    enum color { WHITE, GRAY, BLACK };
    class Node
    {
    public:
        int data;
        int distance;
        int color;
        Node* parent;
        Node(int value);
    };

    class Graph
    {
    private:
        map<Node*, list<Node*>> _adjlist;
        map<int, Node*> _nodeMap;
        Node* MakeOrFindNode(int value);
        void BreadthFirstSearch(Node* node);
    public:
        void PushUndirectedEdge(int valueU, int valueV);
        void BFS(int value);
        vector<pair<int, int>> ShowBFSResult();
    };
}