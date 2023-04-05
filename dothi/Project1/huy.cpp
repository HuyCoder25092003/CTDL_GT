//#include <iostream>
//using namespace std;
//struct NODE
//{
//	float info;
//	NODE* next;
//};
//NODE* pfirst;
//void init(NODE*& pfirst)
//{
//	pfirst = NULL;
//}
//void Add(NODE*& pfirst, float x)
//{
//	NODE* p = new NODE;
//	p->info = x;
//	p->next = NULL;
//	if (pfirst == NULL)
//		pfirst = p;
//	else
//	{
//		NODE* q = pfirst;
//		while (q->next != NULL)
//			q = q->next;
//		q->next = p;
//	}
//}
//void OutPut(NODE* pfirst)
//{
//	while (pfirst != NULL)
//	{
//		cout << pfirst->info << "\t";
//		pfirst = pfirst->next;
//	}
//	cout << endl;
//}
//void InChia(NODE* pfirst)
//{
//	while (pfirst != NULL)
//	{
//		if ((int)pfirst->info % 3 == 0)
//			cout << pfirst->info << "\t";
//		pfirst = pfirst->next;
//	}
//	cout << endl;
//}
//void DeletesAdd(NODE*& pfirst)
//{
//	if (pfirst != NULL)
//	{
//		NODE* q = pfirst;
//		pfirst = pfirst->next;
//		delete q;
//	}
//}
//void Deletes(NODE*& pfirst)
//{
//	while (pfirst != NULL)
//	{
//		NODE*p = pfirst;
//		pfirst = p->next;
//		delete p;
//	}
//	delete pfirst;
//	pfirst = NULL;
//}
//int main()
//{
//	init(pfirst);
//	Add(pfirst, 5);
//	Add(pfirst, 6);
//	Add(pfirst, 9);
//	Add(pfirst, 7);
//	Add(pfirst, 8);
//	OutPut(pfirst);
//	InChia(pfirst);
//	Deletes(pfirst);
//	OutPut(pfirst);
//	return 0;
//}



//#include <iostream>
//#include <conio.h>
//using namespace std;
//struct Cay
//{
//	int data;
//	Cay* Left;
//	Cay* Right;
//
//};
//Cay* root;
//void init(Cay*&root)
//{
//	root=NULL;
//}
//Cay* createData(int data)
//{
//	Cay* p = new Cay;
//	if (p == NULL)
//		return NULL;
//	else
//	{
//		p->data = data;
//		p->Left = p->Right = NULL;
//		return p;
//	}
//}
//void Add(Cay*&root, int value)
//{
//	if (root == NULL)
//		root = createData(value);
//	else
//	{
//		if (root->data == value)
//			return;
//		else if (root->data > value)
//			Add(root->Left, value);
//		else Add(root->Right, value);
//	}
//}
//void Node_cha(Cay* root)
//{
//	if (root == NULL)
//		return;
//	else
//	{
//		if (root->Left != NULL && root->Right != NULL)
//			cout << root->data << "\t";
//		Node_cha(root->Left);
//		Node_cha(root->Right);
//	}
//}
//void Node_con(Cay* root)
//{
//	if (root != NULL)
//	{
//		if (root->Left == NULL && root->Right != NULL || root->Left != NULL && root->Right == NULL)
//			cout << root->data << "\t";
//		Node_con(root->Left);
//		Node_con(root->Right);
//	}
//	return;
//}
//void NLR(Cay*root)
//{
//	if (root!= NULL)
//	{
//		cout << root->data << "\t";
//		NLR(root->Left);
//		NLR(root->Right);
//	}
//}
//void LNR(Cay*root)
//{
//	if (root != NULL)
//	{
//		LNR(root->Left);
//		cout << root->data << "\t";
//		LNR(root->Right);
//	}
//}
//void LRN(Cay* root)
//{
//	if (root != NULL)
//	{
//		LRN(root->Left);
//		LRN(root->Right);
//		cout << root->data << "\t";
//	}
//}
//int main()
//{
//	int choose;
//	bool in = false;
//	init(root);
//	do {
//		system("cls");
//		cout << "\t\tMenu\n";
//		cout << "\t1:Them phan tu vao cay\n";
//		cout << "\t2:Duyet cac phan tu theo thu tu NLR\n";
//		cout << "\t3:Duyet cac phan tu theo thu tu LNR\n";
//		cout << "\t4:Duyet cac phan tu theo thu tu LRN\n";
//		cout << "\t5:In ra nhung node con\n";
//		cout << "\t6:In ra nhung node cha \n";
//		cout << "\t7:Exit\n";
//		cin >> choose;
//		switch (choose)
//		{
//		case 1:
//			int x;
//			cout << "Nhap so ban muon them\n";
//			cin >> x;
//			Add(root, x);
//			cout << "Them thanh cong\n";
//			in = true;
//			break;
//		case 2:
//			if (in)
//				NLR(root);
//			else cout << "Khong co du lieu\n";
//			break;
//		case 3:
//			if (in)
//				LNR(root);
//			else cout << "Khong co du lieu\n";
//			break;
//		case 4:
//			if (in)
//				LRN(root);
//			else cout << "Khong co du lieu\n";
//			break;
//		case 5:
//			if (in)
//				Node_con(root);
//			else cout << "Khong co du lieu\n";
//			break;
//		case 6:
//			if (in)
//				Node_cha(root);
//			else cout << "Khong co du lieu\n";
//			break;
//		case 7:
//			break;
//		default:
//			cout << "Khong co chuc nang tren\n";
//		}
//		_getch();
//	} while (choose > 0 && choose < 7);
//	return 0;
//}


