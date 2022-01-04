#include "stdio.h"
#include "math.h"

typedef int ElementType;

typedef struct Node {
	ElementType Data;
	Node* Next;
} NodeType;

typedef NodeType* NodePointer;

struct Stack{
	NodePointer Head;
};

Stack createEmptyStack()
{
	Stack S;
	S.Head = NULL;
	return S;
}

bool isEmpty(Stack S)
{
	if (S.Head == NULL)
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

void Push(Stack& S, ElementType x)
{
	NodePointer np = createNode(x);
	if (S.Head == NULL)
	{
		S.Head = np;
	}
	else
	{
		np->Next = S.Head;
		S.Head = np;
	}
}

Stack createStack()
{
	Stack S = createEmptyStack();
	ElementType x;
	printf("Enter Data: ");
	do
	{
		scanf("%d",&x);
		if (x == -1)
			break;
		Push(S,x);
	}while(true);
	return S;
}

int exportStack(Stack S)
{
	if (isEmpty(S) == true) 
		return -1;
	NodePointer cur_node = S.Head;
	while (cur_node != NULL)
	{
		printf("%d ",cur_node->Data);
		cur_node = cur_node->Next;
	}
	printf("\n");
	return 1;	
}

NodePointer Pop(Stack& S)
{
	NodePointer np;
	np = S.Head;
	S.Head = S.Head -> Next;
	return np; 
}

NodePointer Top(Stack S)
{
	return S.Head; 
}

void coso2(int n)
{
	Stack S = createEmptyStack();
	if (n == 0 )
	{
		Push(S,0);
		return;
	}
	while(n != 0)
	{
		Push(S,n%2);
		n = n / 2;
	}
	exportStack(S);
}

void coso8(int n)
{
	Stack S = createEmptyStack();
	if (n == 0 )
	{
		Push(S,0);
		return;
	}
	while(n != 0)
	{
		Push(S,n%8);
		n = n / 8;
	}
	exportStack(S);
}

int main()
{
	coso2(10);
	coso8(2764);
}