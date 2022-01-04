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


void printArrayColor(int a[], int size, int start, int end)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (i >= start && i <= end)
            printf("\x1B[32m%d\033[0m ", a[i]);
        else
            printf("%d ", a[i]);
    }
    cout << endl;
}

void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

void bubbleSort(int a[], int n)
{
	int last_term, pair = n-1;
	while(pair > 0 ){
		last_term = 0;
		for (int i = 0; i < pair; i++)
		{
			printArrayColor(a, n, i, i+1);
			if (a[i]>a[i+1])
			{
				swap(a[i],a[i+1]);
				last_term = i;
			}
			printArrayColor(a, n, i, i + 1);
		}
		pair = last_term;
	}
}

int main()
{
	int a[] = {5, 6, 7, 8, 3, 4};
	int n = sizeof(a)/sizeof(a[0]);
	bubbleSort(a,n);
	printArray(a,n);
}