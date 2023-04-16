#include "AccountManager.h"
#include <random>
#include <string>
#include<ctime>



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

std::vector<Account> AccountManager::QueryBlur()
{
  return std::vector<Account>();
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

std::vector<Account> AccountManager::getAccounts()
{
  return std::vector<Account>();
}
