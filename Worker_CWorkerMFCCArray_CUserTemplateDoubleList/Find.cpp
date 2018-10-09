#include "Find.h"

CFind::CFind(CArray<DATA> &cArray):m_array(cArray)
{
}

CFind::~CFind()
{
}
int CFind::FindNumb(int nNumb) const
{
	DATA* pData = m_array.GetData();
	int i = -1, nCount = m_array.GetCount();
	while (++i < nCount)
	{
		if (pData->nNumb == nNumb)
			return i;
		++pData;
	}
	return -1;
}
void CFind::FindByNumb() const
{
	int nNumb;
	cout << "��������Ҫ���ҵĹ��ţ�";
	cin >> nNumb;
	if (!nNumb)
		return;
	int nIndex = FindNumb(nNumb);
	if (nIndex < -1)
	{
		cout << "��Ҫ���ҵĹ��Ų����ڣ�" << endl;
		system("pause");
		return;
	}
	DATA &data = m_array.GetAt(nIndex);
	cout << data.nNumb << '\t';
	cout << data.sName << '\t';
	cout << data.fSalary << endl;
	system("pause");
}

void CFind::FindByName() const
{
	char sName[20];
	cout << "��������Ҫ���ҵ�������";
	cin >> sName;
	int sum = 0, i = -1, nCount = m_array.GetCount();
	const DATA* pData = m_array.GetData();
	while (++i < nCount)
	{
		if (strstr(pData->sName, sName))
		{
			cout << pData->nNumb << '\t';
			cout << pData->sName << '\t';
			cout << pData->fSalary  << endl;
			++sum;
		}
		++pData;
	}
	cout << "һ����" << sum << "�����ݣ�" << endl;
	system("pause");
}

void CFind::FindBySalary() const
{
	float fMin, fMax;
	cout << "��������Ҫ���ҵ�����ʺ���߹��ʣ�";
	cin >> fMin;
	cin >> fMax;
	int sum = 0, i = -1, nCount = m_array.GetCount();
	while (++i < nCount)
	{
		DATA &data = m_array.GetAt(i);
		if (data.fSalary >= fMin &&  data.fSalary <= fMax)
		{
			cout << data.nNumb << '\t';
			cout << data.sName << '\t';
			cout << data.fSalary << endl;
			++sum;
		}
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
