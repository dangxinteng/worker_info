#include"main.h"
MYSQL* g_pConn;
int SqlConn()
{
	g_pConn = mysql_init(NULL);
	if (!g_pConn)
	{
		printf("Error %u: %s\n", mysql_errno(g_pConn), mysql_error(g_pConn));
		return 0;
	}
	if (mysql_real_connect(g_pConn, "localhost", "root", "123456", "d_worker", 0, NULL, 0) == NULL)
	{
		printf("Error %u: %s\n", mysql_errno(g_pConn), mysql_error(g_pConn));
		return 0;
	}
	mysql_query(g_pConn, "set names gbk");
	//puts("数据库连接成功！");
	return 1;
}

void Print(const char *sSQL)
{
	printf("工号\t姓名\t工资\t入职日期\n");
	MYSQL_ROW row;
	MYSQL_RES *res;
	if (sSQL == NULL)
		sSQL = "SELECT * FROM t_winfo";
	mysql_query(g_pConn, sSQL);
	unsigned int i = 0;
	res = mysql_store_result(g_pConn); //res->row_count
	while (row = mysql_fetch_row(res))
	{
		/*for (i = 0; i<mysql_num_fields(res); i++)
		{
		printf("%s\t", row[i]);
		}*/
		printf("%s\t%s\t%s\t%s\n", row[0], row[1], row[2], row[3]);
		++i;
	}
	printf("总共有 %d 条数据\n", i);
	system("pause");

}

int PrintMenu()
{
	system("cls");
	puts("********************************");
	puts("*                              *");
	puts("*      1、按工号排序浏览       *");
	puts("*      2、按姓名排序浏览       *");
	puts("*      3、按工资排序浏览         *");
	puts("*      0、退出                 *");
	puts("*                              *");
	puts("********************************");
	printf("请选择：");
	int i = 0;
	scanf_s("%d", &i);
	switch (i)
	{
	case 1:
		Print("SELECT * FROM t_winfo ORDER BY winfo_numb");
		break;
	case 2:
		Print("SELECT * FROM t_winfo ORDER BY winfo_name");
		break;
	case 3:
		Print("SELECT * FROM t_winfo ORDER BY winfo_salary");
		break;
	}
	return i;
}

int CheckNumb(int nNumb)
{
	MYSQL_RES *res;
	char sSQL[64];
	sprintf(sSQL,"SELECT * FROM t_winfo WHERE winfo_numb = '%d'" , nNumb);
	mysql_query(g_pConn, sSQL);
	res = mysql_store_result(g_pConn); //res->row_count
	if (res->row_count > 0)
		return 1;
	return 0;
}

void Modify()
{	
	int nNumb; 
	printf_s("请输入您要修改的工号：");
	scanf_s("%d", &nNumb);
	if (!nNumb)
	  return;	
	if (!CheckNumb(nNumb))
	{
		printf_s("您输入的工号%d不存在！\n", nNumb);
		system("pause");
		return;
	}
	printf_s("确定修改工号%d【y/n】:",nNumb);
	char c;
	scanf_s("\n%c", &c, (unsigned)sizeof(c));
	if (c == 'y' || c == 'Y')
	{		
		char sName[20], sDate[20];
		float fSalary;
		printf_s("请输入新的姓名、工资、入职日期：");
		scanf_s("%s%f%s", sName, (unsigned)sizeof(sName), &fSalary, sDate, (unsigned)sizeof(sDate));
		char sSQL[256];
		sprintf(sSQL, "UPDATE t_winfo SET winfo_name = '%s',winfo_salary = '%0.2f',winfo_date = '%s' WHERE winfo_numb = '%d'", sName, fSalary, sDate, nNumb);
		mysql_query(g_pConn, sSQL);
		Print(NULL);
		
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
	scanf_s("\n%c", &c, (unsigned)sizeof(c));	
	if (c == 'y' || c == 'Y')
	{
		char sSQL[64];
		sprintf(sSQL, "DELETE FROM t_winfo WHERE winfo_numb = '%d'", nNumb);
		mysql_query(g_pConn, sSQL);
		Print(NULL);
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
	char sName[20],sDate[20];
	float fSalary;
	printf_s("请输入姓名、工资、入职日期：");
	scanf_s("%s%f%s", sName, (unsigned)sizeof(sName), &fSalary, sDate, (unsigned)sizeof(sDate)); 
	char sSQL[128];
	sprintf(sSQL, "INSERT INTO t_winfo VALUES ('%d', '%s', '%0.2f', '%s')", nNumb,sName,fSalary,sDate);
	mysql_query(g_pConn, sSQL);	
	Print(NULL);	
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
		//Print(NULL);
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
	if (!SqlConn())
		return;
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
	mysql_close(g_pConn);
}