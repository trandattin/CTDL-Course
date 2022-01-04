#include "stdio.h"
#include "math.h"

typedef int ElementType;

struct NodeType{
	ElementType tu;
	ElementType mau;
	NodeType* next;
};

typedef NodeType* NodePointer;

struct LinkedList{
	NodePointer Head;
	NodePointer Tail;
};

NodePointer createNode(ElementType tu, ElementType mau)
{
	NodePointer np = new NodeType;
	if (np == NULL)
		printf("Loi cap phat bo nho");
	else
	{
		np->tu = tu;
		np->mau = mau;
		np->next = NULL;
	}
	return np;
}

LinkedList createEmptyLinkList()
{
	LinkedList L;
	L.Head = L.Tail = NULL;
	return L;
}

bool isEmpty(LinkedList L)
{
	if (L.Head == NULL)
		return true;
	return false;
}

void printLinkedList(LinkedList L)
{
	if (isEmpty(L)) 
		return;
	NodePointer cur = L.Head;
	while(cur != NULL)
	{
		if (cur->next != NULL)
			printf("%d/%d + ",cur->tu,cur->mau);
		else
			printf("%d/%d",cur->tu,cur->mau);
		cur = cur->next;
	}
	return;
}

void insertLast(LinkedList& L, int tu, int mau)
{
	NodePointer np = createNode(tu,mau);
	if(L.Head == NULL)
	{
		L.Head = np;
		L.Tail = np;
	}
	else
	{
		L.Tail->next = np;
		L.Tail = np;
	}
}

/* Hàm tính tổng */
double sumOfList(LinkedList L)
{
    double sum = 0;
    NodePointer cur = L.Head;
	while(cur != NULL)
	{
		sum += (cur->tu*1.0/cur->mau);
		cur = cur->next;
	}
    return sum;
}

float permutation(int x)
{
	float s = 1;
	for (int i  = 1; i <= x; i++)
	{
		s = s*i;
	}
	return s;
}

int main()
{
	LinkedList L = createEmptyLinkList();
	printLinkedList(L);
	int n,x;
	printf("n = ");
	scanf("%d",&n);
	printf("x = ");
	scanf("%d",&x);
	for (int i = 1; i <= n; i++)
	{
		int tu = pow(x,i);
		int mau = permutation(i);
		insertLast(L,tu,mau);
	}
	printLinkedList(L);
	double sum = sumOfList(L);
	printf(" = %.2f",sum);
}