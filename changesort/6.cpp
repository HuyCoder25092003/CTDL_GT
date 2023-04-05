#include <iostream>
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
int lon(int a[], int n)
{
    int max = a[0];
    for (int i = 1;i < n;i++)
        if (a[i] >= max)
            max = a[i];
    return max;
}
void printMax(int a[],int n)
{
    int max = lon(a, n);
    for (int i = 0;i < n;i++)
        if (a[i] == max)
            cout << a[i] << "\t";
    cout << endl;
}
int nho(int a[], int n)
{
    int min = a[0];
    for (int i = 1;i < n;i++)
        if (a[i] <= min)
            min = a[i];
    return min;
}
void printMin(int a[], int n)
{
    int min = nho(a, n);
    for (int i = 0;i < n;i++)
        if (a[i] == min)
            cout << a[i] << "\t";
    cout << endl;
}
int main()
{
    int a[MAX], n;
    input(a, n);
    output(a, n);
    printMax(a, n);
    printMin(a, n);
}