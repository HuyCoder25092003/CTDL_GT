#include<iostream>
#include <cstring>
#include <string>
using namespace std;
struct donhang
{
	int maDH, tongSP, ttDH;
	char ngayDH[9];
	double tongDH;
	string tenKH;
	string trangthai;
};
string tt[] = { "dang cho giao" , "dang tren duong giao", "da giao hoan tat" };
struct Node
{
	donhang value;
	Node* next, * prev;
};
void init(Node*& first, Node*& last)
{
	first = last = NULL;
}
Node* createNode(donhang x)
{
	Node* p = new Node;
	p->value = x;
	p->next = NULL;
	p->prev = NULL;
	return p;
}
void insertFirst(Node*& first, Node*& last, Node *p)
{
	if (first == NULL)
		first = last = p;
	else
	{
		last->next = p;
		p->prev =last;
		last = p;
	}
}
void deleteFirst(Node*& first, Node*& last)
{
	if (first != NULL)
	{
		Node* p = first;
		first = first->next;
		delete p;
		if (first != NULL)
			first->prev = NULL;
		else last = NULL;
	}
}
void InputOneSp(donhang& data)
{
	cout << "Ma don hang \n";
	cin >> data.maDH;
	cin.ignore();
	cout << "Ngay don hang\n";
	cin.getline(data.ngayDH, 9);
	cout << "Tong gia tri don hang\n";
	cin >> data.tongDH;
	cout << "Tong so san pham\n";
	cin >> data.tongSP;
	cin.ignore();
	cout << "Ten khach hang\n";
	getline(cin, data.tenKH);
	cout << "Tinh trang don hang(1:dang cho giao , 2:dang tren duong giao , 3:da giao hoan tat )\n";
	cin >> data.ttDH;
	switch (data.ttDH)
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
void OutPut(Node*first)
{
	Node* p = first;
	while (p != NULL)
	{
		cout << p->value.maDH << "\t" << p->value.ngayDH << "\t"
			<< p->value.tongDH << "\t" << p->value.tongSP
			<< "\t" << p->value.tenKH << "\t" << p->value.trangthai << endl;
		p = p->next;
	}
}
Node* search(Node * first,string date) // theo ngày
{
	Node* p = first;
	while (p != NULL && p->value.ngayDH != date)
		p = p->next;
	return p;
}
Node* search1(Node* first,string name) // tìm theo tên 
{
	Node* p = first;
	while (p != NULL && p->value.tenKH != name)
		p = p->next;
	return p;
}
double tongDoanhThu(Node* first)
{
	Node* p = first;
	double tong = 0;
	while (p != NULL)
	{
		tong += p->value.tongDH;
		p = p->next;
	}
	return tong;
}
int main()
{
	donhang data;
	Node* first , * last;
	init(first, last);
	InputOneSp(data);
	Node* p = createNode(data);
	insertFirst(first, last,p);
	OutPut(first);
}