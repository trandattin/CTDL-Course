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
// (d) Insertion Sort
//=============================

void sortedNode(LinkListC& L, int data)
{
	NodePointer add_node = createNode(data);
	NodePointer cur_node = L.Head;
	while(cur_node->Next != NULL && add_node->Data > cur_node->Next->Data)
	{
		cur_node = cur_node->Next;
	}
	add_node->Next = cur_node->Next;
	cur_node->Next = add_node;
	if (cur_node->Next == L.Tail)
	{
		L.Tail = add_node;
	}
}

void insertSort(LinkListC& L)
{
	LinkListC R = createEmptyLinkList();
	insertNode(R,L.Head->Next->Data,R.Tail);
	NodePointer cur_node = L.Head->Next->Next;

	while(cur_node != NULL)
	{
		sortedNode(R,cur_node->Data);
		cur_node = cur_node->Next;
	}
	L = R;
}

int main()
{
	LinkListC L = createEmptyLinkList();
	insertNode(L, 2, L.Tail);
	insertNode(L, -1, L.Tail);
	insertNode(L, 7, L.Tail);
	insertNode(L, 5, L.Tail);
	insertNode(L, 3, L.Tail);
	insertNode(L, 2, L.Tail);
	outputLinkList(L);
	insertSort(L);
	outputLinkList(L);

}