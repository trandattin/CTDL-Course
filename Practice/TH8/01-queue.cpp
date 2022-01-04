#include "stdio.h"
#include "string.h"
#include "math.h"
#include "iostream"

using namespace std;

typedef char ElementType;

struct NodeType {
	ElementType Text;
	NodeType* Next;
};

typedef NodeType* NodePointer;

struct Queue
{
	NodePointer Head;
	NodePointer Tail;
};

NodePointer createNode(ElementType x)
{
	NodePointer np;
	np = new NodeType;
	if (np == NULL)
		printf("Loi cap phat bo nho");
	else
	{
		np->Text = x;
		np->Next = NULL;
	}
	return np;
}

Queue createEmptyQueue()
{
	Queue Q;
	Q.Head = NULL;
	Q.Tail = NULL;
	return Q; 
}

bool isEmpty(Queue Q)
{
	if (Q.Head == NULL)
		return true;
	return false;
}

void enQueue(Queue& Q, ElementType x)
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
	printf("Enter Data ('q' to exit): ");
	do
	{
		fflush(stdin);
		scanf("%c",&x);
		if (x == 'q')
			break;
		enQueue(Q,x);
	}while(true);
	return Q;
}

int exportQueue(Queue Q)
{
	if (isEmpty(Q) == true) 
		return -1;
	NodePointer cur_node = Q.Head;
	while (cur_node != NULL)
	{
		printf("%c",cur_node->Text);
		cur_node = cur_node->Next;
	}
	printf("\n");
	return 1;	
}

NodePointer deQueue(Queue& Q)
{
	NodePointer np;
	np = Q.Head;
	Q.Head = Q.Head -> Next;
	return np; 
}

Queue computeSample(char sample[])
{
	Queue Q = createEmptyQueue();
	int len_sample = strlen(sample);
	for(int i = 0; i < len_sample; i++)
	{
		if (sample[i] == '*')
			deQueue(Q);
		else
			enQueue(Q,sample[i]);
	}
	return Q;
}

int main()
{
	char sample[100];
	gets(sample);
	Queue Q = computeSample(sample);
	exportQueue(Q);
}