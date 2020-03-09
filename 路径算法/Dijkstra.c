//Completed by self
#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h>

#define bool int;
#define true 1;
#define false 0;


typedef struct AdjListNode
{
	int vertex;
	int weight;
	struct AdjListNode* next;
}*AdjListNodePtr;

struct AdjList
{
	struct AdjListNode* head;
};

struct Graph
{
	int size;
	struct AdjList* array;
};

typedef struct MinHeapNode
{
	int vertex;
	int weight;
}*MinHeapNodePtr;

typedef struct MinHeap
{
	int volume;
	int size; //number of nodes present currently
	int* pos;
	struct MinHeapNode** array;
}*MinHeapPtr;

struct AdjListNode* newAdjListNode(int vertex, int weight);
struct Graph* newGraph(int capacity);
void addEdge(struct Graph* graph, int src, int dest, int weight);
struct MinHeap* newMinHeap(int capacity);
struct MinHeapNode* newMinHeapNode(int vertex, int weight);
void decreaseKey(MinHeapPtr minHeapInstance, int location, MinHeapNodePtr minHeapNodeInstance);
void dijkstra(struct Graph* graph,int src);
struct MinHeapNode* extractMin(struct MinHeap* Heap);
int parent(int i) { return (i - 1) / 2; }
int left(int i) { return (i * 2 + 1); }
int right(int i) { return (i * 2 + 2); }
int qiumi(int cishu, int n, int dest);
void swap(MinHeapNodePtr x, MinHeapNodePtr y);
void printGraph(struct Graph* graph);


struct AdjListNode* newAdjListNode(int vertex, int weight)
{
	struct AdjListNode* adjListNodeInstance = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
	adjListNodeInstance->vertex = vertex;
	adjListNodeInstance->weight = weight;
	adjListNodeInstance->next = NULL;
	return adjListNodeInstance;
}

struct Graph* newGraph(int capacity)
{
	struct Graph* graphInstance = (struct Graph*)malloc(sizeof(struct Graph));
	graphInstance->array = (struct AdjList*)malloc(capacity * sizeof(struct AdjList));
	graphInstance->size = capacity;
	for (int i = 0; i < capacity;i++)
	{
		graphInstance->array[i].head = NULL;
	}
	return graphInstance;
}

void addEdge(struct Graph* graph, int src, int dest, int weight)
{
	AdjListNodePtr srcVertex = newAdjListNode(src, weight);
	AdjListNodePtr destVertex = newAdjListNode(dest, weight);

	destVertex->next = graph->array[src].head;
	graph->array[src].head = destVertex;
	
	srcVertex->next = graph->array[dest].head;
	graph->array[dest].head = srcVertex;

	//free(destVertex);
	//free(srcVertex);
}

struct MinHeap* newMinHeap(int capacity)
{
	struct MinHeap* minHeapInstance = (struct MinHeap*)malloc(sizeof(struct MinHeap));
	minHeapInstance->array = (struct MinHeapNode**)malloc(capacity * sizeof(struct MinHeapNode));
	minHeapInstance->pos = (int*)malloc(capacity * sizeof(int));
	minHeapInstance->size = capacity;
	minHeapInstance->volume = capacity;
	//minHeapInstance->pos = NULL;
	for (int i = 0; i < capacity; i++)
	{
		minHeapInstance->array[i] = newMinHeapNode(i, INT_MAX);
		minHeapInstance->pos[i] = 0;
	}
	printf("newMinHeap has been established");
	return minHeapInstance;
}

struct MinHeapNode* newMinHeapNode(int vertex, int weight)
{
	struct MinHeapNode* minHeapNodeInstance = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
	minHeapNodeInstance->vertex = vertex;
	minHeapNodeInstance->weight = weight;
	return minHeapNodeInstance;
}


