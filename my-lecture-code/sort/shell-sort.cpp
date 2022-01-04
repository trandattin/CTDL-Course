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

void shellSort(int a[], int n) 
{
	int maxStep = round(log2(n))-1;
    int i, j, tmp;
    // Lặp theo các bước nhảy
    for (int step = maxStep; step>0; step--)
    {
        for (i = step; i < n; i++)
        {
            tmp = a[i];
            // j báo hiệu đã tới phần tử cuối cùng bên trái
            j = i - step;
            while (j >= 0 && tmp < a[j])
            {
                a[j + step] = a[j];
                j -= step;
            	printArray(a,n);
            }
            a[j + step] = tmp;
	        printArray(a,n);
        }
    }
}

int main()
{
	int a[] = {9,8,7,6,5,4,3};
	int n = sizeof(a)/sizeof(a[0]);
	printArray(a,n);
	shellSort(a,n);
	printArray(a,n);
}