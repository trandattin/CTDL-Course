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

void swap(int& a, int& b)
{
	int t = a; a = b; b = t;
}

// Sắp một phần tử vào một Heap tạo thành một Heap
void Shift(int arr[], int L, int R,int n)
{
	int dad_index = L;
	int son_index = 2 * dad_index;
	int isHeap = 0;
	int dad_value = arr[dad_index];
	while(isHeap != 1 && son_index <= R)
	{
		if (son_index < R) // Nếu cha có 2 con phải thì tìm con lớn nhất
			if (arr[son_index] < arr[son_index+1])
				son_index++;
		if (dad_value >= arr[son_index]){
			isHeap = 1;
		}
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
	//arr[dad_index] = dad_value;
}

void createFullHeap(int arr[], int n)
{
	int L = (n/2);
	int R = n-1;
	while (L >= 0)
	{	
		// Sắp arr[L] vào một Heap tạo thành một Heap
		Shift(arr,L,R,n);
		L--;
	}
	return;
}

void heapSort(int arr[], int n)
{
	// Hiệu chỉnh dãy số ban đầu thành heap
	createFullHeap(arr,n);
	int L = 0;
	int R = n-1;
	while(R>0)
	{
		swap(arr[0],arr[R]);
		R--;
		// Hiệu chỉnh phần còn lại của dãy thành một heap
		Shift(arr,L,R,n);
	}
}


int main()
{
	int arr[] = {1,55,12};
	int n = sizeof(arr)/sizeof(arr[0]);
	printArray(arr,n);
	heapSort(arr,n);
	printArray(arr,n);
}