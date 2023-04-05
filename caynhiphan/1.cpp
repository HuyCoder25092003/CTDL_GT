#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;
struct Node
{
	int value;
	Node* left;
	Node* right;
}; typedef struct Node node;
void init(node*& root)
{
	root = NULL;
}
node* creatData(int x)
{
	node* p = new node;
	p->left = p->right = NULL;
	p->value = x;
	return p;
}
void Add(node*& p, int value)
{
	if (p == NULL)
		p = creatData(value);
	else
	{
		if (p->value == value)
			return;
		else if (p->value < value)
			Add(p->right, value);
		else Add(p->left, value);
	}
}
node* search(node* p, int value)
{
	if (p != NULL)
	{
		if (p->value == value)
			return p;
		else if (p->value < value)
			search(p->right, value);
		else search(p->left, value);
	}
	return NULL;
}
void searchStandFor(node*& p, node*& q)
{
	if (q->left == NULL)
	{
		p->value == q->value;
		p = q;
		q = q->right;
	}
	else searchStandFor(p, q->left);
}
void Deletetree(node*& t, int value)
{
	if (t == NULL)
		return;
	if (t->value == value)
	{
		node* p = t;
		if (t->left == NULL)
			t = t->right;
		else if (t->right == NULL)
			t = t->left;
		else searchStandFor(p, t->right);
		delete p;
		return;
	}
	if (t->value < value)  Deletetree(t->right, value);
	if (t->value > value)  Deletetree(t->left, value);
}
void acceptNLR(node* p)
{
	if (p != NULL)
	{
		cout << p->value << "\t";
		acceptNLR(p->left);
		acceptNLR(p->right);
	}
}
void acceptLNR(node* p)
{
	if (p != NULL)
	{
		acceptLNR(p->left);
		cout << p->value << "\t";
		acceptNLR(p->right);
	}
}
void acceptLRN(node* p)
{
	if (p != NULL)
	{
		acceptLRN(p->left);
		acceptLRN(p->right);
		cout << p->value << "\t";
	}
}
int SumNode(node* p)
{
	if (p == NULL)
		return 0;
	return 1 + SumNode(p->left) + SumNode(p->right);
}
int checkchan(int n)
{
	return n % 2 == 0 ? true : false;
}
int checkle(int n)
{
	return n % 2 != 0 ? true : false;
}
int nto(int n)
{
	if (n < 2)
		return true;
	else {
		for (int i = 2; i <= sqrt(double(n)); i++)
			if (n % i == 0)
				return false;
	}
	return true;
}
int checkchinhphuong(int n)
{
	int i = 0;
	while (i * i <= n)
	{
		if (i * i == n)
			return true;
	}
	return false;
}
int Nodeeven(node* p)
{
	if (p != NULL)
	{
		int a = Nodeeven(p->left);
		int b = Nodeeven(p->right);
		if (checkchan(p->value))
			return 1 + a + b;
		return a + b;
	}
	return 0;
}
int Nodeodd(node* p)
{
	if (p != NULL)
	{
		int a = Nodeeven(p->left);
		int b = Nodeeven(p->right);
		if (checkle(p->value))
			return 1 + a + b;
		return a + b;
	}
	return 0;
}
int Nodeelement(node* p)
{
	if (p != NULL)
	{
		int a = Nodeeven(p->left);
		int b = Nodeeven(p->right);
		if (nto(p->value))
			return 1 + a + b;
		return a + b;
	}
	return 0;
}
int righteous(node* p)
{
	if (p != NULL)
	{
		int a = Nodeeven(p->left);
		int b = Nodeeven(p->right);
		if (checkchinhphuong(p->value))
			return 1 + a + b;
		return a + b;
	}
	return 0;
}
int main()
{
	node* root;
	int choose;
	bool in = false;
	init(root);
	do {
		system("cls");
		cout << "\t\tMenu\n";
		cout << "\t\t1:Them phan tu vao cay\n";
		cout << "\t\t2:Tim phan tu trong cay\n";
		cout << "\t\t3:Xoa mot nut tren cay\n";
		cout << "\t\t4:Duyet cac phan tu theo thu tu NLR\n";
		cout << "\t\t5:Duyet cac phan tu theo thu tu LNR\n";
		cout << "\t\t6:Duyet cac phan tu theo thu tu LRN\n";
		cout << "\t\t7:Tong so node trong cay\n";
		cout << "\t\t8:Co tong cong bao nhieu node la chan \n";
		cout << "\t\t9:Co tong cong bao nhieu node la le \n";
		cout << "\t\t10:Co tong cong bao nhieu node la nguyen to \n";
		cout << "\t\t11:Co tong cong bao nhieu node la chinhphuong \n";
		cout << "\t\t12:Exit\n";
		cin >> choose;
		switch (choose)
		{
		case 1:
			int x;
			cout << "Nhap phan tu ban muon them vao\n";
			cin >> x;
			Add(root, x);
			cout << "Them phan tu thanh cong\n";
			in = true;
			break;
		case 2:
			if (in)
			{
				int value;
				cout << "Tim phan tu ban muon tim\n";
				cin >> value;
				if (search(root, value) == root)
					cout << "Tim thay phan tu do trong cay\n";
				else cout << "Khong tim thay phan tu do trong cay\n";
			}
			else cout << "Khong co du lieu vui long bam so 1 de them data";
			break;
		case 3:
			if (in)
			{
				int y;
				cout << "Nhap gia tri ban muon xoa\n";
				cin >> y;
				Deletetree(root, y);
				cout << "Xoa thanh cong vui long bam so 4 hoac 5 hoac 6 dem xem ket qua\n";
			}
			else cout << "Khong co du lieu vui long bam so 1 de them data";
			break;
		case 4:
			if (in)
			{
				cout << "Duyet cay theo thu tu NLR\n";
				acceptNLR(root);
			}
			else cout << "Khong co du lieu vui long bam so 1 de them data";
			break;
		case 5:
			if (in)
			{
				cout << "Duyet cay theo thu tu LNR\n";
				acceptLNR(root);
			}
			else cout << "Khong co du lieu vui long bam so 1 de them data";
			break;
		case 6:
			if (in)
			{
				cout << "Duyet cay theo thu tu LRN\n";
				acceptLRN(root);
			}
			else cout << "Khong co du lieu vui long bam so 1 de them data";
			break;
		case 7:
			if (in)
			{
				cout << "Tong so node trong cay la: " << SumNode(root) << endl;
			}
			else cout << "Khong co du lieu vui long bam so 1 de them data";
			break;
		case 8:
			if (in)
			{
				cout << "Tong so node chan trong cay la: " << Nodeeven(root) << endl;
			}
			else cout << "Khong co du lieu vui long bam so 1 de them data";
			break;
		case 9:
			if (in)
			{
				cout << "Tong so node le trong cay la: " << Nodeodd(root) << endl;
			}
			else cout << "Khong co du lieu vui long bam so 1 de them data";
			break;
		case 10:
			if (in)
			{
				cout << "Tong so node nguyen to trong cay la: " << Nodeelement(root) << endl;
			}
			else cout << "Khong co du lieu vui long bam so 1 de them data";
			break;
		case 11:
			if (in)
			{
				cout << "Tong so node chinh phuong trong cay la: " << righteous(root) << endl;
			}
			else cout << "Khong co du lieu vui long bam so 1 de them data";
			break;
		case 12:
			break;
		default:
			cout << "Khong co chuc nang tren menu\n";
			delete root;
		}
		_getch();
	} while (choose > 0 && choose < 12);
	return 0;
}