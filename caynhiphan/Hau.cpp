#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;
struct Node
{
	int value;
	Node* left;
	Node* right;
}; typedef struct Node node;
void init(node*& root)
{
	root = NULL;
}
node* creatData(int x)
{
	node* p = new node;
	p->left = p->right = NULL;
	p->value = x;
	return p;
}
void Add(node*& p, int value)
{
	if (p == NULL)
		p = creatData(value);
	else
	{
		if (p->value == value)
			return;
		else if (p->value < value)
			Add(p->right, value);
		else Add(p->left, value);
	}
}
void acceptNLR(node* p)
{
	if (p != NULL)
	{
		cout << p->value << "\t";
		acceptNLR(p->left);
		acceptNLR(p->right);
	}
}
void timNutCon(node* p)
{
	if (p != NULL)
	{
		if (p->left == NULL && p->right != NULL || p->left != NULL && p->right == NULL)
			cout << p->value << "\t";
		timNutCon(p->left);
		timNutCon(p->right);
	}
}
int demNodeLa(node* p)
{
	if (p != NULL)
	{
		if (p->left == NULL && p->right == NULL)
			return 1;
		return demNodeLa(p->left) + demNodeLa(p->right);
	}
	else return 0;
}
int demNodeConBenPhai(node* p)
{
	if (p != NULL)
	{
		int count = (p->left == NULL && p->right != NULL) ? 1 : 0;
		return count + demNodeConBenPhai(p->right) + demNodeConBenPhai(p->left);
	}
	return 0;
}
int demNodeConBenTrai(node* p)
{
	if (p != NULL)
	{
		int count = (p->left != NULL && p->right == NULL) ? 1 : 0;
		return count + demNodeConBenTrai(p->left) + demNodeConBenTrai(p->right);
	}
	return 0;
}
int tongNodeConPhai(node* p, int &sum)
{
	if (p != NULL)
	{
		if(p->left == NULL && p->right!=NULL)
			sum += p->value;
		tongNodeConPhai(p->right,sum);
		tongNodeConPhai(p->left, sum);
	}
	return sum;
}
int tongNodeLaPhai(node* p , int &sum)
{
	if (p != NULL)
	{
		if (p->left == NULL && p->right == NULL)
			sum += p->value;
		tongNodeLaPhai(p->right,sum);
	}
	return sum;
}
int tongNodeMotCon(node* p , int &sum)
{
	if (p != NULL)
	{
		if (p->left == NULL && p->right != NULL || p->left != NULL && p->right == NULL)
			sum += p->value;
		tongNodeMotCon(p->left,sum);
		tongNodeMotCon(p->right,sum);
	}
	return sum;
}
int tongNodeMotConBenPhai(node* p , int &sum) // trái thì p->left != NULL && p->right == NULL
{
	if (p != NULL)
	{
		if (p->left == NULL && p->right != NULL)
			sum += p->value;
		tongNodeMotCon(p->left,sum);
		tongNodeMotCon(p->right,sum);
	}
	return sum;
}
int tinhNodeNhoHonX(node* p, int x)
{
	if (p != NULL)
	{
		if (p->value < x)
			return 1 + tinhNodeNhoHonX(p->left, x) + tinhNodeNhoHonX(p->right, x);
		else return tinhNodeNhoHonX(p->left, x) + tinhNodeNhoHonX(p->right, x);
	}
	return 0;
}
int soNut(node* p, int x, int y) // số nút lớn hơn x nhỏ hơn y 
{
	int n = 0;
	if (p != NULL)
	{
		if (p->value < x)
			n = soNut(p->right, x, y);
		else
		{
			if(p->value > y )
				n = soNut(p->left, x, y);
			else
			{
				if (p->value != x && p->value != y)
					n = 1;
				n = n + soNut(p->left, x, y) + soNut(p->right, x, y);
			}
		}
	}
	return n;
}
void timMax(node* p, int &Max)
{
	if (p == NULL)
		return;
	if (p->left != NULL)
		Max = Max > p->left->value ? Max : p->left->value;
	if(p->right !=NULL)
		Max = Max > p->right->value ? Max : p->right->value;
	Max = Max > p->value ? Max : p->value;
	timMax(p->left, Max);
	timMax(p->right, Max);
}
int soNutTrongCay(node* p)
{
	if (p == NULL)
		return 0;
	return 1 + soNutTrongCay(p->left) + soNutTrongCay(p->right);
}
int cayCanBang(node* p) // kiểm tra thì cho nó bằng 0 thì là cây cân bằng nha 
{
	if (p == NULL)
		return 0;
	int Left = cayCanBang(p->left);
	int MaxL, MaxR;
	if (p->left != NULL && p->right != NULL)
	{
		timMax(p->left, MaxL);
		timMax(p->right, MaxR);
		if (!(MaxL < p->value && p->value < MaxR))
			return 1;
	}
	else if (p->left == NULL && p->right != NULL)
	{
		timMax(p->right, MaxR);
		if (!(p->value < MaxR))
			return 1;
	}
	else if (p->left != NULL && p->right == NULL)
	{
		timMax(p->left, MaxL);
		if (!(MaxL < p->value))
			return 1;
	}
	//kiểm tra điều kiện của cây nhị phân tìm kiếm cân bằng hoàn toàn
	int NodeR = soNutTrongCay(p->right);
	int NodeL = soNutTrongCay(p->left);
	if (abs(NodeR - NodeL) > 1)    //chêch lệch lớn hơn 1
		return 1;
	int Right = cayCanBang(p->right);
	return Left + Right;
}
int TreeHeight(node* p)
{
	if (p != NULL)
	{
		int h1 = TreeHeight(p->left);
		int h2 = TreeHeight(p->right);
		return (h1 > h2 ? h1 : h2) + 1;
	}
	return 0;
}
int doLech(node* p)
{
	int d=0,hl,hr;
	if(p!=NULL)
	{
		d = doLech(p->right) < doLech(p->left) ? doLech(p->left) : doLech(p->right);
		hl = TreeHeight(p->left);
		hr = TreeHeight(p->right);
		if (hr - hl > d)
			d = hr - hl;
		if (hl - hr > d)
			d = hl - hr;
	}
	return d;
}
void searchStandFor(node*& p, node*& q)
{
	if (q->left == NULL)
	{
		p->value = q->value;
		p = q;
		q = q->right;
	}
	else searchStandFor(p, q->left);
}
void Deletetree(node*& t, int value)
{
	if (t == NULL)
		return;
	if (t->value == value)
	{
		node* p = t;
		if (t->left == NULL)
			t = t->right;
		else if (t->right == NULL)
			t = t->left;
		else searchStandFor(p, t->right);
		delete p;
		return;
	}
	if (t->value < value)  Deletetree(t->right, value);
	if (t->value > value)  Deletetree(t->left, value);
}
node* search(node* p, int value)
{
	if (p != NULL)
	{
		if (p->value == value)
			return p;
		else if (p->value < value)
			search(p->right, value);
		else search(p->left, value);
	}
}
int main ()
{
	node* root;
	int choose;
	bool in = false;
	init(root);
	do
	{
		system("cls");
		cout << "\t\tMenu\n";
		cout << "\t1:Them phan tu vao cay\n";
		cout << "\t2:Duyet cac phan tu theo thu tu NLR\n";
		cout << "\t3:Tim tat ca cac nut con ben trai bang so nut con ben phai\n";
		cout << "\t4:Dem so node la , node con trai , node con ben phai\n";
		cout << "\t5:Tinh tong cac node con ben phai\n";
		cout << "\t6:Tinh tong cac node la ben phai\n";
		cout << "\t7:Tinh tong cac node chi co 1 con\n";
		cout << "\t8:Tong cac node chi co 1 con ben phai hoac ben trai\n";
		cout << "\t9:Tinh so node nho hon gia tri x \n";
		cout << "\t10:So nut co khoa lon hon x va nho hon y \n";
		cout << "\t11:Kiem tra cay nhi phan tim kiem la cay can bang?\n";
		cout << "\t12:Tinh do lech chieu cao cay \n";
		cout << "\t13:Xoa chan \n";
		cout << "\t14:Xoa le\n";
		cout << "\t15:Exit\n";
		cin >> choose;
		switch (choose)
		{
		case 1:
			int x;
			cout << "Nhap phan tu ban muon them vao\n";
			cin >> x;
			Add(root, x);
			cout << "Them phan tu thanh cong\n";
			in = true;
			break;
		case 2:
			if (in)
			{
				cout << "Duyet cay theo thu tu NLR\n";
				acceptNLR(root);
			}
			else cout << "Khong co du lieu vui long bam so 1 de them data";
			break;
		case 3:
			if (in)
			{
				cout << "Cac nut con trai bang nut con phai : " << endl;
				timNutCon(root);
			}
			else cout << "Khong co du lieu vui long bam so 1 de them data";
			break;
		case 4:
			if (in)
			{
				cout << "So node la trong cay: " << demNodeLa(root)<<endl;
				cout << "So node con trai trong cay: " << demNodeConBenTrai(root) << endl;
				cout << "So node con phai trong cay: " << demNodeConBenPhai(root) << endl;
			}
			else cout << "Khong co du lieu vui long bam so 1 de them data";
			break;
		case 5:
			if (in)
			{
				int sum = 0;
				cout << "Tong cac node con ben phai: " << tongNodeConPhai(root, sum) << endl;
			}
			else cout << "Khong co du lieu vui long bam so 1 de them data";
			break;
		case 6:
			if (in)
			{
				int sum = 0;
				cout << "Tong cac node la ben phai: " << tongNodeLaPhai(root, sum) << endl;
			}
			else cout << "Khong co du lieu vui long bam so 1 de them data";
			break;
		case 7:
			if (in)
			{
				int sum = 0;
				cout << "Tong cac node chi co 1 con: " << tongNodeMotCon(root,sum) << endl;
			}
			else cout << "Khong co du lieu vui long bam so 1 de them data";
			break;
		case 8:
			if (in)
			{
				int sum = 0;
				cout << "Tong cac node chi co 1 con ben phai: " << tongNodeMotConBenPhai(root,sum) << endl;
			}
			else cout << "Khong co du lieu vui long bam so 1 de them data";
			break;
		case 9:
			if (in)
			{
				int x; 
				cout << "Nhap gia tri x ban muon \n";
				cin >> x;
				cout << "So node nho hon " << x << " vua nhap: " << tinhNodeNhoHonX(root, x) << endl;
			}
			else cout << "Khong co du lieu vui long bam so 1 de them data";
			break;
		case 10:
			if (in)
			{
				int x,y;
				cout << "Nhap gia tri x ban muon\n";
				cin >> x;
				cout << "Nhap gia tri y ban muon\n";
				cin >> y;
				cout << "So nut co khoa lon hon " << x << " va nho hon " <<y<< " : " << soNut(root, x, y) << endl;
			}
			else cout << "Khong co du lieu vui long bam so 1 de them data";
			break;
		case 11:
			if (in)
			{
				if (cayCanBang(root) == 0)
					cout << "Cay cang bang\n";
				else cout << "Khong phai cay can bang\n";
			}
			else cout << "Khong co du lieu vui long bam so 1 de them data";
			break;
		case 12:
			if (in)
				cout << "Do lech chieu cao cua cay: " << doLech(root) << endl;
			else cout << "Khong co du lieu vui long bam so 1 de them data";
			break;
		case 13:
			if (in)
			{
				int x;
				cout << "Nhap so ban muon xoa\n";
				cin >> x;
				if (search(root, x) !=NULL && x % 2 == 0)
				{
					cout << "Xoa chan. Vui long bam so 2 de xem ket qua\n";
					Deletetree(root, x);
				}
				else cout << "Khong the xoa duoc do khong thoa dieu kien\n";
			}
			else cout << "Khong co du lieu vui long bam so 1 de them data";
			break;
		case 14:
			if (in)
			{
				int x;
				cout << "Nhap so ban muon xoa\n";
				cin >> x;
				if (search(root, x) !=NULL && x % 2 != 0)
				{
					cout << "Xoa le. Vui long bam so 2 de xem ket qua\n";
					Deletetree(root, x);
				}
				else cout << "Khong the xoa duoc do khong thoa dieu kien\n";
			}
			else cout << "Khong co du lieu vui long bam so 1 de them data";
			break;
		case 15:
			break;
		default:
			cout << "Khong co chuc nang tren\n";
		}
		_getch();
	}while (choose > 0 && choose < 15);
	return 0;
}