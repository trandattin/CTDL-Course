#include "stdio.h"
#include "math.h"

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

void Partition(int arr[], int n, int low, int high)
{
	int i = low;
	int j = high;
	int mid = (high+low)/2;
	do
	{
		while (abs(arr[i]) < abs(arr[mid])) i++;
		while (abs(arr[j]) > abs(arr[mid])) j--;
		if (i <= j){
			swap(arr[i],arr[j]);
			j--;
			i++;
		}
	}while (i <= j);
	if (j > low)
		Partition(arr,n,low,j);
	if (i < high)
		Partition(arr,n,i,high);
}

void quickSort(int arr[], int n)
{
	Partition(arr, n, 0, n-1);
}

int main()
{
	int arr[] = {-1111,9,-8,7,6,5,4,3,2,-1};
	int n = sizeof(arr)/sizeof(arr[0]);
	printArray(arr,n);
	quickSort(arr,n);
	printArray(arr,n);
}