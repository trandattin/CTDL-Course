#include "stdio.h"
#include "math.h"

typedef int ElementType;

struct NodeType{
	ElementType Data;
	NodeType* Next;
};

typedef NodeType* NodePointer;

struct LinkListC{
	NodePointer Head, Tail;
};

NodePointer createNode(ElementType x)
{
	NodePointer np = new NodeType;
	if (np == NULL)
		printf("Loi cap phat bo nho");
	else
	{
		np->Data = x;
		np->Next = NULL;
	}
	return np;
}

NodePointer createNodeMute()
{
	NodePointer np = new NodeType;
	if (np == NULL)
		printf("Loi cap phat bo nho");
	else
		np->Next = NULL;
	return np;
}

LinkListC createEmptyLinkList()
{
	LinkListC L;
	L.Head = createNodeMute();
	L.Tail = L.Head;
	return L;
}

bool isEmpty(LinkListC L)
{
	if (L.Head->Next == NULL)
		return true;
	return false;
}

void insertNode(LinkListC& L, ElementType x, NodePointer PredNode)
{
	NodePointer np = createNode(x);
	np->Next = PredNode->Next;
	PredNode->Next = np;
	if (PredNode  == L.Tail) 
		L.Tail = np;
}

LinkListC createLinkList()
{
	LinkListC L = createEmptyLinkList();
	printf("Enter Data: \n");
	do
	{
		ElementType x;
		scanf("%d",&x);
		if (x == -1)
			break;
		insertNode(L,x,L.Tail);
	} while (true);
	return L;
}

void outputLinkList(LinkListC L)
{
	if (isEmpty(L))
		return;
	NodePointer cur = L.Head->Next;
	while(cur != NULL)
	{
		printf("%d ",cur->Data);
		cur = cur -> Next;
	}
	printf("\n");
}

//=============================
// (e)
//=============================

void insertElement(LinkListC& L,int x)
{
	NodePointer cur_node = L.Head->Next;
	NodePointer add_node = createNode(x);
	int k = 0;
	if (x >= cur_node->Data)
	{
		L.Head->Next = add_node;
		add_node->Next = cur_node;
		return;
	}
	while(cur_node->Next != NULL)
	{
		if(x <= cur_node->Data && x >= cur_node->Next->Data)
			{
				add_node->Next = cur_node->Next;
				cur_node->Next = add_node;
				k = 1;
				break;
			}
		cur_node = cur_node -> Next;
	}
	if (k != 1)
	{
		cur_node->Next = add_node;
		L.Tail = add_node;
	}
}

void insertArray(LinkListC& L, int a[], int n)
{
	for(int i = 0; i < n; i++)
		insertElement(L,a[i]);
}

int main()
{
	LinkListC L = createEmptyLinkList();
	insertNode(L, 9, L.Tail);
	insertNode(L, 3, L.Tail);
	insertNode(L, 1, L.Tail);
	outputLinkList(L);
	int a[] = {1,4,7,10};
	int n = sizeof(a)/sizeof(a[0]);
	insertArray(L,a,n);
	outputLinkList(L);
}