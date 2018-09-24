#include"main.h"
SWorker* g_pData;
int g_nCount = 0;
int g_nSize = 0;
int GetCount()
{
	return g_nCount;
}
SWorker*  GetData()
{
	return g_pData;
}
void init(int nCount)
{
	g_pData = (SWorker*)malloc(sizeof(SWorker)*nCount);
	g_nSize = nCount;
}
void SetSize(int nSize)
{
	if (nSize <= g_nSize)
		return;
	SWorker* pData = (SWorker*)malloc(sizeof(SWorker)*nSize);
	memcpy(pData, g_pData, sizeof(SWorker)*g_nCount);
	free(g_pData);
	g_pData = pData;
	g_nSize = nSize;
}
void SetCount(int nCount)
{
	if (nCount > g_nSize)
		return;
	g_nCount = nCount;
}
void Add(SWorker Data)
{
	if (g_nCount >= g_nSize)
		SetSize(g_nSize * 2);
	g_pData[g_nCount++] = Data;
}
void DeleteAt(int i)
{
	
	if (i < 0 || i > g_nCount - 1)
		return;
	if(i != --g_nCount)
		memcpy(g_pData + i, g_pData + i + 1, sizeof(SWorker)*(g_nCount - i ));
	
}