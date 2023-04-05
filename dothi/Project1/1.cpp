#include <string>
#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;
#define MAX 20
#define infinity 9999
int spanning[MAX][MAX];
struct Node
{
    int data;
    Node* link;
    Node(int _data)
    {
        data = _data;
        link = NULL;
    }
} typedef STACK;
struct QUEUE
{
    Node* front = NULL;
    Node* back = NULL;
};
bool isEmpty(Node* p)
{
    return p == NULL;
}
void Pop(Node*& p)
{
    if (!isEmpty(p))
    {
        Node* q = p;
        p = p->link;
        delete q;
    }
}
int Check(Node* p)
{
    if (!isEmpty(p))
        return p->data;
    return INT32_MIN;
}
void Push_St(STACK*& st, int value)
{
    STACK* newValue = new STACK(value);
    newValue->link = st;
    st = newValue;
}
void Push_Qu(QUEUE& qu, int value)
{
    Node* q = new Node(value);
    if (qu.front == NULL)
    {
        qu.front = qu.back = q;
        return;
    }
    qu.back->link = q;
    qu.back = q;
}
////////////////////////////////////
// Câu a
void ReadFile(int a[][MAX + 1], int n, string s)
{
    ifstream inData;
    inData.open("input.txt");
    if (inData.is_open())
    {
        inData >> n;
        inData.ignore();
        for (int i = 0; i < n; i++)
            getline(cin, s);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                inData >> a[i][j];
        }
        inData.close();
        cout << "Doc file thanh cong\n";
    }
    else cout << "Doc file khong thanh cong\n";
}
void input(int a[][MAX + 1], int& n , string s[])
{
    do
    {
        cout << "Nhap so dinh cua do thi: ";
        cin >> n;
        if (n < 1 || n > MAX)
            cout << "\n--KHONG HOP LE--\n";
    } while (n < 1 || n > MAX);
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        cout << "Ten dinh cua do thi thu " << i + 1 <<endl;
        getline(cin,s[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << "- Nhap cac dinh ke cua dinh " << i + 1 << ": ";
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    }
}
// Câu b
void output(int a[][MAX + 1], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << "\n";
    }
}
// Câu c
void BFS(int a[][MAX + 1], int n, int i)
{
    bool visted[MAX + 1] = { false };
    QUEUE q;
    Push_Qu(q, i);
    visted[i] = true;
    while (!isEmpty(q.front))
    {
        int u = Check(q.front);
        Pop(q.front);
        cout << u << "\t";
        for (int v = 1; v <= n; v++)
            if (a[u][v] == 1 && !visted[v])
            {
                Push_Qu(q, v);
                visted[v] = true;
            }
    }
    cout << "\n";
}
// Câu d
void DFS(int a[][MAX + 1], int n, int i)
{
    bool visted[MAX + 1] = { false };
    STACK* sp = NULL;
    Push_St(sp, i);
    visted[i] = true;
    cout << i << "\t";
    while (!isEmpty(sp))
    {
        int u = Check(sp);
        for (int v = 1; v <= n; v++)
            if (a[u][v] == 1 && !visted[v])
            {
                cout << v << "\t";
                visted[v] = true;
                Push_St(sp, v);
                break;
            }
        if (u == Check(sp))
            Pop(sp);
    }
    cout << "\n";
}
int Prim(int a[][MAX+1], int n)
{
    int cost[MAX][MAX];
    int u, v, min_distance, distance[MAX], from[MAX];
    int visited[MAX], no_of_edges,  min_cost;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 0)
                cost[i][j] = infinity;
            else
                cost[i][j] = a[i][j];
            spanning[i][j] = 0;
        }
    distance[0] = 0;
    visited[0] = 1;
    for (int i = 1; i < n; i++)
    {
        distance[i] = cost[0][i];
        from[i] = 0;
        visited[i] = 0;
    }
    min_cost = 0;
    no_of_edges = n - 1; 
    while (no_of_edges > 0)
    {
        min_distance = infinity;
        for (int i = 1; i < n; i++)
            if (visited[i] == 0 && distance[i] < min_distance)
            {
                v = i;
                min_distance = distance[i];
            }
        u = from[v];
        spanning[u][v] = distance[v];
        spanning[v][u] = distance[v];
        no_of_edges--;
        visited[v] = 1;
        for (int i = 1; i < n; i++)
            if (visited[i] == 0 && cost[i][v] < distance[i])
            {
                distance[i] = cost[i][v];
                from[i] = v;
            }
        min_cost = min_cost + cost[u][v];
    }
    return min_cost;
}
// Câu e
//bool searchBFS(int a[][MAX + 1], int n, int i, int x)
//{
//    bool visted[MAX + 1] = { 0 };
//    QUEUE q;
//    Push_Qu(q, i);
//    visted[i] = 1;
//    while (!isEmpty(q.front))
//    {
//        int u = Check(q.front);
//        Pop(q.front);
//        if (u == x)
//            return true;
//        for (int v = 1; v <= n; v++)
//            if (a[u][v] == 1 && !visted[v])
//            {
//                visted[v] = 1;
//                Push_Qu(q, v);
//            }
//    }
//    return false;
//}
int main()
{
    string s[5];
    int a[MAX + 1][MAX + 1], n = 0;
    bool in = false;
    int choose;
  /*  ReadFile(a, n, s);
    for (int i = 0; i < n; i++)
        cout << s[i] << "\t";
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j];
        cout << endl;
    }*/
   /* do {
        system("cls");
        cout << "\t\tMenu:\n";
        cout << "\t1:Doc do thi tu file txt\n";
        cout << "\t2:Nhap do thi tren console\n";
        cout << "\t3:Xuat do thi\n";
        cout << "\t4:Duyet DFS\n";
        cout << "\t5:Duyet BFS\n";
        cout << "\t6:Prim\n";
        cout << "\t7:Exit\n";
        cin >> choose;
        switch (choose)
        {
        case 1:
            ReadFile(a, n, s);
            in = true;
            break;
        case 2:
            input(a, n, s);
            in = true;
            break;
        case 3:
            if (in)
            {
                cout << "Xuat cac dinh do thi vua nhap\n";
                output(a, n);
            }
        case 4:
            if (in)
            {
                cout << "\n--QUA TRINH DFS--\n";
                DFS(a, n, 1);
            }
            else cout << "Khong co du lieu\n";
            break;
        case 5:
            if (in)
            {
                cout << "\n--QUA TRINH BFS--\n";
                BFS(a, n, 1);
            }
            else cout << "Khong co du lieu\n";
            break;
        case 6:
            if (in)
            {
                cout << "\n--CAY KHUNG NHO NHAT THEO THUAT TOAN PRIM--\n";
                cout << Prim(a, n);
            }
            else cout << "Khong co du lieu\n";
            break;
        case 7:
            break;
        default:
            cout << "Khong co chuc nang tren\n";
        }
        _getch();
    } while (choose > 0 && choose < 7);*/
   /* int x;
    cout << "\n- Nhap dinh can tim: ";
    cin >> x;*/
   /* if (searchBFS(a, n, 1, x))
        cout << "\n-- GIA TRI << " << x << " >> CO TRONG DO THi --\n";
    else
        cout << "\n-- GIA TRI << " << x << " >> KHONG CO TRONG DO THi --\n";*/
 
    return 0;
}