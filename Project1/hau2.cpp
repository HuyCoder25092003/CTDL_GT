//#include "Node.h"
//void initData(node*& p)
//{
//	p = NULL;
//}
//node* createData(int value)
//{
//	node* p = new node;
//	if (p == NULL)
//		return NULL;
//	else
//	{
//		p->left = p->right = NULL;
//		p->data = value;
//		return p;
//	}
//}
//void Input(node*&p, int value)
//{
//	if (p == NULL)
//		p = createData(value);
//	else
//	{
//		if (p->data == value)
//			return;
//		else if (p->data > value)
//			Input(p->left, value);
//		else Input(p->right, value);
//	}
//}
//void OutPut(node* p)
//{
//	if(p != NULL)
//	{
//		OutPut(p->left);
//		cout << p->data << "\t";
//		OutPut(p->right);
//	}
//}
//int sum(node* p)
//{
//	if (p == NULL)
//		return 0;
//	return p->data + sum(p->left) + sum(p->right);
//}
//int main()
//{
//	node* p;
//	initData(p);
//	int choose;
//	bool check = false;
//	do 
//	{
//		system("cls");
//		cout << "\tMenu:\n";
//		cout << "\t1:Nhap gia tri mot node\n";
//		cout << "\t2:Xuat cac gia tri trong node tang dan\n";
//		cout << "\t3:Tong gia tri cac node vua nhap\n";
//		cout << "\t4:Exit\n";
//		cin >> choose;
//		switch (choose)
//		{
//		case 1:
//			int value;
//			cout << "Nhap gia tri ban muon \n";
//			cin >> value;
//			Input(p, value);
//			cout << "Them thanh cong\n";
//			check = true;
//			break;
//		case 2:
//			if (check)
//				OutPut(p);
//			else cout << "Khong co du lieu\n";
//			break;
//		case 3:
//			if (check)
//				cout << "Tong gia tri cac node vua nhap: " << sum(p) << endl;
//			else cout << "Khong co du lieu\n";
//			break;
//		case 4:
//			break;
//		default:
//			cout << "Khong co chuc nang tren\n";
//		}
//		_getch();
//	} while (choose > 0 && choose < 4);
//	return 0;
//}