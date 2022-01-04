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
// (a) Find Local min and local max
//=============================

void localMax(LinkList L)
{
	NodePointer next_node = L.Head->Next;
	NodePointer cur_node = L.Head;
	int pre_value = -1;
	printf("Max Local: ");
	// TH 1 element
	if (L.Head == L.Tail)
		printf("%d ",cur_node->Data);
	while(next_node != NULL)
	{
		//  TH Head
		if (pre_value == -1 && cur_node->Data >= next_node->Data)
		{
			printf("%d ",cur_node->Data);
		}
		// TH Giữa
		else if (cur_node->Data >= pre_value && cur_node->Data >= next_node->Data)
		{
			printf("%d ",cur_node->Data);
		}
		// TH Tail
		if (next_node == L.Tail && cur_node->Data <= next_node->Data)
		{
			printf("%d ",next_node->Data);
		} 
		pre_value = cur_node->Data;
		cur_node = next_node;
		next_node = next_node->Next;
	}
	printf("\n");
}

void localMin(LinkList L)
{
	NodePointer next_node = L.Head->Next;
	NodePointer cur_node = L.Head;
	int pre_value = -1;
	printf("Min Local: ");
	if (L.Head == L.Tail)
		printf("%d ", cur_node->Data);
	while(next_node != NULL)
	{
		if (pre_value == -1 && cur_node->Data <= next_node->Data)
		{
			printf("%d ",cur_node->Data);
		}
		else if (cur_node->Data <= pre_value && next_node->Data >= cur_node->Data)
		{
			printf("%d ", cur_node->Data);
		}
		if (next_node == L.Tail && next_node->Data <= cur_node->Data)
		{
			printf("%d ", next_node->Data);
		}
		pre_value = cur_node->Data;
		cur_node = next_node;
		next_node = next_node->Next;
	}
	printf("\n");
}

//=============================
// (b) Delete similar number
//=============================

void removeNode(LinkList& L, NodePointer cur_node, NodePointer& move_node)
{
	NodePointer prev_node = cur_node;
	NodePointer del_node;
	while (move_node != NULL)
	{
		if(cur_node->Data == move_node->Data)
		{
			del_node = move_node;
			move_node = move_node->Next;
			prev_node->Next = move_node;
			del_node->Next = NULL;
			delete del_node;
		}		
		else
		{
			prev_node = move_node;
			move_node = move_node->Next;
		}
		
	}
}

void removeMain(LinkList& L)
{
	NodePointer cur_node = L.Head;
	NodePointer move_node = cur_node->Next;
	while(move_node != NULL)
	{
		removeNode(L,cur_node,move_node);
		cur_node = cur_node->Next;
		if(cur_node != NULL){
			move_node = cur_node->Next;
		}
	}
}

//=============================
// (c) Replace a prime by a next prime number
//=============================

bool isPrime(int num)
{
	int i = 2;
	if (num <= 1) return false;
	while (num%i != 0) 
        i++;
	return (i==num);
}

int nextPrime(int num)
{
	num += 1;
	while(isPrime(num) == false)
	{
		num += 1;
	}
	return num;
}

void replacePrime(LinkList& L)
{
	int tmp;
	NodePointer cur_node = L.Head;
	while(cur_node != NULL)
	{
		if (isPrime(cur_node->Data)){
			tmp = nextPrime(cur_node->Data);
			cur_node->Data = tmp;
		}
		cur_node = cur_node->Next;
	}
}

int main()
{
	LinkList L = createEmptyLinkList();
	addTail(L,5);
	addTail(L,3);
	addTail(L,7);
	outputLinkList(L);
	// localMax(L);
	// localMin(L);
	// removeMain(L);
	replacePrime(L);
	outputLinkList(L);
}