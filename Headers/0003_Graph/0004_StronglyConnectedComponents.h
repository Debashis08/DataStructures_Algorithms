#pragma once

#include<list>
#include<map>
#include<string>
#include<vector>
using namespace std;

namespace StronglyConnectedComponents
{
    enum color { WHITE, GRAY, BLACK };

    class Node
    {
    public:
        int data;
        int color;
        int discoveryTime;
        int finishingTime;
        Node* parent;
        Node(int value);
    };

    class Graph
    {
    private:
        int time;
        map<Node*, list<Node*>> _adjlistG;
        map<Node*, list<Node*>> _adjlistT;
        map<int, Node*> _nodeMap;
        list<Node*> _nodesFinishingTimeOrder;
        vector<vector<int>> _allConnectedComponents;
        Node* MakeOrFindNode(int value);
        void DepthFirstSearchOnGraphG(Node* DFSNode);
        void DepthFirstSearchOnGraphT(Node* DFSNode, vector<int>& connectedComponents);
    public:
        void PushDirectedEdge(int valueU, int valueV);
        void PushSingleNode(int valueU);
        void DFSOnGraphG();
        void DFSOnGraphT();
        vector<vector<int>> FindAllStronglyConnectedComponents();
    };
}