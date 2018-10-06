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
		cout << "打开数据文件失败！" << endl;
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
		cout << "保存文件时失败！" << endl;
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
	cout << "学号\t姓名\t工资" << endl;
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
	cout << "一共有" << sum << "条记录!" << endl;
	system("pause");
}

void CWorker::Modify()
{
	int nNumb;
	cout << "请输入您要修改的工号：";
	cin >> nNumb;
	if (!nNumb)
		return;
	POSITION pos = m_find.FindPos(nNumb);
	if (!pos)
	{
		cout << "您输入的工号" << nNumb << "不存在！" << endl;
		system("pause");
		return;
	}
	cout << "确定修改工号" << nNumb << "【y/n】:";
	char c;
	cin >> c;
	if (c == 'y' || c == 'Y')
	{

		DATA &Data = m_list.GetAt(pos);
		cout << "请输入新的姓名和工资：";
		cin >> Data.sName;
		cin >> Data.fSalary;
		Print();
		Save();
	}
}

void CWorker::Delete()
{
	int nNumb;
	cout << "请输入您要删除的工号：";
	cin >> nNumb;
	if (!nNumb)
		return;
	POSITION pos = m_find.FindPos(nNumb);
	if (!pos)
	{
		cout << "您输入的工号" << nNumb << "不存在！" << endl;
		system("pause");
		return;
	}
	cout << "确定删除工号" << nNumb << "【y/n】:";
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
	cout << "请输入工号：";
	while (true)
	{
		cin >> nNumb;
		if (!nNumb)
			return;
		if (!m_find.FindPos(nNumb))
			break;
		cout << "工号" << nNumb << "已经存在，请重新输入：";
	}
	DATA Data = { nNumb };
	cout << "请输入姓名和工资：";
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
	cout << "*       1、浏览所有信息        *" << endl;
	cout << "*       2、添加信息            *" << endl;
	cout << "*       3、删除信息            *" << endl;
	cout << "*       4、修改信息            *" << endl;
	cout << "*       5、查找信息            *" << endl;
	cout << "*       0、退出                *" << endl;
	cout << "********************************" << endl;
	cout << "请选择：";
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




