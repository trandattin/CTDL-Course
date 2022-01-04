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

void shakerSort(int a[], int n)
{
	int Left = 0;
	int Right = n-1;
	int k  = 0;
	while(Left < Right)
	{
		// Duyệt từ dưới lên để đẩy phần tử lớn về cuối dãy
		for (int i = Left; i < Right; i++)
		{
			if(a[i] > a[i+1])
			{
				swap(a[i],a[i+1]);
				k = i;
				// Lưu lại i - vị trí đã sắp rồi để lát gán cho Right
			}
		}
			// Không xét các phần tử đã sắp ở cuối dãy
			Right = k;
			for (int i = Right; i > Left; i--)
			{
				if (a[i] < a[i-1])
				{
					swap(a[i],a[i-1]);
					k = i;
				}
			}
			Left = k;
		}
	}

int main()
{
	int a[] = {9, 6, 7, 8, 3, 4};
	int n = sizeof(a)/sizeof(a[0]);
	shakerSort(a,n);
	printArray(a,n);
}