#include<iostream>
#include <list>

using namespace std;

class Graph 
{	//V represents how many nodes
	int V;

	list<int>* adj;

	void DFSUtil(int s,bool visited[]);
public:
	Graph(int v); //Constructor
	void addEdge(int v, int w); //add a edge from v to w
	void DFS(int s);//depth fist search,s represents where to start
};

Graph::Graph(int v)
{
	this->V = v;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::DFSUtil(int s,bool visited[])
{
	visited[s] = true;
	list<int>::iterator i;
	cout << s;

	for (i = adj[s].begin(); i != adj[s].end(); i++)
	{
		if (visited[*i] == false)
		{
			DFSUtil(*i, visited);
		}	
	}
}

void Graph::DFS(int s)
{
	bool* visited=new bool[V];
	for (int i = 0; i < V; i++)
	{
		visited[i] = false;
	}

	DFSUtil(s,visited);
}

/*
int main()
{
	Graph g(5);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 4);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	//g.addEdge(3, 3);

	cout << "Following is Depth  First Traversal "
		<< "(starting from vertex 2) \n";
	g.DFS(0);

	return 0;
}
*/
