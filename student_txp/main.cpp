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
		puts("�����ļ�ʱʧ�ܣ�");
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
	puts("ѧ��\t����\t����");
	while (++i < nCount)
	{
		printf_s("%d\t%s\t%f\n", p->nNumb, p->sName, p->fSalary);
		++p;
	}
	printf_s("һ����%d����¼!\n", nCount);
	system("pause");

}
		
void Modify()
{
	int nNumb; 
	printf_s("��������Ҫ�޸ĵĹ��ţ�");
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
		printf_s("������Ĺ���%d�����ڣ�\n", nNumb);
		system("pause");
		return;
	}
	printf_s("ȷ���޸Ĺ���%d��y/n��:",nNumb);
	char c;
	scanf_s("\n%c", &c, sizeof(c));
	if (c == 'n' || c == 'N')
		return;
	if (c == 'y' || c == 'Y')
	{		
		printf_s("�������µ������͹��ʣ�");
		scanf_s("%s%f", p[i].sName, sizeof(p[i].sName), &p[i].fSalary);		
		Print();
		Save();
	}
	
}

void Delete()
{
	int nNumb;
	printf_s("��������Ҫɾ���Ĺ��ţ�");
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
		printf_s("������Ĺ���%d�����ڣ�\n", nNumb);
		system("pause");
		return;
	}
	printf_s("ȷ��ɾ������%d��y/n��:", nNumb);
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
	printf_s("�����빤�ţ�");
	while (1)
	{	
		scanf_s("%d", &nNumb);
		if (!nNumb)
			return;
		if (!CheckNumb(nNumb))
			break;
	    printf_s("����%d�Ѿ����ڣ����������룺",nNumb);
	}
	SWorker Data = {nNumb};
	printf_s("�����������͹��ʣ�");
	scanf_s("%s%f", Data.sName,sizeof(Data.sName), &Data.fSalary);
	Add(Data);
	Print();
	Save();
}

int Menu()
{
	system("cls");

	puts("********************************");
	puts("*       1�����������Ϣ        *");
	puts("*       2�������Ϣ            *");
	puts("*       3��ɾ����Ϣ            *");
	puts("*       4���޸���Ϣ            *");
	puts("*       5��������Ϣ            *");
	puts("*       0���˳�                *");
	puts("********************************");
	printf("��ѡ��");
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
	puts("*         Ա������ϵͳ         *");
	puts("*           2018.09            *");
	puts("*                              *");
	puts("*                              *");
	puts("********************************");
	system("pause");
	while (Menu())
	  ;

}