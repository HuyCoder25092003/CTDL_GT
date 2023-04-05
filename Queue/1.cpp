#include <iostream>
using namespace std;
#define MAX 100
void init(int a[], int& front, int &rear)
{
	front = rear = -1;
}
bool empty(int front)
{
	return front == -1 ? true : false;
}
bool isFull(int rear, int front)
{
	return rear - front == MAX - 1 ? true: false;
}
//void push(int a[], int &front, int &rear, int value)
//{
//	// tịnh tiến 
//	if (isFull(rear,front))
//		return;
//	else
//	{
//		if (front == -1)
//			 front=0;
//		if(rear==MAX-1)
//		{
//			for (int i = front; i < MAX; i++)
//				a[i - front] = a[i];
//			rear = MAX - 1 - front;
//			front = 0;
//		}
//		a[++rear] = value;
//	}
//}
void push(int a[], int& front, int &rear, int value)
{
	// vòng 
	if (isFull(rear, front))
		return;
	else
	{
		if (front == -1)
			front = 0;
		if (rear == MAX - 1)
			rear = -1;
		a[++rear] = value;
	}
}
//void pop(int a[], int &front, int &rear, int value)
//{
//	// tịnh tiến 
//	if (!empty(front))
//	{
//		a[front] = 0;
//		front++;
//		if (front > rear)
//			front = rear = -1;
//	}
//	else return;
//}
void pop(int a[], int &front, int &rear, int value)
{
	// vòng 
	if (!empty(front))
	{
		if (front == rear)
			front = rear = -1;
		else
		{
			front++;
			if (front > MAX - 1)
				front = 0;
		}
	}
}
void output(int a[], int front, int rear)
{
	if (!empty(front))
	{
		for (int i = front; i <= rear; i++)
			cout << a[i] << "\t";
		cout << endl;
	}
	else return;
}
int main()
{
	int a[MAX], front, rear, value,x,y,z;
	init(a, front, rear);
	if (empty(front))
		cout << "Danh sach dang rong\n";
	else cout << "Danh sach hien khong rong\n";
	if (isFull(rear, front))
		cout << "Danh sach day\n";
	else cout << "Danh sach hien tai chua day\n";
	cout << "Nhap phan tu ban muon them\n";
	cin >> value;
	push(a, front, rear, value);
	cout << "Nhap phan tu ban muon them\n";
	cin >> x;
	push(a, front, rear, x);
	cout << "Nhap phan tu ban muon them\n";
	cin >> y;
	push(a, front, rear, y);
	cout << "Nhap phan tu ban muon them\n";
	cin >> z;
	push(a, front, rear, z);
	output(a, front, rear);
	pop(a, front, rear,value);
	output(a, front, rear);
	return 0;
}