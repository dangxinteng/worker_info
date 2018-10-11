#pragma once
#include"DList.h"
class CUser
{
	struct UInfo
	{
		char sName[20];
		char sPass[20];
		int nPrior;
	};
	DList<UInfo> m_list;
	UInfo m_currentUser;
	void Load();
	void Save();
	int Menu();
	void PrintUser() const;
	bool AddUser();
	bool DeleteUser();
public:
	CUser();
	~CUser();
	bool IsAdmin();
	bool Login();
	void ModifyPass();
	const UInfo& GetCurrentUser()const;
	DList<UInfo>::POSITION FindUserName(const char* sName)const;
	bool CheckUserPass(const char* sPass)const;
	void UserControl();
	

};

