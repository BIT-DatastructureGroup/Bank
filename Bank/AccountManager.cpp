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
  // ʹ��һ���ļ������󣬲�ָ����ģʽΪ��д�Ͷ�����
  std::fstream dat("account.dat", std::ios::in | std::ios::out | std::ios::binary);
  // ����ļ��Ƿ�򿪳ɹ�
  if (!dat)
  {
    std::cout << "δ�ҵ������ļ����������´���..." << std::endl;
    // ���´��ļ�����ָ����ģʽΪд��Ͷ�����
    dat.open("account.dat", std::ios::out | std::ios::binary);
    // ����ļ��Ƿ�򿪳ɹ�
    if (!dat)
    {
      // �����ʧ�ܵ����
      return false;
    }
  }
  int cnt = 0;
  // �����ļ�������
  dat.seekp(0);
  // ��cntд���ļ�
  dat.write(reinterpret_cast<char *>(&cnt), sizeof(int));
  // ���д���Ƿ�ɹ�
  if (!dat)
  {
    // ����д��ʧ�ܵ����
    return false;
  }
  std::cout << "���ݿ��Ѵ�����\n";
  // �����ļ�������
  dat.seekg(0);
  // ��ȡ�˱��е�cnt
  dat.read(reinterpret_cast<char *>(&cnt), sizeof(int));
  // ����ȡ�Ƿ�ɹ�
  if (!dat)
  {
    // �����ȡʧ�ܵ����
    return false;
  }
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
      // �����ļ����λ��
      dat.seekg(sizeof(int) + i * sizeof(Account));
      // ���ļ���Item��ֵ��I
      dat.read(reinterpret_cast<char *>(&I), sizeof(Account));
      // ����ȡ�Ƿ�ɹ�
      if (!dat)
      {
        // �����ȡʧ�ܵ����
        return false;
      }
      // ��I�浽������
      accountList.add(I);
      // I.print();
    }
    std::cout << "������ɣ�\n";
  }
  return true;
}
// ��������
bool AccountManager::ExportFile()
{

  return false;
}

bool AccountManager::CreateAccount(std::string ID, std::string name, std::string phone, std::string email, std::string IDCard, bool manager)
{
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