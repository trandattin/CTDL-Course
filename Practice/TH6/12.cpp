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

void swap(NodePointer a, NodePointer b)
{
	ElementType tmp = a->Data;
	a->Data = b->Data;
	b->Data = tmp;
}

void bubleSort(LinkList& L)
{
	int swapped;
	NodePointer node_left;
	NodePointer node_right = NULL;
	do
	{
		swapped = 0;
		node_left = L.Head;
		// TH NULL
		while(node_left->Next != node_right)
		{
			if(node_left->Data >node_left->Next->Data)
			{
				swap(node_left,node_left->Next);
				swapped = 1;
			}
			node_left = node_left->Next;
	    }
		node_right = node_left;
	} while (swapped);
	
}

int main()
{
	LinkList L = createLinkList();
	exportLinkList(L);
	bubleSort(L);
	exportLinkList(L);
}