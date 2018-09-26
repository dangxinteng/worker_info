#include"main.h"

Node* g_pHead  = NULL;
Node* GetHead()
{
	return g_pHead;
}
Node* AddHead(DATA data)
{
	Node* pNew = (Node*)malloc(sizeof(Node));
	pNew->data = data;
	pNew->pNext = g_pHead;
	g_pHead = pNew;
	return pNew;
}
Node* AddTail(DATA data)
{
	Node* p = g_pHead;
	if (!p)
		return AddHead(data);
	while (p->pNext)
		p = p->pNext;
	Node* pNew = (Node*)malloc(sizeof(Node));
	pNew->data = data;
	pNew->pNext = p->pNext;
	p->pNext = pNew;
	return pNew;
}
Node* Find(int nNumb)
{
	Node* p = g_pHead;
	while (p)
	{
		if (p->data.nNumb == nNumb)
			return p;
		p = p->pNext;
	}
	return NULL;
}
Node* Modify(int nNumb, const DATA data)
{
	Node* p = NULL;
	p = Find(nNumb);
	if(!p)
		return NULL;
	p->data = data;
	return p;
}
int Delete(int nNumb)
{
	Node* p = g_pHead;	
	Node* pMark = NULL;
	
	while (p)
	{				
		if (p->data.nNumb == nNumb)
			break;
		pMark = p;
		p = p->pNext;		
	}		
	if(!pMark)
	{ 
		g_pHead = p->pNext;
		free(p);
		return true;
	}
	if (!p)
		return false;
	pMark->pNext = p->pNext;
	free(p);
	return true;
}
void RemoveAll()
{
	Node* p = g_pHead;
	while (p)
	{
		Node* pMark = p;
		p = p->pNext;
		free(pMark);
	}
	g_pHead = NULL;
}