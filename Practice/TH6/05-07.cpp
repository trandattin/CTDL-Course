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

ElementType findElement(LinkList L, int index)
{
	int count = 0;
	if (isEmpty(L) == true)
		return -1;
	NodePointer cur = L.Head;
	while(count < index && cur->Next != NULL)
	{
		cur = cur -> Next;
		count++;
	}
	if (count < index) 
		return -1;
	return cur->Data;
}

void insertNodeAfterNode(LinkList& L, ElementType x, NodePointer P)
{
	NodePointer np;
	np = createNodeLL(x);
	if (isEmpty(L))
	{
		L.Head = np;
		L.Tail = np;
	}
	if (P == NULL)
	{
		np->Next = L.Head; // Trỏ next của Tail tới np (móc lai)
		L.Head = np; // Gán danh hiệu
	}
	else
	{
		np->Next = P->Next;
		P->Next = np;
	} 
	if (P == L.Tail)
		L.Tail = np;
}

LinkList addAllElement(LinkList L, int value)
{
	if (isEmpty(L) == true)
		return L;
	NodePointer cur = L.Head;
	while(cur != NULL)
	{
		if (cur->Data == value)
			insertNodeAfterNode(L,-1,cur);
		cur = cur->Next;
	}
	return L;
}

int main()
{
	LinkList L = createLinkList();
	exportLinkList(L);
}