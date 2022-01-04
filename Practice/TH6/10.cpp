#include "stdio.h"

typedef int ElementType;

struct NodeType{
	ElementType Data;
	NodeType* Next;
};

typedef NodeType* NodePointer;

struct LinkList {
	NodePointer Head;
	NodePointer Tail;
};

NodePointer createNode(ElementType x)
{
	NodePointer np = new NodeType;
	if (np == NULL)
	{
		printf("Loi cap phat bo nho");
	} 
	else
	{
		np->Data = x;
		np->Next = NULL;
	}
	return np;
}

LinkList createEmptyLinkList()
{
	LinkList L;
	L.Head = L.Tail = NULL;
	return L;
}

bool isEmpty(LinkList L)
{
	if (L.Head == NULL)
		return true;
	return false;
}

void pushBack(LinkList& L, ElementType x)
{
	NodePointer np = createNode(x);
	if (isEmpty(L))
	{
		L.Head = L.Tail = np;
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
	printf("Enter data: ");
	do
	{
		ElementType x;
		scanf("%d", &x);
		if (x == -1)
			break;
		pushBack(L,x);
	} while (true);
	return L;
}

int exportLinkList(LinkList L)
{
	if (isEmpty(L))
		return -1;
	NodePointer cur_node = L.Head;
	while(cur_node != NULL)
	{
		printf("%d ",cur_node->Data);
		cur_node = cur_node->Next;
	}
	printf("\n");
	return 1;
}

int main()
{
	LinkList L1 = createLinkList();
	exportLinkList(L1);
	LinkList L2 = createLinkList();
	exportLinkList(L2);
}