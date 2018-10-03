#pragma once
#include"List.h"
class Find
{
	List& cList;

public:	
	Find();
	void FindByNumb();
	void FindByName();
	void FindBySalary();
	int FindMenu();
	~Find();
};

