#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node* address;
}; typedef struct Node node;
struct List
{
	node* front;
	node* rear;
}; typedef struct List list;
node* createData(int value)
{
	node* p = new node;
	if (p == NULL)
		return NULL;
	else
	{
		p->data = value;
		p->address = NULL;
	}
	return p;
}
void init(list& lst)
{
	lst.front = lst.rear = NULL;
}
bool empty(list lst)
{
	return lst.front == NULL ? true : false;
}
void push(list &lst, node *p)
{
	if (empty(lst))
		lst.front = lst.rear = p;
	else
	{
		lst.rear->address = p;
		lst.rear = p;
	}
}
void pop(list& lst)
{
	if (empty(lst))
		return;
	else if (lst.front == lst.rear)
	{
		delete lst.front;
		lst.front=lst.rear=NULL;
	}
	else
	{
		node *p = lst.front;
		lst.front = p->address;
		delete p;
	}
}
void output(list lst)
{
	for (node* p = lst.front;p!=NULL;p=p->address)
		cout << p->data << "\t";
	cout << endl;
}
int main ()
{
	list lst;
	init(lst);
	if (empty(lst))
		cout << "Danh sach dang rong\n";
	else cout << "Danh sach hien tai khong rong\n";
	int value;
	cin >> value;
	node *p = createData(value);
	push(lst, p);
	int x;
	cin >> x;
	node *ptr = createData(x);
	push(lst, ptr);
	int y;
	cin >> y;
	node* q = createData(y);
	push(lst, q);
	int z;
	cin >> z;
	node *pointer = createData(z);
	push(lst, pointer);
	output(lst);
	pop(lst);
	output(lst);
	return 0;
}