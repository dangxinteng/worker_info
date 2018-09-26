#include"main.h" 
int Comp(Node* n, Node* m, int i)
{
	if (i == 1)
		return n->data.nNumb < m->data.nNumb;
	if (i == 2)
		return strcmp(n->data.sName, m->data.sName) < 0;
	if (i == 3)
		return n->data.fSalary < m->data.fSalary;
	return 0;
}
void Sort(int i)
{
	Node* p = GetHead();	
	while (p)
	{
		Node *m = p, *n = p;
		while (n = n->pNext)
		{
			if (Comp(n, m, i))
			{
				m = n;
			}			
		}
		if (m != p)
		{
			DATA t = m->data;
			m->data = p->data;
			p->data = t;
		}
		p = p->pNext;
	}	
}
void SortByName()
{
	//int nCount = GetCount();
	//SWorker* p = GetData();
	//int i = -1;
	//--nCount;
	//while (++i < nCount)
	//{
	//	int j = -1;
	//	while (++j < nCount-i)
	//	{
	//		if (strcmp(p[j].sName, p[j + 1].sName) > 0)
	//		{
	//			SWorker t = p[j];
	//			p[j] = p[j+1];
	//			p[j+1] = t;
	//		}
	//	}		
	//}
	//Print();
}
void SortBySalary()
{
	//int nCount = GetCount();
	//SWorker* p = GetData();
	//int i = -1;
	//while (++i < nCount)
	//{
	//	int j = i, m = i;
	//	while (++j < nCount)
	//	{
	//		if (p[j].fSalary < p[m].fSalary)
	//			m = j;
	//	}
	//	if (m != i)
	//	{
	//		SWorker t = p[m];
	//		p[m] = p[i];
	//		p[i] = t;
	//	}
	//}
	//Print();
}
int PrintMenu()
{
	system("cls");
	puts("********************************");
	puts("*                              *");
	puts("*      1¡¢°´¹¤ºÅÅÅÐòä¯ÀÀ       *");
	puts("*      2¡¢°´ÐÕÃûÅÅÐòä¯ÀÀ       *");
	puts("*      3¡¢°´¹¤×ÊÅÅÐòä¯ÀÀ       *");
	puts("*      0¡¢ÍË³ö                 *");
	puts("*                              *");
	puts("********************************");
	printf("ÇëÑ¡Ôñ£º");
	int i = 0;
	scanf_s("%d", &i);
	switch (i)
	{
	case 1:		
	case 2:		
	case 3:
		Sort(i);
		Print();
	
	}
	return i;
}