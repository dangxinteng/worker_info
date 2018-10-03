#pragma once
#include"Find.h"
#include"List.h"
#include"Sort.h"
class Sworker
{	
	Sort cSort;
	Find cFind;

public:
	static List cList;
	Sworker();
	void Load();
	void Save();
	int CheckNumb(int nNumb);
	void Print();
	void Modify();
	void Delete();
	void Input();
	int Menu();
	~Sworker();
};

