#include <iostream>
using namespace std;
void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
	cout << endl;
}
int search(int a[], int n, int x)
{
	for (int i = 0; i < n; i++)
		if (a[i] == x)
		{
			return i;
			break;
		}
	return -1;
}
void themcuoi(int a[], int& n, int x)
{
	a[n] = x;
	n++;
}
void DeleteEnd(int a[], int &n)
{
	if (n > 0)
		n--;
}
void DeleteFirst(int a[], int& n)
{
	for (int i = 0; i < n; i++)
		a[i] = a[i + 1];
	n--;
}
void Deletes(int a[], int& n , int &idx)
{
	if (idx == 0)
		DeleteFirst(a, n);
	else if (idx== n)
		DeleteEnd(a, n);
	else
	{
		for (int i = idx; i < n; i++)
			a[i] = a[i + 1];
		n--;
	}
}
void check(int a[], int& n, int x)
{
	for(int i=0;i<n;i++)
		if (search(a, n, x) != -1)
		{
			Deletes(a, n, i);
			i--;
		}
}
void themdau(int a[], int &n,int x)
{
	for (int i = n-1; i >= 0 ; i--)
		a[i + 1] = a[i];
	a[0] = x;
	n++ ;
}
void them(int a[], int& n, int x, int idx)
{
	if (idx == 0)
		themdau(a, n, x);
	else if (idx == n)
		themcuoi(a, n, x);
	else
	{
		for (int i = idx; i < n; i++)
			a[i + 1] = a[i];
		a[idx] = x;
		n++;
	}
}
int main()
{
	int n= 5;
	int a[100] = { 3,4,5,8,1 };
	output(a, n);
	if (search(a, n, 5) != -1)
		cout << "Tim thay\n";
	else cout << "Khong tim thay\n";
	themcuoi(a, n, -1);
	output(a, n);
	DeleteEnd(a, n);
	output(a, n);
	int idx = 0;
	Deletes(a, n, idx);
	output(a, n);
	check(a, n, 5);
	output(a, n);
	themdau(a, n, 6);
	output(a, n);
	idx = 2;
	them(a, n, 6, idx);
	output(a, n);
}