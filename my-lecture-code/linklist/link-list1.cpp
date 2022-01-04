#include "stdio.h"

typedef int ElementType;

typedef struct node
{
	ElementType Data;
	node* Next;
} NodeType;

typedef NodeType* NodePointer;

struct LinkList{
	NodePointer Tail,Head;
};

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

LinkList createEmptyLL()
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

int exportLL(LinkList L)
{
	if (isEmpty(L) == true)
		return -1;
	NodePointer cur = L.Head;
	while(cur != NULL)
	{
		printf("%d ", cur->Data);
		cur = cur->Next;
	}
	printf("\n");
	return 1;
}


void pushBack(LinkList& L, ElementType x)
{
	NodePointer np = createNodeLL(x);
	if (isEmpty(L))
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
	LinkList L;
	L = createEmptyLL();
	printf("Enter data: \n"); 
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

NodePointer searchPreNode(LinkList L, ElementType x, NodePointer& np)
{
	NodePointer np_Pre = NULL;
	if (isEmpty(L))
	{
		printf("EMPTY LIST\n");
		return np_Pre;
	}
	while(np != NULL)
	{
		if(np->Data == x)
			break;
		np_Pre = np;
		np = np->Next;
	}
	return np_Pre;
}

int removeNodeLL(LinkList& L, ElementType x)
{
	NodePointer np_Del = L.Head;
	NodePointer np_Pre = searchPreNode(L, x, np_Del);

	// Không tìm thấy số cần xoá
	if (np_Del == NULL)
		printf("The Value need to remove not in current list");
	else
	{
		if (np_Del == L.Head)
		{
			L.Head = L.Head->Next;
			np_Del->Next = NULL;
			delete np_Del;
		}

		else if (np_Del == L.Tail)
		{
			L.Tail = np_Pre; 
			np_Pre->Next = NULL;
			delete np_Del;
		}
		else
		{
			np_Pre->Next = np_Del->Next;
			np_Del->Next = NULL;
			delete np_Del;
		}
	}
	return 0;
}

int main()
{
	LinkList L = createEmptyLL();

	pushBack(L, 5);
	pushBack(L, 6);
	pushBack(L, 7);
	pushBack(L, 8);
	exportLL(L);

	removeNodeLL(L,6);
	exportLL(L);
}

