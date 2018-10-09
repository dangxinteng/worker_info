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
	cout << "�����뵱ǰ�û����룺";
	cin >> sPass;
	if (strcmp(m_currentUser.sPass, sPass))
	{
		cout << "�����������" << endl;
		system("pause");
		return;
	}
	cout << "�����������룺";
	cin >> sPass;
	cout << "���ٴ��������룺";
	cin >> sPassConfirm;
	if (strcmp(sPassConfirm, sPass))
	{
		cout << "��������벻һ�£�" << endl;
		system("pause");
		return;
	}
	DList<UInfo>:: POSITION pos = FindUserName(m_currentUser.sName);
	UInfo &u = m_list.GetAt(pos);
	strcpy(u.sPass, sPass);
	strcpy(m_currentUser.sPass, sPass);
	Save();
	cout << "�����޸ĳɹ���\n";
	cout << u.sName << '\t';
	cout << u.sPass << '\t';
	cout << (u.nPrior ? "��ͨ�û�" : "����Ա") << endl;
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
	cout << "�������û�����";
	cin >> sName;
	cout << "�������û����룺";
	cin >> sPass;
	DList<UInfo>::POSITION pos;
	if (!(pos = FindUserName(sName)))
	{
		cout << "�û��������ڣ�";
		system("pause");
		return false;
	}
	if (!CheckUserPass(sPass))
	{
		cout << "���������������" << endl;
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
		cout << "�û����ݶ�ȡʧ�ܣ�" << endl;
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
		cout << "�����ļ�ʱʧ�ܣ�" << endl;
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
	cout << "*      1������˻�       *" << endl;
	cout << "*      2������˻�       *" << endl;
	cout << "*      3��ɾ���˻�       *" << endl;
	cout << "*      4���޸�����       *" << endl;
	cout << "*      0���˳�           *" << endl;
	cout << "*                        *" << endl;
	cout << "*************************" << endl;
	cout << "��ѡ��";
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
	puts("�û���\t����\tȨ��\n");
	while (pos)
	{
		const UInfo& data = m_list.GetAt(pos);
		cout << data.sName << '\t';
		cout << data.sPass << '\t';
		cout <<(data.nPrior?"��ͨ�û�":"����Ա" )<< endl;
		m_list.GetNext(pos);
	}
	cout << "һ����" << m_list.GetCount()<< "������!" << endl;
	system("pause");
}

bool CUser::AddUser()
{
	char sName[20];
	char sPass[20], sPassConfirm[20];
	int nPrior = 1;
	cout << "�������û�����";
	cin >> sName;
	cout << "�������û����룺";
	cin >> sPass;
	cout << "���ٴ��������룺";
	cin >> sPassConfirm;
	while (strcmp(sPassConfirm, sPass))
	{
		cout << "��������벻һ�£����ٴ�����(����:0)��" << endl;
		cin >> sPassConfirm;
		if (!strcmp(sPassConfirm, "0"))
			return false;
	}
	cout << "������Ȩ��(����Ա0|��ͨ�û�1)��";
	cin >> nPrior;
	if (FindUserName(sName))
	{
		cout << "�û����Ѵ��ڣ�";
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
	cout << "�������û�����";
	cin >> sName;
	DList<UInfo>::POSITION pos = FindUserName(sName);
	if (!pos)
	{
		cout << "�û��������ڣ�";
		system("pause");
		return false;
	}
	const UInfo& data = m_list.GetAt(pos);
	cout << data.sName << '\t';
	cout << data.sPass << '\t';
	cout << (data.nPrior ? "��ͨ�û�" : "����Ա") << endl;
	char c;
	cout << "ȷ��ɾ��(y|n):";
	cin >> c;
	if (c != 'y' && c != 'Y')
		return false;
	m_list.RemoveAt(pos);
	PrintUser();
	Save();
	return true;
}
