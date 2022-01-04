// Heap tăng dần
#include "stdio.h"

void outputArray(int arr[], int n)
{
	for(int i = 0; i<n; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void swap(int& a, int& b){
	int t = a; a = b; b = t;
}

void Shift(int arr[], int L, int R){
	int dad_index = L;
	int son_index = 2 * dad_index;
	int isHeap = 0;
	// Dad là k và son là 2*k
	int dad_value = arr[dad_index];
	while(isHeap != 1 && son_index <= R)
	{
		if(son_index < R) // Nếu cha có con phải thì tìm con lớn nhất
			if(arr[son_index] < arr[son_index+1])
				son_index++;
		if (dad_value >= arr[son_index])
			isHeap = 1;
		// nếu dad không là lớn nhất
		else
		{
			// đưa nút con lớn hơn xuống vị trí nút cha
			arr[dad_index] = arr[son_index];
			arr[son_index] = dad_value;
			// Hiệu chỉnh lan truyền
			dad_index = son_index;
			son_index = 2*dad_index;
		}	
	}
	//arr[dad_index] = dad;
}

void creatFullHeap(int arr[], int n)
{
	int L = (n/2), R = n-1; 
	while(L >= 0) 
	{
		Shift(arr,L,R);
		L--;
	}
	return;
}

void heapSort(int arr[], int n)
{
	// Hiệu chỉnh dãy số ban đầu thành heap
	creatFullHeap(arr,n);
	int L = 0; 
	int R = n-1;
	while (R>0)
	{
		swap(arr[0],arr[R]);
		R--;
		// Hiệu chỉnh phần còn lại của dãy thành một heap
		Shift(arr,L,R);
	}
}

int main()
{
	int arr[] = {44,55,12,42,94,18,6,67};
	int n = sizeof(arr)/sizeof(arr[0]);
	outputArray(arr,n);
	heapSort(arr,n);
	outputArray(arr,n);
}