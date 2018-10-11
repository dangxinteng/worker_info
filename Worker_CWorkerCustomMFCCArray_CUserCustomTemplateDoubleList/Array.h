#pragma once
#include<assert.h>
template<class TYPE, class ARG_TYPE = const TYPE&>
class CArray
{
	int m_nSize;
	int m_nCount;
	TYPE* m_pDataHead;
	void ReAlloc(int nSize);
	int GetSize() const//≤‚ ‘ ±”√
	{
		return m_nSize;
	}
	friend void Print(const CArray<int, int>& arr, const char* msg);
public:
	CArray(int nSize = 4)
	{
		assert(nSize >= 1);
		m_pDataHead = new TYPE[nSize];
		m_nSize = nSize;
		m_nCount = 0;
	}
	CArray(const CArray& arr)
	{
		m_nSize = arr.m_nSize;
		m_nCount = arr.m_nCount;
		m_pDataHead = new TYPE[m_nSize];
		memcpy(m_pDataHead, arr.m_pDataHead, m_nSize*sizeof(TYPE));
	}
	~CArray()
	{
		delete[]m_pDataHead;
	}
	int GetCount() const
	{
		return m_nCount;
	}
	TYPE* GetData()
	{
		return m_pDataHead;
	}
	const TYPE* GetData() const
	{
		return m_pDataHead;
	}
	int GetUpperBound() const
	{
		return m_nCount - 1;
	}
	bool IsEmpty() const
	{
		return m_nCount == 0;
	}
	void RemoveAll()
	{
		m_nCount = 0;
		m_nSize = 0;
	}
	TYPE& GetAt(int nIndex)
	{
		assert(nIndex >= 0 && nIndex + 1 <= m_nCount);
		return m_pDataHead[nIndex];
	}
	const TYPE& GetAt(int nIndex) const
	{
		assert(nIndex >= 0 && nIndex + 1 <= m_nCount);
		return m_pDataHead[nIndex];
	}
	TYPE& operator[](int nIndex)
	{
		assert(nIndex >= 0 && nIndex + 1 <= m_nCount);
			return m_pDataHead[nIndex];
	}
	CArray& operator=(const CArray& arr)
	{
		delete[]m_pDataHead;
		m_nSize = arr.m_nSize;
		m_nCount = arr.m_nCount;
		m_pDataHead = new TYPE[m_nSize];
		memcpy(m_pDataHead, arr.m_pDataHead, m_nSize * sizeof(TYPE));
		return *this;
	}
	int Add(ARG_TYPE newElement)
	{
		if (m_nCount + 1 >= m_nSize)
			ReAlloc(m_nSize*2);
		memcpy(&m_pDataHead[m_nCount], &newElement, sizeof(TYPE));
		return m_nCount++;
	}
	void SetAt(int nIndex, ARG_TYPE newElement);
	void InsertAt(int nIndex, ARG_TYPE newElement, int nCount = 1);
	//void InsertAt(int nStartIndex, CArray* pNewArray);
	void RemoveAt(int nIndex, int nCount = 1);
	void SetSize(int nNewSize);
	//int Append(const CArray& src);
	void Copy(const CArray& src);


};


template<class TYPE, class ARG_TYPE>
void CArray<TYPE, ARG_TYPE>::ReAlloc(int nSize)
{
	TYPE* pNew = new TYPE[nSize];
	memcpy(pNew, m_pDataHead, m_nSize * sizeof(TYPE));
	delete m_pDataHead;
	m_pDataHead = pNew;	
	m_nSize = nSize;
}
template<class TYPE, class ARG_TYPE>
void CArray<TYPE, ARG_TYPE>::SetAt(int nIndex, ARG_TYPE newElement)
{
	assert(nIndex >= 0 && nIndex + 1 <= m_nCount);
	if (m_nCount + 1 >= m_nSize)
		ReAlloc(m_nSize * 2);
	memcpy(&m_pDataHead[nIndex], &newElement, sizeof(TYPE));
}
template<class TYPE, class ARG_TYPE>
void CArray<TYPE, ARG_TYPE>::InsertAt(int nIndex, ARG_TYPE newElement, int nCount)
{
	assert(nCount > 0);
	assert(nIndex >= 0);
	if (m_nCount + nCount + 1 >= m_nSize)
		ReAlloc(m_nCount + nCount*2);
	if (nIndex < m_nCount)
	{
		memmove(m_pDataHead + nIndex + nCount, m_pDataHead + nIndex, sizeof(TYPE)*(m_nCount - nIndex));
		m_nCount += nCount;
	}
	else
	{
		SetSize(nIndex + nCount);
		/*int i = m_nCount;
		while (i < nIndex)
			m_pDataHead[i++] = 0;
		m_nCount = nIndex + nCount;*/
	}
	int j = -1;
	while(++j < nCount)
		m_pDataHead[nIndex + j] = newElement;
}

template<class TYPE, class ARG_TYPE>
void CArray<TYPE, ARG_TYPE>::RemoveAt(int nIndex, int nCount)
{
	assert(nCount >= 0);
	assert(nIndex >= 0 && nIndex + 1 <= m_nCount);
	if (m_nCount - nIndex - nCount > 0)
	{
		memcpy(m_pDataHead + nIndex, m_pDataHead + nIndex + nCount, sizeof(TYPE)*(m_nCount - nIndex - nCount));
		m_nCount -= nCount;
	}
	else
		m_nCount = nIndex;
	
}

template<class TYPE, class ARG_TYPE>
void CArray<TYPE, ARG_TYPE>::SetSize(int nNewSize)
{
	assert(nNewSize > 0);
	if (nNewSize > m_nCount)
	{
		int i = nNewSize * 2 > m_nSize * 2 ? nNewSize * 2 : m_nSize * 2;
		ReAlloc(i);
		i = m_nCount;
		while(i < nNewSize)
		{
			m_pDataHead[i] = 0;
			i++;
		}
	}
	m_nCount = nNewSize;
}
template<class TYPE, class ARG_TYPE>
void CArray<TYPE, ARG_TYPE>::Copy(const CArray& src)
{
	delete[]m_pDataHead;
	m_nSize = arr.m_nSize;
	m_nCount = arr.m_nCount;
	m_pDataHead = new TYPE[m_nSize];
	memcpy(m_pDataHead, arr.m_pDataHead, m_nSize * sizeof(TYPE));
}