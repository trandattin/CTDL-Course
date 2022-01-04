#include "stdio.h"

struct Tasks {
	int first;
	int second;
}

void partialize(int x[], int left, int right, int n)
{
	while ()
	{
    	int i = left; 
    	int j = right;
    	int mid = x[(left+right)/2]; // Chọn phần tử “giữa” làm mốc
    	do
    	{
        	while (mid>x[i]) i = i+1;
        	while (mid<x[j]) j = j-1;
        	if (i <= j)
        	{
            	swap(&x[i],&x[j]);
            	i++ ;
            	j-- ;
        	}
    	} while (i <= j);
	}
	
    // if (left < j)
    //     partialize(x, left, j, n);
    // if (right > i)
    // 	partialize(x, i, right, n);
    return;
}

int main()
{
    int arr[] = {3, 17, 81, 25, 62, 7, 23, 9, 43};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, n);
	quickSort(arr, n);
    cout << "Result: \n";
    printArray(arr, n);
    return 0;
}