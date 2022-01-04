#include "stdio.h"
#include "math.h"

typedef int ElementType;

struct NodeType{
	ElementType x;
	ElementType i;
	NodeType* next;
};

typedef NodeType* NodePointer;

struct LinkedList{
	NodePointer Head;
	NodePointer Tail;
};

NodePointer createNode(ElementType x, ElementType i)
{
	NodePointer np = new NodeType;
	if (np == NULL)
		printf("Loi cap phat bo nho");
	else
	{
		np->x = x;
		np->i = i;
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
			printf("%d^%d + ",cur->x,cur->i);
		else
			printf("%d^%d",cur->x,cur->i);
		cur = cur->next;
	}
	return;
}

void insertLast(LinkedList& L, int x, int i)
{
	NodePointer np = createNode(x,i);
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
		sum += pow(cur->x,cur->i);
		cur = cur->next;
	}
    return sum;
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
	for (int i = 0; i <= n; i++)
	{
		insertLast(L,x,i);
	}
	printLinkedList(L);
	double sum = sumOfList(L);
	printf(" = %.2f",sum);
}