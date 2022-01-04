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

void insertNode(NodePointer cur_node, NodePointer add_node)
{
	add_node->Next = cur_node->Next;
	cur_node->Next	= add_node;
}

void mergeLinkList2(LinkList& L1, LinkList& L2)
{
	NodePointer first_point,second_point;
	LinkList* p1;
	if (L1.Head->Data < L2.Head->Data){
		p1 = &L1;
		first_point = L1.Head;
		second_point = L2.Head;
	}
	else
	{
		p1 = &L2;
		first_point = L2.Head;
		second_point = L1.Head;
	}
	int count = 0;
	NodePointer next_first_point = first_point->Next;
	NodePointer next_second_point = second_point->Next;
	do{
		while(second_point->Data > next_first_point->Data){
			first_point = first_point->Next;
			next_first_point = next_first_point->Next;
		}
		insertNode(first_point,second_point);
		first_point = first_point->Next;
		second_point = next_second_point;
		next_second_point = next_second_point->Next;
	}while(true);
}

int main()
{
	LinkList L1 = createEmptyLinkList();
	pushBack(L1,1);
	pushBack(L1,2);
	pushBack(L1,9);
	LinkList L2 = createEmptyLinkList();
	pushBack(L2,5);
	pushBack(L2,6);
	pushBack(L2,10);
	exportLinkList(L1);
	exportLinkList(L2);
	mergeLinkList2(L1,L2);
	exportLinkList(L1);
	exportLinkList(L2);
}