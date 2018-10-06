#pragma once
#include"common.h"
struct SNode
{
	SNode*pPrev, *pNext;
	DATA data;
};
typedef void* POSITION;

class DList
{
	SNode* m_pHead, *m_pTail;
	int m_nCount;
public:
	POSITION GetHeadPosition()
	{
		return (POSITION)m_pHead;
	}
	POSITION GetTailPosition()
	{
		return (POSITION)m_pTail;
	}

	int GetCount()
	{
		return m_nCount;
	}

	DATA& GetAt(POSITION pos)
	{
		return ((SNode*)pos)->data;
	}

	void AddTail(const DATA &data);
	void AddHead(const DATA &data);

	DATA& GetNext(POSITION &pos);
	DATA& GetPrev(POSITION &pos);

	void SetAt(POSITION pos, DATA &data);
	POSITION FindIndex(int index);
	void RemoveHead();
	void RemoveTail();
	void RemoveAt(POSITION pos);

	void RemoveAll();
	DList();
	~DList();
};

