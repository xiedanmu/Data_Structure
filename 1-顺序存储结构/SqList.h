#pragma once
#define bool int
#define LIST_INIT_SIZE 100
#define LIST_INCREAMENT 10
typedef int ElemType;//����������ʲô

typedef struct SqList 
{
	ElemType *elem;
	int length;//Ŀǰ���Ա�ĳ���
	int list_size;//����Ŀռ��С
}SqList, *Ptr, *SqListPtr;

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
Status List_Union(SqListPtr La, SqListPtr Lb);