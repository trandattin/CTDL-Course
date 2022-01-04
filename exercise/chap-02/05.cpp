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
	int tmp = a; a = b; b = tmp;
}

int findMinIndex(int arr[], int begin, int end)
{
	int min_index = begin;
	for (int i = begin; i <= end; i++)
	{
		if(arr[min_index] > arr[i])
			min_index = i;
	}
	return min_index;
}

int findMaxIndex(int arr[], int begin, int end)
{
	int max_index = begin;
	for (int j = begin; j >= end; j--)
	{
		if(arr[max_index] < arr[j])
			max_index = j;
	}
	return max_index;
}

void selectSort(int arr[], int n)
{
	int i = 0;
	int j = n-1;
	while(i<=j)
	{
		int min_index = findMinIndex(arr,i,j);
		swap(arr[min_index],arr[i]);
		i++;
		int max_index = findMaxIndex(arr,j,i);
		swap(arr[max_index],arr[j]);
		j--;
	}
}

int main()
{
	int arr[] = {9,8,7,6,4,3,2,1,0};
	int n = sizeof(arr)/sizeof(arr[0]);
	selectSort(arr,n);
	printArray(arr,n);
}