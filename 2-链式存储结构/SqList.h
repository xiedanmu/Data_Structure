#pragma once
#define ElemType int
#define bool int

typedef struct Node
{
	ElemType elem;
	struct Node *next;
}Node,*Ptr;
typedef Ptr *SqListPtr;//这个是头节点指针的指针

typedef enum Status
{
	success, fail, fatal, range_error //0,1,2,3
}Status;

Status List_Init(SqListPtr L);
void List_Destory(SqListPtr L);
void List_Clear(SqListPtr L);
bool List_Empty(SqListPtr L);
int List_Size(SqListPtr L);
Status List_Retrival(SqListPtr L, int pos, ElemType *elem);
Status List_Locate(SqListPtr L, ElemType elem, int *pos);
Status List_Insert(SqListPtr L, int pos, ElemType elem);
Status List_delete(SqListPtr L, int pos);
Status List_Prior(SqListPtr L, int pos, ElemType * elem);
Status List_Next(SqListPtr L, int pos, ElemType *elem);
void List_Print(SqListPtr L);
