#include <iostream>
#define max 100
using namespace std;
int chuaXet[max];
int A[max][max], n;
void Input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> A[i][j];
    }
}
void Output()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << A[i][j]<<"\t";
        cout << endl;
    }
}
void KhoiTao_ChuaXet() 
{
    for (int i = 0; i < max; i++)
        chuaXet[i] = 1;
}
void DFS(int u) 
{
    chuaXet[u] = 0;
    cout << u << "->";
    for (int v = 0; v < n; v++)
        if (chuaXet[v] == 1 && A[u][v] == 1)
        {
            DFS(v);
        }
}
void BFS(int u) 
{
    int queue[max], dau = 0, cuoi = 0;
    for (int i = 0; i < max; i++) queue[i] = 0;
    queue[cuoi] = u;
    chuaXet[u] = 0;
    cout << u << "->";

    while (dau >= cuoi)
    {
        int p = queue[cuoi];
        cuoi++;
        for (int v = 0; v < n; v++)
            if (chuaXet[v] == 1 && A[p][v] == 1)
            {
                dau++;
                queue[dau] = v;
                chuaXet[v] = 0;
                cout << v << "->";
            }
    }
}
void SearchDFS(int u, int x)
{
    chuaXet[u] = 0;
    if (x == u)
    {
        cout << "Co ton tai\n";
        return;
    }
    for (int v = 0; v < n; v++)
        if (chuaXet[v] == 1 && A[u][v] == 1)
        {
            DFS(v);
        }
}
int main() 
{
    Input();
    Output();
    KhoiTao_ChuaXet();
    cout << "\n Duyet do thi DFS: ";
    DFS(0);
    KhoiTao_ChuaXet();
    cout << "\n Duyet do thi BFS: ";
    BFS(0);
    cout << "\n Tim kiem con x trong do thi DFS: ";
    int value;
    cout << "Moi ban nhap con so ban muon tim\n";
    cin >> value;
    SearchDFS(0, value);
    return 0;
}