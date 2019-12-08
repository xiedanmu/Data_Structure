#include<stdio.h>
#include<stdlib.h>
#include"SqList.h"

Status List_Init(SqListPtr L)
{
	Status s = fail;
	Ptr p;
	if (*L == NULL)
	{
		p = (Ptr)malloc(sizeof(Node));
		if (p == NULL)return s;
		*L = p;
		(*L)->next = NULL;
		s = success;
	}
	return s;
}
void List_Destory(SqListPtr L)
{
	List_Clear(L);
	if(*L)
	{
		free(*L);
		*L = NULL;
	}
}
void List_Clear(SqListPtr L)
{
	Ptr p=NULL;
	if (*L)
	{
		p = (*L)->next;
		while (p)
		{
			(*L)->next = p->next;
			free(p);
			p = (*L)->next;
		}
	}
}
bool List_Empty(SqListPtr L)
{
	if (*L&&(*L)->next == NULL)
	{
		return 1;
	}
	else return 0;
	/*教程里的写法如下
	return ((*L)->next==NULL);*/
}
int List_Size(SqListPtr L)
{
	int len = 0;
	Ptr p=(*L)->next;
	while(p)
	{
		len++;
		p = p->next;
	}
	return len;
}
Status List_Retrival(SqListPtr L, int pos, ElemType *elem)
{
	Status s = fail;
	Ptr p = (*L)->next;
	int i=1;//表示位置
	while (p&&i!=pos)  //教程里是while (p&&i<pos)
	{
		i++;
		p = p->next;
	}
	if (i = pos && p)
	{
		*elem = p->elem;
		s = success;
	}
	return s;
}
Status List_Locate(SqListPtr L, ElemType elem, int *pos)
{
	Status s = fail;
	Ptr p = (*L)->next;
	int i=1;//location
	while (p&&p->elem != elem)
	{
		p = p->next;
		i++;
	}
	if (p && p->elem == elem)
	{
		*pos = i;
		s = success;
	}
	return s;
}
Status List_Insert(SqListPtr L, int pos, ElemType elem)
{
	/*
	Status s = fail;
	int i = 1;
	Ptr p = (*L)->next;
	Ptr b=NULL;
	Ptr n=(Ptr)malloc(sizeof(Node));
	n->elem = elem;
	while (p&&i < pos)
	{
		i++;
		b = p;
		p = p->next;
	}
	if (p&&i == pos)
	{
		n->next = p->next;
		b->next = n;
		s = success;
	}
	return s;
	
	教程中的写法*/
	int i=1;
	Status s= fail;
	Ptr p=(*L)->next,q=(*L);
	while(i<pos&&p)
	{
		q = p;
		p = p->next;
		++i;
	}
	if (i == pos)
	{
		p = (Ptr)malloc(sizeof(Node));
		if (p)
		{
			p->elem = elem;
			p->next = q->next;
			q->next = p;
			s = success;
		}
	}
	return s;
	
}
Status List_delete(SqListPtr L, int pos)
{
	Status s= fail;
	Ptr p = (*L)->next,q=*L;
	int i = 1;
	while (p&&i < pos)
	{
		q = p;
		p = p->next;
		i++;
	}
	if (i == pos && p)
	{
		q->next = p->next;
		free(p);
		p = NULL;
		s = success;
	}
	return s;
}
Status List_Prior(SqListPtr L, int pos, ElemType *elem)
{
	Status s = fail;
	Ptr p=(*L)->next;
	int i=1;
	while (p&&i < pos-1)
	{
		p = p->next;
		i++;
	}
	if (p&&i == pos - 1)
	{
		*elem = p->elem;
		s = success;
	}
	return s;
}
Status List_Next(SqListPtr L, int pos, ElemType *elem)
{
	Status s = fail;
	Ptr p = (*L)->next;
	int i=1;
	while (p&&i < pos + 1)
	{
		p = p->next;
		i++;
	}
	if (p&&i == pos + 1)
	{
		*elem = p->elem;
		s = success;
	}
	return s;
}

void List_Print(SqListPtr L)
{
	Ptr p = (*L)->next;
	int i=1;
	while (p)
	{
		printf("%d", p->elem);
		p = p->next;
		i++;
		if (i % 10 == 1)
		{
			printf("/n");
		}
	}
}