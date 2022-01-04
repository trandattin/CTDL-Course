#include "stdio.h"

int countSubSeq(int arr[], int n)
{
	int count = 1;
	for (int i = 0; i < n-1; i++)
	{
		if (arr[i]>arr[i+1])
			count++;
	}
	return count;
}

int main(){
	int arr[] = {1,2,3,6,0,5,4,5,7,8,3,4,5};
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("So duong chay tu nhien la: %d",countSubSeq(arr, n));
}