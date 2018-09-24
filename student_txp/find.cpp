#include"main.h"
void FindByNumb()
{
	int nNumb;
	printf_s("��������Ҫ���ҵĹ��ţ�");
	scanf_s("%d", &nNumb);
	if (!nNumb)
		return;
	int nCount = GetCount();
	SWorker* p = GetData();
	int i = -1;
	while (++i < nCount)
	{
		if (p->nNumb == nNumb)
			break;
		++p;
	}
	if (i >= nCount)
	{
		printf_s("��Ҫ���ҵĹ��Ų����ڣ�\n");
		system("pause");
		return;
	}		
	printf_s("%d\t%s\t%f\n", p->nNumb, p->sName, p->fSalary);
	system("pause");

}
void FindByName()
{
	char sName[20];
	printf_s("��������Ҫ���ҵ�������");
	scanf_s("%s",sName, sizeof(sName));
	int nCount = GetCount();
	SWorker* p = GetData();
	int i = -1, j = 0;
	while (++i < nCount)
	{
		if (strstr(p->sName, sName))
		{
			printf_s("%d\t%s\t%f\n", p->nNumb, p->sName, p->fSalary);
			++j;
		}

		++p;
	}	
	printf_s("һ��%d�������ݣ�\n", j);
	system("pause");
	
}
void FindBySalary()
{
	float fMin, fMax;
	printf_s("��������Ҫ���ҵ�����ʺ���߹��ʣ�");
	scanf_s("%f%f", &fMin, &fMax);
	int nCount = GetCount();
	SWorker* p = GetData();
	int i = -1, j = 0;
	while (++i < nCount)
	{
		if (p->fSalary >= fMin && p->fSalary <= fMax)
		{
			printf_s("%d\t%s\t%f\n", p->nNumb, p->sName, p->fSalary);
			++j;
		}

		++p;
	}
	printf_s("һ��%d�������ݣ�\n", j);
	system("pause");
}

int FindMenu()
{
	system("cls");
	puts("********************************");
	puts("*                              *");
	puts("*       1�������Ų���          *");
	puts("*       2������������          *");
	puts("*       3�������ʶβ���        *");
	puts("*       0���˳�                *");
	puts("*                              *");
	puts("********************************");
	printf("��ѡ��");
	int i = 0;
	scanf_s("%d", &i);
	switch (i)
	{
	case 1:
		FindByNumb();
		break;
	case 2:
		FindByName();
		break;
	case 3:
		FindBySalary();
		break;
	}
	return i;
}