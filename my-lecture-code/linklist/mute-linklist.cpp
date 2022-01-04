#include "stdio.h"

typedef int ElementType;

struct NodeType {
	ElementType Data;
	NodeType* Next;
};

typedef NodeType* NodePointer;

struct LinkListC {
	NodePointer Head, Tail;
};

NodePointer createNodeMute()
{
	NodePointer np;
	np = new NodeType;
	if (np == NULL)
	{
		printf("Loi cap phat bo nho");
	}
	else
	{
		np->Next = NULL;
	}
	return np;
}

NodePointer createNode(ElementType x)
{
	NodePointer np;
	np = new NodeType;
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

LinkListC createEmptyLinkList()
{
	LinkListC L;
	L.Head = createNodeMute();
	L.Tail = L.Head;
	return L;
}

bool isEmpty(LinkListC L)
{
	if (L.Head->Next == NULL)
		return true;
	return false;
}

void insertNode(LinkListC& L, ElementType x, NodePointer PredNode)
{
	NodePointer np = createNode(x);
	np->Next = PredNode->Next;
	PredNode->Next = np;
	if (PredNode  == L.Tail) 
		L.Tail = np;
}

LinkListC createLinkList()
{
	LinkListC L;
	L = createEmptyLinkList();
	printf("Enter Data: ");
	do{
		ElementType x;
		scanf("%d",&x);
		if (x == -1)
			break;
		insertNode(L, x, L.Tail);
	}while(true);
	return L;
}

void outputLinkList(LinkListC L)
{
	if (isEmpty(L)) 
		return;
	NodePointer cur = L.Head->Next;
	while(cur != NULL) 
	{
		printf("%d ",cur->Data);
		cur = cur -> Next;
	}
	printf("\n");
}

void copyLinkList(LinkListC L1, LinkListC& L2)
{
	if (isEmpty(L1)) return;
	NodePointer cur_node = L1.Head->Next;
	while(cur_node != NULL)
	{
		insertNode(L2,cur_node->Data,L2.Tail);
		cur_node = cur_node->Next;
	}
}

bool checkElement(LinkListC L, ElementType x)
{
	if (isEmpty(L)) return false;
	NodePointer cur_node = L.Head->Next;
	while(cur_node != NULL) 
	{
		if (cur_node->Data == x) return true;
		cur_node = cur_node->Next;
	}
	return false;
}

LinkListC unionOperator(LinkListC L1, LinkListC L2)
{
	LinkListC R = createEmptyLinkList();
	copyLinkList(L1,R);
	NodePointer cur_node = L2.Head->Next;
	while(cur_node != NULL)
	{
		if (checkElement(L1,cur_node->Data) == false){
			insertNode(R,cur_node->Data,R.Tail);
		}
		cur_node = cur_node->Next;
	}
	return R;
}

void removeNode(LinkListC& L, NodePointer& prev_node, NodePointer& cur_node)
{
	NodePointer del_node = cur_node;
	cur_node = cur_node->Next;
	prev_node->Next = cur_node;
	
	del_node->Next = NULL;
	delete del_node;
}

LinkListC intersecOperator(LinkListC L1, LinkListC L2)
{
	LinkListC R = createEmptyLinkList();
	copyLinkList(L1,R);
	NodePointer cur_node = R.Head->Next;
	NodePointer prev_node = R.Head;
	while(cur_node != NULL)
	{
		if (checkElement(L2,cur_node->Data) == false){
			removeNode(R, prev_node, cur_node);
		} else
		{
			prev_node = cur_node;
			cur_node = cur_node->Next;
		}
	}
	return R;
}

LinkListC compleOperator(LinkListC L1, LinkListC L2)
{
	LinkListC R = createEmptyLinkList();
	copyLinkList(L1,R);
	NodePointer cur_node = R.Head->Next;
	NodePointer prev_node = R.Head;
	while(cur_node != NULL)
	{
		if (checkElement(L2,cur_node->Data) == true){
			removeNode(R, prev_node, cur_node);
		} else
		{
			prev_node = cur_node;
			cur_node = cur_node->Next;
		}
	}
	return R;
}

int main(){
	LinkListC L1 = createEmptyLinkList();
	insertNode(L1, 5, L1.Tail);
	insertNode(L1, 6, L1.Tail);
	insertNode(L1, 1, L1.Tail);
	insertNode(L1, 88, L1.Tail);
	LinkListC L2 = createEmptyLinkList();
	insertNode(L2, 9, L2.Tail);
	insertNode(L2, 5, L2.Tail);
	insertNode(L2, 7, L2.Tail);
	insertNode(L2, 6, L2.Tail);
	printf("L1: ");
	outputLinkList(L1);
	printf("L2: ");
	outputLinkList(L2);
	
	LinkListC R1,R2,R3;
	
	R1 = unionOperator(L1,L2);
	printf("Union L1 and L2: ");
	outputLinkList(R1);
	
	printf("Intersection L1 and L2: ");
	R2 = intersecOperator(L1,L2);
	outputLinkList(R2);
	
	printf("Complement L1 and L2: ");
	R3 = compleOperator(L1,L2);
	outputLinkList(R3);
}