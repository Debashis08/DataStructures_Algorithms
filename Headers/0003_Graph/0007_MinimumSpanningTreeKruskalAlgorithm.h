#pragma once

#include<map>
#include<vector>
using namespace std;

namespace MinimumSpanningTreeKruskalAlgorithm
{
	class Node
	{
	public:
		int data;
		Node* parent;
		int rank;
		Node(int data);
	};

	class Edge
	{
	public:
		Node* nodeU;
		Node* nodeV;
		int weight;
		Edge(Node* nodeU, Node* nodeV, int weight);
		bool CompareEdges(Edge* edgeX, Edge* edgeY);
	};

	class Graph
	{
	private:
		map<Node*, vector<Node*>> _adjlist;
		map<int, Node*> _nodeMap;
		Node* MakeOrFindNode(int data);
		void MakeSet(Node* node);
		void Union(Node* nodeU, Node* nodeV);
		void Link(Node* nodeU, Node* nodeV);
		Node* FindSet(Node* node);

	public:
		void PushUndirectedEdge(int valueU, int valueV);
		void FindMinimumSpanningTreeKruskalAlgorithm();
	};
}