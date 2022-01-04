#include "stdio.h"
#include "math.h"

typedef int ElementType;

struct TreeNode{
	ElementType Data;
	struct TreeNode* Rchild;
	struct TreeNode* Lchild;
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
		np->Lchild = NULL;
		np->Rchild = NULL;
	}
	return np;
}

void printLNRRecursive(TreePointer Root)
{
	if(Root != NULL)
	{
		printLNRRecursive(Root->Lchild);
		printf("%d ",Root->Data);
		printLNRRecursive(Root->Rchild);
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
		else if (item < parent_node->Data)
			parent_node->Lchild = cur_node;
		else 
			parent_node->Rchild = cur_node;
	}
	return 0;
}

void createTreeBST(TreePointer& Root)
{
	ElementType item;
	Root = NULL;
	printf("Enter Data: ");
	do{
		scanf("%d",&item);
		if(item != -1)
			insertBSTLoop(Root, item);
	} while(item != -1);
}

// a)
int sumNode(TreePointer Root)
{
	int sum, sumLeft, sumRight;
	sum = sumLeft = sumRight = 0;

	// Check whether tree is empty
	if(Root == NULL)
	{
		printf("Tree is empty\n");
		return 0;
	}
	else
	{
		if(Root->Lchild != NULL)
			sumLeft = sumNode(Root->Lchild);
		
		if(Root->Rchild != NULL)
			sumRight = sumNode(Root->Rchild);
		
		sum = 1 + sumLeft + sumRight;
		return sum;
	}
}

// b)
int countMuc(TreePointer Root, int k)
{
	if (Root == NULL) 
		return 0;
	if (k == 1) 
		return 1;
	return (countMuc(Root->Lchild, k-1) + countMuc(Root->Rchild, k-1));
}

//c)

