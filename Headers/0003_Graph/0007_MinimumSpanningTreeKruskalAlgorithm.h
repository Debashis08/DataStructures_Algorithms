#pragma once

#include<map>
#include<vector>
#include<list>
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
	};

	class Graph
	{
	private:
		map<Node*, vector<Node*>> _adjlist;
		map<int, Node*> _nodeMap;
		vector<Edge*> _edgeList;
		vector<pair<pair<int, int>, int>> _minimumSpanningTree;
		Node* MakeOrFindNode(int data);
		void MakeSet(Node* node);
		void Union(Node* nodeU, Node* nodeV);
		void Link(Node* nodeU, Node* nodeV);
		Node* FindSet(Node* node);

	public:
		void PushUndirectedEdge(int valueU, int valueV, int weight);
		void FindMinimumSpanningTreeKruskalAlgorithm();
		vector<pair<pair<int, int>, int>> GetMinimumSpanningTree();
	};
}