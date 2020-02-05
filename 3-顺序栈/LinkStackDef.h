#pragma 
#define StackEntry int

typedef struct Node {
	StackEntry Entry;
	struct node *next;
}StackNode,*StackNodePtr;

typedef struct stack {
	StackNodePtr top;
}Stack, * StackPtr;

typedef enum Status
{
	success, fail, fatal, range_error, overflow, underflow //0,1,2,3,4
}Status;

Status Stack_Push(StackPtr s, StackEntry *item);
Status Stack_Pop(StackPtr s, StackEntry *item);
Status Stack_Empty(StackPtr s);
Status Stack_Top(StackPtr s, StackEntry *item);
StackNodePtr MakeNode(StackEntry *item);