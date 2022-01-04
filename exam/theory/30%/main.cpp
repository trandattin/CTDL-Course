// Tran Dat Tin
// 2011345
// TNK44
// Kiem Tra 30% mon Cau Truc Du Lieu va Thuat Toan
// Date: 20/12/2021
#include "stdio.h"

// 1 a)
typedef int ElementType;

typedef struct node
{
	ElementType Data;
	node* Next;
} NodeType;

typedef NodeType* NodePointer;

struct LinkList{
	NodePointer Tail,Head;
};

// 1 b)
NodePointer TaoNut(ElementType x)
{
	NodePointer np;
	np = new NodeType;
	if (np == NULL)
		printf("Loi cap phat bo nho");
	else 
	{
		np->Data = x;
		np->Next = NULL;
	}
	return np;
}

LinkList createEmptyLL()
{
	LinkList L;
	L.Head = L.Tail = NULL;
	return L;
}

bool isEmpty(LinkList L)
{
	if (L.Head == NULL)
		return true;
	return false;
}

int exportLL(LinkList L)
{
	if (isEmpty(L) == true)
		return -1;
	NodePointer cur = L.Head;
	while(cur != NULL)
	{
		printf("%d ", cur->Data);
		cur = cur->Next;
	}
	printf("\n");
	return 1;
}

// 1 c)
void ChenDau(LinkList& L, ElementType x)
{
	NodePointer np = TaoNut(x);
	if (L.Head == NULL)
	{
		L.Head = np;
		L.Tail = np;
	}
	else
	{
		np->Next = L.Head;
		L.Head = np;
	}
}

// 2 a)
LinkList TaoDS()
{
	LinkList L;
	L = createEmptyLL();
	printf("Enter data: \n"); 
	do
	{
		ElementType x;
		scanf("%d", &x);
		if (x == -1)
			break;
		ChenDau(L,x);
	} while (true);
	return L;
}

// 2 b)
void SuaDS(LinkList& L, ElementType x, ElementType y)
{
	if (isEmpty(L))
		return;
	else
	{
		NodePointer cur_node = L.Head;
		while(cur_node != NULL)
		{
			if(cur_node->Data == x)
				cur_node->Data = y;
			cur_node = cur_node->Next;
		}
	}
}

// 3
void TachDS(LinkList L1, LinkList& L2, LinkList& L3, ElementType x)
{
	NodePointer cur_node = L1.Head;
	while(cur_node != NULL)
	{
		if(cur_node->Data < x)
		{
			ChenDau(L2,cur_node->Data);
		}
		else
		{
			ChenDau(L3,cur_node->Data);
		}
		cur_node = cur_node->Next;
	}
}

// 4

int searchIndex(LinkList L, ElementType x)
{
	int index = -1;
	int count = 1;
	NodePointer cur_node = L.Head;
	while(cur_node != NULL)
	{
		if (cur_node->Data == x)
			index = count;
		count ++;
		cur_node = cur_node->Next;
	}
	return index;
}

NodePointer searchPreNode(LinkList L, int k)
{
	NodePointer np_Pre = L.Head;
	for(int i = 1; i <= k-2; i++)
	{
		np_Pre = np_Pre->Next;
	}
	return np_Pre;
}

void removeNodeLL(LinkList& L, ElementType x)
{
	int index = searchIndex(L,x);
	if (index == -1)
	{
		printf("Khong tim thay nut can xoa");
		return;
	}
	NodePointer np_Pre = searchPreNode(L, index);
	NodePointer np_Del = np_Pre->Next;
	if (np_Del == L.Head)
	{
		L.Head = L.Head->Next;
		np_Del->Next = NULL;
		delete np_Del;
	}
	else if (np_Del == L.Tail)
	{
		L.Tail = np_Pre; 
		np_Pre->Next = NULL;
		delete np_Del;
	}
	else
	{
		np_Pre->Next = np_Del->Next;
		np_Del->Next = NULL;
		delete np_Del;
	}
	return;
}

//5
int main()
{
	LinkList L = createEmptyLL();
	LinkList L2 = createEmptyLL();
	LinkList L3 = createEmptyLL();
	int x,y;
	NodePointer k;
	int choice = -1;
    while (choice != 0)
    {
        printf("What do you want to do?\n");
        printf("[0] Exit\n");
        printf("[1] Tao Nut\n");
        printf("[2] Tao danh sach lien ket L \n");
        printf("[3] Chen Dau gia tri x vao L\n");
        printf("[4] Sua danh sach lien ket L thay tat ca x thanh y\n");
        printf("[5] Tach danh sach lien ket L theo x\n");
        printf("[6] Xoa nut x cuoi cung trong danh sach lien ket L\n");
        printf("[7] Xuat L\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            return 0;
            break;

        case 1:
			printf("x = ");
			scanf("%d",&x);
			k = TaoNut(x);
			printf("Tao nut thanh cong");
            break;

        case 2:
            L = TaoDS();
			exportLL(L);
            break;

        case 3:
			printf("\nBEFORE\n");
			exportLL(L);
			printf("x = ");
			scanf("%d",&x);
            ChenDau(L,x);
			printf("\nAFTER\n");
			exportLL(L);
            break;

        case 4:
			printf("\nBEFORE\n");
			exportLL(L);
            printf("x = ");
			scanf("%d",&x);
            printf("y = ");
			scanf("%d",&y);
			SuaDS(L,x,y);
			printf("\nAFTER\n");
			exportLL(L);
            break;

       case 5:
			printf("\nBEFORE\n");
			exportLL(L);
            printf("x = ");
            scanf("%d",&x);
			TachDS(L,L2,L3,x);
			printf("\nAFTER\n");
			printf("L2: ");
			exportLL(L2);
			printf("L3: ");
			exportLL(L3);

		case 6:
			printf("\nBEFORE\n");
			exportLL(L);
			printf("x = ");
			scanf("%d",&x);
			removeNodeLL(L,x);
			printf("\nAFTER\n");
			exportLL(L);

		case 7:
			exportLL(L);

        default:
            // do nothing, just loop again
            break;
        }
        printf("\n\n");
    }
}

