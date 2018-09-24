#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <process.h>
#include<malloc.h>
#include<memory.h>
#include<string.h>

typedef struct SWorker
{
	int nNumb;
	char sName[20];
	float fSalary;
}SWorker;
void init(int nCount);
SWorker*  GetData();
int GetCount();
void SetCount(int nCount);
void SetSize(int nSize);
void Add(SWorker Data);
void DeleteAt(int i);
void Print();
int PrintMenu();
int FindMenu();
