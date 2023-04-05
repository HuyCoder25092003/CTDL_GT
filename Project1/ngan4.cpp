#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
struct DATA
{
	string mssv, ten;
	double tb;
};
struct NODE
{
	DATA data;
	NODE* address;
};
struct List
{
	NODE* head;
	NODE* tail;
};
void init(List& lst)
{
	lst.head = lst.tail = NULL;
}
NODE* createData(string mssv, string ten, double tb)
{
	NODE* p = new NODE;
	if (p == NULL)
		return NULL;
	else
	{
		p->data.mssv = mssv;
		p->data.ten = ten;
		p->data.tb = tb;
		p->address = NULL;
	}
	return p;
}
void Addhead(List& lst, NODE* p)
{
	if (!lst.head)
		lst.head = lst.tail = p;
	else
	{
		p->address = lst.head;
		lst.head = p;
	}
}
void Deleteadd(List& lst, NODE* p)
{
	if (!lst.head)
		cout << "Khong the xoa duoc do danh sach khong co phan tu\n";
	else if (lst.head == lst.tail)
	{
		delete lst.head;
		lst.head = lst.tail = NULL;
	}
	else
	{
		p = lst.head;
		lst.head = p->address;
		delete p;
	}
}
void Processlist(List lst)
{
	NODE* p = lst.head;
	while (p != NULL)
	{
		cout << p->data.mssv << "\t" << p->data.ten << "\t" << p->data.tb << endl;
		p = p->address;
	}
}
int danhsachcobaonhieuphantu(List lst)
{
	int dem = 0;
	while (lst.head != NULL)
	{
		dem++;
		lst.head = lst.head->address;
	}
	return dem;
}
void Addlast(List& lst, NODE* p)
{
	if (!lst.head)
		lst.head = lst.tail = p;
	else
	{
		lst.tail->address = p;
		lst.tail = p;
	}
}
void Add(List& lst, int position, string mssv, string hoten, double diem)
{
	NODE* p = createData(mssv, hoten, diem);
	if (!lst.head)
		lst.head = lst.tail = p;
	else if (lst.head == lst.tail)
		Addlast(lst, p);
	else
	{
		int n = danhsachcobaonhieuphantu(lst);
		if (position == 0)
			Addhead(lst, p);
		else if (position == n - 1)
			Addlast(lst, p);
		else
		{
			NODE* q = lst.head;
			for (int i = 1; i < position; i++)
				q = q->address;
			p->address = q->address;
			q->address = p;
		}
	}
}
void Deletelast(List& lst)
{
	if (!lst.head)
		cout << "Khong co danh sach \n";
	else if (lst.head == lst.tail)
	{
		delete lst.head;
		lst.head = lst.tail = NULL;
	}
	else
	{
		NODE* temp = lst.head;
		while (temp->address != lst.tail)
			temp = temp->address;
		temp->address = NULL;
		delete lst.tail;
		lst.tail = temp;
	}
}
void Delete(List& lst, int position)
{
	if (!lst.head)
		cout << "Khong the xoa do khong co danh sach truoc do \n";
	else if (lst.head == lst.tail)
	{
		delete lst.head;
		lst.head = lst.tail = NULL;
	}
	else
	{
		NODE* p = lst.head;
		for (int i = 0; i < position - 1; i++)
			p = p->address;
		NODE* temp = p->address;
		p->address = p->address->address;
		delete temp;
	}
}
void xoaphantu(List& lst, NODE* p)
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
		NODE* temp = p->address;
		if (temp)
		{
			p->address = temp->address;
			delete temp;
		}
	}
}
void RemoveNode(List& lst, string s)
{
	if (!lst.head)
		cout << "Khong co danh sach\n";
	else
	{
		NODE* temp = lst.head;
		NODE* q = NULL;
		while (temp != NULL && temp->data.ten != s)
		{
			q = temp;
			temp = temp->address;
		}
		if (temp)
		{
			if (temp == lst.head)
				Deleteadd(lst, q);
			else
				xoaphantu(lst, q);
		}
	}
}
NODE* timkiem(List& lst, string s)
{
	NODE* p = lst.head;
	while (p != NULL && p->data.mssv != s)
		p = p->address;
	return p;
}
int main()
{
	List lst;
	init(lst);
	DATA data;
	int chon;
	string mssv, hoten;
	double diem;
	bool in = false;
	NODE* p = { 0 };
	do {
		system("cls");
		cout << "\t\tMenu\n";
		cout << "\t1:Them sinh vien vao dau danh sach\n";
		cout << "\t2:Xoa sinh vien o dau danh sach\n";
		cout << "\t3:Xuat thong tin sinh vien trong danh sach\n";
		cout << "\t4:Them sinh vien theo chi dinh\n";
		cout << "\t5:Xoa sinh vien theo chi dinh\n";
		cout << "\t6:Xoa cac ten sinh vien chua chuoi con chi dinh\n";
		cout << "\t7:Tim sinh vien theo ma so sinh vien\n";
		cout << "\t8:Exit\n";
		cin >> chon;
		switch (chon)
		{
		case 1:
			cin.ignore();
			cout << "Nhap ma so sinh vien \n";
			getline(cin, mssv);
			cout << "Nhap ho ten \n";
			getline(cin, hoten);
			cout << "Diem trung binh \n";
			cin >> diem;
			p = createData(mssv, hoten, diem);
			Addhead(lst, p);
			cout << "Them thanh cong \n";
			in = true;
			break;
		case 2:
			if (in)
			{
				Deleteadd(lst, p);
				cout << "Xoa thanh cong \n";
			}
			else cout << "Khong co du lieu vui long bam so 1 de cung cap du lieu \n";
			break;
		case 3:
			if (in)
			{
				cout << "Xuat cac thong tin hien co trong danh sach\n";
				Processlist(lst);
			}
			else cout << "Khong co du lieu vui long bam so 1 de cung cap du lieu \n";
			break;
		case 4:
			if (in)
			{
				int n = danhsachcobaonhieuphantu(lst);
				int vitri;
				cout << "Nhap vi tri ban muon them trong danh sach\n";
				do {
					cin >> vitri;
				} while (vitri > n || vitri < 0);
				string ma, name;
				double diemtb;
				cin.ignore();
				cout << "Nhap ma so sinh vien \n";
				getline(cin, ma);
				cout << "Nhap ho ten \n";
				getline(cin, name);
				cout << "Diem trung binh \n";
				cin >> diemtb;
				Add(lst, vitri, ma, name, diemtb);
				cout << "Them thanh cong \n";
			}
			else cout << "Khong co du lieu vui long bam so 1 de cung cap du lieu \n";
			break;
		case 5:
			if (in)
			{
				int n = danhsachcobaonhieuphantu(lst);
				int vitri;
				cout << "Nhap vi tri ban muon xoa trong danh sach\n";
				do {
					cin >> vitri;
				} while (vitri > n || vitri <= 0);
				if (vitri - 1 == 0)
					Deleteadd(lst, p);
				else if (vitri - 1 == n - 1)
					Deletelast(lst);
				else Delete(lst, vitri - 1);
				cout << "Xoa thanh cong \n";
			}
			else cout << "Khong co du lieu vui long bam so 1 de cung cap du lieu \n";
			break;
		case 6:
			if (in)
			{
				cin.ignore();
				int n = danhsachcobaonhieuphantu(lst);
				string chuoi;
				cout << "Nhap ho ten ban muon xoa\n";
				getline(cin, chuoi);
				RemoveNode(lst, chuoi);
				cout << "Xoa thanh cong \n";
			}
			break;
		case 7:
			if (in)
			{
				cin.ignore();
				string masosinhvien1;
				cout << "Nhap ma so sinh vien ban muon tim trong danh sach \n";
				getline(cin, masosinhvien1);
				NODE* q = timkiem(lst, masosinhvien1);
				if (q == NULL)
					cout << "Khong tim thay trong danh sach\n";
				else
					cout << "Co trong danh sach\n";
			}
			break;
		case 8:
			break;
		default:
			cout << "Khong co chuc nang tren\n";
			delete[]p;
		}
		_getch();
	} while (chon >= 1 && chon <= 7);
}