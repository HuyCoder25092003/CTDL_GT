#include <iostream>
#include <cstring>
#include <string>
#include <conio.h>
using namespace std;
struct Data
{
	int ma, nam;
	string tg;
	int tt;
	string trangthai;
	double giatri;
};
string tt[] = { "dang muon", "dang cho muon"};
struct Node
{
	Data data;
	Node* next;
	Node* prev;
};
struct List
{
	Node* head, * tail;
};
void initData(List& l)
{
	l.head = l.tail = NULL;
}
Node* createData(Data value)
{
	Node* p = new Node;
	if (p == NULL)
		return NULL;
	else
	{
		p->data = value;
		p->next = p->prev = NULL;
		return p;
	}
}
void InputOneSp(Data& data)
{
	cout << "Ma sach \n";
	cin >> data.ma;
	cin.ignore();
	cout << "Nam xuat ban\n";
	cin >> data.nam;
	cin.ignore();
	cout << "Ten tac gia\n";
	getline(cin, data.tg);
	cout << "Tinh trang don hang( 1: dang muon , 2: dang cho muon )\n";
	cin >> data.tt;
	switch (data.tt)
	{
	case 1:
		data.trangthai = tt[0];
		break;
	case 2:
		data.trangthai = tt[1];
		break;
	case 3:
		data.trangthai = tt[2];
		break;
	}
	cout << "Tong gia tri don hang\n";
	do {
		cin >> data.giatri;
		/*if (data.giatri < 0)
			cout << "Nhap lai\n";*/
	} while (data.giatri < 0);

}
void AddHead(Node*p, List& l)
{
	if (l.head == NULL)
		l.head = l.tail = p;
	else
	{
		p->next = l.head;
		l.head->prev = p;
		l.head = p;
	}
}
void Input(Node* p, List&l) // thêm cuối
{
	if (l.head == NULL)
		l.head = l.tail = p;
	else
	{
		l.tail->next = p;
		p->prev = l.tail;
		l.tail = p;
	}
}
void OutPut(List l)
{
	Node* p = l.head;
	while (p != NULL)
	{
		cout << p->data.ma << "\t" << p->data.nam << "\t"
			 << p->data.trangthai << "\t"<< "\t" << p->data.tg 
			 << "\t" << p->data.giatri << endl;
		p = p->next;
	}
}
void DeleteFirst(List &l)// xóa đầu
{
	if (l.head == NULL)
	{
		delete l.head;
		l.head = l.tail = NULL;
	}
	else 
	{
		Node* p = l.head;
		l.head = l.head ->next;
		l.head->prev = NULL;
		p->next = NULL;
		delete p;
	}
}
void DeleteLast(List &l)
{
	if (l.head == NULL)
	{
		delete l.head;
		l.head = l.tail = NULL;
	}
	else 
	{
		Node* p = l.tail;
		l.tail = l.tail->prev;
		l.tail->next = NULL;
		p->prev = NULL;
		delete p;
	}
}
Node* search1(List l,string name) // tìm theo tên 
{
	Node* p = l.head;
	while (p != NULL && p->data.tg != name)
		p = p->next;
	return p;
}
void Remove(List &l,string name) // xóa theo tên
{
	Node* p = search1(l,name);
	if (p != NULL) // tìm thấy 
	{
		if (p->prev == NULL) // xóa đầu 
		{
			DeleteFirst(l);
			return;
		}
		if (p->next == NULL) // xóa cuối 
		{
			DeleteLast(l);
			return;
		}
		// thay đổi liên kết của thằng xóa (debug là thấy nha ) còn ko hỉu thì nhắn qua mess rồi chạy tay cho 
		p->prev->next = p->next;
		p->next->prev = p->prev;
		// gán con trỏ prev và next của thang xoa ve NULL
		p->prev = p->next = NULL;
		delete p;
		cout << "Xoa thanh cong\n";
	}
	else cout << "Khong co ten tac gia trong danh sach\n";
}
void QuickSort(List &l)
{
	List l1, l2;
	Node* tag, * p;
	if (l.head == l.tail) // nếu ko có danh sách 
		return;
	initData(l1); initData(l2);
	tag = l.head;
	l.head = l.head->next; // cập nhật lại head
	tag->next = NULL; // cô lập tag
	while (l.head != NULL)
	{
		p = l.head;
		l.head = l.head->next;
		p->next = NULL;
		if (p->data.giatri >= tag->data.giatri)
			AddHead( p, l1 );
		else AddHead(p,l2);
	}
	// gọi đệ quy sắp xếp l1 l2 
	QuickSort(l1);
	QuickSort(l2);
	if (l1.head != NULL) // l1 ko rỗng 
	{
		l.head = l1.head; // lấy head của l1 gán cho head của l 
		l1.tail->next = tag;
	}
	// l1 rỗng
	else l.head = tag;
	tag->next = l2.head;
	if (l2.head != NULL)
		l.tail = l2.tail;
	else l.tail = tag;
}
int main()
{
	List l;
	initData(l);
	Data data;
	int choose;
	bool in = false;
	Node* p = 0;
	do {
		system("cls");
		cout << "\t\tMenu\n";
		cout << "\t1:Nhap danh sach\n";
		cout << "\t2:Xuat danh sach\n";
		cout << "\t3:Xoa phan tu trong danh sach\n";
		cout << "\t4:Sap xep gia tien giam dan bang QuickSort\n";
		cout << "\t5:Exit\n";
		cin >> choose;
		switch (choose)
		{
		case 1:
			InputOneSp(data);
			p = createData(data);
			Input(p,l);
			in = true;
			break;
		case 2:
			if (in)
				OutPut(l);
			else cout << "Khong co du lieu\n";
			break;
		case 3:
			if (in)
			{
				cin.ignore();
				string name;
				cout << "Nhap tac gia ban muon xoa\n";
				getline(cin, name);
				Remove(l,name);
			}
			else cout << "Khong co du lieu\n";
			break;
		case 4:
			if (in)
			{
				cout << "Sap xep thanh cong vui long bam so 2 de check\n";
				QuickSort(l);
			}
			else cout << "Khong co du lieu\n";
			break;
		case 5:
			break;
		default:
			cout << "Khong co chuc nang tren\n";
		}
		_getch();
	} while (choose > 0 && choose < 5);
}