#include"main.h" 
typedef int(*BYFUN)(Node*, Node*);
int ByNumb(Node* n, Node* m)
{
	return n->data.nNumb < m->data.nNumb;
}
int ByName(Node* n, Node* m)
{
	return strcmp(n->data.sName, m->data.sName) < 0;
}
int BySalary(Node* n, Node* m)
{
	return n->data.fSalary < m->data.fSalary;
}
void Sort(BYFUN fun)
{
	Node* p = GetHead();	
	while (p)
	{
		Node *m = p, *n = p;
		while (n = n->pNext)
		{
			if (fun(n, m))
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
	BYFUN ByFun[] = { ByNumb,ByName,BySalary };
	if (i > 0 && i < 4)
	{
		Sort(ByFun[i - 1]);
		Print();
	}	
	return i;
}