void decreaseKey(MinHeapPtr minHeapInstance, int location, MinHeapNodePtr minHeapNodeInstance)
{
	minHeapInstance->array[location]->weight = minHeapNodeInstance->weight;
	
	int parent = (location - 1) >> 1;
	int tempPoint = NULL;
	while (parent >= 0 &&
		minHeapInstance->array[location]->weight< minHeapInstance->array[parent]->weight)
	{
		MinHeapNodePtr tempHeapNode = newMinHeapNode(minHeapInstance->array[parent]->vertex, minHeapInstance->array[parent]->weight);
		tempPoint = minHeapInstance->pos[minHeapInstance->array[parent]->vertex];
		minHeapInstance->pos[minHeapInstance->array[parent]->vertex] = minHeapInstance->pos[minHeapInstance->array[location]->vertex];
		minHeapInstance->pos[minHeapInstance->array[location]->vertex] = tempPoint;
		minHeapInstance->array[parent] = minHeapNodeInstance;
		minHeapInstance->array[location] = tempHeapNode;

		location = parent;
		parent = (location - 1) >> 1;
	}
	
	printf("After decress Key,now the queue is \n");
	for (int n = 0; n < minHeapInstance->size; n++)
	{
		printf("[%d,%d]\n ", minHeapInstance->array[n]->vertex, minHeapInstance->array[n]->weight);
	}

	printf("The pointer is \n");
	for (int n = 0; n < minHeapInstance->volume; n++)
	{
		printf("[point:%d,vertex:%d]\n ", n, minHeapInstance->pos[n]);
	}
}


struct MinHeapNode* extractMin(struct MinHeap* Heap)
{
	if (Heap == NULL)
	{
		printf("The Heap is NULL!");
		return;
	}
	if (Heap->size == 0)
	{
		return NULL;
	}
	MinHeapNodePtr TopOfTheHeap = Heap->array[0];
	Heap->pos[Heap->array[0]->vertex] = -1;
	Heap->array[0] = Heap->array[Heap->size - 1];
	if (Heap->size > 1)
	{
		Heap->array[Heap->size - 1] = NULL;
	}
	Heap->pos[Heap->array[0]->vertex] = 0;
	Heap->size--;

	//find the smallest son between topnode's sons;
	int i = 0;
	int tempInt = NULL;
	while(i <= (Heap->size)) // If there are elements of son exist
	{
		//pick the smaller as the top value

		if (Heap->array[right(i)])//if right son exist
		{
			if (Heap->array[left(i)]->weight < Heap->array[i]->weight && 
				Heap->array[left(i)]->weight < Heap->array[right(i)]->weight)
			{
				//smallest = left(i);
				Heap->pos[Heap->array[left(i)]->vertex] = i;
				Heap->pos[Heap->array[i]->vertex] = left(i);
				MinHeapNodePtr temp = Heap->array[i];
				Heap->array[i] = Heap->array[left(i)];
				Heap->array[left(i)] = temp;
				//tempInt = Heap->pos[i];
				
				i = left(i);
				continue;
			}
			if (Heap->array[right(i)]->weight < Heap->array[i]->weight && 
				Heap->array[right(i)]->weight < Heap->array[left(i)]->weight)
			{
				Heap->pos[Heap->array[right(i)]->vertex] = i;
				Heap->pos[Heap->array[i]->vertex] = right(i);
				MinHeapNodePtr temp = Heap->array[i];
				Heap->array[i] = Heap->array[right(i)];
				Heap->array[right(i)] = temp;
				//tempInt = Heap->pos[i];
				i = right(i);
				continue;
			}
			break;
		}
		else if (!Heap->array[right(i)])//if right son not exist
		{
			if (!Heap->array[left(i)])
			{
				break;
			}
			if (Heap->array[left(i)]->weight < Heap->array[i]->weight)
			{
				Heap->pos[Heap->array[left(i)]->vertex] = i;
				Heap->pos[Heap->array[i]->vertex] = left(i);
				MinHeapNodePtr temp = Heap->array[i];
				Heap->array[i] = Heap->array[left(i)];
				Heap->array[left(i)] = temp;
				//tempInt = Heap->pos[i];
				i = left(i);
				continue;
			}
			break;
		}
	}

