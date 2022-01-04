#include "stdio.h"
#include  "math.h"

void printArray(int a[], int n)
{
	for(int i = 0; i<n; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

void shellSort(int arr[], int n)
{
	int maxStep = round(log2(n))-1;
	// Lặp lại thao tác bước nhảy
	for (int step = maxStep; step>0; step--)
	{
		for(int i = step; i < n; i++)
		{
			int tmp = arr[i];
            // j báo hiệu đã tới phần tử cuối cùng bên trái
			int j = i - step;
			while(j >= 0 && tmp < arr[j])
			{
				arr[j + step] = arr[j];
				j = j - step;
			}
			arr[j+step] = tmp;
		}
	}
}

int main()
{
	int arr[] = {9,8,7,6,4,3,2};
	int n = sizeof(arr) / sizeof(arr[0]);
	printArray(arr,n);
	shellSort(arr,n);
	printArray(arr,n);
}