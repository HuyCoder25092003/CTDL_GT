#include <iostream>
#include <stack>
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
	else { 
		p->data = data;
		p->address = NULL;
	}
	return p;
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
void xuat(List lst)
{
	NODE* p = lst.phead;
	while (p != NULL)
	{
		cout << p->data << "\t"; 
		p = p->address;
	}
}
void themthutu(int* a, int &n, int index)
{
	int i = n;
	while (i > 0 && a[i - 1] > index)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[i] = index;
	n++;
}
int check(int* a, int n, int x)
{
	for (int i = 0; i < n; i++)
		if (a[i] == x)
			return i;
	return -1;
}
void timvaxoa(int* a, int &n, int x)
{
	int i = check(a, n, x);
	if (i == -1)
		return;
	else
	{
		for (int j = i; j < n - 1; j++)
			a[j] = a[j + 1];
		n--;
	}
}
void output(int* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
	cout << endl;
}
int checkphuong(int n)
{
	int i = 0;
	while (i * i <= n)
	{
		if (i * i == n)
			return true;
		i++;
	}
	return false;
}
int tong(List lst)
{
	int sum = 0;
	for (NODE* p = lst.phead; p != NULL; p = p->address)
	{
		if (p->data % 2 == 0 && checkphuong(p->data))
			sum += p->data;
	}
	return sum;
}
int main()
{
	List lst;
	khoidong(lst);
	NODE* p = taodanhsach(0);
	NODE* q = taodanhsach(1);
	NODE* ptr = taodanhsach(4);
	
	themcuoi(lst, p);
	themcuoi(lst, q);
	themcuoi(lst, ptr);
	xuat(lst);
	cout << endl;
	/*int* a = NULL, x, n;
	n= mang(lst, a);
	cout << "\nNhap gia tri ban muon chen \n";
	cin >> x;
	themthutu(a, n, x);
	output(a, n);
	int y;
	cout << "Nhap gia tri ban muon kiem tra trong danh sach\n";
	cin >> y;
	int kq = check(a, n, y);
	if (kq!=-1)
		cout << "Co trong danh sach va xuat hien o vi tri so "<<kq+1<<endl;
	else cout << "Khong co trong danh sach\n";
	int value;
	cout << "Nhap gia tri ban muon tim de xoa phan tu do \n";
	cin >> value;
	timvaxoa(a, n, value);
	output(a, n);*/
	cout << tong(lst);
	delete[]p;
	delete[]q;
	delete[]ptr;
	return 0;
}