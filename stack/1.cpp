#include <iostream>
#include <conio.h>
using namespace std;
#define MAX 100
int st=-1,a[MAX];
bool empty()
{
	return st == -1 ? true : false;
}
bool isfull()
{
	return st == MAX - 1 ? true : false;
}
void push(int value)
{
	if (!isfull())
		a[++st] = value;
}
void pop()
{
	if (!empty())
		st--;
}
void output()
{
	for (int i = 0; i < st; i++)
		cout << a[i] << "\t";
	cout << endl;
}
int main()
{
	int choose;
	bool in = false;
	int value;
	do{
		system("cls");
		cout << "\t\tMenu\n";
		cout << "1:Kiem tra stack hien tai co rong khong\n";
		cout << "2:Kiem tra stack co day chua\n";
		cout << "3:Them 1 phan tu vao stack\n";
		cout << "4:Xoa 1 phan tu trong stack\n";
		cout << "5:Xem man hinh console ket qua hien tai trong stack\n";
		cout << "6:Exit\n";
		cin >> choose;
		switch (choose)
		{
		case 1:
			if (empty() == 1)
				cout << "Stack hien tai dang rong\n";
			else cout << "Stack hien tai khong rong\n";
			break;
		case 2:
			if (isfull() == 1)
				cout << "Stack hien tai da day\n";
			else cout << "Stack chua day\n";
			break;
		case 3:
			do {
				cin >> value;
			} while (value > MAX);
			push(value);
			in = true;
			cout << "Them thanh cong vui long bam so 5 dem xem ket qua sau khi them\n";
			break;
		case 4:
			if (in)
			{
				pop();
				cout << "Xoa thanh cong vui long bam so 5 de xem ket qua sau khi xoa\n";
			}
			else cout << "Khong co du lieu vui long bam vo so 3 de them du lieu\n";
			break;
		case 5:
			if (in)
			{
				output();
			}
			else cout << "Khong co du lieu vui long bam vo so 3 de them du lieu \n";
			break;
		case 6:
			break;
		default:
			cout << "Khong co chuc nang tren\n";
		}
		_getch();
	} while (choose >= 1 && choose <= 5);
	return 0;
}