	printf("After extractMin,now the queue is \n");
	for (int n = 0; n < Heap->size; n++)
	{
		printf("[%d,%d]\n ", Heap->array[n]->vertex, Heap->array[n]->weight);
	}

	printf("The pointer is \n");
	for (int n = 0; n < Heap->volume; n++)
	{
		printf("[point:%d,vertex:%d]\n ",n, Heap->pos[n]);
	}

	return TopOfTheHeap;
}


void swap(MinHeapNodePtr x, MinHeapNodePtr y)
{
	struct MinHeapNode temp = *x;
	*x = *y;
	*y = temp;
}

int qiumi(int cishu, int n, int dest)
{
	int NumberOfLine = n * 2;
	cishu++;
	if (NumberOfLine < dest)
	{
		return qiumi(cishu, NumberOfLine, dest);
	}
	if (NumberOfLine > dest)
	{
		return cishu;
	}
}

bool isInMinHeap(struct MinHeap* minHeap, int v)
{
	if (minHeap->array[minHeap->pos[v]] != NULL)
		return true;
	//if (minHeap->pos[v] < minHeap->size)
	//	return true;
	return false;
}

void printArr(int dist[], int n)
{
	printf("Vertex Distance from Source\n");
	for (int i = 0; i < n; ++i)
		printf("%d \t\t %d\n", i, dist[i]);
}


void dijkstra(struct Graph* graph, int src)
{
	MinHeapPtr minHeap = newMinHeap(graph->size);
	int* longth = (int*)malloc(graph->size * sizeof(int));
	for (int i = 0; i < graph->size; i++)
	{
		minHeap->array[i]->vertex = i;
		minHeap->pos[i] = i;
		longth[i] = INT_MAX;
	}
	
	//set the weight of begining as 0
	minHeap->array[src]->weight = 0;
	longth[src] = 0;
	decreaseKey(minHeap, minHeap->pos[src], minHeap->array[src]);

	while (minHeap != NULL)
	{
		struct MinHeapNode* minHeapNode = extractMin(minHeap);
		if (minHeapNode == NULL)
		{
			break;
		}
		int fromVertex = minHeapNode->vertex; // Store the extracted vertex number 

		AdjListNodePtr toNode = graph->array[fromVertex].head;

		while (toNode!= NULL)
		{
			int toVertex = toNode->vertex;

			if (isInMinHeap(minHeap, toVertex) && longth[fromVertex] < INT_MAX &&
				(toNode->weight + longth[fromVertex] < longth[toVertex]))
			{
				longth[toVertex] = toNode->weight + longth[fromVertex];
				minHeap->array[minHeap->pos[toVertex]]->weight = longth[toVertex];
				decreaseKey(minHeap, minHeap->pos[toVertex], minHeap->array[minHeap->pos[toVertex]]);
			}

			toNode = toNode->next;
		}
	}
	printArr(longth, graph->size);
}

void printGraph(struct Graph* graph) {
	struct AdjListNode* pCrawl = NULL;
	for (int s = 0; s < graph->size; s++) {
		printf("\n Adjacency list of vertex%d\n head", s);
		pCrawl = graph->array[s].head;
		while (pCrawl) {
			printf("->%d", pCrawl->vertex);
			pCrawl = pCrawl->next;
		}
		printf("\n");
	}
}

int main()
{
	// create the graph given in above fugure 
	int V = 9;
	struct Graph* graph = newGraph(V);
	addEdge(graph, 0, 1, 4);
	addEdge(graph, 0, 7, 8);
	addEdge(graph, 1, 2, 8);
	addEdge(graph, 1, 7, 11);
	addEdge(graph, 2, 3, 7);
	addEdge(graph, 2, 8, 2);
	addEdge(graph, 2, 5, 4);
	addEdge(graph, 3, 4, 9);
	addEdge(graph, 3, 5, 14);
	addEdge(graph, 4, 5, 10);
	addEdge(graph, 5, 6, 2);
	addEdge(graph, 6, 7, 1);
	addEdge(graph, 6, 8, 6);
	addEdge(graph, 7, 8, 7);
	printGraph(graph);
	dijkstra(graph, 0);

	return 0;
}