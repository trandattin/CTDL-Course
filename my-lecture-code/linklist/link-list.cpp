#include "stdio.h"

typedef int ElementType;

typedef struct node
{
	ElementType Data;
	struct node* Next; 
}NodeType;

typedef NodeType* NodePointer;

struct LinkList
{
	NodePointer Head, Tail;
};

NodePointer createNodeLL(ElementType x)
{
	NodePointer np;
	// Cấp phát bộ nhớ
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

bool isEmptyLL(LinkList L)
{
	if(L.Head == NULL)
		return true;
	return false;
}

int exportLL(LinkList L)
{
	if (isEmptyLL(L) == true) 
		return -1;
	NodePointer cur = L.Head;
	while(cur != NULL)
	{
		printf("%d ",cur->Data);
		cur = cur->Next;
	}
	return 1;
}

void pushBack(LinkList& L, ElementType x)
{
	NodePointer np;
	np = createNodeLL(x);
	if (isEmptyLL(L))
	{
		L.Head = np;
		L.Tail = np;
	}
	else
	{
		L.Tail->Next = np; // Trỏ next của Tail tới np (móc lai)
		L.Tail = np; // Gán danh hiệu
	}
}

void pushHead(LinkList& L, ElementType x)
{
	NodePointer np;
	np = createNodeLL(x);
	if (isEmptyLL(L))
	{
		L.Head = np;
		L.Tail = np;
	}
	else
	{
		np->Next = L.Head; // Trỏ next của Tail tới np (móc lai)
		L.Head = np; // Gán danh hiệu
	}
}

LinkList createLinkList()
{
	LinkList L;
	L = createEmptyLL();
	do
	{
		ElementType x;
		printf("Enter data: ");
		scanf("%d", &x);
		if (x == -1) 
			break;
		pushBack(L,x);
	} while (true);
	return L;
}

void insertNodeAfterNode(LinkList& L, ElementType x, NodePointer P)
{
	NodePointer np;
	np = createNodeLL(x);
	// if (isEmptyLL(L))
	// {
	// 	L.Head = np;
	// 	L.Tail = np;
	// }
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

int main()
{
	LinkList L;
	L = createLinkList();
	exportLL(L);
	return 0;
}