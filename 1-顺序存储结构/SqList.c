#include<stdio.h>
#include<stdlib.h>
#include"SqList.h"

Status List_Init(SqListPtr L) 
{
	Status s = fail;
	if (L != NULL) 
	{
		L->elem = (ElemType *)malloc((LIST_INIT_SIZE+1) * sizeof(ElemType));
		//加1是为了物理存储逻辑和正常逻辑相符合，能用1到n而不是0到n-1
		if (L->elem) 
		{
			L->list_size = LIST_INIT_SIZE;
			L->length = 0;
			s = success;
		}
	}
	return s;
}
void List_Destory(SqListPtr L) 
{
	if (L)//如果存在线性表L
	{
		if (L->elem)//如果这个元素存在
		{
			free(L->elem);//释放空间
			L->elem = NULL;//线性表里的元素就为空了
			L->length = 0;//元素个数为0了
		}
	}
}
void List_Clear(SqListPtr L) 
{
	if (L)
	{
		L->length = 0;
	}
}
bool List_Empty(SqListPtr L) 
{
	return(L->length == 0);
}
int List_Size(SqListPtr L) 
{
	return L->length;
}
Status List_Retrival(SqListPtr L, int pos, ElemType *elem) //从pos位置获取数据放入elem中
{
	Status s = range_error;//先假设状态是越界，后面成功了再修改此状态
	if (L) // 先确定pos是否为合法位置
	{
		if (pos >= 1 && pos <= L->length)
		{
			*elem = L->elem[pos];
			//*elem指针指向以elem为首地址的第pos个位置的数据,等号左右的elme不是一个东西
			s = success;
		}
	}
	return s;
}
Status List_Locate(SqListPtr L, ElemType elem, int *pos) //找到elem并把它的位置放入pos当中
{
	Status s = range_error;
	int i = 1;
	if (L)
	{
		for(i=1;i<=L->length;i++)
		{
			if (L->elem[i] == elem)
			{
				*pos = i;//语法上是pos指向的地址的值是i
				s = success;
				break;
			}
		}
	}
	return s;
}
Status List_Insert(SqListPtr L, int pos, ElemType elem) //插入操作
{
	Status s = range_error;
	if (L)
	{
		if (pos >= 1 && pos <= L->length + 1)//判断位置是否合法
		{
			if (L->length < L->list_size)
			{
				int i;
				for (i = L->length; i >= pos; --i)
					L->elem[i + 1] = L->elem[i];
				L->elem[i] = elem;
				L->length++;
				s = success;
			}
		}
	}
	return s;
}
Status List_delete(SqListPtr L, int pos) 
{
	Status s = range_error;
	if (L)
	{
		if (pos >= 1 && pos <= L->length)
		{
			int i;
			for (i = pos + 1; i < L->length; i++)
				L->elem[i - 1] = L->elem[i];
			L->length--;
			s = success;
		}
	}
	return s;
}
Status List_Prior(SqListPtr L, int pos, ElemType * elem) //找直接前驱
{
	Status s = range_error;
	if (L)
	{
		if(pos>1 && pos<=L->length)
		{
			*elem = L->elem[pos - 1];
			s = success;
		}
	}
	return s;
}
Status List_Next(SqListPtr L, int pos, ElemType *elem) //找直接后继
{
	Status s = range_error;
	if (L)
	{
		if (pos >= 1 && pos < L->length)
		{
			*elem = L->elem[pos + 1];
			s = success;
		}
	}
	return s;
}
void List_Print(SqListPtr L)
{
	int i;
	if (L)
	{
		for (i = 1; i <= L->length; i++)
		{
			printf("%d ", L->elem[i]);
			if(i%10==0)
			{
				printf("\n");
			}
		}
	}
}