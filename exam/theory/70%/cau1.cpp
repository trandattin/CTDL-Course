//Tran Dat Tin
//TNK44
//2011345

#include <stdio.h>

typedef int array[100];

// a)

void inputArray(array a, int& n ){
	printf("size array a: ");
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		printf("a[%d] = ",i+1);
		scanf("%d",&a[i]);
	}
}

void outputArray(array a,int n){
	printf("**Output Array**\n");
	for (int i = 0; i<n; i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}

//b)
int findMax(array a, int n)
{
	int res = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > res)
			res = a[i];
	}
	return res;
}

//c)

bool check(int n){
    int sum = 0;//khai bao biem sum
    for(int i = 1; i <= n/2 ; i++){
        if(n % i == 0) 
            sum += i;
    }
    if(sum == n) return true; // tra ve true
    return false;
}

void TimSoHoanChinh(array a, int n)
{
	printf("So hoan chinh trong mang A: ");
	for (int i = 0; i<n; i++)
	{
		if (check(a[i]) == true)
		{
			printf("%d ",a[i]);
		}
	}
	printf("\n");
}

// d)

void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

int minIndex(int a[], int i, int n, int& co) 
{
	int co = 1;
    int min_index = i;
    for (int j=i+1; j<n; j++)
        if (a[j] < a[min_index] && a[j] % 2 == 0)
            min_index = j;
	if (a[min_index] % 2 != 0)
		co = -1;
    return min_index;
}

void selectSort(int arr[], int n)
{
    int i, min_index, co;
    for (i = 0; i < n - 1; i++)
    {
		min_index = minIndex(arr, i+1, n, co);
		if (co == -1)
			break;
        if (arr[min_index] < arr[i])
            swap(arr[min_index], arr[i]);
    }
}

int main(){
	array a;
	int n;
	inputArray(a,n);
	outputArray(a,n);
	selectSort(a,n);
	outputArray(a,n);

	LL L1= TaoDSRong();
	LL L2 ;
	int x,y;
	int choice = -1;
    while (choice != 0)
    {
        printf("What do you want to do?\n");
        printf("[0] Exit\n");
        printf("[1] Chen Cuoi vao L1\n");
        printf("[2] Tim trong L1 va xuat ra gia tri chan dau tien lon hon X \n");
        printf("[3] Chen L2 vao L1 sau mot gia tri chan dau tien lon hon X trong L1\n");
        printf("[4] Xoa hai nut dau tien co du lieu nho hon X cho truoc trong L1\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            return 0;
            break;

        case 1:
			printf("X = ");
			scanf("%d",&x);
			ChenCuoi(L1,x);
			break;

        case 2:
			printf("X = ");
			scanf("%d",&x);
            findValue(L1,x);

        case 3:
			printf("Nhap du lieu L2");
			L2 = TaoDS();
			printf("X = ");
			scanf("%d",&x);
			ChenDanhSach(L1,L2,x);
			printf("Before\n");
			XuatDS(L1);
			printf("After\n");
			XuatDS(L1);
            break;

        case 4:
			printf("X = ");
			scanf("%d",&x);
			printf("Before\n");
			XuatDS(L1);
			L1 = removeTwoNode(L1,x);
			printf("After\n");
			XuatDS(L1);
            break;

        default:
            // do nothing, just loop again
            break;
        }
        printf("\n\n");
    }
}