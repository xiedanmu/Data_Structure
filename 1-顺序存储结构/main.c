#include<stdio.h>
#include<stdlib.h>
#include"TestSqList.h"

int main()
{
	int opt=1;
	SqList list;
	int pos,size,i;
	ElemType e, *data;
	Status s;
	while (opt!=6)
	{
		printf("������ѡ��:\n");
		printf("1:���Խ������Ա�\n");
		printf("2:����������Ա�\n");
		printf("3:������ĳλ�õ����Ա�ֵ��ǰ�����\n");
		printf("4:���Բ�ѯĳԪ�ص�λ��\n");
		printf("5:�������Ա�ĳ���\n");
		printf("6.��������\n");
		scanf_s("%d", &opt);
		switch (opt)
		{
		case 1:
			printf("���Ա���:\n");
			scanf_s("%d", &size);
			data = (ElemType*)malloc(size * sizeof(ElemType));
			if (data == NULL)
				break;
			printf("���Ա�Ԫ��:\n");
			for (i = 0; i < size; i++)
				scanf_s("%d", &data[i]);
				
			s = Test_ClearList(&list, data, size);
			if (s != success)
				printf("�������Ա�ʧ��\n");
			break;

		case 2:
			printf("���Ա���:\n");
			scanf_s("%d", &size);
			data = (ElemType*)malloc(size * sizeof(ElemType));
			if (data == NULL)
				break;
			printf("���Ա�Ԫ��:\n");
			for (i = 0; i < size; i++)
				scanf_s("%d", &data[i]);

			s = Test_ClearList(&list, data, size);
			if (s == success)
			{
				if (!List_Empty(&list))
				{
					List_Clear(&list);
					if (List_Empty(&list))
					{
						printf("�Ѿ�������Ա�\n");
					}
				}
			}
			break;

		case 3:
			printf("���Ա���:\n");
			scanf_s("%d", &size);
			data = (ElemType*)malloc(size * sizeof(ElemType));
			if (data == NULL)
				break;
			printf("���Ա�Ԫ��:\n");
			for (i = 0; i < size; i++)
				scanf_s("%d", &data[i]);

			s = Test_ClearList(&list, data, size);
			if (s == success)
			{
				printf("��������ҵ�λ��:\n");
				scanf_s("%d", &pos);
				Test_RetrivalPriorNext(&list, pos);
			}
			break;

		case 4:
			printf("���Ա���:\n");
			scanf_s("%d", &size);
			data = (ElemType*)malloc(size * sizeof(ElemType));
			if (data == NULL)
				break;
			printf("���Ա�Ԫ��:\n");
			for (i = 0; i < size; i++)
				scanf_s("%d", &data[i]);

			s = Test_ClearList(&list, data, size);
			if (s == success)
			{
				printf("�������ѯ��Ԫ��ֵ:\n");
				scanf_s("%d",&e);
				Test_Locate(&list, e);
			}
			break;

		case 5:
			printf("���Ա���:\n");
			scanf_s("%d", &size);
			data = (ElemType*)malloc(size * sizeof(ElemType));
			if (data == NULL)
				break;
			printf("���Ա�Ԫ��:\n");
			for (i = 0; i < size; i++)
				scanf_s("%d", &data[i]);

			s = Test_ClearList(&list, data, size);
			if (s == success)
			{
				Test_Size(&list);
			}
			break;

		default:
			break;
		}
	}

	return 0;
}