//#include <iostream>
//using namespace std;
//typedef struct node
//{
//    float data;
//    node* next;
//};
//node* first;
//void init(node*&first)
//{
//    first = NULL;
//}
//node* createData(int x)
//{
//    node* p = new node;
//    if (p == NULL)
//        return NULL;
//    else
//    {
//        p->data = x;
//        p->next = NULL;
//        return p;
//    }
//}
//void AddFirst(node*&first, int x)
//{
//    if (first == NULL)
//        first = createData(x);
//    else
//    {
//        node* p = new node;
//        p = createData(x);
//        p->next = first;
//        first = p;
//    }
//}
//void AddLast(node*&first, int x)
//{
//    if (first == NULL)
//        first = createData(x);
//    else
//    {
//        node*p = createData(x),*q=first;
//        while (q->next != NULL)
//            q = q->next;
//        q->next = p;
//    }
//}
//void Add(node*& first, int x, int k) // thêm vào khoảng bạn muốn 
//{
//    node* p = first;
//    for (int i = 0; i < k - 1; i++)
//        p = p->next;
//    node* temp = new node;
//    temp = createData(x);
//    temp->next = p->next;
//    p->next = temp;
//}
//void DeletesAdd(node*& first)
//{
//    if (first != NULL)
//    {
//        node* p = first;
//        first = first->next;
//        delete p;
//    }
//}
//void DeletesLast(node*& first)
//{
//    if (first != NULL)
//    {
//        node* p = first, * q = NULL;
//        if (p != NULL)
//            while (p->next != NULL)
//            {
//                q = p;
//                p = p->next;
//            }
//        if (p != first)
//            q->next = NULL;
//        else first = NULL;
//        delete p;
//    }
//}
//void DeletesAll(node*& first)
//{
//    while (first != NULL)
//    {
//        node* p = first;
//        first = p->next;
//        delete p;
//    }
//    delete first;
//    first = NULL;
//    /*node* p;
//    while (first != NULL)
//    {
//        p = first;
//        first = p->next;
//        delete p;
//    }*/
//}
//void Deletes(node* first, int k)
//{
//    node* p = first;
//    for (int i = 0; i < k - 1; i++)
//        p = p->next;
//    node* temp = p->next;
//    p->next = p->next->next;
//    delete temp;
//}
//node* search(node* first, int x)
//{
//    while (first != NULL && first->data != x)
//        first = first->next;
//    return first;
//}
//node *outputnode(node* first, int k)// xuất danh sách đơn ở vị trí thứ k
//{
//    node* p = first;
//    for (int i = 0; i < k; i++)
//        p = p->next;
//    return p;
//}
//void OutPutKhoang(node* first, int x, int y) // thay đổi giá trị a thành giá trị b
//{
//    node* p = first;
//    while (p != NULL)
//    {
//        if (p->data == x)
//            p->data = y;
//        p = p->next;
//    }
//}
//
//void OutPut(node* first)
//{
//    node* p = first;
//    while (p != NULL)
//    {
//        cout << p->data << "\t";
//        p = p->next;
//    }
//    cout << endl;
//}
//int main()
//{
//    init(first);
//    AddFirst(first, 5);
//    AddLast(first, 6);
//    AddFirst(first, 7);
//    Add(first, 1, 2);
//    AddLast(first, 10);
//    AddLast(first, 11);
//    OutPut(first);
//    if (search(first, 5) != NULL)
//        cout << "Tim thay\n";
//    else cout << "Khong tim thay\n";
//    DeletesAdd(first);
//    OutPut(first);
//    DeletesLast(first);
//    OutPut(first);
//    Deletes(first, 1);
//    OutPut(first);
//    DeletesAll(first);
//    OutPut(first);
//    return 0;
//}

