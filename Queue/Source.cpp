#include <iostream>
using namespace std;
struct Node
{
    int info;
    Node* link;
}; typedef struct Node node;
void init(node*& first)
{
    first = NULL;
}
node *createData(int value)
{
    node* p = new node;
    if (p == NULL)
        return NULL;
    else
    {
        p->info = value;
        p->link = NULL;
        return p;
    }
}
void Addlast(node *&first,int value)
{
    node* p = createData(value);
    if (first == NULL)
        first = p;
    else
    {
        node* q = first;
        while (q->link!=NULL)
            q = q->link;
        q->link = p;
    }
}
void rally(node *first, node *first1)
{
    node* p = first, * q = first1;
    while (p != NULL)
    {
        cout << p->info << "\t";
        while (q != NULL)
        {
            cout << q->info << "\t";
            q = q->link;
        }
        p = p->link;
    }
    cout << endl;
}
void setdelivery(node* first, node* first1)
{
    node* p = first;
    while (p != NULL)
    {
        for(node *q = first1;q!=NULL;q=q->link)
        {
            if (p->info == q->info)
                cout << p->info << "\t";
        }
        p = p->link;
    }
    cout << endl;
}
int size(node* first)
{
    node* p = first;
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->link;
    }
    return count;
}
int main()
{
    node* first,*first1;
    init(first);
    init(first1);
    Addlast(first, 3);
    Addlast(first, 5);
    Addlast(first, 6);
    Addlast(first, 7);
    Addlast(first1, 1);
    Addlast(first1, 5);
    Addlast(first1, 6);
    rally(first, first1);
    return 0;
}