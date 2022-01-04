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
	return 0;
}

void reverseLinkList(LinkList& L)
{
	LinkList L2 = createEmptyLinkList();
	NodePointer cur_node = L.Head;
	NodePointer prev_node,next_node = NULL;
	while(cur_node != NULL)
	{
		next_node = cur_node->Next;
		cur_node->Next = prev_node;
		prev_node = cur_node;
		cur_node = next_node;
	}
	L.Head = prev_node;
}

int main(){
	LinkList L = createEmptyLinkList();
	pushBack(L,3);
	pushBack(L,5);
	pushBack(L,4);
	pushBack(L,5);
	pushBack(L,7);
	exportLinkList(L);
	reverseLinkList(L);
	exportLinkList(L);
}