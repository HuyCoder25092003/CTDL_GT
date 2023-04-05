#include <iostream>
#include <conio.h>
using namespace std;
struct Node
{
	int data;
	Node* address;
};
struct List
{
	Node* head;
	Node* tail;
};
void init(List& lst)
{
	lst.head = lst.tail = NULL;
}
Node* createData(int value)
{
	Node* p = new Node;
	if (p == NULL)
		return NULL;
	else
	{
		p->data = value;
		p->address = NULL;
	}
	return p;
}
bool empty(List lst)
{
	return lst.head == NULL ? true : false;
}
void push(List& lst, int value, Node* p)
{
	if (!lst.head)
		lst.head = lst.tail = p;
	else
	{
		p->address = lst.head;
		lst.head = p;
	}
}
void pop(List& lst)
{
	if (empty(lst))
		cout << "Khong co danh sach nao de xoa ca\n";
	else if (lst.head == lst.tail)
	{
		delete lst.head;
		lst.head = lst.tail = NULL;
	}
	else
	{
		Node* p = lst.head;
		lst.head = lst.head->address;
		delete p;
	}
}
void ProceesList(List lst)
{
	Node* p = lst.head;
	while (p != NULL)
	{
		cout << p->data << "\t";
		p = p->address;
	}
}
int main()
{
	List lst;
	Node* p = { 0 };
	init(lst);
	int choose;
	bool in = false;
	do {
		system("cls");
		cout << "\t\tMenu\n";
		cout << "1:Kiem tra stack hien tai co rong khong\n";
		cout << "2:Them 1 phan tu vao stack\n";
		cout << "3:Xoa 1 phan tu trong stack\n";
		cout << "4:Xem man hinh console ket qua hien tai trong stack\n";
		cout << "5:Exit\n";
		cin >> choose;
		switch (choose)
		{
		case 1:
			if (empty(lst))
				cout << "Stack hien tai dang rong\n";
			else cout << "Stack hien tai khong rong\n";
			break;
		case 2:
			int value;
			cin >> value;
			p = createData(value);
			push(lst, value, p);
			in = true;
			break;
		case 3:
			if (in)
			{
				pop(lst);
				cout << "Xoa thanh cong\n";
			}
			else cout << "khong co du lieu vui long bam so 3 de them\n";
			break;
		case 4:
			if (in)
			{
				ProceesList(lst);
			}
		case 5:
			break;
		default:
			cout << "Khong co chuc nang tren\n";
		}
		_getch();
	} while (choose >= 1 && choose <= 4);
}