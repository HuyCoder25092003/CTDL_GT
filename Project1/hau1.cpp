#include "Node.h"
void initData(list& l)
{
	l.head = l.tail = NULL;
}
void nhap1(SanPham& sp)
{
	cin.ignore();
	cout << "Nhap ten san pham\n";
	getline(cin, sp.name);
	cout << "Nhap gia san pham\n";
	cin >> sp.value;
}
node* createData(SanPham value)
{
	node* p = new node;
	if (p == NULL)
		return NULL;
	else
	{
		p->next = p->prev = NULL;
		p->data = value;
		return p;
	}
}
void AddLast(node* p, list &l)
{
	if (l.head == NULL)
		l.head = l.tail = p;
	else
	{
		l.tail->next = p;
		p->prev = l.tail;
		l.tail = p;
	}
}
void OutPut(list l)
{
	node* p = l.head;
	while (p != NULL)
	{
		cout << p->data.name << "\t" << p->data.value<<"\t"<<endl;
		p = p->next;
	}
}
void OutPut2(list l, int value1, int value2)
{
	for (node* p = l.head; p != NULL; p = p->next)
	{
		if (p->data.value >= value1 && p->data.value <= value2)
			cout << p->data.name << "\t" << p->data.value<<endl;
	}
}
int main()
{
	SanPham sp;
	list l;
	node* p={0};
	initData(l);
	int choose;
	bool check = false;
	do
	{
		system("cls");
		cout << "\tMenu\n";
		cout << "\t1:Them danh sach \n";
		cout << "\t2:Xuat danh sach\n";
		cout << "\t3:Xuat danh sach trong khoang\n";
		cout << "\t4:Exit\n";
		cin >> choose;
		switch (choose)
		{
		case 1:
			nhap1(sp);
			p = createData(sp);
			AddLast(p,l);
			check = true;
			break;
		case 2:
			if (check)
				OutPut(l);
			else cout << "Khong co du lieu\n";
			break;
		case 3:
			if (check)
			{
				int value1, value2;
				cout << "Nhap 2 muc gia tra trong khoang tu gia tri thu 1 toi gia tri thu 2\n";
				cin >> value1 >> value2;
				OutPut2(l, value1, value2);
			}
			else cout << "Khong co du lieu\n";
			break;
		case 4:
			break;
		default:
			cout << "Khong co chuc nang tren\n";
		}
		_getch();
	} while (choose > 0 && choose < 4);
}