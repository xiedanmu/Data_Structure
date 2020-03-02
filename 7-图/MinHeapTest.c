#include<stdio.h>
#include"MinHeap.h"
#include<stdlib.h>
#include<time.h>
#define max 100   
#define min 1    

int main()
{
	srand(time(0));
	struct MinHeap* NewHeap=creatMinHeap(200);
	for (int i = 0; i <200; i++)
	{
		int num = rand() % (max - min) + min;
		insertIntoHeap(NewHeap, num);
	}
	printHeap(NewHeap);
	int a = extractMin(NewHeap);
	printf("\n%d\n", a);

	system("pause");
	return 0;
}