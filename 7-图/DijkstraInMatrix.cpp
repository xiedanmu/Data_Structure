#include <stdio.h>
#include <stdlib.h>

#define V 9

int minDistance(int dist[], bool sptSet[])
{
	int min = INT_MAX, vertics;
	for (int i = 0; i < V; i++)
	{
		if (sptSet[i] == false && dist[i] < min)
			//if vertice i has already benn detacted and the distance is shortest,select it
			min = dist[i], vertics = i;
	}
	return vertics;
}

void printTheShortestPath(int dist[],int src)
{
	printf("The src is \tto vertices is\t the distence is\n");
	for (int i = 0; i < V; i++)
	{
		printf("\t%d\t\t%d\t\t%d\n",src,i, dist[i]);
	}
}

void dijkstra(int graph[V][V], int src)
{
	int dist[V];
	bool sptSet[V];

	for (int i = 0; i < V; i++)
	{
		dist[i] = INT_MAX, sptSet[i] = false;
	}

	dist[src] = 0;

	for (int count = 0; count < V - 1; count++)
	{
		int u = minDistance(dist, sptSet);

		sptSet[u] = true;//The vertics is about to being detacted,change the tag

		for (int v = 0; v < V; v++)
		{
			if (sptSet[v] == false && graph[u][v] && dist[u] < INT_MAX 
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
		}
	}
	
	
	printTheShortestPath(dist,src);
}
/*
int main()
{
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
						{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

	dijkstra(graph, 0);

	system("pause");
	return 0;
}
*/