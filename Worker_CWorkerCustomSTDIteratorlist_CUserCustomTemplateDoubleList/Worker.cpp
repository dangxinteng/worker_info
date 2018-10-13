#define _CRT_SECURE_NO_WARNINGS
#include "Worker.h"
CWorker::CWorker():m_sort(m_arry),m_find(m_arry)
{
	while (!m_user.Login())
		;
	Load();
}
bool CWorker::Start()
{
	while (Menu())
		;
	return false;
}

CWorker::~CWorker()
{
}
void CWorker::Load()
{

	FILE *fp = fopen("./worker.txp", "rb");
	if (!fp)
	{
		cout << "�������ļ�ʧ�ܣ�" << endl;
		system("pause");
		return;
	}
	DATA data;
	while (fread(&data, sizeof(DATA), 1, fp) == 1)
		m_arry.push_back(data);
	fclose(fp);
}

void CWorker::Save() const
{
	FILE *fp = fopen("./worker.txp", "wb");
	if (!fp)
	{
		cout << "�����ļ�ʱʧ�ܣ�" << endl;
		system("pause");
		return;
	}
	CList<DATA>::iterator itData = m_arry.begin();
	while (itData != m_arry.end())
	{
		DATA data = *itData;
		if (fwrite(&data, sizeof(DATA), 1, fp) != 1)
		{
			cout << "�ļ�д��ʧ�ܣ�" << endl;
			system("pause");
		}
		itData++;
	}
	fclose(fp);
}


void CWorker::Print() const
{
	cout << "ѧ��\t����\t����" << endl;
	CList<DATA>::iterator itData = m_arry.begin();
	/*CList<DATA>::SNode* it = itData;
	it->*/
	while (itData != m_arry.end())
	{
		cout << itData->nNumb << '\t';
		cout << itData->sName << '\t';
		cout << itData->fSalary << '\n';
		++itData;
	}
	cout << "һ����" << m_arry.size() << "����¼!" << endl;
	system("pause");
}

void CWorker::Modify()
{
	int nNumb;
	cout << "��������Ҫ�޸ĵĹ��ţ�";
	cin >> nNumb;
	if (!nNumb)
		return;
	CList<DATA>::iterator itData = m_find.FindNumb(nNumb);
	if (itData == m_arry.end())
	{
		cout << "������Ĺ���" << nNumb << "�����ڣ�" << endl;
		system("pause");
		return;
	}
	cout << "ȷ���޸Ĺ���" << nNumb << "��y/n��:";
	char c;
	cin >> c;
	if (c == 'y' || c == 'Y')
	{
		cout << "�������µ������͹��ʣ�";
		cin >> itData->sName;
		cin >> itData->fSalary;
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
		return;
	CList<DATA>::iterator itData = m_find.FindNumb(nNumb);
	if (itData == m_arry.end())
	{
		cout << "������Ĺ���" << nNumb << "�����ڣ�" << endl;
		system("pause");
		return;
	}
	cout << "ȷ��ɾ������" << nNumb << "��y/n��:";
	char c;
	cin >> c;
	if (c == 'y' || c == 'Y')
	{
		m_arry.erase(itData);
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
			return;
		if (m_find.FindNumb(nNumb) == m_arry.end())
			break;
		cout << "����" << nNumb << "�Ѿ����ڣ����������룺";
	}
	DATA Data = { nNumb };
	cout << "�����������͹��ʣ�";
	cin >> Data.sName;
	cin >> Data.fSalary;
	m_arry.push_back(Data);
	Print();
	Save();
}

int CWorker::Menu()
{
	system("cls");

	cout << "********************************" << endl;
	cout << "* ��ǰ�û���" << m_user.GetCurrentUser().sName << " Ȩ��(" 
		 <<( m_user.GetCurrentUser().nPrior?"��ͨ�û�)*": "����Ա) *") << endl;
	cout << "*       1�����������Ϣ        *" << endl;
	cout << "*       2�������Ϣ            *" << endl;
	cout << "*       3��ɾ����Ϣ            *" << endl;
	cout << "*       4���޸���Ϣ            *" << endl;
	cout << "*       5��������Ϣ            *" << endl;
	if(m_user.IsAdmin())
		cout << "*       6���˻�����            *" << endl;
	else
		cout << "*       6���޸�����            *" << endl;
	cout << "*       0���˳�                *" << endl;
	cout << "********************************" << endl;
	cout << "��ѡ��";
	int i = 0;
	cin >> i;
	switch (i)
	{
	case 1:
		//Print();
		while (m_sort.SortMenu())
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
		while (m_find.FindMenu())
			;
		break;
	case 6:
		if (m_user.IsAdmin())
			m_user.UserControl();
		else
			m_user.ModifyPass();
		break;

	}
	return i;
}




