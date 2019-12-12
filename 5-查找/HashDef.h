#pragma once
#define StackEntry int
#define SIZE 20

typedef struct Node {
	StackEntry Entry;
	struct node* next;
}StackNode, * StackNodePtr;

typedef struct stack {
	StackNodePtr top;
}Stack, * StackPtr;

typedef enum Status
{
	success, fail, fatal, range_error, overflow, underflow //0,1,2,3,4
}Status;

int Hash(int key);
Status SearchHash(HashTable H, )

