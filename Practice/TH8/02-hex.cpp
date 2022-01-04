#include "stdio.h"
#include "math.h"

typedef char ElementType;

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
		fflush(stdin);
		scanf("%c",&x);
		if (x == 'q')
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
		printf("%c",cur_node->Data);
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

void hexEncode(int n)
{
	Stack S = createEmptyStack();
	if (n == 0 )
	{
		Push(S,0);
		return;
	}
	int i = 0;
	char tmp;
	while(n != 0)
	{
		if (n%16 > 9)
		{
			tmp = (n%16)+55;
			Push(S,tmp);
			n = n/16;
		}
		else
		{
			tmp = (n%16)+48;
			Push(S,tmp);
			n = n/16;
		}
		i++;
	}
	exportStack(S);
}

int main()
{
	hexEncode(5679); //162F
}