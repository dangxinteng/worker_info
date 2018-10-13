#pragma once
#include"common.h"
template<typename TYPE,typename ARG_TYPE = const TYPE &>
class CList
{
	struct SNode
	{
		SNode*pPrev, *pNext;
		TYPE data;
	};
	SNode m_end;
	int m_nCount;
public:
	class iterator
	{
		SNode* p;
	public:
		iterator(SNode* p)
		{
			this->p = p;
		}
		TYPE& operator*()
		{
			return p->data;
		}
		operator SNode*()
		{
			return p;
		}
		TYPE* operator->()
		{
			return &p->data;
		}
		iterator& operator++()
		{
			p = p->pNext;
			return *this;
		}
		iterator operator++(int)
		{
			SNode*q = p;
			p = p->pNext;
			return q;
		}
		iterator& operator--()
		{
			p = p->pPrev;
			return *this;
		}
		iterator operator--(int)
		{
			SNode*q = p;
			p = p->pPrev;
			return q;
		}

	};
	iterator begin()  const
	{
		return m_end.pNext;
	}
	iterator end() const
	{
		return (SNode*)&m_end;//const SNode 
	}

	int size() const
	{
		return m_nCount;
	}

	void push_back(ARG_TYPE data)
	{
		SNode* p = new SNode;
		p->data = data;
		p->pNext = &m_end;
		if (m_nCount == 0)
		{
			m_end.pNext = p;
			p->pPrev = &m_end;
		}
		else
		{
			m_end.pPrev->pNext = p;
			p->pPrev = m_end.pPrev;
		}
		m_end.pPrev = p;
		++m_nCount;
	}
	void push_front(ARG_TYPE data)
	{
		SNode* p = new SNode;
		p->data = data;
		p->pPrev = &m_end;
		if (m_nCount == 0)
		{
			m_end.pPrev = p;
			p->pNext = &m_end;
		}
		else
		{
			m_end.pNext->pPrev = p;
			p->pNext = m_end.pNext;
		}
		m_end.pNext = p;
		++m_nCount;
	}

	void erase(iterator pos)
	{
		if (pos == end())
			return;
		SNode* p = pos;
		if (m_nCount > 1)
		{
			p->pPrev->pNext = p->pNext;
			p->pNext->pPrev = p->pPrev;
		}
		delete p;
		--m_nCount;
		if (m_nCount == 0)
		{
			m_end.pNext = m_end.pPrev = &m_end;
		}
	}

	void clear()
	{
		SNode* p = begin(), *q;
		while (p != end())//this ->比p速度要慢10倍
		{
			q = p;
			p = p->pNext;
			delete q;
		}
		m_end.pNext = m_end.pPrev = &m_end;
		m_nCount = 0;
	}
	CList()
	{
		m_end.pNext = m_end.pPrev = &m_end;
		m_nCount = 0;
	}
	~CList()
	{
		clear();
	}
};