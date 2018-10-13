#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "User.h"
using namespace std;

CUser::CUser()
{
	Load();
	if (!m_list.GetCount())
	{
		m_list.AddTail({ "admin", "admin", 0 });
		Save();
	}
		
}

CUser::~CUser()
{
}

bool CUser::IsAdmin()
{
	return !m_currentUser.nPrior;
}
void CUser::ModifyPass()
{
	char sPass[20],sPassConfirm[20];
	cout << "请输入当前用户密码：";
	cin >> sPass;
	if (strcmp(m_currentUser.sPass, sPass))
	{
		cout << "密码输入错误！" << endl;
		system("pause");
		return;
	}
	cout << "请输入新密码：";
	cin >> sPass;
	cout << "请再次输入密码：";
	cin >> sPassConfirm;
	if (strcmp(sPassConfirm, sPass))
	{
		cout << "输入的密码不一致！" << endl;
		system("pause");
		return;
	}
	DList<UInfo>:: POSITION pos = FindUserName(m_currentUser.sName);
	UInfo &u = m_list.GetAt(pos);
	strcpy(u.sPass, sPass);
	strcpy(m_currentUser.sPass, sPass);
	Save();
	cout << "密码修改成功！\n";
	cout << u.sName << '\t';
	cout << u.sPass << '\t';
	cout << (u.nPrior ? "普通用户" : "管理员") << endl;
	system("pause");
}
const CUser::UInfo & CUser::GetCurrentUser() const
{
	return m_currentUser;
}
bool CUser::Login()
{
	char sName[20];
	char sPass[20];
	cout << "请输入用户名：";
	cin >> sName;
	cout << "请输入用户密码：";
	cin >> sPass;
	DList<UInfo>::POSITION pos;
	if (!(pos = FindUserName(sName)))
	{
		cout << "用户名不存在！";
		system("pause");
		return false;
	}
	if (!CheckUserPass(sPass))
	{
		cout << "你输入的密码有误！" << endl;
		system("pause");
		return false;
	}
	m_currentUser = m_list.GetAt(pos);
	return true;
}
DList<CUser::UInfo>::POSITION CUser::FindUserName(const char* sName) const
{
	DList<UInfo>::POSITION pos = m_list.GetHeadPosition();
	while (pos)
	{
		const UInfo& data = m_list.GetAt(pos);
		if (!_stricmp(sName, data.sName))
			break;
		m_list.GetNext(pos);
	}
	return pos;
}
bool CUser::CheckUserPass(const char* sPass) const
{
	DList<UInfo>::POSITION pos = m_list.GetHeadPosition();
	while (pos)
	{
		const UInfo& data = m_list.GetAt(pos);
		if (!strcmp(sPass, data.sPass))
			break;
		m_list.GetNext(pos);
	}
	if (!pos)
		return false;
	return true;
}
void CUser::Load()
{
	FILE *fp = fopen("./user.txp", "rb");
	if (!fp)
	{
		cout << "用户数据读取失败！" << endl;
		return;
	}
	UInfo uData;
	while (fread(&uData, 1, sizeof(UInfo), fp) == sizeof(UInfo))
	{
		m_list.AddTail(uData);
	}
	fclose(fp);
}

void CUser::Save()
{
	FILE *fp = fopen("./user.txp", "wb");
	if (!fp)
	{
		cout << "保存文件时失败！" << endl;
		return;
	}
	DList<UInfo>::POSITION pos = m_list.GetHeadPosition();
	while (pos)
	{
		const UInfo &data = m_list.GetAt(pos);
		fwrite(&data, 1, sizeof(UInfo), fp);
		m_list.GetNext(pos);
	}
	fclose(fp);
}

int CUser::Menu()
{
	system("cls");
	cout << "**************************" << endl;
	cout << "*                        *" << endl;
	cout << "*      1、浏览账户       *" << endl;
	cout << "*      2、添加账户       *" << endl;
	cout << "*      3、删除账户       *" << endl;
	cout << "*      4、修改密码       *" << endl;
	cout << "*      0、退出           *" << endl;
	cout << "*                        *" << endl;
	cout << "*************************" << endl;
	cout << "请选择：";
	int i = 0;
	cin >> i;
	switch (i)
	{
	case 1:
		PrintUser();
		break;
	case 2:
		AddUser();
		break;
	case 3:
		DeleteUser();
		break;
	case 4:
		ModifyPass();
		break;
	}
	return i;
}

void CUser::UserControl()
{
	while (Menu())
		;
}

void CUser::PrintUser() const
{
	DList<UInfo>::POSITION pos = m_list.GetHeadPosition();
	puts("用户名\t密码\t权限\n");
	while (pos)
	{
		const UInfo& data = m_list.GetAt(pos);
		cout << data.sName << '\t';
		cout << data.sPass << '\t';
		cout <<(data.nPrior?"普通用户":"管理员" )<< endl;
		m_list.GetNext(pos);
	}
	cout << "一共有" << m_list.GetCount()<< "条数据!" << endl;
	system("pause");
}

bool CUser::AddUser()
{
	char sName[20];
	char sPass[20], sPassConfirm[20];
	int nPrior = 1;
	cout << "请输入用户名：";
	cin >> sName;
	cout << "请输入用户密码：";
	cin >> sPass;
	cout << "请再次输入密码：";
	cin >> sPassConfirm;
	while (strcmp(sPassConfirm, sPass))
	{
		cout << "输入的密码不一致！请再次输入(返回:0)：" << endl;
		cin >> sPassConfirm;
		if (!strcmp(sPassConfirm, "0"))
			return false;
	}
	cout << "请输入权限(管理员0|普通用户1)：";
	cin >> nPrior;
	if (FindUserName(sName))
	{
		cout << "用户名已存在！";
		system("pause");
		return false;
	}
	UInfo data;
	data.nPrior = nPrior;
	strcpy(data.sName, sName);
	strcpy(data.sPass, sPass);
	m_list.AddTail(data);
	PrintUser();
	Save();
	return true;
}

bool CUser::DeleteUser()
{
	char sName[20];
	cout << "请输入用户名：";
	cin >> sName;
	DList<UInfo>::POSITION pos = FindUserName(sName);
	if (!pos)
	{
		cout << "用户名不存在！";
		system("pause");
		return false;
	}
	const UInfo& data = m_list.GetAt(pos);
	cout << data.sName << '\t';
	cout << data.sPass << '\t';
	cout << (data.nPrior ? "普通用户" : "管理员") << endl;
	char c;
	cout << "确定删除(y|n):";
	cin >> c;
	if (c != 'y' && c != 'Y')
		return false;
	m_list.RemoveAt(pos);
	PrintUser();
	Save();
	return true;
}
