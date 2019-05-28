#include<stdio.h>
#include<stdlib.h>
#include"SqList.h"

Status List_Init(SqListPtr L) 
{
	Status s = fail;
	if (L != NULL) 
	{
		L->elem = (ElemType *)malloc((LIST_INIT_SIZE+1) * sizeof(ElemType));
		//��1��Ϊ������洢�߼��������߼�����ϣ�����1��n������0��n-1
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
	if (L)//����������Ա�L
	{
		if (L->elem)//������Ԫ�ش���
		{
			free(L->elem);//�ͷſռ�
			L->elem = NULL;//���Ա����Ԫ�ؾ�Ϊ����
			L->length = 0;//Ԫ�ظ���Ϊ0��
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
Status List_Retrival(SqListPtr L, int pos, ElemType *elem) //��posλ�û�ȡ���ݷ���elem��
{
	Status s = range_error;//�ȼ���״̬��Խ�磬����ɹ������޸Ĵ�״̬
	if (L) // ��ȷ��pos�Ƿ�Ϊ�Ϸ�λ��
	{
		if (pos >= 1 && pos <= L->length)
		{
			*elem = L->elem[pos];
			//*elemָ��ָ����elemΪ�׵�ַ�ĵ�pos��λ�õ�����,�Ⱥ����ҵ�elme����һ������
			s = success;
		}
	}
	return s;
}
Status List_Locate(SqListPtr L, ElemType elem, int *pos) //�ҵ�elem��������λ�÷���pos����
{
	Status s = range_error;
	int i = 1;
	if (L)
	{
		for(i=1;i<=L->length;i++)
		{
			if (L->elem[i] == elem)
			{
				*pos = i;//�﷨����posָ��ĵ�ַ��ֵ��i
				s = success;
				break;
			}
		}
	}
	return s;
}
Status List_Insert(SqListPtr L, int pos, ElemType elem) //�������
{
	Status s = range_error;
	if (L)
	{
		if (pos >= 1 && pos <= L->length + 1)//�ж�λ���Ƿ�Ϸ�
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
Status List_Prior(SqListPtr L, int pos, ElemType * elem) //��ֱ��ǰ��
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
Status List_Next(SqListPtr L, int pos, ElemType *elem) //��ֱ�Ӻ��
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