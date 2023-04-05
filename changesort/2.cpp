#include <iostream>
#include <conio.h>
using namespace std;
struct Node
{
	int data;
	Node* addrrees;
}; typedef struct Node node;
struct List
{
	node* first;
	node* last;
}; typedef struct List list;
void init(list& lst)
{
	lst.first = lst.last = NULL;
}
node* creatData(int value)
{
	node* p = new node;
	if (p == NULL)
		return NULL;
	else
	{
		p->data = value;
		p->addrrees = NULL;
	}
	return p;
}
void Addfirst(list &lst,int value)
{
	node* p = creatData(value);
	if (!lst.first)
		lst.first = lst.last = p;
	else
	{
		p->addrrees = lst.first;
		lst.first = p;
	}
}
void Output(list lst)
{
	node* p = lst.first;
	while (p != NULL)
	{
		cout << p->data << "\t";
		p = p->addrrees;
	}
}
void InterchangeSort(list lst)
{
	for (node *p = lst.first; p->addrrees != NULL; p = p->addrrees)
	{
		for (Node* q = p->addrrees; q != NULL; q = q->addrrees)
			if (p->data > q->data)
			{
				swap(p->data, q->data);
			}
	}
}
void SelectionSort(list lst)
{
	for (node *p = lst.first; p->addrrees != NULL; p = p->addrrees)
	{
		int min_pos = p->data;
		for (Node* q = p->addrrees; q != NULL; q = q->addrrees)
		{
			if (q->data< min_pos)
				swap(q->data, min_pos);
		}
		p->data = min_pos;
	}
}
void InsertionSort(list lst)
{
	for (Node* i = lst.first; i != NULL; i = i->addrrees)
		for (Node* j = i; j != NULL; j = j->addrrees)
			if (i->data > j->data)
				swap(i->data, j->data);
}

int main()
{
	List lst;
	init(lst);
	int data;
	int chon;
	bool in = false;
	do {
		system("cls");
		cout << "\t\tMenu\n";
		cout << "1:Them phan tu vao dau danh sach\n";
		cout << "2:Xuat phan tu cua danh sach\n";
		cout << "3:Sap xep danh sach theo InterchangeSort\n";
		cout << "4:Sap xep danh sach theo SelectionSort\n";
		//cout << "5:Sap xep danh sach theo InsertionSort\n";
		cout << "6:Exit\n";
		cin >> chon;
		switch (chon)
		{
		case 1:
			cout << "Them phan tu vao dau danh sach ban muon \n";
			cin >> data;
			Addfirst(lst, data);
			cout << "Them thanh cong \n";
			in = true;
			break;
		case 2:
			if (in)
			{
				cout << "Thong tin cac phan tu hien co trong danh sach\n";
				Output(lst);
			}
			else cout << "Khong co du lieu \n";
			break;
		case 3:
			if (in)
			{
				InterchangeSort(lst);
				cout << "Sap xep thanh cong\n";
			}
			else cout << "Khong co du lieu \n";
			break;
		case 4:
			if (in)
			{
				SelectionSort(lst);
				cout << "Sap xep thanh cong\n";
			}
			else cout << "Khong co du lieu \n";
			break;
		/*case 5:
			if (in)
			{
				int* a;
				int n = 0;
				InsertionSort(lst, a, n);
				for (int i = 0; i < n; i++)
					cout << a[i] << "\t";
				delete[]a;
			}*/
		case 6:
			break;
		default:
			cout << "Khong co chuc nang tren\n";
		}
		_getch();
	} while (chon >= 1 && chon <= 4);
	return 0;
}