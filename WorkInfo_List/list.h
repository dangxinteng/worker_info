#pragma once
struct SWorker
{
	int nNumb;
	char sName[20];
	float fSalary;
};
typedef SWorker DATA;
typedef struct Node
{
	DATA data;
	Node* pNext;
}Node;

Node* GetHead();
Node* AddHead(DATA data);
Node* AddTail(DATA data);
Node* Find(int nNumb);
Node* Modify(int nNumb, const DATA data);
int Delete(int nNumb);
void RemoveAll();