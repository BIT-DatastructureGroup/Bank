#include "AccountManager.h"
#include <random>
#include <string>
#include<ctime>

// 实例化模板类
template class AccountList<Account>; 

bool AccountManager::ImportFile()
{
	return false;
}

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