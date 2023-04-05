#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;
#define MAX 100
struct Dathuc
{
	int heso[MAX]={0}, bac;
}; typedef struct Dathuc dathuc;
void input(dathuc &d)
{
	cout << "Nhap bac da thuc ban muon\n";
	do {
		cin >> d.bac;
	} while (d.bac < 0);
	for (int i = 0; i <= d.bac; i++)
	{
		int heso;
		cout << "Nhap he so bac " << i << endl;
		cin >> heso;
		d.heso[i] = heso;
	}
}
void output(dathuc d)
{
	for (int i = 0 ;i <d.bac; i++)
	{
		if(d.heso[i]!=0)
			cout << d.heso[i] << "*x^" << i << " + ";
	}
	cout << d.heso[d.bac] << "*x^" <<d.bac << endl;
}
//dathuc polynomialaddition(dathuc a, dathuc b,dathuc &kq) //cộng
//{
//	kq.bac = a.bac > b.bac ? a.bac : b.bac;
//	for (int i = 0; i <= kq.bac; i++)
//		kq.heso[i] = a.heso[i] + b.heso[i];
//	return kq;
//}
//dathuc subtractpolynomial(dathuc a, dathuc b, dathuc& kq) // trừ
//{
//	kq.bac = a.bac > b.bac ? a.bac : b.bac;
//	for (int i = 0; i <= kq.bac; i++)
//		kq.heso[i] = a.heso[i] - b.heso[i];
//	return kq;
//}
//dathuc multiply2polynomials(dathuc a, dathuc b, dathuc& kq) // nhân
//{
//	kq.bac = a.bac * b.bac;
//	for (int i = 0; i <= a.bac; i++)
//	{
//		for (int j = 0; j <= b.bac; j++)
//			kq.heso[i + j] = a.heso[i] * b.heso[j];
//	}
//	return kq;
//}
int sum(dathuc d, int x)
{
	int tong = 0;
	for (int i = 0; i <= d.bac; i++)
		tong += d.heso[i] * pow(x, i);
	return tong;
}
int main()
{
	// chưa làm được chia đa thức 
	dathuc a; /*b, kq1, kq2, kq3,kq4*/;
	int choose;
	bool in = false;
	do {
		system("cls");
		cout << "\t\tMenu\n";
		cout << "\t1:Nhap da thuc\n";
		cout <<"\t2:Xuat da thuc\n";
		cout << "\t3:Tinh gia tri da thuc tai x \n";
		cout << "\t4:Exit\n";
		cin >> choose;
		switch (choose)
		{
		case 1:
			input(a);
			in = true;
			break;
		case 2:
			if (in)
			{
				cout << "Xuat da thuc\n";
				output(a);
			}
			else cout << "Khong co du lieu vui long bam so 1 \n";
			break;
		case 3:
			if (in)
			{
				int x;
				cout << "Nhap gia tri x ban muon tinh\n";
				cin >> x;
				cout << "Gia tri cua da thuc tai x = " << x << " : " << sum(a, x) << endl;
			}
			else cout << "Khong co du lieu vui long bam so 1 \n";
			break;
		case 4:
			break;
		default:
			cout << "Khong co chuc nang tren\n";
		}
		_getch();
	} while (choose > 0 && choose < 4);
	
	/*input(b);
	output(b);*/
	
	/*cout << "Sau khi cong 2 da thuc thi ket qua la \n";
	kq1 = polynomialaddition(a, b, kq1);
	output(kq1);
	cout << "Sau khi tru 2 da thuc thi ket qua la \n";
	kq2 = subtractpolynomial(a, b, kq2);	
	output(kq2);
	cout << "Sau khi nhan 2 da thuc thi ket qua la \n";
	kq3 = multiply2polynomials(a, b, kq3);*/
	//output(kq3);
}