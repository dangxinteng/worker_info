#include"main.h"
void FindByNumb()
{
	int nNumb;
	printf_s("请输入您要查找的工号：");
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
		printf_s("你要查找的工号不存在！\n");
		system("pause");
		return;
	}		
	printf_s("%d\t%s\t%f\n", p->nNumb, p->sName, p->fSalary);
	system("pause");

}
void FindByName()
{
	char sName[20];
	printf_s("请输入您要查找的姓名：");
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
	printf_s("一共%d有条数据！\n", j);
	system("pause");
	
}
void FindBySalary()
{
	float fMin, fMax;
	printf_s("请输入您要查找的最低资和最高工资：");
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
	printf_s("一共%d有条数据！\n", j);
	system("pause");
}

int FindMenu()
{
	system("cls");
	puts("********************************");
	puts("*                              *");
	puts("*       1、按工号查找          *");
	puts("*       2、按姓名查找          *");
	puts("*       3、按工资段查找        *");
	puts("*       0、退出                *");
	puts("*                              *");
	puts("********************************");
	printf("请选择：");
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