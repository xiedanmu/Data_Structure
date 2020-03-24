#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void quickSort(int* arr, int low, int high)//!WARNING:low and high are indexs of the arr,NOTICE !!!
{
	if (low >= high||low<0)
	{
		return;
	}
	int pivot = arr[high];
	int leftflag=low;
	int rightflag=high-1;
	int changePivotFlag = 0;//bool
	for (; leftflag <= high; leftflag++)
	{
		
		if (arr[leftflag] >= pivot)
		{
			for (; rightflag >= leftflag; rightflag--)
			{
				if (arr[rightflag] < pivot)
				{
					swap(&arr[leftflag], &arr[rightflag]);
					break;
				}
				if (rightflag == leftflag)
				{
					swap(&arr[leftflag], &arr[high]);
					changePivotFlag = 1;
					quickSort(arr, low, leftflag-1);
					quickSort(arr, rightflag+1, high);
				}
			}
		}

		if (changePivotFlag)
		{
			break;
		}
		if (leftflag == high)
		{
			quickSort(arr, low, leftflag-1);
		}
	}
}



int* sort(int* arr, int low, int high)// optimize this function to achieve this requirement that user can invoke "int* sort(int* arr)" directly
{
	quickSort(arr, low, high);
	return arr;
}

int main()
{
	int a[13] = { 0,1,2,1,1,2,3,4,6,5,5,9,7 };
	quickSort(a, 0, 13-1);
	for (int i = 0; i < 13; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}