#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct MinHeap 
{
	int* harr; //pointer to array of elements in heap
	int capacity; //maximum possible size of min heap
	int heap_size; //Current number of elements in heap
};
typedef struct MinHeap* MinHeapPtr;

struct MinHeap* creatMinHeap(int V);
int parent(int i) { return (i - 1) / 2; }
int left(int i) { return (i * 2 + 1); }
int right(int i) { return (i * 2 + 2); }
void insertIntoHeap(struct MinHeap* Heap, int value);
int extractMin(struct MinHeap* Heap);
void swap(int a, int b);
void printHeap(struct MinHeap* Heap);
int qiumi(int cishu, int n, int dest);

struct MinHeap* creatMinHeap(int V)
{
	struct MinHeap* newMinheap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
	if (V)
	{
		newMinheap->capacity = V;
		newMinheap->harr = (int*)malloc(V * sizeof(int));
		newMinheap->heap_size = 0;
		printf("creatMinHeap SUCCESS");
		return newMinheap;
	}

	printf("creatMinHeap FAILED with returning a NULL");
	return NULL;
}

void insertIntoHeap(struct MinHeap* Heap,int value)
{
	if (Heap == NULL|| Heap->heap_size == Heap->capacity)
	{
		printf("The Heap is NULL or exceed capacity!");
		return;
	}
	Heap->heap_size++;
	int i=Heap->heap_size-1;//point to the last one 
	Heap->harr[i] = value;
	while (Heap->harr[i] < Heap->harr[parent(i)])
	{
		swap(&Heap->harr[i], &Heap->harr[parent(i)]);//swap the two value
		i = parent(i);
	}
}

int extractMin(struct MinHeap* Heap)
{
	if (Heap == NULL)
	{
		printf("The Heap is NULL!");
		return;
	}
	int TopOfTheHeap = Heap->harr[0];
	
	Heap->harr[0] = Heap->harr[Heap->heap_size - 1];
	Heap->harr[Heap->heap_size - 1] = NULL;
	Heap->heap_size--;

	//find the smallest son between topnode's sons;
	int i = 0;
	
	while (i<=(Heap->heap_size -1)) // If there are elements of son exist
	{
		//pick the smaller as the top value
	
		if (Heap->harr[right(i)])//if right son exist
		{
			if (Heap->harr[left(i)] < Heap->harr[i]&& Heap->harr[left(i)]< Heap->harr[right(i)])
			{
				//smallest = left(i);
				int temp = Heap->harr[i];
				Heap->harr[i] = Heap->harr[left(i)];
				Heap->harr[left(i)] = temp;
				i = left(i);
			}
			if (Heap->harr[right(i)] < Heap->harr[i] && Heap->harr[right(i)] < Heap->harr[left(i)])
			{
				int temp = Heap->harr[i];
				Heap->harr[i] = Heap->harr[right(i)];
				Heap->harr[right(i)] = temp;
				i = right(i);
			}
		}
		else if(!Heap->harr[right(i)])//if right son not exist
		{
			if (Heap->harr[left(i)] < Heap->harr[i])
			{
				swap(Heap->harr[i], Heap->harr[left(i)]);
				i = left(i);
			}
		}
	}
	return TopOfTheHeap;
}


//void swap(int* a, int* b)
void swap(int* x, int* y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 

void printHeap(struct MinHeap* Heap)
{
	printf("\n");
	int amount = Heap->heap_size-1;
	int numberOfLines = qiumi(1, 2, amount+1);
	int CurrentLine = numberOfLines;
	int numofspace=1;
	while (CurrentLine >= 1)
	{
		while (amount>(pow(2, CurrentLine-1)-2))
		{
			printf("[%d]", Heap->harr[amount]);
			for (int i = 0; i < CurrentLine; i++)
			{
				printf(" ");
			}
			amount--;
		}
		numofspace++;
		printf("\n");
		for (int i = 0; i < numofspace;i++)
		{
			printf("   ");
		}
		CurrentLine--;
	}

}

int qiumi(int cishu,int n,int dest)
{
	int NumberOfLine = n * 2;
	cishu++;
	if (NumberOfLine < dest)
	{
		return qiumi(cishu,NumberOfLine,dest);
	}
	if (NumberOfLine > dest)
	{
		return cishu;
	}
}
