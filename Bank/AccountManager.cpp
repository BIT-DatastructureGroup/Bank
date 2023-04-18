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
  // 使用一个文件流对象，并指定打开模式为读写和二进制
  std::fstream dat("account.dat", std::ios::in | std::ios::out | std::ios::binary);
  // 检查文件是否打开成功
  if (!dat)
  {
    std::cout << "未找到数据文件，正在重新创建..." << std::endl;
    // 重新打开文件，并指定打开模式为写入和二进制
    dat.open("account.dat", std::ios::out | std::ios::binary);
    // 检查文件是否打开成功
    if (!dat)
    {
      // 处理打开失败的情况
      return false;
    }
  }
  int cnt = 0;
  // 设置文件里的起点
  dat.seekp(0);
  // 把cnt写入文件
  dat.write(reinterpret_cast<char *>(&cnt), sizeof(int));
  // 检查写入是否成功
  if (!dat)
  {
    // 处理写入失败的情况
    return false;
  }
  std::cout << "数据库已创建！\n";
  // 设置文件里的起点
  dat.seekg(0);
  // 读取账本中的cnt
  dat.read(reinterpret_cast<char *>(&cnt), sizeof(int));
  // 检查读取是否成功
  if (!dat)
  {
    // 处理读取失败的情况
    return false;
  }
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
      // 设置文件里的位置
      dat.seekg(sizeof(int) + i * sizeof(Account));
      // 把文件中Item赋值给I
      dat.read(reinterpret_cast<char *>(&I), sizeof(Account));
      // 检查读取是否成功
      if (!dat)
      {
        // 处理读取失败的情况
        return false;
      }
      // 把I存到链表里
      accountList.add(I);
      // I.print();
    }
    std::cout << "载入完成！\n";
  }
  return true;
}
// 保存数据
bool AccountManager::ExportFile()
{

  return false;
}

bool AccountManager::CreateAccount(std::string ID, std::string name, std::string phone, std::string email, std::string IDCard, bool manager)
{
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

bool AccountManager::Deposite(Account &newaccount, float money)
{
  std::string ID = newaccount.ID;
  // 将传进来的账户引用的余额加上money
  newaccount.balance += money;
  // 在链表中进行同样的操作
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