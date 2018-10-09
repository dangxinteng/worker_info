#pragma once
#include<assert.h>
template <typename TYPE, typename ARG_TYPE = const TYPE &>
class DList
{
	struct SNode
	{
		SNode*pPrev, *pNext;
		TYPE data;
	};
	SNode* m_pHead, *m_pTail;
	int m_nCount;
public:
	struct  _POSITION {};
	typedef _POSITION* POSITION;
	DList()
	{
		m_pHead = NULL;
		m_pTail = NULL;
		m_nCount = 0;
	}
	~DList()
	{
		RemoveAll();
	}
	POSITION GetHeadPosition() const
	{
		return (POSITION)m_pHead;
	}
	POSITION GetTailPosition() const
	{
		return (POSITION)m_pTail;
	}

	int GetCount() const
	{
		return m_nCount;
	}

	const TYPE& GetAt(POSITION pos) const
	{
		return ((SNode*)pos)->data;
	}
	TYPE& GetAt(POSITION pos) 
	{
		return ((SNode*)pos)->data;
	}
	void AddTail(ARG_TYPE data)
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
	void AddHead(ARG_TYPE data)
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

	TYPE& GetNext(POSITION &pos) const
	{
		assert(pos != nullptr);
		SNode* p = (SNode*)pos;
		if (!p->pNext)
			pos = nullptr;
		else
			pos = (POSITION)p->pNext;
		return  p->data;
	}
	const TYPE& GetPrev(POSITION &pos) const
	{
		assert(pos != NULL);
		SNode* p = (SNode*)pos;
		if (!p->pPrev)
			pos = NULL;
		else
			pos = p->pPrev;
		return p->data;
	}
	bool SetAt(POSITION pos, ARG_TYPE data)
	{
		if (!pos)
			return false;
		SNode* p = (SNode*)pos;
		p->data = data;
		return true;
	}
	POSITION FindIndex(int index) const
	{
		if (index >= m_nCount)
			return nullptr;
		SNode* pos = m_pHead;
		int i = -1;
		while (++i < index)
			pos = pos->pNext;
		return (POSITION)pos;
	}
	void RemoveHead()
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
	void RemoveTail()
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
	void RemoveAt(POSITION pos)
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

	void RemoveAll()
	{
		SNode* p = m_pHead, *q;
		while (p)
		{
			q = p;
			p = p->pNext;
			delete q;
		}
		m_nCount = 0;
	}
};

