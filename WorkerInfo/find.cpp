#include"main.h"
void FindByNumb()
{
	int nNumb;
	printf_s("��������Ҫ���ҵĹ��ţ�");
	scanf_s("%d", &nNumb);
	if (!nNumb)
		return;
	MYSQL_ROW row;
	MYSQL_RES *res;
	char sSQL[64];
	sprintf(sSQL, "SELECT * FROM t_winfo WHERE winfo_numb = '%d'", nNumb);
	mysql_query(g_pConn, sSQL);
	res = mysql_store_result(g_pConn); 
	if(row = mysql_fetch_row(res))
		printf("%s\t%s\t%s\t%s\n", row[0], row[1], row[2], row[3]);
	else
		printf_s("��Ҫ���ҵĹ��Ų����ڣ�\n");
	system("pause");
}
void FindByName()
{
	char sName[20];
	printf_s("��������Ҫ���ҵ�������");
	scanf_s("%s",sName, (unsigned)sizeof(sName));
	if (!sName)
		return;
	MYSQL_ROW row;
	MYSQL_RES *res;
	char sSQL[128];
	sprintf(sSQL, "SELECT * FROM t_winfo WHERE winfo_name LIKE '%%%s%%'", sName);
	mysql_query(g_pConn, sSQL);
	res = mysql_store_result(g_pConn);
	int sum = 0;
	while (row = mysql_fetch_row(res))
	{
		printf("%s\t%s\t%s\t%s\n", row[0], row[1], row[2], row[3]);
		++sum;
	}
	if(!sum) 
		printf_s("��Ҫ���ҵ����������ڣ�\n");
	else
		printf_s("һ��%d�������ݣ�\n", sum);
	system("pause");
	
}
void FindBySalary()
{
	float fMin, fMax;
	printf_s("��������Ҫ���ҵ�����ʺ���߹��ʣ�");
	scanf_s("%f%f", &fMin, &fMax);
	if (!fMin || !fMax)
		return;
	MYSQL_ROW row;
	MYSQL_RES *res;
	char sSQL[128];
	sprintf(sSQL, "SELECT * FROM t_winfo WHERE winfo_salary >= %0.2f AND winfo_salary <= %0.2f", fMin, fMax);
	mysql_query(g_pConn, sSQL);
	res = mysql_store_result(g_pConn);
	int sum = 0;
	while (row = mysql_fetch_row(res))
	{
		printf("%s\t%s\t%s\t%s\n", row[0], row[1], row[2], row[3]);
		++sum;
	}
	if (!sum)
		printf_s("û����Ҫ���ҵĹ��ʶΣ�\n");
	else
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