#include <iostream>
using namespace std;
void SelectionSort(int a[], int n) // giảm dần
{
	int min_pos;
	for (int i = 0; i < n - 1; i++)
	{
		min_pos = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] > a[min_pos])
				min_pos = j;
		swap(a[min_pos], a[i]);
	}
}
void InsertionSORT(int a[], int n) // giảm dần
{
	int x, j;
	for (int i = 1; i < n; i++)
	{
		x = a[i];
		j = i - 1;
		while (j >= 0 && x > a[j])
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
void BubbleSort(int a[], int n) // giảm dần
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n - 1; j > i; j--)
			if (a[j] > a[j - 1])
				swap(a[j], a[j - 1]);
	}
}
void InterchangeSort(int a[], int n) // giảm dần
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] < a[j])
                swap(a[i], a[j]); 
}
void QuickSort(int a[], int left, int right) // tăng dần
{
	int x = a[(left + right) / 2];
	int i = left;
	int j = right;
	while (i <= j)
	{
		while (a[i] < x) i++;
		while (a[j] > x) j--;
		if (i <= j) 
		{
			swap(a[i], a[j]);
			i++; 
			j--;
		}
	}
	if (left < j) 
		QuickSort(a, left, j);
	if (i < right)
		QuickSort(a, i, right);
}
void QuickSort_des(int a[], int left, int right) // giảm dần
{
	int pivot = a[(left + right) / 2];
	int i = left, j = right;
	do {
		while (a[i] > pivot)
			i++;
		while (a[j] < pivot)
			j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (left < j)
		QuickSort_des(a, left, j);
	if (i < right)
		QuickSort_des(a, i, right);
}
void shift(int a[], int i, int n)
{
	int j = 2 * i + 1;
	if (j >= n)
		return;
	if (j + 1 < n)
	{
		if (a[j] < a[j + 1])
			j++;
	}
	if (a[i] >= a[j])
		return;
	swap(a[i], a[j]);
	shift(a, j, n);
}
void HeapSorthight(int a[], int n) // tăng da
{
	int i = n / 2;
	while (i >= 0)
	{
		shift(a, i, n - 1);
		i--;
	}
	int right = n - 1;
	while (right > 0)
	{
		if (a[0] > a[right])
			swap(a[0], a[right]);
		right--;
		if (right > 0)
			shift(a, 0, right);
	}
}
void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
	cout << endl;
}
int main()
{
	int a[5] = { 3,5,1,0,-6 };
	//SelectionSort(a, sizeof(a) / sizeof(a[0]) );
	//InsertionSORT(a, sizeof(a) / sizeof(a[0]));
	//BubbleSort(a, sizeof(a) / sizeof(a[0]));
   /* InterchangeSort(a, sizeof(a) / sizeof(a[0]));*/
	//QuickSort(a,0,5-1);
	//QuickSort_des(a, 0, 5-1);
	HeapSorthight(a, 5);
	output(a, 5);
	return 0;
}

