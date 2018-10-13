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
		cout << "打开数据文件失败！" << endl;
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
		cout << "保存文件时失败！" << endl;
		system("pause");
		return;
	}
	CList<DATA>::iterator itData = m_arry.begin();
	while (itData != m_arry.end())
	{
		DATA data = *itData;
		if (fwrite(&data, sizeof(DATA), 1, fp) != 1)
		{
			cout << "文件写入失败！" << endl;
			system("pause");
		}
		itData++;
	}
	fclose(fp);
}


void CWorker::Print() const
{
	cout << "学号\t姓名\t工资" << endl;
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
	cout << "一共有" << m_arry.size() << "条记录!" << endl;
	system("pause");
}

void CWorker::Modify()
{
	int nNumb;
	cout << "请输入您要修改的工号：";
	cin >> nNumb;
	if (!nNumb)
		return;
	CList<DATA>::iterator itData = m_find.FindNumb(nNumb);
	if (itData == m_arry.end())
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
		cout << "请输入新的姓名和工资：";
		cin >> itData->sName;
		cin >> itData->fSalary;
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
	CList<DATA>::iterator itData = m_find.FindNumb(nNumb);
	if (itData == m_arry.end())
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
		m_arry.erase(itData);
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
		if (m_find.FindNumb(nNumb) == m_arry.end())
			break;
		cout << "工号" << nNumb << "已经存在，请重新输入：";
	}
	DATA Data = { nNumb };
	cout << "请输入姓名和工资：";
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
	cout << "* 当前用户：" << m_user.GetCurrentUser().sName << " 权限(" 
		 <<( m_user.GetCurrentUser().nPrior?"普通用户)*": "管理员) *") << endl;
	cout << "*       1、浏览所有信息        *" << endl;
	cout << "*       2、添加信息            *" << endl;
	cout << "*       3、删除信息            *" << endl;
	cout << "*       4、修改信息            *" << endl;
	cout << "*       5、查找信息            *" << endl;
	if(m_user.IsAdmin())
		cout << "*       6、账户管理            *" << endl;
	else
		cout << "*       6、修改密码            *" << endl;
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
	case 6:
		if (m_user.IsAdmin())
			m_user.UserControl();
		else
			m_user.ModifyPass();
		break;

	}
	return i;
}




