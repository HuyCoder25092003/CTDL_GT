#include <iostream>
#include <cstring>
#include <conio.h>
using namespace std;
struct Data
{
	int ma;
	char baihat[20];
	char nhacsi[40];
};
struct Node
{
	Data data;
	Node* address;
}; typedef struct Node node;
struct List
{
	node* head, * tail;
}; typedef struct List list;
void intitData(list& l)
{
	l.head = l.tail = NULL;
}
void onesp(Data& data)
{
	cout << "Ma san pham\n";
	cin >> data.ma;
	cin.ignore();
	cout << "Ten bai hat\n";
	cin.getline(data.baihat, 20);
	cout << "Ten nhac si\n";
	cin.getline(data.nhacsi, 20);
}
node* createdData(Data data)
{
	node* p = new node;
	if (p == NULL)
		return NULL;
	else
	{
		p->data = data;
		p->address = NULL;
		return p;
	}
}
void input(node* p, list& l)
{
	if (l.head == NULL)
		l.head = l.tail = p;
	else
	{
		l.tail->address = p;
		l.tail = p;
	}
}
void output(list l)
{
	node* p = l.head;
	while (p != NULL)
	{
		cout << p->data.ma << "\t" << p->data.baihat << "\t" << p->data.nhacsi << "\t" << endl;
		p = p->address;
	}
}
void swap(Data& a, Data& b)
{
	Data c = a;
	a = b;
	b = c;
}
void hight(list& l)
{
	for (node* p = l.head; p != NULL; p = p->address)
	{
		for (node* q = p->address; q != NULL; q = q->address)
			if (p->data.ma > q->data.ma)
				swap(p->data, q->data);
	}
}
void xoadau(List& l)
{
	if (!l.head)
		cout << "Emty list \n";
	else if (l.head == l.tail)
	{
		delete l.head;
		l.head = l.tail = NULL;
	}
	else
	{
		node* p = l.head;
		l.head = l.head->address;
		delete p;
	}
}
void xoaphantu(List& lst, node* p)
{
	if (!lst.head)
		cout << "Khong co danh sach\n";
	else if (lst.head == lst.tail)
	{
		delete lst.head;
		lst.head = lst.tail = NULL;
	}
	else
	{
		node* temp = p->address;
		if (temp)
		{
			p->address = temp->address;
			delete temp;
		}
	}
}
void Deletes(list& l, string name)
{
	if (l.head == NULL)
		cout << "Khong co phan tu de xoa \n";
	else
	{
		node* temp = l.head;
		node* q = NULL;
		while (temp != NULL && temp->data.baihat != name)
		{
			q = temp;
			temp = temp->address;
		}
		if (temp)
		{
			if (temp == l.head)
				xoadau(l);
			else
				xoaphantu(l, q);
		}
	}
}
int main()
{
	list l;
	int choose;
	intitData(l);
	bool check = false;
	Data data;
	node* p = { 0 };
	do {
		system("cls");
		cout << "\t\tMenu\n";
		cout << "\t1:Nhap danh sach\n";
		cout << "\t2:Xuat danh sach\n";
		cout << "\t3:Sap xep danh sach giam dan\n";
		cout << "\t4:Xoa ten san pham ban muon\n";
		cout << "\t5:Exit\n";
		cin >> choose;
		switch (choose)
		{
		case 1:
			onesp(data);
			p = createdData(data);
			input(p, l);
			check = true;
			cout << "Nhap thanh cong\n";
			break;
		case 2:
			if (check)
				output(l);
			else cout << "Khong co du lieu\n";
			break;
		case 3:
			if (check)
			{
				hight(l);
				cout << "Sap xep thanh cong. Bam so 2 de check\n";
			}
			else cout << "Khong co du lieu\n";
			break;
		case 4:
			if (check)
			{
				cin.ignore();
				char ten[40];
				cout << "Nhap ten bai hat ban muon xoa\n";
				cin.getline(ten, 20);
				Deletes(l, ten);
				cout << "Xoa thanh cong. Bam so 2 de kiem tra\n";
			}
			else cout << "Khong co du lieu\n";
			break;
		case 5:
			break;
		default:
			cout << "Xoa thanh cong\n";
		}
		_getch();
	} while (choose > 0 && choose < 5);
	return 0;
}