//#include<stdio.h> 
//#include<stdlib.h> 
//struct Node
//{
//	int data;
//	struct Node* next;
//};
//
//void sortedInsert(struct Node**, struct Node*);
//
//void insertionSort(struct Node** head_ref)
//{
//	struct Node* sorted = NULL;
//	struct Node* current = *head_ref;
//	while (current != NULL)
//	{
//		struct Node* next = current->next;
//		sortedInsert(&sorted, current);
//		current = next;
//	}
//	*head_ref = sorted;
//}
//void sortedInsert(struct Node** head_ref, struct Node* new_node)
//{
//	struct Node* current;
//	if (*head_ref == NULL || (*head_ref)->data <= new_node->data)
//	{
//		new_node->next = *head_ref;
//		*head_ref = new_node;
//	}
//	else
//	{
//		current = *head_ref;
//		while (current->next != NULL &&
//			current->next->data > new_node->data)
//		{
//			current = current->next;
//		}
//		new_node->next = current->next;
//		current->next = new_node;
//	}
//}
//
//void printList(struct Node* head)
//{
//	struct Node* temp = head;
//	while (temp != NULL)
//	{
//		printf("%d  ", temp->data);
//		temp = temp->next;
//	}
//}
//void push(struct Node** head_ref, int new_data)
//{
//	struct Node* new_node = new Node;
//
//	new_node->data = new_data;
//
//	new_node->next = (*head_ref);
//	(*head_ref) = new_node;
//}
//int main()
//{
//	struct Node* a = NULL;
//	push(&a, 5);
//	push(&a, 20);
//	push(&a, 4);
//	push(&a, 3);
//	push(&a, 30);
//
//	printf("Linked List before sorting \n");
//	printList(a);
//
//	insertionSort(&a);
//
//	printf("\nLinked List after sorting \n");
//	printList(a);
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//struct Node
//{
//	int data;
//	Node* left, * right;
//};
//Node*root;
//struct Nodes
//{
//	int x;
//	Nodes* next;
//};
//Nodes* sp;
//int isEmpty()
//{
//	return sp == NULL ? 1 : 0;
//}
//void Push(int x)
//{
//	Nodes* p = new Nodes;
//	p->x = x;
//	p->next = sp;
//	sp = p;
//}
//void Pop(int &x)
//{
//	if (sp != NULL)
//	{
//		Nodes* p = sp;
//		x = p->x;
//		sp = p->next;
//		delete p;
//	}
//}
//Node*search(Node*p, int x)
//{
//	if (p != NULL)
//	{
//		if (p->data == x)
//			return p;
//		else
//			if (x > p->data)
//				return search(p->right, x);
//			else
//				return search(p->left, x);
//	}
//	return NULL;
//}
//void LNR_NoRe(Node* p)
//{
//	Node* cur = p;
//	while (cur != NULL || isEmpty() == 0)
//	{
//		while (cur != NULL)
//		{
//			Push(cur->data);
//			cur = cur->left;
//		}
//		int x;
//		Pop(x);
//		cur = search(root, x);
//		cout << p->data << "\t";
//		cur = cur->right;
//	}
//}

//#include <iostream>
//using namespace std;
//struct node
//{
//    int data;
//    node* next, * previous;
//};
//node* first, * last;
//void init()
//{
//    first = last = NULL;
//}
//void AddFirst(int data)
//{
//    node* p = new node;
//    p->data = data;
//    p->next = first;
//    p->previous = NULL;
//    if (first != NULL)
//        first->previous = p;
//    else last = p;
//    first = p;
//}
//void AddLast(int data)
//{
//    node* p = new node;
//    p->data = data;
//    p->next = NULL;
//    p->previous = last;
//    if (last != NULL)
//        last->next = p;
//    else first = p;
//    last = p;
//}
//void DeleteFirst()
//{
//    if (first != NULL)
//    {
//        node* p = first;
//        first = first->next;
//        delete p;
//        if (first != NULL)
//            first->previous = NULL;
//        else last = NULL;
//    }
//}
//void DeleteLast()
//{
//    if (last != NULL)
//    {
//        node* p = last;
//        last = last->previous;
//        if (last != NULL)
//            last->next = NULL;
//        else first = NULL;
//        delete p;
//    }
//}
//node* search(int data)
//{
//    node* p = first;
//    while (p != NULL && p->data != data)
//        p = p->next;
//    return p;
//}
//void Delete(int data)
//{
//    node* p = search(data);
//    if (p != NULL)
//    {
//        if (p->previous == NULL)
//        {
//            DeleteFirst();
//            return;
//        }
//        if (p->next == NULL)
//        {
//            DeleteLast();
//            return;
//        }
//        p->previous->next = p->next;
//        p->next->previous = p->previous;
//        p->previous = NULL;
//        p->next = NULL;
//        delete p;
//    }
//}
//void Output()
//{
//    node* p = first;
//    while (p != NULL)
//    {
//        cout << p->data << "\t";
//        p = p->next;
//    }
//    cout << endl;
//}
//void Add(int k,int data)
//{
//    node* p = first;
//    for (int i = 0; i < k - 1; i++)
//        p = p->next;
//    node* temp = new node;
//    temp->data = data;
//    temp->previous = p;
//    temp->next = p->next;
//    p->next->previous = temp;
//    p->next = temp;
//}
//int main()
//{
//    init();
//    AddFirst(5);
//    AddLast(6);
//    AddFirst(9);
//    AddLast(10);
//    AddFirst(0);
//    Output();
//    DeleteFirst();
//    Output();
//    DeleteLast();
//    Output();
//    Delete(5);
//    Output();
//    Add(1, 2);
//    Output();
//}