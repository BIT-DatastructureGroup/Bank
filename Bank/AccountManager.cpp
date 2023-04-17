#include "AccountManager.h"
#include <random>
#include <string>
#include<ctime>
#include <fstream>
#include<iostream>

// ʵ����ģ����
template class AccountList<Account>; 

// ���ļ��е�������
bool AccountManager::ImportFile()
{
	std::fstream* dat;
	std::fstream DATA("account.dat", std::ios::in | std::ios::out | std::ios::binary);
	dat = &DATA;
	if (!DATA)
	{
		std::cout << "δ�ҵ������ļ����������´���..." << std::endl;
	}
	fopen("account.dat", "wb");
	dat = new std::fstream("account.dat", std::ios::in | std::ios::out | std::ios::binary);
	int cnt = 0;
	dat->seekp(0);//�����ļ�������
	dat->write(reinterpret_cast<char*>(&cnt), sizeof(int));//��cntд���ļ�
	std::cout << "���ݿ��Ѵ�����\n";
	dat->seekp(0);
	dat->read(reinterpret_cast<char*> (&cnt), sizeof(int));//��ȡ�˱��е�cnt
	if (cnt == 0)
	{
		std::cout << "��ǰ���ݿ�Ϊ�գ��뿪ʼ���Ĳ�����\n";
	}
	else
	{
		std::cout << "��ǰ���� " << cnt << "����Ŀ������������...\n";
		for (int i = 0; i < cnt; i++)
		{
			Account I;
			dat->seekp(sizeof(int) + i * sizeof(Account));
			dat->read(reinterpret_cast<char*>(&I), sizeof(Account));//���ļ���Item��ֵ��I
			accountList.add(I);//��I�浽������
			//I.print();
		}
		std::cout << "������ɣ�\n";
	}
	return false;
}

//��������
bool AccountManager::ExportFile()
{

	return false;
}

bool AccountManager::CreateAccount(std::string ID, std::string name, std::string phone, std::string email, std::string IDCard, bool manager)
{
	// ����6λ�����
	srand(time(NULL));
	int randomNumber = rand() % 900000 + 100000;
	std::string Card = std::to_string(randomNumber);
	Account newAccount(ID, name, phone, email, IDCard, Card, 0,manager);
	accountList.add(newAccount);
	return true;
}

AccountList<Account> AccountManager::QueryBlur(std::string blur)
{
	return AccountList<Account>();
}

bool AccountManager::QueryById(std::string ID, Account& out)
{
	Account newAccount;
	if (accountList.find(ID, newAccount))
	{
		out = newAccount;
		return true;
	}
	return false;
}

bool AccountManager::ModifyAccount(std::string ID,std::string s, int modifyType)
{
	
	// �޸�����
	if (modifyType == 0)
	{
		accountList.modifyEmail(ID, s);
		return true;
	}
	// �޸ĵ绰
	else if (modifyType == 1)
	{
		accountList.modifyPhone(ID, s);
		return true;
	}
	else
	{
		return false;
	}
}

bool AccountManager::ModifyAccount(Account newaccount, std::string s, int modifyType)
{
	std::string ID = newaccount.ID;
	// �޸�����
	if (modifyType == 0)
	{
		accountList.modifyEmail(ID, s);
		return true;
	}
	// �޸ĵ绰
	else if (modifyType == 1)
	{
		accountList.modifyPhone(ID, s);
		return true;
	}
	else
	{
		return false;
	}
}

bool AccountManager::Deposite(std::string ID, float money)
{
	
	accountList.deposite(ID, money);
	return true;
}

bool AccountManager::Deposite(Account newaccount, float money)
{
	std::string ID = newaccount.ID;
	accountList.deposite(ID, money);
	return true;
}

bool AccountManager::Withdraw(std::string ID, float money)
{
	
	if (accountList.withdraw(ID, money))
	{
		return true;
	}
	return false;
}

bool AccountManager::Withdraw(Account newaccount, float money)
{
	std::string ID = newaccount.ID;
	if (accountList.withdraw(ID, money))
	{
		return true;
	}
	return false;
}

bool AccountManager::DeleteUser(std::string ID)
{
	if (accountList.deleteaccount(ID))
	{
		return true;
	}
	return false;
}

bool AccountManager::DeleteUser(Account newaccount)
{
	std::string ID = newaccount.ID;
	if (accountList.deleteaccount(ID))
	{
		return true;
	}
	return false;
}

AccountList<Account> AccountManager::getAccounts()
{
	return AccountList<Account>(accountList);
}