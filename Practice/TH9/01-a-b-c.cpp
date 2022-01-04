#include "stdio.h"

typedef int ElementType;

struct TreeNode{
	ElementType data;
	struct TreeNode* right;
	struct TreeNode* left;
};

typedef TreeNode* TreePointer;

TreePointer createNode(ElementType item)
{
	TreePointer np = new TreeNode;
	if (np == NULL)
		printf("Loi cap phat bo nho");
	else
	{
		np->data = item;
		np->left = NULL;
		np->right = NULL;
	}
	return np;
}

void printLNRRecursive(TreePointer Root)
{
	if(Root != NULL)
	{
		printLNRRecursive(Root->left);
		printf("%d ",Root->data);
		printLNRRecursive(Root->right);
	}
	return;
}

TreePointer findBSTLoop(TreePointer Root, ElementType item, TreePointer& parent_node)
{
	TreePointer cur_node = Root;
	parent_node = NULL;
	while(cur_node != NULL)
	{
		if (item == cur_node->data)
			return cur_node;
		else
		{
			parent_node = cur_node;
			if (item > cur_node->data)
				cur_node = cur_node->right;
			else
				cur_node = cur_node->left;
		}
	}
	return NULL;
}

int insertBSTLoop(TreePointer& Root, ElementType item)
{
	TreePointer cur_node, parent_node;
	if(findBSTLoop(Root, item, parent_node) != NULL)
	{
		printf("Da co phan tu %d trong cay\n", item);
		return -1;
	}
	else // item chua co trong cay
	{
		cur_node = createNode(item);
		if (parent_node == NULL)
			Root = cur_node;
		else if (item < parent_node->data)
			parent_node->left = cur_node;
		else 
			parent_node->right = cur_node;
	}
	return 0;
}

void createTreeBST(TreePointer& Root)
{
	ElementType item;
	Root = NULL;
	printf("Enter data: ");
	do{
		scanf("%d",&item);
		if(item != -1)
			insertBSTLoop(Root, item);
	} while(item != -1);
}

int deleteNode(TreePointer& Root, ElementType item)
{
	TreePointer cur_node, parent_node, cur_succ, subtree;
	cur_node = findBSTLoop(Root, item, parent_node);
	if(cur_node == NULL)
		return -1;
	else
	{
		if (cur_node->left != NULL && cur_node->right != NULL)
		{
			cur_succ = cur_node->right;
			parent_node = cur_node;
			while(cur_succ->left != NULL)
			{
				parent_node = cur_succ;
				cur_succ = cur_succ->left;
			}
			cur_node->data = cur_succ->data;
			cur_node = cur_succ;
		} // Đưa nút có hai con về nút có tối đa 1 con
		subtree = cur_node->left;
		if (subtree == NULL) 
			subtree = cur_node->right;
		if (parent_node == NULL) 
			Root = subtree;
		else if (parent_node->left == cur_node) 
			parent_node->left = subtree;
		else parent_node->right = subtree;
		delete cur_node;
		return 1;
	}
}

int main()
{
	TreePointer T;
	createTreeBST(T);
	printLNRRecursive(T);
	printf("\n");
	deleteNode(T,5);
	printLNRRecursive(T);
}