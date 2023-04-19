#include "AccountManager.h"
#include <random>
#include <string>
#include <ctime>
#include <fstream>
#include <iostream>
#include<vector>

// ʵ����ģ����
template class AccountList<Account>;

// ���ļ��е�������

bool AccountManager::ImportFile()
{
    if (accountList.loadtxt())
    {
        return true;
    }
  return false;
}
// ��������
bool AccountManager::ExportFile()
{
    if (accountList.savetxt())
    {
        return true;
    };
    return false;
}

bool AccountManager::CreateAccount(std::string ID, std::string name, std::string phone, std::string email, std::string IDCard, bool manager)
{
    Account temp;
    if (accountList.find(ID, temp))
    {
        std::cout << "ID�Դ��ڣ������´�����" << std::endl;
        return false;
    }
  // ����6λ�����
  static bool inited = false;
  if (!inited)
  {
    // ֻ��ʼ��һ��
    srand(time(NULL));
    inited = true;
  }
  int randomNumber = rand() % 900000 + 100000;
  std::string Card = std::to_string(randomNumber);
  Account newAccount(ID, name, phone, email, IDCard, Card, 0, manager);
  accountList.add(newAccount);
  return true;
}

AccountList<Account> AccountManager::QueryBlur(std::string blur)
{
  return AccountList<Account>();
}

bool AccountManager::QueryById(std::string ID, Account &out)
{
  Account newAccount;
  if (accountList.find(ID, newAccount))
  {
    out = newAccount;
    return true;
  }
  return false;
}

bool AccountManager::ModifyAccount(std::string ID, std::string s, int modifyType)
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

bool AccountManager::Deposite(Account &newaccount, float money)
{
  std::string ID = newaccount.ID;
  // �����������˻����õ�������money
  newaccount.balance += money;
  // �������н���ͬ���Ĳ���
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

std::vector<Account> AccountManager::getAccounts()
{
    std::vector<Account> v1 = accountList.listtovector();
    return v1;
}

int AccountManager::getnum()
{
    
    return accountList.length();
}
