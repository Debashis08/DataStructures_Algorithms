#pragma once

#include<map>
#include<list>
using namespace std;
enum color { WHITE, GRAY, BLACK };
class Node
{
public:
    char data;
    int distance;
    int color;
    Node* parent;
    Node(char val);
};

class CompareNodes
{
public:
    bool operator()(Node* temp_u, Node* temp_v);
};

class BFSGraph
{
private:
    map<Node*, list<Node*>, CompareNodes> adjlist;
    list<Node*> node_list;
    Node* find_node_in_list(char val);
    void graph_bfs(Node* node);
public:
    void push_edge(char val_u, char val_v);
    void show_graph_data();
    void bfs(char val);
    void show_bfs_result();
};