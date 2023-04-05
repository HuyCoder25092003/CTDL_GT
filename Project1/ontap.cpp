#include <iostream>
using namespace std;
#define MAX 100
void nhap(int a[], int &n)
{
	cout << "Nhap so luong phan tu ban muon\n";
	do {
		cin >> n;
	} while (n <= 0 || n > MAX);
	for (int i = 0; i < n; i++)
		cin >> a[i];
}
void xuat(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
	cout << endl;
}
bool search(int a[], int n, int value)
{
	for (int i = 0; i < n; i++)
		if (a[i] == value)
			return true;
	return false;
}
void AddFirst(int a[], int& n, int value)
{
	n++;
	for (int i = 0; i < n - 1; i++)
		a[i + 1] = a[i];
	a[0] = value;
}
void InsertEnd(int a[], int &n, int x)
{
	if (n < MAX)
	{
		a[n] = x;
		n++;
	}
	else return;
}
void Add(int a[], int& n, int x,int vitri)
{
	for (int i = vitri; i < n - 1; i++)
		a[i + 1] = a[i];
	a[vitri] = x;
}
void DeletesEnd(int a[], int& n)
{
	n--;
}
void Deletes(int a[], int& n, int vitri)
{
	for (int i = vitri - 1; i < n; i++)
		a[i] = a[i + 1];
	n--;
}
void DeletesSearch(int a[], int& n, int x)
{
	for(int i=0;i<n;i++)
		if (a[i] == x)
		{
			Deletes(a, n, i);
			i--;
		}
}
void InsertSortEnd(int a[], int& n, int x)
{
	if (a[0] > x)
		AddFirst(a, n, x);
	else if (a[n-1] < x)
		InsertEnd(a, n, x);
	else
	{
		for (int i = 1; i < n - 1; i++)
			if (a[i] == x)
			{
				Add(a, n, x, i);
				break;
			}
	}
}
int main()
{
	int a[MAX],n;
	nhap(a, n);
	//InsertEnd(a, n, 7);
	//xuat(a, n);
	//DeletesEnd(a, n);
	//xuat(a, n);
	//Deletes(a, n, 5);
	//xuat(a, n);
	//Deletes(a, n, 3);
	xuat(a, n);
	InsertSortEnd(a, n, 5);
	xuat(a, n);
	return 0;
}