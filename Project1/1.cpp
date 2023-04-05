#include <iostream>
#include <conio.h>
using namespace std;
struct NODE
{
	int data;
	NODE* address;
};
struct List
{
	NODE* phead;
	NODE* ptail;
};
void khoidong(List& lst) 
{
	lst.phead = lst.ptail = NULL;
}
NODE* taodanhsach(int data)
{
	NODE* p = new NODE;
	if (p == NULL)
		return NULL;
	else 
	{
		p->data = data;
		p->address = NULL;
	}
	return p;
}
void themdaudanhsach(List& lst, NODE* p)
{
	if (!lst.phead)
		lst.phead = lst.ptail = p;
	else 
	{
		p->address = lst.phead;
		lst.phead = p;
	}
}
NODE* timkiem(List& lst, int value)
{
	NODE* p = lst.phead; 
	while (p != NULL && p->data != value)
		p = p->address;
	return p;
}
void xuat(List lst)
{
	NODE* p = lst.phead;
	while (p != NULL)
	{
		cout << p->data << "\t";
		p = p->address;
	}
}
void xoadau(List& lst)
{
	if (!lst.phead)
		cout << "Emty list \n";
	else if (lst.phead == lst.ptail)
	{
		delete lst.phead;
		lst.phead = lst.ptail = NULL;
	}
	else
	{
		NODE* p = lst.phead;
		lst.phead = lst.phead->address;
		delete p;
	}
}
void themcuoi(List& lst, NODE* p)
{
	if (!lst.phead)
		lst.phead = lst.ptail = p;
	else
	{
		lst.ptail->address = p;
		lst.ptail = p;
	}
}
void xoacuoi(List& lst)
{
	if (!lst.phead)
		cout << "Khong co danh sach \n";
	else if (lst.phead == lst.ptail)
	{
		delete lst.phead;
		lst.phead = lst.ptail = NULL;
	}
	else
	{
		NODE* temp = lst.phead; 
		while (temp->address != lst.ptail)
			temp = temp->address;
		temp->address = NULL;
		delete lst.ptail;
		lst.ptail = temp;
	}
}
void xoaphantu(List& lst, NODE* p)
{
	if (!lst.phead)
		cout << "Khong co danh sach\n";
	else if (lst.phead == lst.ptail)
	{
		delete lst.phead;
		lst.phead = lst.ptail = NULL; 
	}
	else
	{
		NODE* temp = p->address;
		if (temp)
		{
			p->address = temp->address;
			delete temp;
		}
	}
}
void xoaphantutimthay(List& lst, int value)
{
	if (!lst.phead)
		cout << "Khong co danh sach\n";
	else
	{
		NODE* temp = lst.phead;
		NODE* q = NULL;
		while (temp != NULL && temp->data != value)
		{
			q = temp;
			temp = temp->address;
		}
		if (temp)
		{
			if (temp == lst.phead)
				xoadau(lst);
			else
				xoaphantu(lst, q);
		}
	}
}
void hoandoi(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}
void tangdan(List&lst)
{
	for (NODE* p = lst.phead; p != NULL; p = p->address)
	{
		for (NODE* p2 = p->address; p2 != NULL; p2 = p2->address)
			if (p->data > p2->data)
				hoandoi(p->data, p2->data);
	}
}
int danhsachcobaonhieuphantu(List lst)
{
	int dem = 0;
	while (lst.phead != NULL)
	{
		dem++;
		lst.phead = lst.phead->address;
	}
	return dem;
}
int mang(List lst, int*& a)
{
	int n = danhsachcobaonhieuphantu(lst), dem = 0;
	a = new int[n];
	while (lst.phead != NULL)
	{
		a[dem++] = lst.phead->data;
		lst.phead = lst.phead->address;
	}
	return n;
}
void tangdan(List lst, int*& a, int& n)
{
	n = mang(lst, a);
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
				hoandoi(a[i], a[j]);
	}
}
void xoahet(List& lst)
{
	NODE* p = lst.phead;
	while (lst.phead)
	{
		p = p->address;
		delete lst.phead;
		lst.phead = p;
	}
	lst.phead = lst.ptail = NULL;
}
int main()
{
	List lst;
	khoidong(lst);
	int data;
	int chon;
	NODE* p = { 0 };
	bool in = false;
	do {
		system("cls");
		cout << "\t\tMenu\n";
		cout << "1:Them phan tu vao dau danh sach\n";
		cout << "2:Xuat phan tu cua danh sach\n";
		cout << "3:Tim phan tu trong danh sach\n";
		cout << "4:Xoa phan tu dau trong danh sach\n";
		cout << "5:Them mot phan tu vao cuoi danh sach\n";
		cout << "6:Xoa phan tu khoi cuoi danh sach\n";
		cout << "7:Tim xong xoa khoi danh sach\n";
		cout << "8:Sap xep danh sach tang dan\n";
		cout << "9:Xoa het phan tu\n";
		cout << "10:Exit\n";
		cin >> chon;
		switch (chon)
		{
		case 1:
			cout << "Them phan tu vao dau danh sach ban muon \n";
			cin >> data;
			p = taodanhsach(data);
			themdaudanhsach(lst, p);
			cout << "Them thanh cong \n";
			in = true;
			break;
		case 2:
			if (in)
			{
				cout << "Thong tin cac phan tu hien co trong danh sach\n";
				xuat(lst);
			}
			else cout << "Khong co du lieu \n";
			break;
		case 3:
			if (in)
			{
				int x;
				cout << "Nhap gia tri ban muon tim kiem \n";
				cin >> x;
				NODE* temp = timkiem(lst, x);
				if (temp == NULL)
					cout << "Khong tim thay con " << x << endl;
				else cout << "Tim thay con " << x << endl;
			}
			else cout << "Khong co du lieu \n";
			break;
		case 4:
			if (in)
			{
				xoadau(lst);
				cout << "Xoa dau thanh cong \n";
			}
			else cout << "Khong co du lieu \n";
			break;
		case 5:
			if (in)
			{
				int data1;
				cout << "Them phan tu phia sau ban muon \n";
				cin >> data1;
				NODE* ptr = taodanhsach(data1);
				themcuoi(lst, ptr);
				cout << "Them thanh cong \n";
			}
			else cout << "Khong co du lieu \n";
			break;
		case 6:
			if (in)
			{
				xoacuoi(lst);
				cout << "Xoa cuoi thanh cong \n";
			}
			else cout << "Khong co du lieu \n";
			break;
		case 7:
			if (in)
			{
				int value;
				cout << "Nhap phan tu ban muon tim de xoa \n";
				cin >> value;
				xoaphantutimthay(lst, value);
				
				cout << "Xoa thanh cong \n";
			}
			else cout << "Khong co du lieu \n";
			break;
		case 8:
			if (in)
			{
				int* a;
				int n = 0;
				tangdan(lst, a, n);
				for (int i = 0; i < n; i++)
					cout << a[i] << "\t";
				delete[]a;
			}
			else cout << "Khong co du lieu \n";
			break;
		case 9:
			if (in)
			{
				xoahet(lst);
				cout << "Xoa het phan tu thanh cong \n";
			}
			else cout << "Khong co du lieu \n";
			break;
		case 10:
			break;
		default:
			cout << "Khong co chuc nang tren\n";
			delete p;
		}
		_getch();
	} while (chon >= 1 && chon <= 9);
}