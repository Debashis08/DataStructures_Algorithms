#include "../Headers/0003_Graph/0001_BreadthFirstSearch.h"
using namespace std;

Node::Node(char val)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
{
	this->data = val;
	distance = INT_MAX;
	color = WHITE;
	parent = NULL;
}

bool CompareNodes::operator()(Node* temp_u, Node* temp_v)
{
	return (temp_u->data < temp_v->data);
}