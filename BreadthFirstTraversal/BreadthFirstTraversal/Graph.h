// Program to print BFS traversal from a given source vertex. 
// BFS(int s) traverses vertices reachable from s.

#ifndef H_GRAPH
#define H_GRAPH

#include <iostream>
#include <list>

class Graph
{
private:
	int v; // No. of vertices
	std::list<int> *adj; // pointer to an array of lists of adjacent nodes

public:
	/* Constructor */
	Graph(int v);

	/* Add an edge to the graph */
	void addEdge(int v, int w);

	/* Print BFS traversal from a given source s */
	void BFS(int s);
};

#endif // !H_GRAPH

