#include"main.h"

void Load()
{
	FILE *fp = fopen("./student.txp", "r");
	if (!fp)
	  return;
	SWorker* p = GetData();	
	fseek(fp, 0, SEEK_END);
	int nCount = ftell(fp)/sizeof(SWorker);	
	rewind(fp);
	fread(p, 1, sizeof(SWorker)*nCount, fp);
	SetCount(nCount);
	fclose(fp);
}
void Save()
{
	FILE *fp = fopen("./student.txp", "w");
	if (!fp)
	{
		puts("保存文件时失败！");
		return;
	}
	SWorker* p = GetData();
	int nCount = GetCount();	
	fwrite(p, sizeof(SWorker), nCount, fp);
	fclose(fp);
}

int CheckNumb(int nNumb)
{
	SWorker* p = GetData();
	int nCount = GetCount(), i = -1;
	while (++i < nCount)
	{
		if (p->nNumb == nNumb)
			return 1;
		++p;
	}
	return 0;
}

void Print()
{
	int i = -1;
	SWorker* p = GetData();
	int nCount = GetCount();
	puts("学号\t姓名\t工资");
	while (++i < nCount)
	{
		printf_s("%d\t%s\t%f\n", p->nNumb, p->sName, p->fSalary);
		++p;
	}
	printf_s("一共有%d条记录!\n", nCount);
	system("pause");

}
		
void Modify()
{
	int nNumb; 
	printf_s("请输入您要修改的工号：");
	scanf_s("%d", &nNumb);
	if (!nNumb)
	  return;
	SWorker* p = GetData();
	int nCount = GetCount();
	int i = -1;
	while (++i < nCount)
	{
		if (p->nNumb == nNumb)
			break;
		++p;
	}	
	if (i == nCount)
	{
		printf_s("您输入的工号%d不存在！\n", nNumb);
		system("pause");
		return;
	}
	printf_s("确定修改工号%d【y/n】:",nNumb);
	char c;
	scanf_s("\n%c", &c, sizeof(c));
	if (c == 'n' || c == 'N')
		return;
	if (c == 'y' || c == 'Y')
	{		
		printf_s("请输入新的姓名和工资：");
		scanf_s("%s%f", p[i].sName, sizeof(p[i].sName), &p[i].fSalary);		
		Print();
		Save();
	}
	
}

void Delete()
{
	int nNumb;
	printf_s("请输入您要删除的工号：");
	scanf_s("%d", &nNumb);
	if (!nNumb)
		return;
	SWorker* p = GetData();
	int nCount = GetCount();
	int i = -1;
	while (++i < nCount)
	{
		if (p->nNumb == nNumb)
			break;
		++p;
	}
	if (i == nCount)
	{
		printf_s("您输入的工号%d不存在！\n", nNumb);
		system("pause");
		return;
	}
	printf_s("确定删除工号%d【y/n】:", nNumb);
	char c;
	scanf_s("\n%c", &c, sizeof(c));	
	if (c == 'y' || c == 'Y')
	{
		DeleteAt(i);
		Print();
		Save();
	}
}

void Input()
{
	int nNumb;
	printf_s("请输入工号：");
	while (1)
	{	
		scanf_s("%d", &nNumb);
		if (!nNumb)
			return;
		if (!CheckNumb(nNumb))
			break;
	    printf_s("工号%d已经存在，请重新输入：",nNumb);
	}
	SWorker Data = {nNumb};
	printf_s("请输入姓名和工资：");
	scanf_s("%s%f", Data.sName,sizeof(Data.sName), &Data.fSalary);
	Add(Data);
	Print();
	Save();
}

int Menu()
{
	system("cls");

	puts("********************************");
	puts("*       1、浏览所有信息        *");
	puts("*       2、添加信息            *");
	puts("*       3、删除信息            *");
	puts("*       4、修改信息            *");
	puts("*       5、查找信息            *");
	puts("*       0、退出                *");
	puts("********************************");
	printf("请选择：");
	int i = 0;
	scanf_s("%d", &i);
	switch (i)
	{
	case 1:
		//Print();
		while (PrintMenu())
			;
		break;
	case 2:
		Input();
		break;
	case 3:
		Delete();
		break;
	case 4:
		Modify();
		break;
	case 5:
		while (FindMenu())
			;
		break;
		
	}
	return i;
}

void main()
{
	init(4);
	Load();
	puts("********************************");
	puts("*                              *");
	puts("*                              *");
	puts("*         员工管理系统         *");
	puts("*           2018.09            *");
	puts("*                              *");
	puts("*                              *");
	puts("********************************");
	system("pause");
	while (Menu())
	  ;

}