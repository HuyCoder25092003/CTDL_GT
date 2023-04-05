#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;
#define MAX 100
void input(int a[], int &n)
{
	cout << "Nhap so luong phan tu ban muon\n";
	do {
		cin >> n;
		if (n <= 0 || n > MAX)
			cout << "Nhap lai\n";
	} while (n <= 0 || n > MAX);
	for (int i = 0; i < n; i++)
		cin >> a[i];
}
void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
	cout << endl;
}
void Add(int a[], int &n, int value, int vitri)
{
	for (int i = n - 1; i >= vitri; i--)
		a[i +1] = a[i];
	a[vitri] = value;
	n++;
}
bool nto(int n)
{
	if (n < 2)
		return false;
	else
	{
		for (int i = 2; i <= sqrt(double(n)); i++)
			if (n % i == 0)
				return false;
	}
	return true;
}
void In(int a[], int n)
{
	for (int i = 0; i < n; i++)
		if (nto(a[i]) && i % 2 != 0)
			cout << a[i] << "\t";
	cout << endl;
}
int sum(int a[], int n)
{
	int tong = 0;
	for (int i = 0; i < n; i++)
		if (i % 2 == 0)
			tong += a[i];
	return tong;
}
int main()
{
	int a[MAX], n;
	int choose;
	bool check = false;
	do {
		system("cls");
		cout << "\t\tMenu\n";
		cout << "\t1:Nhap danh sach\n";
		cout << "\t2:Xuat danh sach\n";
		cout << "\t3:In ra so nguyen to o vi tri le tinh tu vi tri 0 toi vi tri n-1 \n";
		cout << "\t4:Tong cac phan tu o vi tri chan trong danh sach\n";
		cout << "\t5:Exit\n";
		cin >> choose;
		switch (choose)
		{
		case 1:
			input(a, n);
			check = true;
			break;
		case 2:
			if (check)
				output(a, n);
			else cout << "Khong co du lieu\n";
			break;
		case 3:
			if (check)
				In(a, n);
			else cout << "Khong co du lieu\n";
			break;
		case 4:
			if (check)
				cout << "Tong cac phan tu o vi tri chan tinh tu 0 toi "<<n-1<<": "<< sum(a, n)<<endl;
			break;
		case 5:
			break;
		default:
			cout << "Khong co chuc nang tren\n";
		}
		_getch();
	} while (choose > 0 && choose < 5);
	return 0;
}