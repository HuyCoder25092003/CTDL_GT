#include<iostream>
using namespace std;

struct donhang
{
	int maDH, tongSP, ttDH;
	char* ngayDH;
	double tongDH;
	char* tenKH;
};
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
void insertFirst(Node*& first, Node*& last, donhang x)
{
	Node* p = createNode(x);
	if (first != NULL)
		first->prev = p;
	else last = p;
	first = p;
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
donhang taoDH(int maDH, char* ngayDH, double tongDH, int tongSP, char* tenKH, int ttDH)
{
	donhang x;
	x.maDH = maDH;
	x.ngayDH = ngayDH;
	x.tongDH = tongDH;
	x.tongSP = tongSP;
	x.tenKH = tenKH;
	x.ttDH = ttDH;
	return x;
}
void out1DH(donhang x)
{
	cout << "Ma don hang: " << x.maDH << endl;
	cout << "Ngay don hang: " << x.ngayDH << endl;
	cout << "Tong gia tri don hang: " << x.tongDH << endl;
	cout << "Tong so SP: " << x.tongSP << endl;
	cout << "Ten khach hang: " << x.tenKH << endl;
	if (x.ttDH == 1)
		cout << "Dang cho giao.\n";
	else if (x.ttDH == 2)
		cout << "Dang tren duong giao.\n";
	else cout << "Da giao hoan tat.\n";
}
void outPut(Node*& first)
{
	Node* p = first;
	int dem = 0;
	while (p != NULL)
	{
		cout << "\t\t\tooo Thong tin don hang thu " << ++dem << " :\n";
		out1DH(p->value);
		cout << "-------------------------------------------\n";
		p = p->next;
	}
}
int searchDH(Node* first, char* tenKH, char* ngayDH)
{
	Node* p = first;
	while (p != NULL)
	{
		for (int i = 0; i < strlen(tenKH); i++)//chuyển hết về thường
			if (p->value.tenKH[i] >= 65 && p->value.tenKH[i] <= 90)
				p->value.tenKH[i] += 32;
		if (strcmp(p->value.tenKH, tenKH) == 0)
			return 1;
		if (strcmp(p->value.ngayDH, ngayDH) == 0)
			return 1;
		p = p->next;
	}
	return 0;
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
	Node* first = NULL, * last = NULL;
	init(first, last);
	char a[] = "02032003";
	char* p = a;
	char b[] = "Le trung hieu";
	char* q = b;
	insertFirst(first, last, taoDH(1, p, 9.7, 5, q, 2));
}