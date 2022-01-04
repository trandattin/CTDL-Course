#include "stdio.h"
#include "math.h"

typedef int ElementType;

typedef struct Node{
	ElementType Data;
	Node* Next;
}NodeType;

typedef NodeType* NodePointer;

struct LinkList{
	NodePointer Head;
	NodePointer Tail;
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

void addTail(LinkList& L, ElementType x)
{
	NodePointer np = createNode(x);	
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
	LinkList L = createEmptyLinkList();
	printf("Enter Data: \n");
	do
	{
		ElementType x;
		scanf("%d",&x);
		if (x == -1)
			break;
		addTail(L,x);
	} while (true);
	return L;
}

int outputLinkList(LinkList L)
{
	if (isEmpty(L))
		return -1;
	NodePointer cur = L.Head;
	while(cur != NULL)
	{
		printf("%d ",cur->Data);
		cur = cur -> Next;
	}
	printf("\n");
	return 1;
}

//=============================
// (d) Selection Sort
//=============================

void swap(NodePointer& a, NodePointer& b)
{
	int tmp = a->Data;
	a->Data = b->Data;
	b->Data = tmp;
}

NodePointer findMinNode(LinkList L, NodePointer begin_node)
{
	NodePointer move_node = begin_node->Next;
	NodePointer min_node = begin_node; 
	while(move_node != NULL) 
	{
		if(move_node->Data < min_node->Data){
			min_node = move_node;
		}
		move_node = move_node->Next;
	}
	return min_node;
}

void selectSort(LinkList& L)
{
	NodePointer cur_node = L.Head;
	NodePointer move_node = cur_node->Next;
	NodePointer tmp_node;
	while(move_node != NULL)
	{
		tmp_node = findMinNode(L,move_node);
		if (tmp_node->Data < cur_node->Data)
			swap(tmp_node,cur_node);

		cur_node = cur_node->Next;
		move_node = move_node -> Next;
	}
}

int main()
{
	LinkList L = createEmptyLinkList();
	addTail(L, 5);
	addTail(L, 4);
	addTail(L, 3);
	addTail(L, 6);
	addTail(L, 2);
	addTail(L, 1);
	
	selectSort(L);
	outputLinkList(L);
}