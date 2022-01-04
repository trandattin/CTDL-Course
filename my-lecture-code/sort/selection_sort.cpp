#include "stdio.h"
#include "math.h"
#include <iostream>
#include <string>
using namespace std;

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

int minIndex(int a[], int i, int n) 
{
    int min_index = i;
    for (int j=i+1; j<n; j++)
        if (a[j] < a[min_index])
            min_index = j;
    return min_index;
}

void selectSort(int arr[], int n)
{
    int i, min_index;
    for (i = 0; i < n - 1; i++)
    {
        min_index = minIndex(arr, i+1, n);
        if (arr[min_index] < arr[i])
            swap(arr[min_index], arr[i]);
    }
}

int main()
{
	int a[] = {5, 6, 7, 8, 4, 3};
	int n = sizeof(a)/sizeof(a[0]);
	selectSort(a,n);
	printArray(a,n);
}