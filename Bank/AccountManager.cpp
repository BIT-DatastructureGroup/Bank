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

bool AccountManager::CreateAccount(std::string ID, std::string name, std::string phone, std::string email, std::string IDCard)
{
	// 生成6位随机数
	srand(time(NULL));
	int randomNumber = rand() % 900000 + 100000;
	std::string Card = std::to_string(randomNumber);
	Account newAccount(ID, name, phone, email, IDCard, Card, 0);
	accountList.add(newAccount);
	return true;
}

AccountList<Account> AccountManager::QueryBlur()
{
	return AccountList<Account>();
}

bool AccountManager::QueryById(std::string ID, Account& out)
{
	return false;
}

bool AccountManager::ModifyAccount(Account newValue, int modifyType)
{
	return false;
}

bool AccountManager::Deposite(Account user, float money)
{
	return false;
}

bool AccountManager::Withdraw(Account user, float money)
{
	return false;
}

bool AccountManager::DeleteUser(Account user)
{
	return false;
}

AccountList<Account> AccountManager::getAccounts()
{
	return AccountList<Account>();
}