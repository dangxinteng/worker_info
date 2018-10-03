#pragma once
struct Worker
{
	int nNumb;
	char sName[20];
	float fSalary;
};
typedef Worker DATA;
typedef struct Node
{
	DATA data;
	struct Node* pNext;
}Node;
class List
{
	Node* m_pHead;
	int m_nCount;
public:
	List();
	Node* GetHead();
	int GetCount();
	void GrowCount();
	Node* AddHead(const DATA data);
	Node* AddTail(const DATA data);
	Node* FindNumb(const int nNumb);
	Node* Modify(const int nNumb, const DATA data);
	int Delete(const int nNumb);
	void RemoveAll();
	~List();
};

