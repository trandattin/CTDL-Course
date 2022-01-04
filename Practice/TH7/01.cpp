#include "stdio.h"
#include "string.h"
#include <iostream>
using namespace std;

struct Info
{
	char NAME[100];
	int quanity;
};

typedef struct node 
{
	node* Next;
	Info Data;
} NodeType;

typedef NodeType* NodePointer;

struct LinkList
{
	NodePointer Head,Tail;		
};

LinkList createEmptyLinkList()
{
	LinkList L;
	L.Head = NULL;
	L.Head = NULL;
	return L;
}

bool isEmpty(LinkList L) 
{
	if (L.Head == NULL)
		return true;
	return false;
}

NodePointer createNodeLL(Info x)
{
	NodePointer np;
	np = new NodeType;
	if (np == NULL)
		printf("Loi cap phat bo nho");
	else
	{
		np->Data = x;
		np->Next = NULL;;
	}
	return np;
}

// IMPORT PRODUCT

void inputInfo(Info& x)
{
	printf("Enter name product: \n");
	scanf("%s",&x.NAME);
	printf("Enter quanity product: \n");
	scanf("%d",&x.quanity);
}

bool updateProduct(LinkList& L, Info x, NodePointer check_node)
{
	while(check_node != NULL)
	{
		if (strcmp(check_node->Data.NAME,x.NAME) == 0)
			return true;
		check_node = check_node->Next;
	}
	return false;
}

void pushBack(LinkList& L, Info x)
{
	NodePointer np = createNodeLL(x);
	NodePointer check_node = L.Head;
	if (isEmpty(L))
	{
		L.Head = np;
		L.Tail = np;
	}
	else if (updateProduct(L,x,check_node) == true)
	{
		check_node->Data.quanity += x.quanity;
	}
	else
	{
		L.Tail->Next = np;
		L.Tail = np;
	}
}

LinkList createLinkList()
{
	LinkList L = createEmptyLinkList();
	do
	{
		Info x;
		inputInfo(x);
		if (x.quanity == -1)
			break;
		pushBack(L,x);
	} while (true);
	return L;
}

void AddProductToStorage(LinkList& L)
{
	Info add_product;
	cout << "Enter name product to Add: ";
	cin >> add_product.NAME;
	cout << "Enter quanity of product: ";
	cin >> add_product.quanity;
	pushBack(L,add_product);
}

// EXPORT PRODUCT

void outputProduct(Info x)
{
	printf("NAME: %s\n",x.NAME);
	printf("Quanity: %d\n",x.quanity);
}

int outputLinkList(LinkList L)
{

	if (isEmpty(L))
		return -1;
	NodePointer cur = L.Head;
	while(cur != NULL)
	{
		outputProduct(cur->Data);
		cur = cur->Next;
	}
	return 0;
}

void exportProduct(LinkList&L)
{
	char name_product[50];
	int num;
	cout << "Enter name product to export: ";
	cin >> name_product;
	cout << "Enter quanity of product to export: ";
	cin >> num;
	NodePointer cur_node = L.Head;
	int checked = 0;
	while(cur_node != NULL)
	{
		if (strcmp(cur_node->Data.NAME,name_product) == 0)
		{
			cur_node->Data.quanity -= num;
			checked = 1;
		}
		cur_node = cur_node->Next;
	}
	if (checked == 0)
		printf("Khong co san pham can xuat ra huhu");
}

// REMOVE PRODUCT

bool checkProduct(LinkList L, Info x, NodePointer cur, NodePointer pre)
{
	while(cur != NULL)
	{
		if (strcmp(cur->Data.NAME,x.NAME) == 0)
			return true;
		pre = cur;
		cur = cur->Next;
	}
	return false;
}

void removeProduct(LinkList& L)
{
	Info x;
	cout << "Enter name product to remove: ";
	cin >> x.NAME;
	NodePointer cur = L.Head;
	NodePointer pre = NULL;
	if(checkProduct(L,x,cur,pre))
	{
		if(cur == L.Head)
		{
			L.Head = L.Head->Next;
			cur->Next = NULL;
			delete cur;
		} 
		else
		{
			pre->Next = cur->Next;
			cur->Next = NULL;
			delete cur;
		}
	} 
}

// SORT PRODUCT BY NAME

void swap(NodePointer a, NodePointer b)
{
	int tmp_quanity = a->Data.quanity;
	a->Data.quanity = b->Data.quanity;
	b->Data.quanity = tmp_quanity;

	char tmp_name[100];
	strcpy(tmp_name, a->Data.NAME); 
	strcpy(a->Data.NAME, b->Data.NAME); 
	strcpy(b->Data.NAME, tmp_name); 
}

void sortProduct(LinkList& L)
{
	int swapped;
	NodePointer node_left;
	NodePointer node_right = NULL;
	do
	{
		swapped = 0;
		node_left = L.Head;
		while(node_left->Next != node_right)
		{
			if(strcmp(node_left->Data.NAME,node_left->Next->Data.NAME) == 1)
			{
				printf("debug\n");
				swap(node_left,node_left->Next);
				swapped = 1;
			}
			node_left = node_left->Next;
		}
		node_right = node_left;
	} while (swapped);
}

int main()
{	
	LinkList L = createEmptyLinkList();

	int choice = -1;
    while (choice != 0)
    {
        printf("What do you want to do?\n");
        printf("[0] Exit\n");
        printf("[1] Print list of products order by name asc\n");
        printf("[2] Add product to storage\n");
        printf("[3] Get product from storage\n");
        printf("[4] Stop selling a product\n");
        
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            return 0;
            break;

        case 1:
			printf("BEFORE SOFT\n");
            outputLinkList(L);
            sortProduct(L);
			printf("\nAFTER SOFT\n");
            outputLinkList(L);
            break;

        case 2:
            AddProductToStorage(L);
            break;

        case 3:
            exportProduct(L);
            break;

        case 4:
            removeProduct(L);
            break;

        default:
            // do nothing, just loop again
            break;
        }
        printf("\n\n");
    }
}
