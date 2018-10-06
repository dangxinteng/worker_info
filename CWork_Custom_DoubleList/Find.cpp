#include "Find.h"

CFind::CFind(DList &list):m_list(list)
{
}

CFind::~CFind()
{
}
POSITION CFind::FindPos(int nNumb)
{
	POSITION pos = m_list.GetHeadPosition();
	while (pos)
	{
		DATA &data = m_list.GetAt(pos);
		if (data.nNumb == nNumb)
			return pos;
		m_list.GetNext(pos);
	}
	return NULL;
}
void CFind::FindByNumb()
{
	int nNumb;
	cout << "��������Ҫ���ҵĹ��ţ�";
	cin >> nNumb;
	if (!nNumb)
		return;
	POSITION pos = FindPos(nNumb);
	if (!pos)
	{
		cout << "��Ҫ���ҵĹ��Ų����ڣ�" << endl;
		system("pause");
		return;
	}
	DATA &data = m_list.GetAt(pos);
	cout << data.nNumb << '\t';
	cout << data.sName << '\t';
	cout << data.fSalary << endl;
	system("pause");
}

void CFind::FindByName()
{
	char sName[20];
	cout << "��������Ҫ���ҵ�������";
	cin >> sName;
	int sum = 0;
	POSITION pos = m_list.GetHeadPosition();
	while (pos)
	{
		DATA &data = m_list.GetAt(pos);
		if (strstr(data.sName, sName))
		{
			cout << data.nNumb << '\t';
			cout << data.sName << '\t';
			cout << data.fSalary  << endl;
			++sum;
		}
		m_list.GetNext(pos);
	}
	cout << "һ����" << sum << "�����ݣ�" << endl;
	system("pause");
}

void CFind::FindBySalary()
{
	float fMin, fMax;
	cout << "��������Ҫ���ҵ�����ʺ���߹��ʣ�";
	cin >> fMin;
	cin >> fMax;
	int sum = 0;
	POSITION pos = m_list.GetHeadPosition();
	while (pos)
	{
		DATA &data = m_list.GetAt(pos);
		if (data.fSalary >= fMin &&  data.fSalary <= fMax)
		{
			cout << data.nNumb << '\t';
			cout << data.sName << '\t';
			cout << data.fSalary << endl;
			++sum;
		}
		m_list.GetNext(pos);
	}
	cout << "һ��" << sum << "�������ݣ�" << endl;
	system("pause");
}

int CFind::FindMenu()
{
	system("cls");
	cout << "********************************" << endl;
	cout << "*                              *" << endl;
	cout << "*       1�������Ų���          *" << endl;
	cout << "*       2������������          *" << endl;
	cout << "*       3�������ʶβ���        *" << endl;
	cout << "*       0���˳�                *" << endl;
	cout << "*                              *" << endl;
	cout << "********************************" << endl;
	cout << "��ѡ��";
	int i = 0;
	cin >> i;
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
