#pragma once
#include<stdio.h>
#include<stdlib.h>

struct AdjListNode {
	int dest;
	struct AdjListNode* next;
};

struct AdjList {
	struct AdjListNode* head;
};

struct Graph {
	int size;
	struct AdjList* array;
};

struct AdjListNode* newAdjListNode(int dest){
	struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
	if (newNode) {
		newNode->dest = dest;
		newNode->next = NULL;
		return newNode;
	}
	else printf("newNode malloc error,error is:%d\n", errno);
}

struct Graph* newGraph(int size) {
	struct Graph* newGraph = (struct Graph*)malloc(sizeof(struct Graph));
	if (newGraph) {
		newGraph->size = size;
		newGraph->array = (struct AdjList*)malloc(size * sizeof(struct AdjList));
		for (int i = 0; i < size; i++) {
			newGraph->array[i].head = NULL;
		}
		return newGraph;
	}
	else printf("newGraph malloc error,error is:%d\n", errno);
}

void addEdge(struct Graph* Graph, int src, int dest) {

	struct AdjListNode* newNode = newAdjListNode(dest);
	struct AdjListNode* scanNode = NULL;
	if (Graph->array[src].head == NULL)
		Graph->array[src].head = newNode;
	else {
		scanNode = Graph->array[src].head;
		while (scanNode->next) {
			scanNode = scanNode->next;
		}
		scanNode->next = newNode;
	}


	newNode = newAdjListNode(src);
	if (Graph->array[dest].head == NULL)
		Graph->array[dest].head = newNode;
	else {
		scanNode = Graph->array[dest].head;
		while (scanNode->next) {
			scanNode = scanNode->next;
		}
		scanNode->next = newNode;
	}
}
	

/*	The version in https://www.geeksforgeeks.org/graph-and-its-representations/
void addEdge(struct Graph* graph, int src, int dest){
	
	// Add an edge from src to dest.  A new node is  
	// added to the adjacency list of src.  The node 
	// is added at the begining 
	struct AdjListNode* newNode = newAdjListNode(dest);
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;

	// Since graph is undirected, add an edge from 
	// dest to src also 
	newNode = newAdjListNode(src);
	newNode->next = graph->array[dest].head;
	graph->array[dest].head = newNode;	
}
*/

void printGraph(struct Graph* graph){
	struct AdjListNode* pCrawl = NULL;
	for (int s = 0; s < graph->size; s++) {
		printf("\n Adjacency list of vertex%d\n head", s);
		pCrawl = graph->array[s].head;
		while (pCrawl) {
			printf("->%d", pCrawl->dest);
			pCrawl = pCrawl->next;
		}
		printf("\n");
	}
}






