// Tran Dat Tin
// 2011345
#include "stdio.h"

// a)	

typedef int ElementType;

struct TreeNode{
	ElementType data;
	struct TreeNode* right;
	struct TreeNode* left;
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

//b)

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

//c)

int DemChan(TreePointer Root, int Y)
{
    if (Root !=NULL)
    {
        int a = DemChan(Root->left, Y);
        int b = DemChan(Root->right, Y);
        if (Root->data % 2 == 0 && Root->data > Y)
            return 1 + a + b;
        return a + b;
    }
    return 0;
}

//d)

int deleteNode(TreePointer& Root, TreePointer cur_node, TreePointer parent_node)
{
	TreePointer cur_succ, subtree;
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

void deleteMain(TreePointer& Root, ElementType X)
{
	TreePointer parent_node, cur_node;
	cur_node = findBSTLoop(Root,X,parent_node);
	if ((cur_node->left != NULL & cur_node->right != NULL) == false)
		deleteNode(Root,cur_node,parent_node);
	return;
}



//e) 
int DemRong(TreePointer Root)
{
    if (Root !=NULL)
    {
        int a = DemRong(Root->left);
        int b = DemRong(Root->right);
        if ((Root->left == NULL && Root->right == NULL) == false)
            return 1 + a + b;
        return a + b;
    }
    return 0;
}

//f)

int KiemTraMuc(TreePointer Root, int data, int level)
{
    if (Root == NULL)
        return 0;
 
    if (Root -> data == data)
        return level;
 
    int downlevel = KiemTraMuc(Root->left, data, level + 1);
    if (downlevel != 0)
        return downlevel;
 
    downlevel = KiemTraMuc(Root->right, data, level + 1);
    return downlevel;
}

void addPrint(TreePointer Root, TreePointer p, Queue& Q, int muc_k)
{
	if (p != NULL)
	{
		if(KiemTraMuc(Root, p->data,1) == muc_k)
		{
			printf("%d ",p->data);
		}
		enQueue(Q,p);
	}
	else
	{
		return;
	}
}

void printAsMuc(TreePointer root, int muc_k)
{
	TreePointer p = root;
	Queue Q = createEmptyQueue();
	addPrint(root,p,Q,muc_k);
	do 
	{
		if (Q.Head != NULL)
		{
			p = deQueue(Q)->data; // Lấy ra phần tử p ở đầu queue Q
			addPrint(root,p->left,Q,muc_k);
			addPrint(root,p->right,Q,muc_k);
		}
		else
		{
			break;
		}
	} while(true);
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


//g)
int main()
{
	//a) b)
	TreePointer T;
	// Nhap tu ban phim
	createTreeBST(T);
	// Chen gia tri
	insertBSTLoop(T,15);
	// In ra LNR
	printLNRRecursive(T);
	
	//c)
	int Y ;
	printf("\nY = ");
	scanf("%d",&Y);
	printf("So nut chan lon hon Y la: %d",DemChan(T,Y));

	// d)
	printf("\n**Before**\n");
	printLNRRecursive(T);
	int X ;
	printf("\nNhap vao X la mot gia tri trong cay = ");
	scanf("%d",&X);
	deleteMain(T,X);
	printf("\n**After**\n");
	printLNRRecursive(T);

	//e)
	printf("\nSo nut co it nhat mot con khac rong la: %d",DemRong(T));

	// f)
	int muc_k;
	printf("\nmuc_k = ");
	scanf("%d",&muc_k);
	printf("\n");
	printAsMuc(T,muc_k);
}