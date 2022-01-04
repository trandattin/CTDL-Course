#include "stdio.h"
#include "math.h"
#include <string>
using namespace std;

void printArray(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

void insertSort(int a[], int n)
{
	for (int i = n-2; i>=0; i--){
		// get a value from unsorted array
		a[n] = a[i];
		int k = i + 1;
		// find a proper index for it in the sorted array
        while (a[k] < a[n])
        {
            a[k-1] = a[k];
            k++;
        }
		// insert value to sorted array
        if (k>i+1)
            a[k-1] = a[n];
	}
    printArray(a,n);
}

int main()
{
	int a[] = {9,8,7,7,6,5};
	int n = 6;
	printArray(a,n);
	insertSort(a,n);
}