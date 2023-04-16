#include "AccountManager.h"

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
  return false;
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
