#include "stdio.h"

// Build Tree

typedef int ElementTree;

struct TreeNode{
	ElementTree data;
	struct TreeNode* left;
	struct TreeNode* right;
};

typedef TreeNode* TreePointer;

// Build Queue

typedef TreePointer ElementQueue;

struct QueueNode{
	ElementQueue data;
	struct QueueNode* next;
};

typedef QueueNode* QueuePointer;

struct Queue
{
	QueuePointer Head;
	QueuePointer Tail;
};

Queue createEmptyQueue()
{
	Queue Q;
	Q.Head = NULL;
	Q.Tail = NULL;
	return Q;
}

QueuePointer createQueueNode(ElementQueue x)
{
	QueuePointer np = new QueueNode;
	if (np == NULL)
		printf("Loi cap phat bo nho");
	else
	{
		np->data = x;
		np->next = NULL;
	}
	return np;
}

Queue enQueue(Queue& Q, ElementQueue x)
{
	QueuePointer np = createQueueNode(x);
	if (Q.Head == NULL)
	{
		Q.Head = np;
		Q.Tail = np;
	}
	else
	{
		Q.Tail->next = np;
		Q.Tail = np;
	}
	return Q;
}

QueuePointer deQueue(Queue& Q)
{
	if (Q.Head == NULL)
		return NULL;
	QueuePointer np;
	np = Q.Head;
	Q.Head = np->next;
	np->next = NULL;
	return np;
}

TreePointer createTreeNode(ElementTree x)
{
	TreePointer np = new TreeNode;
	if (np == NULL)
		printf("Loi cap phat bo nho");
	else
	{
		np->data = x;
		np->left = NULL;
		np->right = NULL;
	}
	return np;
}

TreePointer findBSTLoop(TreePointer root, ElementTree item, TreePointer& parent_node)
{
	TreePointer cur_node = root;
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

void insertBSTLoop(TreePointer& root, ElementTree item)
{
	TreePointer cur_node, parent_node;
	if (findBSTLoop(root,item,parent_node) != NULL)
	{
		printf("Da co phan tu %d trong cay \n",item);
		return;
	}
	else
	{
		cur_node = createTreeNode(item);
		if (parent_node == NULL)
			root = cur_node;
		else if (item < parent_node->data)
			parent_node->left = cur_node;
		else
			parent_node->right = cur_node;
		return;
	}
}



void addPrint(TreePointer p, Queue& Q)
{
	if (p != NULL)
	{
		printf("%d ",p->data);
		enQueue(Q,p);
	}
	else
	{
		return;
	}
}

void widthSearch(TreePointer root)
{
	TreePointer p = root;
	Queue Q = createEmptyQueue();
	addPrint(p,Q);
	do 
	{
		if (Q.Head != NULL)
		{
			p = deQueue(Q)->data; // Lấy ra phần tử p ở đầu queue Q
			addPrint(p->left,Q);
			addPrint(p->right,Q);
		}
		else
		{
			break;
		}
	} while(true);

}

int main()
{
	TreePointer root = NULL;
	insertBSTLoop(root,8);
	insertBSTLoop(root,4);
	insertBSTLoop(root,9);
	insertBSTLoop(root,3);
	insertBSTLoop(root,5);
	insertBSTLoop(root,10);
	widthSearch(root);
}