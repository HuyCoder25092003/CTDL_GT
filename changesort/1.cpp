#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100
void input(int a[], int &n)
{
    cout << "Nhap so luong phan tu ban muon them vao mang\n";
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
void InsertionSort(int a[], int n)
{
    int x,j;
    for (int i = 1; i < n; i++)
    {
        x = a[i];
        j = i - 1;
        while (0 <= j && x < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j+1] = x;
    }
}
void SelectionSort(int a[], int n)
{
    int min_pos;
    for (int i = 0; i < n; i++)
    {
        min_pos = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min_pos])
                min_pos = j;
        swap(a[min_pos], a[i]);
    }
}
void InterchangeSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j])
                swap(a[i], a[j]);
    }
}
void BubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
            if (a[j] < a[j - 1])
                swap(a[j], a[j - 1]);
    }
}
int main ()
{
    int a[MAX], n;
    input(a, n);
    output(a, n);
    InsertionSort(a, n); 
    //SelectionSort(a, n);
    //InterchangeSort(a, n);
    //BubbleSort(a, n);
    output(a, n);
}