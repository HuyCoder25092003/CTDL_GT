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
void acceptNLR(node* p)
{
	if (p != NULL)
	{
		cout << p->value << "\t";
		acceptNLR(p->left);
		acceptNLR(p->right);
	}
}
void acceptLNR(node* p)
{
	if (p != NULL)
	{
		acceptLNR(p->left);
		cout << p->value << "\t";
		acceptNLR(p->right);
	}
}
void acceptLRN(node* p)
{
	if (p != NULL)
	{
		acceptLRN(p->left);
		acceptLRN(p->right);
		cout << p->value << "\t";
	}
}
int LeafNodeCount(node* p)
{
	if (p != NULL)
	{
		if (p->left == NULL && p->right == NULL)
			return 1;
		return LeafNodeCount(p->left) + LeafNodeCount(p->right);
	}
	else return 0;
}
int SumNode(node* p)
{
	if (p == NULL)
		return 0;
	return 1 + SumNode(p->left) + SumNode(p->right);
}
int CountTheNumberOfNodes1Subtree(node* p)
{
	if (p != NULL)
	{
		int count = (p->left == NULL && p->right == NULL) || (p->left != NULL && p->right != NULL) ? 1 : 0;
		return count + CountTheNumberOfNodes1Subtree(p->left) + CountTheNumberOfNodes1Subtree(p->right);
	}
	return 0;
}
void PrintOutTheSubtree(node* p)
{
	if (p == NULL)
		return ;
	if (p->left != NULL && p->right == NULL || p->left==NULL && p->right!=NULL)
		cout << p->value << "\t";
	PrintOutTheSubtree(p->left);
	PrintOutTheSubtree(p->right);
}
void CountTheNumberOfNodesWith2Subtrees(node* p)
{
	if (p == NULL)
		return ;
	if (p->left != NULL && p->right != NULL)
		cout << p->value << "\t";
	CountTheNumberOfNodesWith2Subtrees(p->left);
	CountTheNumberOfNodesWith2Subtrees(p->right);
}
bool TwoBinaryTreesAreEqual(node *p , node *q)
{
	if (p == NULL && q == NULL)
		return true;
	if (p == NULL && q != NULL || (p != NULL && q == NULL))
		return 0;
	else 
	{
		if((p->value==q->value)&&(TwoBinaryTreesAreEqual(p->left,q->left)==1) && (TwoBinaryTreesAreEqual(p->right, q->right) == 1))
			return true;
		return false;
	}
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
int DeepTree(node* p, int value, int depth)
{
	if (p != NULL)
	{
		if (p->value == value)
			return depth;
		int a = DeepTree(p->left, value, depth+1);
		int b= DeepTree(p->right, value, depth+1);
		return a > b ? a : b;
	}
	return -1;
}
int LevelTree(node* p, int lv)
{
	if (p == NULL)
		return lv - 1;
	int l = LevelTree(p->left, lv+1);
	int r = LevelTree(p->right, lv + 1);
	return l > r ? l : r;
}
int main()
{
	node* root,*root1;
	int choose;
	bool in = false;
	init(root);
	do {
		system("cls");
		cout << "\t\tMenu\n";
		cout << "\t\t1:Them phan tu vao cay\n";
		cout << "\t\t2:Xoa mot nut tren cay\n";
		cout << "\t\t3:Duyet cac phan tu theo thu tu NLR\n";
		cout << "\t\t4:Duyet cac phan tu theo thu tu LNR\n";
		cout << "\t\t5:Duyet cac phan tu theo thu tu LRN\n";
		cout << "\t\t6:Tong so node la trong 1 cay \n";
		cout << "\t\t7:Tong so node trong cay\n";
		cout << "\t\t8:Dem so node duy nhat 1 cay con\n";
		cout << "\t\t9:In ra nhung node co cay con trai hoac cay con phai\n";
		cout << "\t\t10:In ra nhung node co 2 cay con \n";
		cout << "\t\t11:kiem tra 2 cay nhi phan tim kiem bang nhau\n";
		cout << "\t\t12:Chieu cao cua cay nhi phan tim kiem\n";
		cout << "\t\t13:Do sau cua mot node trong cay nhi phan tim kiem\n";
		cout << "\t\t14:Muc cua cac node la trong cay nhi phan\n";
		cout << "\t\t15:Exit\n";
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
				int y;
				cout << "Nhap gia tri ban muon xoa\n";
				cin >> y;
				Deletetree(root, y);
				cout << "Xoa thanh cong vui long bam so 4 hoac 5 hoac 6 dem xem ket qua\n";
			}
			else cout << "Khong co du lieu vui long bam so 1 de them data";
			break;
		case 3:
			if (in)
			{
				cout << "Duyet cay theo thu tu NLR\n";
				acceptNLR(root);
			}
			else cout << "Khong co du lieu vui long bam so 1 de them data";
			break;
		case 4:
			if (in)
			{
				cout << "Duyet cay theo thu tu LNR\n";
				acceptLNR(root);
			}
			else cout << "Khong co du lieu vui long bam so 1 de them data";
			break;
		case 5:
			if (in)
			{
				cout << "Duyet cay theo thu tu LRN\n";
				acceptLRN(root);
			}
			else cout << "Khong co du lieu vui long bam so 1 de them data";
			break;
		case 6:
			if (in)
			{
				cout << "Tong so node la trong 1 cay: " << LeafNodeCount(root)<<endl;
			}
			else cout << "Khong co du lieu vui long bam so 1 de them data";
			break;
		case 7:
			if (in)
			{
				cout << "Tong so node trong cay la: " << SumNode(root) << endl;
			}
			else cout << "Khong co du lieu vui long bam so 1 de them data";
			break;
		case 8:
			if (in)
			{
				cout << "Tong so node duy nhat 1 cay: " << CountTheNumberOfNodes1Subtree(root) << endl;
			}
			else cout << "Khong co du lieu vui long bam so 1 de them data";
			break;
		case 9:
			if (in)
			{
				PrintOutTheSubtree(root);
				cout << endl;
			}
			else cout << "Khong co du lieu vui long bam so 1 de them data";
			break;
		case 10:
			if (in)
			{
				CountTheNumberOfNodesWith2Subtrees(root);
				cout << endl;
			}
			else cout << "Khong co du lieu vui long bam so 1 de them data";
			break;
		case 11:
			if (in)
			{
				int value;
				init(root1);
				do{
					system("cls");
					cout << "Nhap phan tu ban muon them vao \n";
					cin >> value;
					Add(root1, value);
					cout << "Them thanh cong\n";
					cout << "Ban muon tiep tuc hay dung lai. Bam 1 de tiep tuc\n";
					cin >> kitu;
					if (kitu != '1')
						break;
					_getch();
				} while (kitu=='1');
				if (TwoBinaryTreesAreEqual(root, root1)!=false)
					cout << "2 cay nhi phan bang nhau\n";
				else cout << "2 cay nhi phan ko bang nhau\n";
				delete root1;
			}
			else cout << "Khong co du lieu vui long bam so 1 de them data";
			break;
		case 12:
			if (in)
			{
				cout << "Chieu cao cua cay nhi phan = " << TreeHeight(root) << endl;
			}
			else cout << "Khong co du lieu vui long bam so 1 de them data";
			break;
		case 13:
			if (in)
			{
				int value;
				cout << "Nhap gia tri ban muon tinh do sau\n";
				cin >> value;
				cout << "Do sau 1 node trong cay la :" << DeepTree(root, value, 0) << endl;
			}
			else cout << "Khong co du lieu vui long bam so 1 de them data";
			break;
		case 14:
			if (in)
			{
				
				cout << "Muc trong cay tinh tu 0: " << LevelTree(root, 0);
			}
			else cout << "Khong co du lieu vui long bam so 1 de them data";
			break;
		case 15:
			break;
		default:
			cout << "Khong co chuc nang tren menu\n";
			delete root;
		}
		_getch();
	} while (choose > 0 && choose < 15);
	return 0;
}