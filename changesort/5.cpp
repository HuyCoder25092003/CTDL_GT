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
void Addfirst(list& lst, int value)
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
bool nto(int n)
{
	if (n < 2)
		return false;
	else {
		for (int i = 2;i <= sqrt(double(n));i++)
			if (n % i == 0)
				return false;
	}
	return true;
}
void printnto(list lst)
{
	node* p = lst.first;
	while (p != NULL)
	{
		if (nto(p->data))
			cout << p->data << "\t";
		p = p->addrrees;
	}
	cout << endl;
}
bool chinhphuong(int n)
{
	int i = 0;
	while (i*i<=n)
	{
		if (i * i == n)
			return true;
		i++;
	}
	return false;
}
void printchinhphuong(list lst)
{
	node* p = lst.first;
	while (p != NULL)
	{
		if (chinhphuong(p->data))
			cout << p->data << "\t";
		p = p->addrrees;
	}
	cout << endl;
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
		cout << "3:In cac so nguyen to trong danh sach\n";
		cout << "4:In cac so chinh phuong trong danh sach\n";
		cout << "5:Exit\n";
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
				printnto(lst);
			else cout << "Khong co du lieu \n";
			break;
		case 4:
			if (in)
				printchinhphuong(lst);
			else cout << "Khong co du lieu \n";
			break;
		case 5:
			break;
		default:
			cout << "Khong co chuc nang tren\n";
		}
		_getch();
	} while (chon >= 1 && chon <= 4);
	return 0;
}