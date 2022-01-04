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

void mixLinkList(LinkList& C, NodePointer np, LinkList L)
{
	while(np != NULL)
	{
		C.Tail->Next = np; 
		C.Tail = np;
		np = np->Next;
	}
}

LinkList mergeLinkList(LinkList L1, LinkList L2)
{
	LinkList C = createEmptyLinkList();
	NodePointer first_list = L1.Head;
	NodePointer second_list = L2.Head;
	if (L1.Head->Data < L2.Head->Data)
	{
		C.Head = C.Tail = L1.Head;
		first_list = first_list->Next;
	}
	else
	{
		C.Head = C.Tail = L2.Head;
		second_list = second_list->Next;
	}
	while(first_list != NULL && second_list != NULL)
	{
		if(first_list->Data < second_list->Data)
		{
			C.Tail->Next = first_list;
			C.Tail = first_list;
			first_list = first_list->Next;
		}	
		else
		{
			C.Tail->Next = second_list;
			C.Tail = second_list;
			second_list = second_list->Next;
		}	
	}
	if(first_list == NULL)
		mixLinkList(C,second_list,L2);
	else if(second_list == NULL)
		mixLinkList(C,first_list,L1);
	return C;
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
	LinkList C = mergeLinkList(L1,L2);
	exportLinkList(C);
}