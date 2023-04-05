#include <iostream>
#include <conio.h>
using namespace std;
struct Node
{
	char value;
	Node* left;
	Node* right;
}; typedef struct Node node;
void init(node*& root)
{
	root = NULL;
}
node* creatData(char x)
{
	node* p = new node;
	p->left = p->right = NULL;
	p->value = x;
	return p;
}
void Add(node*& p, char value)
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
void acceptLNR(node* p)  // Lưu ý: nếu đề bài yêu cầu xuất cái cây tăng dần thì xài cái này nhé
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
void Node_cha(node* p) // node cha là node đẻ ra cả 2 nhánh trái phải 
{
	if (p != NULL)
	{
		if (p->right != NULL && p->left != NULL)
			cout << p->value << "\t";
		Node_cha(p->left);
		Node_cha(p->right);
	}
}
void Node_la(node* p) // node la là node đẻ ra 1 trong 2 nhánh trái phải -> tức là đẻ trái thì ko đẻ phải và ngược lại.
{
	if (p != NULL)
	{
		if (p->right == NULL && p->left != NULL || p->left == NULL && p->right != NULL)
			cout << p->value << "\t";
		Node_la(p->left);
		Node_la(p->right);
	}
}
void searchStandFor(node*& p, node*& q) /* VD trong slide đi là nó muốn xóa con 20 ép con 21 lên thay.
Thì ý tưởng của cái void này dùng để là check xem toàn bộ nhánh bên phải cực trái( phải rồi tới trái)
 xem coi thằng nào lớn hơn thằng xóa và là con số nhỏ nhất để nó thay*/
//p: lúc này là con 20 và q là toàn bộ nhánh phải của 20
{
	if (q->left == NULL) // kiểm tra xem thằng bên trái đã hết số chưa nết hết rồi thì chạy 
	{
		p->value = q->value; 
		p = q;
		// chép toàn bộ con 21 vô thằng p

		// đưa liên kết q trỏ và q->right( tức là trỏ con 22)
		q = q->right;
		
	}
}
void Deletetree(node*& t, char value)
{
	if (t == NULL)
		return;
	if (t->value == value)
	{
		node* p = t;
		//if với else if là trường hợp xóa nhánh con 
		if (t->left == NULL)
			t = t->right;
		else if (t->right == NULL)
			t = t->left;
		else searchStandFor(p, t->right); // trường hợp xóa node cha 
		delete p;// xóa đi ( với th node cha là xóa thằng 21 đi vì trước đó you đã chép hết toàn bộ thằng 21 lên 20 rồi thì nó sẽ còn dư thằng 21 ở dưới nên xóa đi)
		return;
	}
	if (t->value < value)  Deletetree(t->right, value);
	if (t->value > value)  Deletetree(t->left, value);
}
node* search(node* p, char value)
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
void Hoa(node *p)
{
	if (p != NULL)
	{
		if (p->value >= 97 && p->value <= 122)
			p->value = p->value - 32;
		Hoa(p->left);
		Hoa(p->right);
	}
}
void Thuong(node* p)
{
	if (p != NULL)
	{
		if (p->value >= 65 && p->value <= 90)
			p->value = p->value + 32;
		Hoa(p->left);
		Hoa(p->right);
	}
}
int main()
{
	node* root;
	int choose;
	bool in = false;
	init(root);
	do {
		system("cls");
		cout << "\t\tMenu\n";
		cout << "\t1:Them phan tu vao cay\n";
		cout << "\t2:Xoa mot nut tren cay\n";
		cout << "\t3:Duyet cac phan tu theo thu tu NLR\n";
		cout << "\t4:Duyet cac phan tu theo thu tu LNR\n";
		cout << "\t5:Duyet cac phan tu theo thu tu LRN\n";
		cout << "\t6:Liet ke cac node la \n";
		cout << "\t7:Liet ke cac node cha \n";
		cout << "\t8:Exit\n";
		cin >> choose;
		switch (choose)
		{
		case 1:
			char a;
			cout << "Nhap 1 ki tu ban muon \n";
			cin >> a;
			Add(root, a);
			in = true;
			break;
		case 2:
			if (in)
			{
				char y[1]; // cho 1 vì char nó sẽ bị ăn cấp bởi kí tự '\0' nên bắt buộc phải để dư 1 cái để ko bị sai ( có thể coi slide chương 4 kỹ thuật or lên google xem nếu ko tin )
				cout << "Nhap chu ban muon xoa\n";
				cin >> y;
				Thuong(root);
				y[0] = tolower(y[0]);
				// nên có 2 thằng này vì you sẽ tránh trường hợp người dùng ngứa đòn nhập khác ( mà nếu theo đề thì ko cần mà làm sẵn để check cho chắc)
				if (search(root, y[0]))
				{
					Deletetree(root, y[0]);
					cout << "Xoa thanh cong vui long bam so 3 hoac 4 hoac 5 dem xem ket qua\n";
				}
				else cout << "Khong tim thay chu ban muon xoa\n";
			}
			else cout << "Khong co du lieu vui long bam so 1 de them data";
			break;
		case 3:
			if (in)
			{
				Hoa(root);// này đề số lẻ
				/*Thuong(root); này là đề số chẵn nha*/
				cout << "Duyet cay theo thu tu NLR\n";
				acceptNLR(root);
			}
			else cout << "Khong co du lieu vui long bam so 1 de them data";
			break;
		case 4:
			if (in)
			{
				Hoa(root);// này đề số lẻ
				/*Thuong(root); này là đề số chẵn nha*/
				cout << "Duyet cay theo thu tu LNR\n";
				acceptLNR(root);
			}
			else cout << "Khong co du lieu vui long bam so 1 de them data";
			break;
		case 5:
			if (in)
			{
				Hoa(root);// này đề số lẻ
				/*Thuong(root); này là đề số chẵn nha*/
				cout << "Duyet cay theo thu tu LRN\n";
				acceptLRN(root);
			}
			else cout << "Khong co du lieu vui long bam so 1 de them data";
			break;
		case 6:
			if (in)
			{
				cout << "Cac node la co trong cay \n";
				Node_la(root);
			}
			else cout << "Khong co du lieu vui long bam so 1 de them data";
			break;
		case 7:
			if (in)
			{
				cout << "Cac node cha trong cay\n";
				Node_cha(root);
			}
			else cout << "Khong co du lieu vui long bam so 1 de them data";
			break;
		case 8:
			break;
		default:
			cout << "Khong co chuc nang tren\n";
			delete root;
		}
		_getch();
	} while (choose > 0 && choose < 8);
	return 0;
}