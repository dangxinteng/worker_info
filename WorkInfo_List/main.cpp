#include"main.h"

void Save()
{
	FILE *fp = fopen("./student.txp", "wb");
	if (!fp)
	{
		puts("保存文件时失败！");
		return;
	}
	Node* p = GetHead();
	while (p)
	{
		fwrite(&p->data, 1, sizeof(DATA), fp);
		p = p->pNext;
	}	
	fclose(fp);
}


void Load()
{
	FILE *fp = fopen("./student.txp", "rb");
	if (!fp)
	  return;
	DATA data;
	fseek(fp, 0, SEEK_END);
	int nCount = ftell(fp)/sizeof(DATA);	
	rewind(fp);
	Node* p = GetHead();
	int i = -1;
	while (++i < nCount)
	{		
		fread(&data, 1, sizeof(DATA), fp);
		if (!p)
		{
			p = AddHead(data);
			continue;
		}
		Node* pNew = (Node*)malloc(sizeof(Node));
		pNew->data = data;
		pNew->pNext = p->pNext;
		p->pNext = pNew;
		p = pNew;
}	
	fclose(fp);	
	
}

int CheckNumb(int nNumb)
{
	if(Find(nNumb))
		return 1;
	return 0;
}

void Print()
{
	Node* p = GetHead();
	int sum = 0;
	puts("学号\t姓名\t工资");
	while (p)
	{
		printf_s("%d\t%s\t%0.2f\n", p->data.nNumb, p->data.sName, p->data.fSalary);
		p = p->pNext;
		++sum;
	}
	printf_s("一共有%d条记录!\n", sum);
	system("pause");

}
		
void Modify()
{
	int nNumb; 
	printf_s("请输入您要修改的工号：");
	scanf_s("%d", &nNumb);
	if (!nNumb)
	  return;
	if(!CheckNumb(nNumb))
	{
		printf_s("您输入的工号%d不存在！\n", nNumb);
		system("pause");
		return;
	}
	printf_s("确定修改工号%d【y/n】:",nNumb);
	char c;
	scanf_s("\n%c", &c, sizeof(c));
	if (c == 'y' || c == 'Y')
	{				
		DATA Data = { nNumb };
		printf_s("请输入新的姓名和工资：");
		scanf_s("%s%f", Data.sName, sizeof(Data.sName), &Data.fSalary);
		Modify(nNumb, Data);
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
	if (!CheckNumb(nNumb))
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
		Delete(nNumb);
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
	DATA Data = {nNumb};
	printf_s("请输入姓名和工资：");
	scanf_s("%s%f", Data.sName,sizeof(Data.sName), &Data.fSalary);
	AddTail(Data);
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
	RemoveAll();
}