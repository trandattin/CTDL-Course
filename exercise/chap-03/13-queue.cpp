#include "stdio.h"

typedef int ElementType;

typedef struct Node
{
	ElementType Data;
	Node *Next;
} NodeType;

typedef NodeType *NodePointer;

struct Queue
{
	NodePointer Head;
	NodePointer Tail;
};

Queue createEmptyQueue()
{
	Queue Q;
	Q.Head = Q.Tail = NULL;
	return Q;
}

bool isEmpty(Queue Q)
{
	if (Q.Head == NULL)
		return true;
	return false;
}

NodePointer createNode(ElementType x)
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

//Pussh
void enQueue(Queue &Q, ElementType x)
{
	NodePointer np = createNode(x);
	if (isEmpty(Q))
	{
		Q.Head = np;
		Q.Tail = np;
	}
	else
	{
		Q.Tail->Next = np;
		Q.Tail = np;
	}
}

Queue createQueue()
{
	Queue Q = createEmptyQueue();
	ElementType x;
	printf("Enter Data: ");
	do
	{
		scanf("%d", &x);
		if (x == -1)
			break;
		enQueue(Q, x);
	} while (true);
	return Q;
}

int exportQueue(Queue Q)
{
	if (isEmpty(Q) == true)
		return -1;
	NodePointer cur_node = Q.Head;
	while (cur_node != NULL)
	{
		printf("%d ", cur_node->Data);
		cur_node = cur_node->Next;
	}
	printf("\n");
	return 1;
}

NodePointer deQueue(Queue& Q)
{
	NodePointer np;
	np = Q.Head;
	Q.Head = Q.Head->Next;
	return np;
}

void reverseQueue(Queue& Q)
{
	if (isEmpty(Q))
		return;

	NodePointer np = deQueue(Q);
	reverseQueue(Q);
	enQueue(Q,np->Data);
}

int main()
{
	Queue Q = createQueue();
	exportQueue(Q);
	reverseQueue(Q);
	exportQueue(Q);
}