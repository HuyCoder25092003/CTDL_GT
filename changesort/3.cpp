#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 100
using namespace std;
struct NhanVien
{
	char ma[4], hoten[40];
	int luong = 0;
}; typedef struct NhanVien nhanvien;
void nhap1(nhanvien& nv)
{
	cin.ignore();
	cout << "Ho ten nhan vien\n";
	cin.getline(nv.hoten, 40);
	cout << "Ma nhan vien\n";
	cin.getline(nv.ma, 4);
	cout << "Luong cua nhan vien\n";
	cin >> nv.luong;
}
void nhap(nhanvien nv[], int& n)
{
	cout << "\t\tNhap so luong nhan vien ban muon\n";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap thong tin nhan vien so " << i + 1 << endl;
		nhap1(nv[i]);
	}
}
void xuat1(nhanvien nv)
{
	cout << "Ho va ten nhan vien: " << nv.hoten << endl
		<< "Ma nhan vien: " << nv.ma << endl << "Luong: " << nv.luong << endl;
}
void xuat(nhanvien nv[], int n)
{
	cout << "\t\tThong tin toan bo nhan vien\n";
	for (int i = 0; i < n; i++)
	{
		cout << "Thong tin nhan vien so " << i + 1 << endl;
		xuat1(nv[i]);
	}
}
void SelectionSort(nhanvien nv[], int n)
{
	int min_pos;
	for (int i = 0; i < n; i++)
	{
		min_pos = i;
		for (int j = i + 1; j < n; j++)
			if (nv[j].luong < nv[min_pos].luong)
				min_pos = j;
		swap(nv[min_pos], nv[i]);
	}
}
void InsertionSort(nhanvien nv[], int n)
{
	int j;
	for (int i = 1; i < n; i++)
	{
		nhanvien tmp = nv[i];
		j = i - 1;
		while (0 <= j && tmp.luong < nv[j].luong)
		{
			nv[j + 1] = nv[j];
			j--;
		}
		nv[j + 1] = tmp;
	}
}
int main()
{
	nhanvien nv[MAX];
	int n;
	nhap(nv, n);
	xuat(nv, n);
	//SelectionSort(nv, n);
	InsertionSort(nv, n);
	xuat(nv, n);
	return 0;
}