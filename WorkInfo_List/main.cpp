#include"main.h"

void Save()
{
	FILE *fp = fopen("./student.txp", "wb");
	if (!fp)
	{
		puts("�����ļ�ʱʧ�ܣ�");
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
	puts("ѧ��\t����\t����");
	while (p)
	{
		printf_s("%d\t%s\t%0.2f\n", p->data.nNumb, p->data.sName, p->data.fSalary);
		p = p->pNext;
		++sum;
	}
	printf_s("һ����%d����¼!\n", sum);
	system("pause");

}
		
void Modify()
{
	int nNumb; 
	printf_s("��������Ҫ�޸ĵĹ��ţ�");
	scanf_s("%d", &nNumb);
	if (!nNumb)
	  return;
	if(!CheckNumb(nNumb))
	{
		printf_s("������Ĺ���%d�����ڣ�\n", nNumb);
		system("pause");
		return;
	}
	printf_s("ȷ���޸Ĺ���%d��y/n��:",nNumb);
	char c;
	scanf_s("\n%c", &c, sizeof(c));
	if (c == 'y' || c == 'Y')
	{				
		DATA Data = { nNumb };
		printf_s("�������µ������͹��ʣ�");
		scanf_s("%s%f", Data.sName, sizeof(Data.sName), &Data.fSalary);
		Modify(nNumb, Data);
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
	if (!CheckNumb(nNumb))
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
		Delete(nNumb);
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
	DATA Data = {nNumb};
	printf_s("�����������͹��ʣ�");
	scanf_s("%s%f", Data.sName,sizeof(Data.sName), &Data.fSalary);
	AddTail(Data);
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
	RemoveAll();
}