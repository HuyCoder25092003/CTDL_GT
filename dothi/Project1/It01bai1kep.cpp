﻿#include <iostream>
#include <cstring>
#include <string>
#include <conio.h>
using namespace std;
struct Data
{
	int ma, tongsp;
	char date[9]; // do kí tự cuối cùng là kí tự xuống dòng nên phải để dư nó 
	string ten;
	int tt;
	string trangthai;
	double giatri;
};
string tt[] = { "dang cho giao" , "dang tren duong giao", "da giao hoan tat" };
struct Node
{
	Data data;
	Node* next;
	Node* prev;
};
Node* first,*last;
Node* createData(Data value)
{
	Node* p = new Node;
	if (p == NULL)
		return NULL;
	else
	{
		p->data = value;
		p->next = p->prev = NULL;
		return p;
	}
}
void InputOneSp(Data& data)
{
	cout << "Ma don hang \n";
	cin >> data.ma;
	cin.ignore();
	cout << "Ngay don hang\n";
	cin.getline(data.date, 9);
	cout << "Tong gia tri don hang\n";
	cin >> data.giatri;
	cout << "Tong so san pham\n";
	cin >> data.tongsp;
	cin.ignore();
	cout << "Ten khach hang\n";
	getline(cin, data.ten);
	cout << "Tinh trang don hang(1:dang cho giao , 2:dang tren duong giao , 3:da giao hoan tat )\n";
	cin >> data.tt;
	switch (data.tt)
	{
	case 1:
		data.trangthai = tt[0];
		break;
	case 2:
		data.trangthai = tt[1];
		break;
	case 3:
		data.trangthai = tt[2];
		break;
	}
}
void Input(Node *&p) // thêm cuối
{
	if (first == NULL)
		first = last = p;
	else
	{
		p->prev = last;
		last->next = p;
		last = p;
	}
}
void OutPut()
{
	Node* p = first;
	while (p != NULL)
	{
		cout << p->data.ma << "\t" << p->data.date << "\t"
			<< p->data.giatri << "\t" << p->data.tongsp
			<< "\t" << p->data.ten << "\t" << p->data.trangthai << endl;
		p = p->next;
	}
}
void DeleteFirst()// xóa đầu
{
	if (first != NULL)
	{
		Node* p = first;
		first = first->next;
		delete p;
		if (first != NULL) // trường hợp ds khácrỗng phần tử nào
			first->prev = NULL;
		else last = NULL; // trường hợp ds không còn phần tử nào
	}
}
void DeleteLast()
{
	if (last != NULL)
	{
		Node* p = last;
		last = last->prev;
		if (last != NULL) // trường hợp danh sách khác rỗng
			last->next = NULL;
		else first == NULL; // ds ko còn phần tử nào
		delete p;
	}
}
Node* search(string date)
{
	Node* p = first;
	while (p != NULL && p->data.date != date)
		p = p->next;
	return p;
}
Node* search1(string name) // tìm theo tên 
{
	Node* p = first;
	while (p != NULL && p->data.ten != name)
		p = p->next;
	return p;
}
void Remove(string name) // xóa theo tên
{
	Node* p = search1(name);
	if (p != NULL) // tìm thấy 
	{
		if (p->prev == NULL) // xóa đầu 
		{
			DeleteFirst();
			return;
		}
		if (p->next == NULL) // xóa cuối 
		{
			DeleteLast();
			return;
		}
		// thay đổi liên kết của thằng xóa (debug là thấy nha ) còn ko hỉu thì nhắn qua mess rồi chạy tay cho 
		p->prev->next = p->next;
		p->next->prev = p->prev;
		// gán con trỏ prev và next của thang xoa ve NULL
		p->prev = p->next = NULL;
		delete p;
	}
}
double tong()
{
	Node* p = first;
	int sum = 0;
	while (p != NULL)
	{
		sum += p->data.giatri;
		p = p->next;
	}
	return sum;
}
int main()
{
	Data data;
	int choose;
	bool in = false;
	Node* p = 0;
	do {
		system("cls");
		cout << "\t\tMenu\n";
		cout << "\t1:Nhap danh sach\n";
		cout << "\t2:Xuat danh sach\n";
		cout << "\t3:Xoa phan tu trong danh sach\n";
		cout << "\t4:Tim kiem don hang \n";
		cout << "\t5:Tong doanh thu 1 ngay\n";
		cout << "\t6:Exit\n";
		cin >> choose;
		switch (choose)
		{
		case 1:
			InputOneSp(data);
			p = createData(data);
			Input(p);
			in = true;
			break;
		case 2:
			if (in)
				OutPut();
			else cout << "Khong co du lieu\n";
			break;
		case 3:
			if (in)
			{
				cin.ignore();
				string name;
				cout << "Nhap ten khach hang ban muon xoa\n";
				getline(cin, name);
				if (search1(name) != NULL)
				{
					Remove(name);
					cout << "Xoa thanh cong\n";
				}
				else cout << "Khong co ten ban muon xoa\n";
			}
			else cout << "Khong co du lieu\n";
			break;
		case 4:
			if (in)
			{
				cin.ignore();
				string name;
				cout << "Nhap ten khach hang ban muon tim\n";
				getline(cin, name);
				if (search1(name) != NULL)
					cout << "Tim thay \n";
				else cout << "Khong tim thay \n";
			}
			else cout << "Khong co du lieu\n";
			break;
		case 5:
			if (in)
				cout << "Tong doanh thu trong 1 ngay: " << tong();
			else cout << "Khong co du lieu\n";
			break;
		case 6:
			break;
		default:
			cout << "Khong co chuc nang tren\n";
		}
		_getch();
	} while (choose > 0 && choose < 6);
}