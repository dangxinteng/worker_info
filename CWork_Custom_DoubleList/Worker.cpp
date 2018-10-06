#include "Worker.h"
CWorker::CWorker():m_sort(m_list),m_find(m_list)
{
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
		return;
	}
	DATA data;
	while (fread(&data, 1, sizeof(DATA), fp) == sizeof(DATA))
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
		cout << "�����ļ�ʱʧ�ܣ�" << endl;
		return;
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


void CWorker::Print()
{
	int sum = 0;
	cout << "ѧ��\t����\t����" << endl;
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
	cout << "һ����" << sum << "����¼!" << endl;
	system("pause");
}

void CWorker::Modify()
{
	int nNumb;
	cout << "��������Ҫ�޸ĵĹ��ţ�";
	cin >> nNumb;
	if (!nNumb)
		return;
	POSITION pos = m_find.FindPos(nNumb);
	if (!pos)
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
		return;
	POSITION pos = m_find.FindPos(nNumb);
	if (!pos)
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
			return;
		if (!m_find.FindPos(nNumb))
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

	cout << "********************************" << endl;
	cout << "*       1�����������Ϣ        *" << endl;
	cout << "*       2�������Ϣ            *" << endl;
	cout << "*       3��ɾ����Ϣ            *" << endl;
	cout << "*       4���޸���Ϣ            *" << endl;
	cout << "*       5��������Ϣ            *" << endl;
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

	}
	return i;
}




