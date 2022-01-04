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

struct Stack
{
	NodePointer Head;
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
	printf("Enter Data ('q' to exit): ");
	do
	{
		ElementType x;
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
		printf("%c",cur_node->Text);
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

Stack computeSample(char sample[])
{
	Stack S = createEmptyStack();
	int len_sample = strlen(sample);
	for(int i = 0; i < len_sample; i++)
	{
		if (sample[i] == '*')
			Pop(S);
		else
			Push(S,sample[i]);
	}
	return S;
}

int main()
{
	char sample[100];
	gets(sample);
	Stack S = computeSample(sample);
	exportStack(S);
}