#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "Worker.h"
using namespace std;
CWorker::CWorker()
{
	Load();
}

void CWorker::Load()
{
	
	FILE *fp = fopen("./worker.txp", "rb");
	if (!fp)
	{
		cout << "�������ļ�ʧ�ܣ�\n";
		return;
	}		
	DATA data;	
	while (fread(&data, 1, sizeof(DATA), fp)== sizeof(DATA))
	{
		m_list.AddTail(data);
	}
	fclose(fp);
}

void CWorker::Save()
{
	FILE *fp = fopen("./worker.txp", "wb");
	if (!fp)
	{
		cout << "�����ļ�ʱʧ�ܣ�\n";
		return ;
	}
	POSITION pos = m_list.GetHeadPosition();
	while (pos)
	{
		DATA &data = m_list.GetAt(pos);
		fwrite(&data, 1, sizeof(DATA), fp);
		m_list.GetNext(pos);
	}
	fclose(fp);
}

POSITION CWorker::FindPos(int nNumb)
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

void CWorker::Print()
{
	int sum = 0;
	cout << "ѧ��\t����\t����\n";
	POSITION pos = m_list.GetHeadPosition();
	while (pos)
	{
		DATA &data = m_list.GetAt(pos);
		cout << data.nNumb << '\t';
		cout << data.sName << '\t';
		cout << data.fSalary << '\n';
		++sum;
		m_list.GetNext(pos);
	}	
	cout << "һ����" << sum << "����¼!\n";
	system("pause");
}

void CWorker::Modify()
{
	int nNumb;
	cout << "��������Ҫ�޸ĵĹ��ţ�";
	cin >> nNumb;
	if (!nNumb)
		return ;
	POSITION pos = FindPos(nNumb);
	if (!pos)
	{
		cout << "������Ĺ���" << nNumb << "�����ڣ�\n";
		system("pause");
		return ;
	}
	cout << "ȷ���޸Ĺ���" << nNumb << "��y/n��:";
	char c;
	cin >> c;
	if (c == 'y' || c == 'Y')
	{
		
		DATA &Data = m_list.GetAt(pos);
		cout << "�������µ������͹��ʣ�";
		cin >> Data.sName;
		cin >> Data.fSalary;
		Print();
		Save();
	}
}

void CWorker::Delete()
{
	int nNumb;
	cout << "��������Ҫɾ���Ĺ��ţ�";
	cin >> nNumb;
	if (!nNumb)
		return ;
	POSITION pos = FindPos(nNumb);
	if (!pos)
	{
		cout << "������Ĺ���" << nNumb << "�����ڣ�\n";
		system("pause");
		return ;
	}
	cout << "ȷ��ɾ������" << nNumb << "��y/n��:";
	char c;
	cin >> c;
	if (c == 'y' || c == 'Y')
	{
		m_list.RemoveAt(pos);
		Print();
		Save();
	}
}

void CWorker::Input()
{
	int nNumb;
	cout << "�����빤�ţ�";
	while (true)
	{
		cin >> nNumb;
		if (!nNumb)
			return ;
		if (!FindPos(nNumb))
			break;
		cout << "����" << nNumb << "�Ѿ����ڣ����������룺";
	}
	DATA Data = { nNumb };
	cout << "�����������͹��ʣ�";
	cin >> Data.sName;
	cin >> Data.fSalary;
	m_list.AddTail(Data);
	Print();
	Save();
}

int CWorker::Menu()
{
	system("cls");

	cout << "********************************\n";
	cout << "*       1�����������Ϣ        *\n";
	cout << "*       2�������Ϣ            *\n";
	cout << "*       3��ɾ����Ϣ            *\n";
	cout << "*       4���޸���Ϣ            *\n";
	cout << "*       5��������Ϣ            *\n";
	cout << "*       0���˳�                *\n";
	cout << "********************************\n";
	cout << "��ѡ��";
	int i = 0;
	cin >> i;
	switch (i)
	{
	case 1:
		//Print();
		while (SortMenu())
			;
		break;
	case 2:
		Input();
		break;
	case 3:
		Delete();
		break;
	case 4:
		Modify();
		break;
	case 5:
		while (FindMenu())
			;
		break;

	}
	return i;
}

