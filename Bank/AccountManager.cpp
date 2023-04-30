#include "AccountManager.h"
#include <random>
#include <string>
#include <ctime>
#include <fstream>
#include <iostream>
#include<vector>

// 实例化模板类
template class AccountList<Account>;

// 从文件中导入数据
bool AccountManager::ImportFile()
{
    if (accountList.loadtxt())
    {
        return true;
    }
  return false;
}
// 保存数据
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
        std::cout << "ID已存在，请重新创建！" << std::endl;
        return false;
    }
  // 生成6位随机数
  static bool inited = false;
  if (!inited)
  {
    // 只初始化一次
    srand(time(NULL));
    inited = true;
  }
  int randomNumber = rand() % 900000 + 100000;
  std::string Card = std::to_string(randomNumber);
  Account newAccount(ID, name, phone, email, IDCard, Card, 0, manager,0);
  accountList.add(newAccount);
  ExportFile();
  return true;
}

std::vector<Account> AccountManager::QueryBlur(std::string blur)
{
    std::vector<Account> a;
    a = accountList.findinfo(blur);
    return a;
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

  // 修改邮箱
  if (modifyType == 0)
  {
    accountList.modifyEmail(ID, s);
    ExportFile();
    return true;
  }
  // 修改电话
  else if (modifyType == 1)
  {
    accountList.modifyPhone(ID, s);
    ExportFile();
    return true;
  }
  else
  {
    return false;
  }
}

bool AccountManager::ModifyAccount(Account &newaccount, std::string s, int modifyType)
{
  std::string ID = newaccount.ID;
  // 修改邮箱
  if (modifyType == 0)
  {
    accountList.modifyEmail(ID, s);
    newaccount.email = s;
    ExportFile();
    return true;
  }
  // 修改电话
  else if (modifyType == 1)
  {
    newaccount.phone = s;
    accountList.modifyPhone(ID, s);
    ExportFile();
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
  ExportFile();
  return true;
}

bool AccountManager::Deposite(Account &newaccount, float money)
{
  std::string ID = newaccount.ID;
  // 将传进来的账户引用的余额加上money
  newaccount.balance += money;
  // 在链表中进行同样的操作
  accountList.deposite(ID, money);
  ExportFile();
  return true;
}

bool AccountManager::Withdraw(std::string ID, float money)
{

  if (accountList.withdraw(ID, money))
  {
    ExportFile();
    return true;
  }
  return false;
}

bool AccountManager::Withdraw(Account &newaccount, float money)
{
  std::string ID = newaccount.ID;
  if (accountList.withdraw(ID, money))
  {
      newaccount.balance += money;
      ExportFile();
    return true;
  }
  return false;
}

bool AccountManager::DeleteUser(std::string ID)
{
  if (accountList.deleteaccount(ID))
  {
    ExportFile();
    return true;
  }
  return false;
}

bool AccountManager::DeleteUser(Account newaccount)
{
  std::string ID = newaccount.ID;
  if (accountList.deleteaccount(ID))
  {
    ExportFile();
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
void AccountManager::findin(std::string ID)//模糊查找
{
    accountList.findinfo(ID);
}
