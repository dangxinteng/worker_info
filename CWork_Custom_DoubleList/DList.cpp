#include "DList.h"
DList::DList()
{
	m_pHead = NULL;
	m_pTail = NULL;
	m_nCount = 0;
}
DList::~DList()
{
	RemoveAll();
}

void DList::AddTail(const DATA &data)
{
	SNode* pNew = new SNode;
	pNew->data = data;
	pNew->pNext = NULL;
	pNew->pPrev = m_pTail;
	if (!m_pHead)
		m_pHead = pNew;
	else
		m_pTail->pNext = pNew;
	m_pTail = pNew;
	m_nCount++;
}

void DList::AddHead(const DATA &data)
{
	SNode* pNew = new SNode;
	pNew->data = data;
	pNew->pPrev = NULL;
	pNew->pNext = m_pHead;
	if (!m_pHead)
		m_pTail = pNew;
	else		
		m_pHead->pPrev = pNew;
	m_pHead = pNew;
	m_nCount++;
}

DATA& DList::GetNext(POSITION & pos)
{
	assert(pos != NULL);
	SNode* p = (SNode*)pos;
	if (!p->pNext)
		pos = NULL;
	else
		pos = (POSITION)p->pNext;
	return  p->data;
}

DATA& DList::GetPrev(POSITION & pos)
{
	assert(pos != NULL);
	SNode* p = (SNode*)pos;
	if (!p->pPrev)
		pos = NULL;
	else
		pos = p->pPrev;
	return p->data;
}

void DList::SetAt(POSITION pos, DATA& data)
{
	if (!pos)
		return;
	SNode* p = (SNode*)pos;
	p->data = data;
}
POSITION DList::FindIndex(int index)
{
	if (index >= m_nCount)
		return NULL;
	SNode* pos = m_pHead;
	int i = -1;
	while (++i < index)
		pos = pos->pNext;
	return (POSITION)pos;
}
void DList::RemoveHead()
{
	if (m_nCount <= 0)
		return;
	if (m_nCount == 1)
	{
		delete m_pHead;
		m_pHead = m_pTail = NULL;
		return;
	}
	SNode* p = m_pHead;
	p->pNext->pPrev = NULL;
	m_pHead = p->pNext;
	delete p;
	m_nCount--;
}

void DList::RemoveTail()
{
	if (m_nCount <= 0)
		return;
	if (m_nCount == 1)
	{
		delete m_pTail;
		m_pHead = m_pTail = NULL;
		return;
	}
	SNode* p = m_pTail;
	p->pPrev->pNext = NULL;
	m_pTail = p->pPrev;
	delete p;
	m_nCount--;
}
void DList::RemoveAt(POSITION pos)
{
	if (!pos)
		return;
	SNode* p = (SNode*)pos;
	if (p == m_pHead)
		m_pHead = p->pNext;
	else
		p->pPrev->pNext = p->pNext;
	if (p == m_pTail)
		m_pTail = p->pPrev;
	else
		p->pNext->pPrev = p->pPrev;
	delete p;
	m_nCount--;
}
void DList::RemoveAll()
{
	SNode* p = m_pHead,*q;
	while (p)
	{
		q = p;
		p = p->pNext;
		delete q;
	}
	m_nCount = 0;
}
