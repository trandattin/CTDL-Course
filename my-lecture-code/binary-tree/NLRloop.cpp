#include "stdio.h"

typedef int ElementType;

struct TreeNode{
	ElementType Data;
	struct TreeNode* Lchild;
	struct TreeNode* Rchild;
};

typedef TreeNode* TreePointer;

typedef TreePointer ElementType2;

struct StackNode{
	ElementType2 Data;
	struct StackNode* Next;
};

typedef StackNode* StackPointer;

struct Stack{
	StackPointer Head;
};

Stack createEmptyStack()
{
	Stack S;
	S.Head = NULL;
	return S;
}

StackPointer createStackNode(ElementType2 x)
{
	StackPointer np;
	np = new StackNode;
	if (np == NULL)
		printf("loi cap phat bo nho");
	else
	{
		np->Data = x;
		np->Next = NULL;
	}
	return np;
}

void Push(Stack& S, ElementType2 x)
{
	StackPointer np = createStackNode(x);
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

StackPointer Pop(Stack& S)
{
	StackPointer np;
	np = S.Head;
	S.Head = S.Head -> Next;
	return np; 
}

TreePointer createTreeNode(ElementType item)
{
	TreePointer np = new TreeNode;
	if (np == NULL)
		printf("Loi cap phat bo nho");
	else
	{
		np->Data = item;
		np->Lchild = NULL;
		np->Rchild = NULL;
	}
	return np;
}

TreePointer findBSTLoop(TreePointer Root, ElementType item, TreePointer& parent_node)
{
	TreePointer cur_node = Root;
	parent_node = NULL;
	while(cur_node != NULL)
	{
		if (item == cur_node->Data)
			return cur_node;
		else
		{
			parent_node = cur_node;
			if (item > cur_node->Data)
				cur_node = cur_node->Rchild;
			else
				cur_node = cur_node->Lchild;
		}
	}
	return NULL;
}

void insertBSTLoop(TreePointer& Root, ElementType item)
{
	TreePointer cur_node, parent_node;
	if(findBSTLoop(Root,item,parent_node) != NULL)
	{
		printf("Da co phan tu %d trong cay\n", item);
		return;
	}
	else
	{
		cur_node = createTreeNode(item);
		if (parent_node == NULL)
			Root = cur_node;
		else if (item < parent_node->Data)
			parent_node->Lchild = cur_node;
		else
			parent_node->Rchild = cur_node;
		return;
	}
}

void createTreeBST(TreePointer& Root)
{
	ElementType item;
	Root = NULL;
	printf("Enter Data: ");
	do{
		scanf("%d",&item);
		if(item != -1)
			insertBSTLoop(Root,item);
	}while(item != -1);
}

void printNLRLoop(TreePointer Root)
{
	TreePointer p = Root;
	Stack S = createEmptyStack();
	do
	{
		while(p != NULL)
		{
			Push(S,p);
			printf("%d ",p->Data);
			p = p->Lchild;
		}
		if (S.Head != NULL)
		{
			p = Pop(S)->Data; // Lấy ra phần tử p ở đỉnh stack S
			p = p->Rchild;
		}
		else
		{
			break;
		}
	}while(true);
}

int main()
{
	TreePointer root = NULL;
	insertBSTLoop(root,6);
	insertBSTLoop(root,5);
	insertBSTLoop(root,7);
	insertBSTLoop(root,3);
	insertBSTLoop(root,4);
	insertBSTLoop(root,8);
	printNLRLoop(root);
}