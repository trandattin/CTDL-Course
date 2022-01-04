#include "stdio.h"

typedef int ElementType;

struct TreeNode{
	ElementType Data;
	struct TreeNode* LChild;
	struct TreeNode* RChild;
};

typedef TreeNode* TreePointer;

TreePointer createNode(ElementType item)
{
	TreePointer np = new TreeNode;
	if (np == NULL)
		printf("Loi cap phat bo nho");
	else
	{
		np->Data = item;
		np->LChild = NULL;
		np->RChild = NULL;
	}
	return np;
}

void printLNRRecursive(TreePointer Root)
{
	if (Root != NULL)
	{
		printLNRRecursive(Root->LChild);
		printf("%d ",Root->Data);
		printLNRRecursive(Root->RChild);
	}
	return;
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
				cur_node = cur_node->RChild;
			else 
				cur_node = cur_node->LChild;
		}
	}
	return NULL;
}

int insertBSTLoop(TreePointer& Root, ElementType item)
{
	TreePointer cur_node, parent_node;
	if (findBSTLoop(Root, item, parent_node) != NULL)
	{
		printf("Da co phan tu %d trong cay\n", item);
		return -1;
	}
	else // item chua co trong cay
	{
		cur_node = createNode(item);
		if(parent_node == NULL)
			Root = cur_node;
		else if (item < parent_node->Data)
			parent_node->LChild = cur_node;
		else
			parent_node->RChild = cur_node;
		return 1;
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

int main()
{
	TreePointer T;
	createTreeBST(T);
	printLNRRecursive(T);
}