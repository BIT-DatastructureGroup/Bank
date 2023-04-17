#include "AccountManager.h"
#include <random>
#include <string>
#include<ctime>

// ʵ����ģ����
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

bool AccountManager::ModifyAccount(Account user,std::string s, int modifyType)
{
	std::string ID = user.ID;
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

bool AccountManager::Deposite(Account user, float money)
{
	std::string ID = user.ID;
	accountList.deposit(ID, money);
	return true;
}

bool AccountManager::Withdraw(Account user, float money)
{
	std::string ID = user.ID;
	if (accountList.withdraw(ID, money))
	{
		return true;
	}
	return false;
}

bool AccountManager::DeleteUser(Account user)
{
	std::string ID = user.ID;
	if (accountList.deleteacconut(ID))
	{
		return true;
	}
	return false;
}

AccountList<Account> AccountManager::getAccounts()
{
	return AccountList<Account>(accountList);
}