int findMaxValue(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int findHighTree(TreePointer Root)
{
	if (Root == NULL)
		return 0;
	return findMaxValue(findHighTree(Root->Lchild)+1, findHighTree(Root->Rchild)+1);
}

// d)
int sumValue(TreePointer Root)
{
	int sum, sumLeft, sumRight;  
    sum = sumRight = sumLeft = 0;  
      
    //Check whether tree is empty  
    if(Root == NULL) {  
        printf("Tree is empty\n");  
        return 0;  
    }  
    else {  
        //Calculate the sum of nodes present in left subtree  
        if(Root->Lchild != NULL)  
            sumLeft = sumValue(Root->Lchild);  
          
        //Calculate the sum of nodes present in right subtree  
        if(Root->Rchild != NULL)  
              sumRight = sumValue(Root->Rchild);  
          
        //Calculate the sum of all nodes by adding sumLeft, sumRight and root node's data  
        sum = Root->Data + sumLeft + sumRight;   
        return sum;  
  }      
}

//e)
bool checkStrictTree(TreePointer Root)
{
	if(Root == NULL)
		return true;
	if(Root->Lchild != NULL && Root->Rchild == NULL)
		return false;
	if(Root->Lchild == NULL && Root->Rchild != NULL)
		return false;
	return(checkStrictTree(Root->Lchild) && checkStrictTree(Root->Rchild));
}

//f)
bool isBalanced(TreePointer Root, int& height)
{
	/* lh --> Height of left subtree
    rh --> Height of right subtree */
    int lh = 0, rh = 0;
	
	/* l will be true if left subtree is balanced
    and r will be true if right subtree is balanced */
    int l = 0, r = 0;
	
	if (Root == NULL) 
	{
        height = 0;
        return 1;
    }

    /* Get the heights of left and right subtrees in lh and rh
    And store the returned values in l and r */
    l = isBalanced(Root->Lchild, lh);
    r = isBalanced(Root->Rchild, rh);
 
    /* Height of current node is max of heights of left and
    right subtrees plus 1*/
    height = (lh > rh ? lh : rh) + 1;
 
    /* If difference between heights of left and right
    subtrees is more than 2 then this node is not balanced
    so return 0 */
    if (abs(lh - rh) >= 2)
        return 0;
 
    /* If this node is balanced and left and right subtrees
    are balanced then return true */
    else
        return l && r;
}

//g)
int twoNonEmpty(TreePointer Root)
{
	int sum = 0;
	if(Root == NULL)
		return 0;
	if(Root->Lchild != NULL && Root->Rchild != NULL)
		sum += 1;
	return sum + (twoNonEmpty(Root->Lchild)) + twoNonEmpty(Root->Rchild);
}

//h)
int oneNonEmpty(TreePointer Root)
{
	int sum = 0;
	if(Root == NULL)
		return 0;
	if(Root->Lchild != NULL && Root->Rchild == NULL)
		sum += 1;
	if(Root->Lchild == NULL && Root->Rchild != NULL)
		sum += 1;
	return sum + (twoNonEmpty(Root->Lchild)) + twoNonEmpty(Root->Rchild);
}

//i)
int smaller(TreePointer Root, int x){
	int sum = 0;
	if (Root == NULL)
		return 0;
	if (Root->Data < x)
		sum += 1;
	return sum + smaller(Root->Lchild, x) + smaller(Root->Rchild,x);
}

//j)
int bigger(TreePointer Root, int x)
{
	int sum = 0;
	if (Root == NULL)
		return 0;
	if (Root->Data > x)
		sum += 1;
	return sum + smaller(Root->Lchild, x) + smaller(Root->Rchild,x);
}

//k)
int smallerBigger(TreePointer Root, int y, int x)
{
	int sum = 0;
	if (Root == NULL)
		return 0;
	if (Root->Data < x && Root->Data > y)
		sum += 1;
	return sum + smallerBigger(Root->Lchild, y, x) + smallerBigger(Root->Rchild, y, x);
}

//l)
void printNLRRecursive(TreePointer Root)
{
	if(Root != NULL)
	{
		printf("%d ",Root->Data);
		printNLRRecursive(Root->Lchild);
		printNLRRecursive(Root->Rchild);
	}
	return;
}

//n)
int maxTree(TreePointer Root)
{
 	// Base case
    if (Root == NULL)
        return INT_MIN;
    // Return maximum of 3 values:
    // 1) Root's data 2) Max in Left Subtree
    // 3) Max in right subtree
    int res = Root->Data;
    int lres = maxTree(Root->Lchild);
    int rres = maxTree(Root->Rchild);
    if (lres > res)
        res = lres;
    if (rres > res)
        res = rres;
    return res;
}

int minTree(TreePointer Root)
{
 	// Base case
    if (Root == NULL)
        return INT_MAX;

    // Return maximum of 3 values:
    // 1) Root's data 2) Max in Left Subtree
    // 3) Max in right subtree
    int res = Root->Data;
    int lres = minTree(Root->Lchild);
    int rres = minTree(Root->Rchild);
    if (lres < res)
        res = lres;
    if (rres < res)
        res = rres;
    return res;
}

int diffMaxMin(TreePointer Root){
	if (Root == NULL)
		return INT_MIN;
	int res = abs(findHighTree(Root->Lchild) - findHighTree(Root->Rchild));
	int lres = diffMaxMin(Root->Lchild);
	if (lres > res){
		res = lres;
	}
	int rres = diffMaxMin(Root->Rchild);
	if (rres > res){
		res = rres;
	}
	return res;
}	

//o)
void exchangeNodeTree(TreePointer& Root)
{
	TreePointer np;
	np = Root->Rchild;
	Root->Rchild = Root->Lchild;
	Root->Lchild = np;
}

void exchangeTree(TreePointer& Root)
{
	if(Root == NULL)
		return;
	// Đổi Lchild và Rchild
	exchangeNodeTree(Root);
	exchangeTree(Root->Rchild);
	exchangeTree(Root->Lchild);
}

//p
int getLevelUtil(TreePointer& Root, int data, int level)
{
    if (Root == NULL)
        return 0;
 
    if (Root -> Data == data)
        return level;
 
    int downlevel = getLevelUtil(Root->Lchild, data, level + 1);
    if (downlevel != 0)
        return downlevel;
 
    downlevel = getLevelUtil(Root->Rchild, data, level + 1);
    return downlevel;
}

int main()
{
	TreePointer T = NULL;
	int choice = -1;
	int x,k,y;
	int height = 0;
	while (choice != 0)
    {
        printf("What do you want to do?\n");
        printf("[0] Exit\n");
        printf("[1] Add value to Binary Search Tree (BST)\n");
        printf("[2] Sum of node in BST\n");
        printf("[3] Sum of node at muc k in BST\n");
        printf("[4] Get height of BST\n");
        printf("[5] Sum of node value in BST\n");
        printf("[6] Kiem tra xem do co phai la cay nhi phan chac\n");
        printf("[7] Kiem tra xem T co phai la cay nhi phan can bang hoan toan hay khong\n");
        printf("[8] So nut co dung 2 con khac rong\n");
        printf("[9] So nut co dung 1 con khac rong\n");
        printf("[10] So nut co khoa nho hon x tren cay nhi phan hoac BST\n");
        printf("[11] So nut co khoa nho hon x tren cay nhi phan hoac BST\n");
		printf("[12] So nut co khoa nho hon x va lon hon y tren cay nhi phan hoac cay BST\n");
		printf("[13] Duyet cay theo chieu rong NLR\n");
		printf("[14] Duyet cay theo chieu sau LNR\n");
		printf("[15] Do lech lon nhat cua cac nut tren cay\n");
		printf("[16] Dao nhanh trai va phai cua moi nut tren mot cay nhi phan va xuat LNR\n");
		printf("[17] Road\n");
        
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            return 0;
            break;

        case 1:
			printf("Value is: ");
			scanf("%d",&x);
			insertBSTLoop(T, x);
            break;

        case 2:
            x = sumNode(T);
			printf("Result: %d",x);
            break;

        case 3:
			printf("Enter k: ");
			scanf("%d",&k);
            x = countMuc(T,k);
			printf("Result: %d",x);
            break;

		case 4:
			x = findHighTree(T);
			printf("Result: %d",x);
			break;

		case 5:
			x = sumValue(T);
			printf("Result: %d",x);
			break;

		case 6:
			if (checkStrictTree(T))	
				printf("Yes");
			else
				printf("No");
			break;

		case 7:
			if (isBalanced(T,height))
				printf("Yes");
			else
				printf("No");
			break;
		
		case 8:
			x = twoNonEmpty(T);
			printf("Result: %d",x);
			break;

		case 9:
			x = oneNonEmpty(T);
			printf("Result: %d",x);
			break;

		case 10:
			printf("Enter key: ");
			scanf("%d",&k);
			x = smaller(T,k);
			printf("Result: %d, x");
			break;

		case 11:
			printf("Enter key: ");
			scanf("%d",&k);
			x = bigger(T,k);
			printf("Result: %d",x);
			break;

		case 12:
			printf("Enter x: ");
			scanf("%d",&x);
			printf("Enter y: ");
			scanf("%d",&y);
			k = smallerBigger(T,y,x);
			printf("Result: %d",k);
			break;

		case 13: 
			printNLRRecursive(T);
			break;

		case 14:
			printLNRRecursive(T);
			break;

		case 15:
			x = diffMaxMin(T);
			printf("Result: %d",x);
			break;

		case 16: 
			exchangeTree(T);
			printLNRRecursive(T);
			break;

		case 17: 
			x = getLevelUtil(T,5,0);
			printf("Road = %d",x);
			break;

        default:
            // do nothing, just loop again
            break;
        }
        printf("\n\n");
    }
}