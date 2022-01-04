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

void removeNode(LinkList& L,NodePointer& pre_node, NodePointer& cur_node)
{
	NodePointer tmp = cur_node;
	if (cur_node == L.Head)
	{
		L.Head = L.Head->Next;
		cur_node = cur_node->Next;
	}
	else
	{
		cur_node = cur_node->Next;
	 	pre_node->Next = cur_node;
	}
	tmp->Next = NULL;
	delete tmp;
}

LinkList removeAllNode(LinkList L, int value)
{
	if (isEmpty(L))
		return L;
	NodePointer cur_node = L.Head;
	NodePointer pre_node = NULL;
	while(cur_node != NULL)
	{
		if (cur_node->Data == value)
		{
			removeNode(L,pre_node,cur_node);
		}
		else
		{
			pre_node = cur_node;
			cur_node = cur_node->Next;
		}
	}
	return L;
}

int main(){
	LinkList L = createEmptyLinkList();
	pushBack(L,4);
	pushBack(L,5);
	pushBack(L,4);
	pushBack(L,4);
	pushBack(L,6);
	pushBack(L,4);
	exportLinkList(L);
	L = removeAllNode(L,4);
	exportLinkList(L);
}