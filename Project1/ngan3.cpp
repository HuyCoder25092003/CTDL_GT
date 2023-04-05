#include <iostream>
using namespace std;
struct NODE
{
	int data;
	NODE* address;
};
NODE* first;
void init()
{
	first = NULL;
}
void Addhead(int value)
{
	NODE* p = new NODE;
	p->data = value;
	p->address = first;
	first = p;
}
void Addlast(int value)
{
	NODE* p = new NODE;
	p->data = value;
	p->address = NULL;
	if (first == NULL)
		first = p;
	else
	{
		NODE* q = first;
		while (q->address != NULL)
			q = q->address;
		q->address = p;
	}
}
NODE* search(int value)
{
	NODE* p = first;
	while (p != NULL && p->data != value)
		p = p->address;
	return p;
}
void addBefore(int value, int x)
{
	if (first!=NULL)
	{
		NODE *p = first;
		NODE *prev = nullptr;
		while (p != nullptr && p->data != value)
		{
			prev = p;
			p = p->address;
		}

		if (p != nullptr)
		{
			NODE *r = new NODE;
			r->data = x;
			r->address = NULL;
			if (prev == nullptr)
				first = r;
			else
				prev->address = r;
			r->address= p;
		}
	}
}
void Addafter(int value, int x)
{
	if (first != NULL)
	{
		NODE *p = search(value);
		if (p != NULL)
		{
			NODE* r = new NODE;
			r->data = x;
			r->address = NULL;
			r->address = p->address;
			p->address = r;
		}
	}
}
void DeleteAdd()
{
	NODE* temp = first;
	first = temp->address;
	delete temp;
}
void DeleteLast()
{
	if (first == NULL)
		cout << "Co gia tri trong danh sach eo dau ma xoa :))) \n";
	else if (first != NULL)
	{
		NODE* p = first;
		NODE* q = NULL;
		while (p->address != NULL)
		{
			q= p;
			p = p->address;
		}
		if (p != first)
			q->address = NULL;
		else first = NULL;
		delete p;
	}
}
void deletex(NODE *node)
{
	if (first != NULL)
	{
		NODE* p = first;
		while (p->address != node)
			p = p->address;
		if (node == first)
			DeleteAdd();
		else p->address = node->address;
		delete node;
	}
}
void Deletesearch(int value)
{
	NODE* p = search(value);
	if (p != NULL)
		deletex(p);
	else cout << "Eo thay con " << value << " trong danh sach " << endl;
}
void addInc(int x)
{
	if (first!=NULL)
	{
		NODE*p = first;
		NODE *prev = nullptr;

		while (p != nullptr && p->data < x)
		{
			prev = p;
			p = p->address;
		}

		NODE *r = new NODE;
		r->data = x;
		r->address = NULL;
		if (p == nullptr)
			prev->address = r;
		else
		{
			if (prev == nullptr)
				first = r;
			else
				prev->address = r;
			r->address = p;
		}
	}
}
void DeleteNode(int value)
{
	NODE* p = search(value);
	if (first!=NULL)
	{
		NODE* q = first,*before=NULL;
		while (q->address != p)
		{
			before = q;
			q = q->address;
		}
		if (q == first)
			DeleteAdd();
		else
		{
			before->address = q->address;
			delete q;
		}
	}
}
void themvitri(int x, int position)
{
	NODE *p = first;
	for (int i = 0; i < position - 1; i++) {
		p = p->address;
	}
	NODE *temp = new NODE;
	temp->data = x;
	temp->address = p->address;
	p->address = temp;
}
void output()
{
	NODE* p = first;
	while (p != NULL)
	{
		cout << p->data << "\t";
		p = p->address;
	}
	cout << endl;
}
int main()
{
	init();
	Addhead(10);
	Addhead(30);
	Addlast(40);
	Addlast(100);
	//addBefore(5, 40);
	//Addafter(50, 10);
	//output();
	//DeleteAdd();
	//output();
	//DeleteLast();
	//output();
	//Deletesearch(80);
	//output();
	addInc(50);
	output();
	//DeleteNode(50);
	//output();
	//themvitri(5, 2);
	//output();
	delete first;
}