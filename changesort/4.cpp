#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100
void input(int a[], int& n)
{
	cout << "Nhap so luong phan tu ban muon\n";
	do {
		cin >> n;
	} while (n <= 0 || n > MAX);
	for (int i = 0; i < n; i++)
		cin >> a[i];
}
void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
	cout << endl;
}
void QuickSortdown(int a[], int left, int right)
{
	int x = a[(left + right) / 2];
	int i = left, j = right;
	do {
		while (a[i] > x)
			i++;
		while (a[j] < x)
			j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (left < j)
		QuickSortdown(a, left, j);
	if (i < right)
		QuickSortdown(a, i, right);
}
void QuickSort_head(int a[], int left, int right)
{
	int x = a[left];
	int i = left;
	int j = right;
	while (i < j)
	{
		while (a[i] < x) i++;
		while (a[j] > x) j--;
		if (i <= j) {
			swap(a[i], a[j]);
			i++; j--;
		}
	}
	if (left < j) QuickSort_head(a, left, j);
	if (i < right)
		QuickSort_head(a, i, right);
}
void shift(int a[],int i,int n)
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
void HeapSorthight(int a[], int n)
{
	int i = n / 2;
	while (i >= 0)
	{
		shift(a, i, n-1);
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
int BinarySearch(int a[], int n, int x)
{
	int left = 0,right=n-1,mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (a[mid] == x)
			return a[mid];
		if (a[mid] > x)
			left = mid + 1;
		if (a[mid] < x)
			right = mid - 1;
	}
	return -1;
}
int main()
{
	int a[MAX], n;
	input(a, n);
	output(a, n);
	QuickSortdown(a, 0, n - 1);
	output(a, n);
	QuickSorthight(a, 0, n - 1);
	output(a, n);
	//QuickSortdown(a, 0, n - 1);
	//output(a, n);
	QuickSort_head(a, 0, n - 1);
	output(a, n);
	//HeapSorthight(a, n);
	//output(a, n);
	/*int x;
	cout << "Nhap con ban muon tim\n";
	do {
		cin >> x;
	} while (x > MAX);
	if (BinarySearch(a, n, x) != -1)
		cout << "Tim thay con " << x << endl;
	else cout << "Tim khong thay con " << x << endl;*/
	return 0;
}