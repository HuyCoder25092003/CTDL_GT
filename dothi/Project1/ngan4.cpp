#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <conio.h>
using namespace std;
struct SinhVien
{
	double diem;
	string mssv;
	char ten[100];
};
struct NODE
{
	SinhVien data;
	NODE* next;
};
void initData(NODE*& first)
{
	first = NULL;
}
void  chuanhoa(char s[])
{
	// xóa dấu cách đầu chuỗi
	while (s[0] == ' ')
		strcpy(&s[0], &s[1]); // coppy
	// xóa dấu cách cuối chuỗi
	while (s[strlen(s)-1] == ' ')
		s[strlen(s)-1] = '\0';
	// xóa  dấu cách  giữa chuỗi
	for(int i=0;i<strlen(s);i++)
		if (s[i] == ' ' && s[i + 1] == ' ') // nếu thằng thứ i và thứ i+1 đều khoảng trắng 
		{
			strcpy(&s[i],&s[i + 1]);
			i--;
		}
	_strlwr(s); // viết thường toàn bộ chuỗi 
	s[0] = toupper(s[0]);
	for (int i = 0; i < strlen(s); i++)
		if (s[i] == ' ')
			s[i + 1] = toupper(s[i + 1]);;
}
void InputOneSV(SinhVien& sv)
{
	cin.ignore();
	cout << "Nhap ma so sinh vien\n";
	getline(cin, sv.mssv);
	cout << "Nhap ten sinh vien\n";
	cin.getline(sv.ten,100);
	chuanhoa(sv.ten);
	cout << "Diem trung binh cua sinh vien\n";
	do
	{
		cin >> sv.diem;
		// ( do câu này t thấy  dư thừa nên nếu you muốn thì để nha ) 
		/*if (sv.diem < 0 || sv.diem > 10)
			cout << "Nhap lai\n";*/
	} while (sv.diem < 0 || sv.diem > 10);
}
NODE* createData(SinhVien value)
{
	NODE* p = new NODE;
	if (p == NULL)
		return NULL;
	else
	{
		p->data = value;
		p->next = NULL;
		return p;
	}
}
void AddFirst(NODE*& first, SinhVien value) // thêm dâu 
{
	NODE* p = createData(value);
	if (first == NULL)
		first = p;
	else
	{
		p->next = first;
		first = p;
	}
}
void AddLast(NODE*& first, SinhVien value) // thêm cuối
{
	NODE* p = createData(value);
	if (first == NULL)
		first = p;
	else
	{
		NODE* tail = first;
		while (tail->next != NULL)
			tail = tail->next;
		tail->next = p;
	}
}
void DeleteFirst(NODE*& first)// xóa đầu
{
	if (first != NULL)
	{
		NODE* p = first;
		first = first->next;
		delete p;
	}
}
void OutPut(NODE* first)
{
	NODE* p = first;
	while (p != NULL)
	{
		cout << p->data.mssv << "\t" << p->data.ten << "\t" << p->data.diem << endl;
		p = p->next;
	}
}
int size(NODE* first) // hàm chuyển về mảng 
{
	int dem = 0;
	while (first != NULL)
	{
		dem++;
		first = first->next;
	}
	return dem;
}
void Add(NODE*& first, int position, SinhVien data) // thêm ở vị trí chỉ định  biến position là vị trí muốn thêm ( tính từ 1 tới n )  
{
	NODE* p = createData(data);
	if (first == NULL)
		AddFirst(first, data);
	else
	{
		int n = size(first);
		if (position == 1)
			AddFirst(first, data);
		else if (position == n)
			AddLast(first, data);
		else
		{
			NODE* q = first; // cho q là first
			for (int i = 2; i < position - 1; i++)
				/*  chạy từ 2 tới vitri - 1 (vd 2 3 4 5 6 7 thêm 10 ở vị trí 4 (trong ngôn ngữ người nha)
				thì nó sẽ chạy từ con số 3 tới con số 4 tới số 5 sẽ ko chạy nữa  */
				q = q->next;
			p->next = q->next; // lấy địa chỉ con 10 trỏ vào địa chỉ con 5
			q->next = p; // lấy địa chỉ con 4 trỏ vào con 10 
		}
	}
}
void DeleteLast(NODE*& first)
{
	if (first != NULL) // nếu đầu khác rỗng 
	{
		NODE* p = first, * q = NULL; // tạo 2 biến p trỏ tới first và q là null 
		if (p != NULL) // nếu đầu khác rỗng 
		{
			while (p->next != NULL) // có nghĩa là chạy đến khi nào gần cuối ( VD: 1 2 3 4 5 ) thì nó chỉ dc chạy tới con số 4 con số 5 ko dc chạy do địa chỉ sẽ là NULL
			{
				q = p; // gán p vô q 
				p = p->next; // cho nó chạy tới con khác
			}
		}
		if (p != first) // nếu p là thằng đầu tiên thì ko bao giờ có thằng q 
			q->next = NULL;
		else first = NULL;
		delete p;
	}
}
void Deletes(NODE*& first, int position) //hàm xóa theo vị trí you thích  position tính từ 1 tới n 
{
	if (position == 1 || first == NULL)
		DeleteFirst(first);
	else
	{
		int k = 2;
		NODE* p = first; // cho p là con trỏ đầu
		while (p->next->next != NULL && k != position)
			/*VD : 2 3 4 5 6 xóa con 5 thì chạy từ con 2 tới con 4*/
		{
			p = p->next;
			k++; // tăng vị trí 
		}
		if (k != position) // nếu tìm ko thấy vị trị đó thì ko làm thằng void nữa 
			return;
		else p->next = p->next->next; // có thì trỏ địa chỉ con  5 sang  con 6 
	}
}
void xoaphantu(NODE*& p) // lúc này p là chữ h trong VD
{
	if (p != NULL)
	{
		NODE* temp = p->next; // temp là con u 
		if (temp)
		{
			p->next = temp->next; // trỏ địa chỉ con u thành địa chỉ con y 
			delete temp; // xóa u 
		}
	}
}
void Remove(NODE*& first, string name) // xóa theo tên (VD:  h u y )
{
	if (first != NULL)
	{
		NODE* temp = first, * q = NULL;
		while (temp != NULL && name.find(temp->data.ten,0) < 0 )
		{
			q = temp;// gán con temp thành con q 
			temp = temp->next;
		}
		if (temp)
		{
			if (temp == first) // xóa đầu
				DeleteFirst(first);
			else xoaphantu(q);
		}
	}
}
NODE* search(NODE* first, string name) // tìm kiếm 
{
	NODE* p = first;
	while (p != NULL && p->data.mssv != name)
		p = p->next;
	return p;
}
int main()
{
	NODE* p;
	initData(p);
	SinhVien data;
	bool in = false;
	int choose;
	do {
		system("cls");
		cout << "\t\tMenu\n";
		cout << "\t1:Them sinh vien vao dau danh sach\n";
		cout << "\t2:Xoa sinh vien dau danh sach\n";
		cout << "\t3:Xuat thong tin cac sinh vien co trong danh sach\n";
		cout << "\t4:Them sinh vien theo chi dinh\n";
		cout << "\t5:Xoa sinh vien theo chi dinh\n";
		cout << "\t6:Xoa sinh vien theo ten chi dinh\n";
		cout << "\t7:Tim sinh vien theo chi dinh\n";
		cout << "\t8:Exit\n";
		cin >> choose;
		switch (choose)
		{
		case 1:
			InputOneSV(data);
			AddFirst(p, data);
			cout << "Them thanh cong\n";
			in = true;
			break;
		case 2:
			if (in)
			{
				cout << "Xoa thanh cong bam so 3 de check dap an \n";
				DeleteFirst(p);
			}
			else cout << "Khong co du lieu vui long bam so 1 de them du lieu\n";
			break;
		case 3:
			if (in)
			{
				cout << "Xuat cac thong tin sinh vien dang co trong danh sach\n";
				OutPut(p);
			}
			else cout << "Khong co du lieu vui long bam so 1 de them du lieu\n";
			break;
		case 4:
			if (in)
			{
				int n = size(p);
				int vitri;
				cout << "Nhap vi tri ban muon them\n";
				do {
					cin >> vitri;
					/*if (vitri <= 0 || vitri > n)
						cout << "Nhap lai\n";*/
				} while (vitri <= 0 || vitri > n);
				InputOneSV(data);
				Add(p, vitri, data);
				cout << "Them thanh cong\n";
			}
			else cout << "Khong co du lieu vui long bam so 1 de them du lieu\n";
			break;
		case 5:
			if (in)
			{
				int n = size(p);
				int vitri;
				cout << "Nhap vi tri ban muon xoa\n";
				do {
					cin >> vitri;
					/*if (vitri < 0 || vitri > n)
						cout << "Nhap lai\n";*/
				} while (vitri <= 0 || vitri > n);
				if (vitri == 1)
					DeleteFirst(p);
				else if (vitri == n)
					DeleteLast(p);
				else Deletes(p, vitri);
				cout << "Xoa thanh cong\n";
			}
			else cout << "Khong co du lieu vui long bam so 1 de them du lieu\n";
			break;
		case 6:
			if (in)
			{
				cin.ignore();
				int n = size(p);
				char chuoi[100];
				cout << "Nhap ten ban muon xoa\n";
				cin.getline(chuoi,100);
				chuanhoa(chuoi);
				string s = string(chuoi); // ép kiểu từ char về string 
				if (s.find(p->data.ten,0) > 0 )
				{
					Remove(p, chuoi);
					cout << "Xoa thanh cong\n";
				}
				else cout << "Khong co ten trong danh sach\n";
			}
			else cout << "Khong co du lieu vui long bam so 1 de them du lieu\n";
			break;
		case 7:
			if (in)
			{
				cin.ignore();
				string chuoi;
				cout << "Nhap mssv ban muon tim\n";
				getline(cin, chuoi);
				if (search(p, chuoi) != NULL)
					cout << "Co trong danh sach\n";
				else cout << "Khong tim thay trong danh sach\n";
			}
			break;
		case 8:
			break;
		default:
			cout << "Khong co chuc nang tren\n";
		}
		_getch();
	} while (choose > 0 && choose < 8);
	return 0;
}