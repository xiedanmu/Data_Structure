#include<stdio.h>
#include<stdlib.h>
#include"TestSqList.h"

Status Test_CreateList(SqListPtr list,ElemType data[],int n)
{
	Status s = fail;
	int i;
	s = List_Init(list);
	if (s == success)
	{
		for(i=1;i<=n;++i)
		{
			s = List_Insert(list, i, data[i]);
			if (s != success)
				break;
		}
		List_Print(list);
	}
	return s;
}
Status Test_ClearList(SqListPtr list)
{
	Status s = fail;
	if (!List_Empty(list))
	{
		List_Clear(list);
		if (List_Empty(list))
		{
			s = success;
		}
	}
	return 0;
}
Status Test_RetrivalPriorNext(SqListPtr list,int pos) 
{
	Status s = range_error;
	ElemType e;
	s = List_Retrival(list, pos,&e);
	if (s == success)
	{
		printf("%d��Ԫ����%d", pos, e);
		s = List_Prior(list, pos, &e);
		if (s == success)
		{
			printf("%d��ֱ��ǰ��Ԫ��ֵ��%d\n", pos, e);
		}
		else 
			printf("û��ֱ��ǰ��\n");
		s = List_Next(list, pos, &e);
		if (s == success)
			printf("%d��ֱ�Ӻ����%d\n",pos,e);
		else
			printf("û��ֱ�Ӻ��\n");
	}
	else
	{
		printf("λ�ò��Ϸ�\n");
	}
	return s;
}
Status Test_Locate(SqListPtr list,ElemType e) 
{
	Status s = fail;
	int pos;
	s = List_Locate(list, e, &pos);
	if (s == success)
	{
		printf("%d��λ����%d\n", e, pos);
	}
	else
		printf("����ʧ��\n");
	return s;
}
void Test_Size(SqListPtr list) 
{
	int len = List_Size(list);
	printf("���Ա�ĳ���%d\n", len);
}