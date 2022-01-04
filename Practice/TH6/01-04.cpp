#include "stdio.h"

typedef int ElementType;

typedef struct node {
	ElementType Data;
	node* Next;
} NodeType;

typedef NodeType* NodePointer;

struct LinkList {
	NodePointer Head,Tail;
};

LinkList createEmptyLinkList()
{
	LinkList L;
	L.Head = NULL;
	L.Tail = NULL;
	return L;
}

bool isEmpty(LinkList L)
{
	if (L.Head == NULL)
		return true;
	return false;
}

NodePointer createNodeLL(ElementType x)
{
	NodePointer np;
	np = new NodeType;
	if (np == NULL)
		printf("Loi cap phat bo nho");
	else
	{
		np->Data = x;
		np->Next = NULL;
	}
	return np;
}

void pushBack(LinkList& L, ElementType x)
{
	NodePointer np = createNodeLL(x);
	if (isEmpty(L) == true)
	{
		L.Head = np;
		L.Tail = np;
	}
	else
	{
		L.Tail->Next = np;
		L.Tail = np;
	}
}

LinkList createLinkList()
{
	LinkList L = createEmptyLinkList();
	printf("Enter data: \n");
	do
	{
		ElementType x;
		scanf("%d", &x);
		if (x == -1)
			break;
		pushBack(L,x);
	} while(true);
	return L;
}

ElementType exportLinkList(LinkList L)
{
	if (isEmpty(L) == true)
		return -1;
	NodePointer cur = L.Head;
	while(cur != NULL)
	{
		printf("%d ",cur->Data);
		cur = cur->Next;
	}
	printf("\n");
	return 1;
}

LinkList copyLinkList(LinkList L)
{
	LinkList L2 = createEmptyLinkList();
	if (isEmpty(L) == true)
		return L2;

	NodePointer cur = L.Head;
	while(cur != NULL)
	{
		pushBack(L2,cur->Data);
		cur = cur->Next;
	}
	return L2;
}

LinkList connectLinkList(LinkList L1, LinkList L2)
{
	LinkList L3 = createEmptyLinkList();
	if (isEmpty(L1) == true && isEmpty(L2) == false)
	{
		L3 = copyLinkList(L1);
		return L3;
	}
	if (isEmpty(L1) == false && isEmpty(L2) == true)
	{
		L3 = copyLinkList(L2);
		return L3;
	}
	if (isEmpty(L1) == true && isEmpty(L2) == true)
		return L3;
	L3 = copyLinkList(L1);
	NodePointer cur = L2.Head;
	while(cur != NULL)
	{
		pushBack(L3,cur->Data);
		cur = cur->Next;
	}
	return L3;
}

int countElement(LinkList L)
{
	int count = 0;
	NodePointer cur = L.Head;
	while(cur != NULL)
	{
		cur = cur->Next;
		count++;
	}
	return count;
}

int main(){
	LinkList L1 = createLinkList();
	exportLinkList(L1);
	printf("Count %d \n",countElement(L1));
}