#include "stdio.h"

void printArray(int a[], int n)
{
	for(int i = 0; i<n; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

void findSubSeq(int arr[], int n, int first, int& least, int& end_seq)
{
	int behind_least = first;
	least = first + 1;
	while(least <= n-1 && arr[behind_least] <= arr[least])
	{
		behind_least = least;
		least++;
	}
	// hiệu chỉnh và đánh dấu hết mảng
	if (least > n-1)
	{
		least = n-1;
		end_seq = 1;
	}
	else //arr[behind_least] > arr[least]
	{
		least--;
	}
}

void mixSubSeq(int arr[], int tmp[], int first1, int least1, int first2, int least2)
{
	//Sắp vào mảng phụ
	for (int i = first1; i <= least1; i++)
		tmp[i] = arr[i];
	for (int j = first2; j <= least2; j++)
		// Xếp ngược theo thứ tự giảm dần ở cuối dãy phụ
		tmp[least2+first2-j] = arr[j];
	//Sort mảng phụ
	int i = first1;
	int j = least2;
	for (int k=first1; k <=least2; k++)
	{
		if (tmp[i] < tmp[j])
		{
			arr[k] = tmp[i];
			i++;
		}
		else
		{
			arr[k] = tmp[j];
			j--;
		}
	}
}

void mergeSort(int arr[], int n)
{
	int num_seq, first1, first2, least1, least2,end_seq;
	int tmp[100];
	do
	{
		num_seq = 0;
		first1 = 0;
		end_seq = 0;
		while (end_seq != 1)
		{
			findSubSeq(arr,n,first1,least1,end_seq); 
			num_seq++;
			if (end_seq != 1)
			{
				first2 = least1 + 1;
				findSubSeq(arr,n,first2,least2,end_seq);
				mixSubSeq(arr,tmp,first1,least1,first2,least2);
				first1 = least2 + 1;
			}
		}
	} while(num_seq == 1);
}

int main()
{
	int arr[] = {8,7,6,5,4,3,2};
	int n = sizeof(arr)/sizeof(arr[0]);
	printArray(arr,n);
	mergeSort(arr,n);
	printArray(arr,n);
}