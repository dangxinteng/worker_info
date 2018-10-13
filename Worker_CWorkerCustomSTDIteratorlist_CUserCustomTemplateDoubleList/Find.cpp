#include "Find.h"

CFind::CFind(CList<DATA> &cArray):m_array(cArray)
{
}

CFind::~CFind()
{
}
CList<DATA>::iterator CFind::FindNumb(int nNumb) const
{
	CList<DATA>::iterator itData = m_array.begin();
	while(itData != m_array.end())
	{
		if (itData->nNumb == nNumb)
			break;
		itData++;
	}
	return itData;
}
void CFind::FindByNumb() const
{
	int nNumb;
	cout << "��������Ҫ���ҵĹ��ţ�";
	cin >> nNumb;
	if (!nNumb)
		return;
	CList<DATA>::iterator itData= FindNumb(nNumb);
	if (itData == m_array.end())
	{
		cout << "��Ҫ���ҵĹ��Ų����ڣ�" << endl;
		system("pause");
		return;
	}
	cout << itData->nNumb << '\t';
	cout << itData->sName << '\t';
	cout << itData->fSalary << endl;
	system("pause");
}

void CFind::FindByName() const
{
	char sName[20]; int sum = 0;
	cout << "��������Ҫ���ҵ�������";
	cin >> sName;
	CList<DATA>::iterator itData = m_array.begin();
	while (itData != m_array.end())
	{
		if (strstr(itData->sName, sName))
		{
			cout << itData->nNumb << '\t';
			cout << itData->sName << '\t';
			cout << itData->fSalary  << endl;
			++sum;
		}
		++itData;
	}
	cout << "һ����" << sum << "�����ݣ�" << endl;
	system("pause");
}

void CFind::FindBySalary() const
{
	float fMin, fMax; int sum = 0;
	cout << "��������Ҫ���ҵ�����ʺ���߹��ʣ�";
	cin >> fMin;
	cin >> fMax;
	CList<DATA>::iterator itData = m_array.begin();
	while (itData != m_array.end())
	{
		if (itData->fSalary >= fMin &&  itData->fSalary <= fMax)
		{
			cout << itData->nNumb << '\t';
			cout << itData->sName << '\t';
			cout << itData->fSalary << endl;
			++sum;
		}
		++itData;
	}
	cout << "һ��" << sum << "�������ݣ�" << endl;
	system("pause");
}

int CFind::FindMenu() const
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
