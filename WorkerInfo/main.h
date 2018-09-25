#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <process.h>
#include<mysql.h>
#pragma comment (lib,"libmysql.lib")
typedef struct SWinfo
{
	int nNumb;
	char sName[20];
	float fSalary;
}SWinfo;
extern MYSQL* g_pConn;
int FindMenu();
