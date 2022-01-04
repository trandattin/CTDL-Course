#include "stdio.h"

typedef int ElementType; // Kiểu dữ liệu cơ sở của mỗi phần tử

typedef struct node {
	ElementType Data;
	struct node *Next;
}NodeType;

typedef NodeType * NodePointer;

typedef struct {
	NodePointer Head, Tail;
}LL;

NodePointer TaoNut(ElementType x)
{
	NodePointer np;
	// Cấp phát bộ nhớ
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

LL TaoDSRong()
{
	LL L;
	L.Head = L.Tail = NULL;
	return L;
}

bool KiemTraDSLKRong(LL L)
{
	if(L.Head == NULL)
		return true;
	return false;
}


//a)
void ChenCuoi(LL& L, ElementType x)
{
	NodePointer np;
	np = TaoNut(x);
	if (KiemTraDSLKRong(L))
	{
		L.Head = np;
		L.Tail = np;
	}
	else
	{
		L.Tail->Next = np; // Trỏ next của Tail tới np (móc lai)
		L.Tail = np; // Gán danh hiệu
	}
}

LL TaoDS()
{
	LL L;
	L = TaoDSRong();
	do
	{
		ElementType x;
		printf("Enter data: ");
		scanf("%d", &x);
		if (x == -1) 
			break;
		ChenCuoi(L,x);
	} while (true);
	return L;
}

int XuatDS(LL L)
{
	if (KiemTraDSLKRong(L) == true) 
		return -1;
	NodePointer cur = L.Head;
	while(cur != NULL)
	{
		printf("%d ",cur->Data);
		cur = cur->Next;
	}
	return 1;
}

//b)

void findValue(LL L, ElementType X){
	NodePointer cur = L.Head;
	while(cur != NULL)
	{
		if(cur->Data > X && cur->Data % 2 == 0)
		{
			printf("%d la so chan va %d > X = %d",cur->Data,cur->Data,X);
			break;
		}
		cur = cur->Next;
	}
	if (cur == NULL)
		printf("Khong co gia tri can tim trong danh sach");
}

// c)

NodePointer TimGiaTri(LL L, ElementType X){
	NodePointer cur = L.Head;
	while(cur != NULL)
	{
		if(cur->Data > X && cur->Data % 2 == 0)
			return cur;
		cur = cur->Next;
	}
	return NULL;
}

void mixLinkList(LL& L1, NodePointer M, LL L2)
{
	if (M == L1.Tail)
	{
		M->Next = L2.Head;
		L1.Tail = L2.Tail;
	}
	else
	{
		L2.Tail->Next = M->Next;
		M->Next = L2.Head;
	}
}

void ChenDanhSach(LL L1, LL L2, ElementType X)
{
	NodePointer cur = TimGiaTri(L1,X);
	if (cur == NULL)
		cur = L1.Tail;
	mixLinkList(L1,cur,L2);
}


//d)

void removeNode(LL& L,NodePointer& pre_node, NodePointer& cur_node)
{
	NodePointer tmp = cur_node;
	if (cur_node == L.Head)
	{
		L.Head = L.Head->Next;
		cur_node = cur_node->Next;
	}
	else
	{
		cur_node = cur_node->Next;
	 	pre_node->Next = cur_node;
	}
	tmp->Next = NULL;
	delete tmp;
}

LL removeTwoNode(LL L, int X)
{
	if (KiemTraDSLKRong(L))
		return L;
	NodePointer cur_node = L.Head;
	NodePointer pre_node = NULL;
	int count = 0;
	while(cur_node != NULL && count < 2)
	{
		if (cur_node->Data < X)
		{
			removeNode(L,pre_node,cur_node);
			count++;
		}
		else
		{
			pre_node = cur_node;
			cur_node = cur_node->Next;
		}
	}
	return L;
}

int main()
{
	LL L1= TaoDSRong();
	LL L2 ;
	int x,y;
	int choice = -1;
    while (choice != 0)
    {
        printf("What do you want to do?\n");
        printf("[0] Exit\n");
        printf("[1] Chen Cuoi vao L1\n");
        printf("[2] Tim trong L1 va xuat ra gia tri chan dau tien lon hon X \n");
        printf("[3] Chen L2 vao L1 sau mot gia tri chan dau tien lon hon X trong L1\n");
        printf("[4] Xoa hai nut dau tien co du lieu nho hon X cho truoc trong L1\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            return 0;
            break;

        case 1:
			printf("X = ");
			scanf("%d",&x);
			ChenCuoi(L1,x);
			break;

        case 2:
			printf("X = ");
			scanf("%d",&x);
            findValue(L1,x);

        case 3:
			printf("Nhap du lieu L2");
			L2 = TaoDS();
			printf("X = ");
			scanf("%d",&x);
			ChenDanhSach(L1,L2,x);
			printf("Before\n");
			XuatDS(L1);
			printf("After\n");
			XuatDS(L1);
            break;

        case 4:
			printf("X = ");
			scanf("%d",&x);
			printf("Before\n");
			XuatDS(L1);
			L1 = removeTwoNode(L1,x);
			printf("After\n");
			XuatDS(L1);
            break;

        default:
            // do nothing, just loop again
            break;
        }
        printf("\n\n");
    }
}