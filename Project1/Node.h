#pragma once
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
struct SanPham
{
	int value;
	string name;
};
struct Node
{
	SanPham data;
	Node* next, * prev;
}; typedef struct Node node;
struct List
{
	node* head, * tail;
}; typedef struct List list;
void initData(list &l);
node* createData(SanPham value);
void AddLast(node* p, list &l);
void OutPut(list l);
void OutPut2(list l, int value1, int value2);