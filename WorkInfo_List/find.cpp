#include"main.h"
void FindByNumb()
{
	int nNumb;
	printf_s("��������Ҫ���ҵĹ��ţ�");
	scanf_s("%d", &nNumb);
	if (!nNumb)
		return;
	Node* p = Find(nNumb);
	if (!p)
	{
		printf_s("��Ҫ���ҵĹ��Ų����ڣ�\n");
		system("pause");
		return;
	}		
	printf_s("%d\t%s\t%f\n", p->data.nNumb, p->data.sName, p->data.fSalary);
	system("pause");

}
void FindByName()
{
	char sName[20];
	printf_s("��������Ҫ���ҵ�������");
	scanf_s("%s",sName, sizeof(sName));	
	Node* p = GetHead();
	int sum = 0;
	while (p)
	{
		if (strstr(p->data.sName, sName))
		{
			printf_s("%d\t%s\t%f\n", p->data.nNumb, p->data.sName, p->data.fSalary);
			++sum;
		}
			
		p = p->pNext;
	}
	printf_s("һ��%d�������ݣ�\n", sum);
	system("pause");
	
}
void FindBySalary()
{
	float fMin, fMax;
	printf_s("��������Ҫ���ҵ�����ʺ���߹��ʣ�");
	scanf_s("%f%f", &fMin, &fMax);
	Node* p = GetHead();
	int sum = 0;
	while (p)
	{
		if (p->data.fSalary >= fMin &&  p->data.fSalary  <= fMax)
		{
			printf_s("%d\t%s\t%f\n", p->data.nNumb, p->data.sName, p->data.fSalary);
			++sum;
		}
		p = p->pNext;
	}	
	printf_s("һ��%d�������ݣ�\n", sum);
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