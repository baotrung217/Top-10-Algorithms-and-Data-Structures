#include "Graph.h"

Graph::Graph(int v)
{
	this->v = v;
	adj = new std::list<int>[v];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::BFS(int s)
{
	bool *visited = new bool[v];
	for (int j = 0; j < v; j++)
	{
		visited[j] = false;
	}

	std::list<int> queue;
	queue.push_back(s);
	visited[2] = true;

	while (!queue.empty())
	{
		int n = queue.front();
		std::cout << n << " ";
		queue.pop_front();

		std::list<int>::iterator i;
		for (i = adj[n].begin(); i != adj[n].end(); i++)
		{
			if (!visited[*i])
			{
				queue.push_back(*i);
				visited[*i] = true;
			}
		}
	}
}
