#include "stdio.h"

void printArray(int a[], int n)
{
	for(int i = 0; i<n; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

int findMinPositive(int arr[], int begin, int end)
{
	int index = begin;
	for (int i = begin+1; i < end; i++){
		if (arr[index] < 0 && arr[index] < arr[i] && arr[i] >=0)
			index = i;
		if(arr[index] >= 0 && arr[index] > arr[i] && arr[i] >= 0)
			index = i;
	}
	return index;
}

int findMaxNegative(int arr[], int begin, int end)
{
	int index = end;
	for (int i = end-1; i > begin; i--)
	{
		if (arr[index] < 0 && arr[index] < arr[i] && arr[i] < 0)
			index = i;
		if (arr[index] >= 0 && arr[index] > arr[i] && arr[i] < 0)
			index = i;
	}
	return index;
}

void selectionSort(int arr[], int n)
{
	int index;
	int i = 0;
	int j = n-1;
	while(i < j)
	{
		index = findMinPositive(arr,i,n);
		if (arr[index] >= 0)
			swap(arr[i],arr[index]);
		index = findMaxNegative(arr,0,j);
		if (arr[index] < 0)
			swap(arr[j],arr[index]);
		j--;
		i++;
	}
}

int main()
{
	int arr[] = {-1,10,-9,-8,-7,6,5,4,3,2,1,-1,-2,-3,-4,0};
	int n = sizeof(arr)/sizeof(arr[0]);
	printArray(arr,n);
	selectionSort(arr,n);
	printArray(arr,n);
}