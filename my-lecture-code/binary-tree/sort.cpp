#include "stdio.h"

typedef int ElementType;

struct TreeNode{
	ElementType Data;
	struct TreeNode* Lchild;
	struct TreeNode* Rchild;
};

typedef TreeNode* TreePointer;

typedef TreePointer ElementType2;


void outputArray(int arr[], int n)
{
	for(int i = 0; i<n; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n\n");
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

void browseLNRRecursive(TreePointer Root, int arr[], int& i)
{
	if (Root != NULL)
	{
		browseLNRRecursive(Root->Lchild,arr,i);
		arr[i] = Root->Data;
		i++;
		browseLNRRecursive(Root->Rchild,arr,i);
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

int main(){
	int arr[] = {5,4,3,2,1};
	int n = sizeof(arr)/sizeof(arr[0]);
	outputArray(arr,n);
    TreePointer T = NULL;
	for (int i = 0; i < n; i++){
		insertBSTLoop(T,arr[i]);
	}
	int i = 0;
	browseLNRRecursive(T,arr,i);
	outputArray(arr,n);
}