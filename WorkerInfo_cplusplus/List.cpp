#include<iostream>
#include "List.h"

List::List()
{
	Node* m_pHead = NULL;
	int m_nCount = 0;
}

int List::GetCount()
{
	return m_nCount;
}
void List::GrowCount()
{
	++m_nCount;
}
Node* List::GetHead()
{
	return m_pHead;
}
Node* List::AddHead(const DATA data)
{
	Node* pNew = new Node;
	pNew->data = data;
	pNew->pNext = m_pHead;
	m_pHead = pNew;
	++m_nCount;
	return pNew;
}
Node* List::AddTail(const DATA data)
{
	Node* p = m_pHead;
	if (!p)
		return AddHead(data);
	while (p->pNext)
		p = p->pNext;
	Node* pNew = new Node;
	pNew->data = data;
	pNew->pNext = p->pNext;
	p->pNext = pNew;
	++m_nCount;
	return pNew;
}
Node* List::FindNumb(const int nNumb)
{
	Node* p = m_pHead;
	while (p)
	{
		if (p->data.nNumb == nNumb)
			return p;
		p = p->pNext;
	}
	return NULL;
}
Node* List::Modify(const int nNumb, const DATA data)
{
	Node* p = NULL;
	p = FindNumb(nNumb);
	if (!p)
		return NULL;
	p->data = data;
	return p;
}
int List::Delete(const int nNumb)
{
	Node* p = m_pHead;
	Node* pMark = NULL;

	while (p)
	{
		if (p->data.nNumb == nNumb)
			break;
		pMark = p;
		p = p->pNext;
	}
	if (!pMark)
	{
		m_pHead = p->pNext;
		free(p);
		return true;
	}
	if (!p)
		return false;
	pMark->pNext = p->pNext;
	--m_nCount;
	free(p);
	return true;
}
void List::RemoveAll()
{
	Node* p = m_pHead;
	while (p)
	{
		Node* pMark = p;
		p = p->pNext;
		delete pMark;
	}
	m_pHead = NULL;
	m_nCount = 0;
}

List::~List()
{
	RemoveAll();
}
