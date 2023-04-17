#include "AccountManager.h"
#include <random>
#include <string>
#include<ctime>
#include <fstream>
#include<iostream>

// 实例化模板类
template class AccountList<Account>; 

// 从文件中导入数据
bool AccountManager::ImportFile()
{
	std::fstream* dat;
	std::fstream DATA("account.dat", std::ios::in | std::ios::out | std::ios::binary);
	dat = &DATA;
	if (!DATA)
	{
		std::cout << "未找到数据文件，正在重新创建..." << std::endl;
	}
	fopen("account.dat", "wb");
	dat = new std::fstream("account.dat", std::ios::in | std::ios::out | std::ios::binary);
	int cnt = 0;
	dat->seekp(0);//设置文件里的起点
	dat->write(reinterpret_cast<char*>(&cnt), sizeof(int));//把cnt写入文件
	std::cout << "数据库已创建！\n";
	dat->seekp(0);
	dat->read(reinterpret_cast<char*> (&cnt), sizeof(int));//读取账本中的cnt
	if (cnt == 0)
	{
		std::cout << "当前数据库为空！请开始您的操作！\n";
	}
	else
	{
		std::cout << "当前已有 " << cnt << "项账目，正在载入中...\n";
		for (int i = 0; i < cnt; i++)
		{
			Account I;
			dat->seekp(sizeof(int) + i * sizeof(Account));
			dat->read(reinterpret_cast<char*>(&I), sizeof(Account));//把文件中Item赋值给I
			accountList.add(I);//把I存到链表里
			//I.print();
		}
		std::cout << "载入完成！\n";
	}
	return false;
}

//保存数据
bool AccountManager::ExportFile()
{

	return false;
}

bool AccountManager::CreateAccount(std::string ID, std::string name, std::string phone, std::string email, std::string IDCard, bool manager)
{
	// 生成6位随机数
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
	
	// 修改邮箱
	if (modifyType == 0)
	{
		accountList.modifyEmail(ID, s);
		return true;
	}
	// 修改电话
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
	// 修改邮箱
	if (modifyType == 0)
	{
		accountList.modifyEmail(ID, s);
		return true;
	}
	// 修改电话
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