int CWorker::SortByNumb(DATA &n, DATA &m)
{
	return n.nNumb < m.nNumb;
}

int CWorker::SortByName(DATA &n, DATA &m)
{
	return strcmp(n.sName, m.sName) < 0;
}

int CWorker::SortBySalary(DATA &n, DATA &m)
{
	return n.fSalary < m.fSalary;
}

void CWorker::SortFun(BYFUN pFun)
{
	int nCount = m_list.GetCount();
	POSITION* _pp = new POSITION[nCount];
	POSITION*  pp = _pp;
	int i = -1;
	while (++i < nCount)
	{
		*pp = m_list.FindIndex(i);
		pp++;
	}
	i = -1; pp = _pp;
	while (++i < nCount)
	{
		int j = i, m = i;
		while (++j < nCount)
		{
			DATA &data1 = m_list.GetAt(pp[j]);
			DATA &data2 = m_list.GetAt(pp[m]);
			if (pFun(data1, data2))
			{
				m = j;
			}
		}
		if (m != i)
		{
			POSITION t = pp[i];
			pp[i] = pp[m];
			pp[m] = t;
		}
	}
	pp = _pp;
	cout << "ѧ��\t����\t����\n";
	i = -1;
	while (++i < nCount)
	{
		DATA &data = m_list.GetAt(pp[i]);
		cout << data.nNumb << '\t';
		cout << data.sName << '\t';
		cout << data.fSalary << '\n';
	}
	cout << "һ����" << i << "����¼!\n";	
	system("pause");
	delete _pp;
}

int CWorker::SortMenu()
{
	system("cls");
	cout << "********************************\n";
	cout << "*                              *\n";
	cout << "*      1���������������       *\n";
	cout << "*      2���������������       *\n";
	cout << "*      3���������������       *\n";
	cout << "*      0���˳�                 *\n";
	cout << "*                              *\n";
	cout << "********************************\n";
	cout << "��ѡ��";
	int i = 0;
	cin >> i;
	BYFUN ByFun[] = { SortByNumb,SortByName,SortBySalary };
	if (i > 0 && i < 4)
		SortFun(ByFun[i - 1]);
	return i;
}

void CWorker::FindByNumb()
{
	int nNumb;
	cout << "��������Ҫ���ҵĹ��ţ�";
	cin >> nNumb;
	if (!nNumb)
		return ;
	POSITION pos = FindPos(nNumb);
	if (!pos)
	{
		cout << "��Ҫ���ҵĹ��Ų����ڣ�\n";
		system("pause");
		return ;
	}
	DATA &data = m_list.GetAt(pos);
	cout << data.nNumb << '\t';
	cout << data.sName << '\t';
	cout << data.fSalary << '\n';
	system("pause");
}

void CWorker::FindByName()
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
			cout << data.fSalary << '\n';
			++sum;
		}
		m_list.GetNext(pos);
	}
	cout << "һ����" << sum << "�����ݣ�\n";
	system("pause");
}

void CWorker::FindBySalary()
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
			cout << data.fSalary << '\n';
			++sum;
		}
		m_list.GetNext(pos);
	}
	cout << "һ��" << sum << "�������ݣ�\n";
	system("pause");
}

int CWorker::FindMenu()
{
	system("cls");
	cout << "********************************\n";
	cout << "*                              *\n";
	cout << "*       1�������Ų���          *\n";
	cout << "*       2������������          *\n";
	cout << "*       3�������ʶβ���        *\n";
	cout << "*       0���˳�                *\n";
	cout << "*                              *\n";
	cout << "********************************\n";
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


CWorker::~CWorker()
{
}
