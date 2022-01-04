#include "stdio.h"
#include "string.h"

struct Student {
	char name[100];
	int birth;
	char email[100];
};

void printStudent(Student A){
    printf("Name: %s\n",A.name);
    printf("Birth year: %d\n",A.birth);
    printf("Email: %s\n",A.email);
}

void printClass(Student TNK44[], int n)
{
	for(int i = 0; i < n; i++)
	{
		printStudent(TNK44[i]);
		printf("\n");
	}
}

void searchName(Student TNK44[], int n, char name_search[])
{
	for (int i = 0; i < n; i++){
		if (strcmp(TNK44[i].name,name_search) == 0)
		{
			printStudent(TNK44[i]);
		}
	}
	printf("\n");
}

void swap(Student* x1, Student* x2){
    Student tmp = *x1; 
    *x1 = *x2;
    *x2 = tmp;
}

// SHAKER SORT
void sortName(Student TNK44[], int n)
{
	// Từ left đến right là đoạn cần sắp xếp
	int left = 0;
	int right = n-1;
	// Ghi nhận ví trí k xảy ra hoán vị sau cùng
	// Để làm cơ sở thu hẹp đoạn left - right
	int k = 0; 
	while(left < right)
	{
		for(int i = left; i < right; i++)
		{
			if (strcmp(TNK44[i].name,TNK44[i+1].name) > 0)
			{
				swap(&TNK44[i],&TNK44[i+1]);
				k = i;
			}
		}
		right = k;
		for (int i = right; i > left; i--)
		{
			if (strcmp(TNK44[i].name,TNK44[i-1].name) < 0)
			{
				swap(&TNK44[i],&TNK44[i-1]);
			}
		}
		left = k;
	}
}

//QUICK SORT
void Partialize(Student TNK44[], int left, int right, int n)
{
	int i = left;
	int j = right;
	int mid = (left+right)/2;
	do
	{ 
		while(strcmp(TNK44[i].email,TNK44[mid].email) < 0) i++;
		while(strcmp(TNK44[j].email,TNK44[mid].email) > 0) j--;
		if (i <= j) // a[j] < a[mid] < a[i] mà a[i] đứng sau a[j]
		{
			swap(&TNK44[i],&TNK44[j]);
			i++;
			j--;
		}
	} while (i <= j); // Chưa hết mảng
	if (left < j) Partialize(TNK44,left,i,n);
	if (right > i) Partialize(TNK44,j,right,n);
}

void sortMail(Student TNK44[], int n)
{
	Partialize(TNK44,0,n-1,n);
}

// BINARY INSERT SORT
int binarySearch(Student TNK44[], int selected, int low, int high)
{
	if (high <= low)
		return (selected > TNK44[low].birth) ? (low + 1) : low;
	
	int mid = (low + high) / 2;

	if (selected == TNK44[mid].birth)
		return mid + 1;
	if (selected > TNK44[mid].birth)
		return binarySearch(TNK44,selected,mid+1,high);
	return binarySearch(TNK44,selected,low,mid-1);
}

void sortBirth(Student TNK44[], int n)
{
	int j, selected, loc;
	for (int i = 1; i < n; i++)
	{
		j = i - 1;
		Student selected = TNK44[i];

		// find location 
		loc = binarySearch(TNK44,selected.birth,0,j);
		while (j >= loc)
		{
			TNK44[j+1] = TNK44[j];
			j--;
		}
		TNK44[j+1] = selected; 
	}
}

int main()
{
	Student TNK44[100];
	// Tin
	strcpy(TNK44[0].name,"Tran Dat Tin");
	TNK44[0].birth = 2000;
	strcpy(TNK44[0].email,"201039995@dlu.edu.vn");
	// Thanh
	strcpy(TNK44[1].name, "Tran Duy Thanh");
	TNK44[1].birth = 1991;
	strcpy(TNK44[1].email,"2015380@dlu.edu.vn");
	// Trong
	strcpy(TNK44[2].name, "Nguyen Huu Trong");
	TNK44[2].birth = 2003;
	strcpy(TNK44[2].email,"2011346@dlu.edu.vn");
	int n = 3;
	printClass(TNK44,n);

	// SEARCH NAME
	char name_search[100];
	strcpy(name_search,"Tran Dat Tin");
	printf("SEARCHING FOR \"%s\" \n...\n",name_search);
	searchName(TNK44,n,name_search);

	// SORT BY NAME
	printf("SORTING BY NAME\n");
	sortName(TNK44,n); 
	printClass(TNK44,n);

	//SORT BY EMAIL
	printf("SORTING BY EMAIL\n");
	sortMail(TNK44,n);
	printClass(TNK44,n);

	//SORT BY BIRTH
	printf("SORTING BY BIRTH\n");
	sortBirth(TNK44,n);
	printClass(TNK44,n);
}