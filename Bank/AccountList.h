#ifndef ACCOUNTLIST_H
#define ACCOUNTLIST_H
#include "AccountNode.h"
#include <string>
#include <iostream>
#include <vector>
#include<fstream>
template <typename T> // ���Ͳ�����
class AccountList     // ��ģ����
{
private:
  AccountNode<T> *head; // ʹ�����Ͳ���T��ΪԪ������
public:
  AccountList()
  {
    head = new AccountNode<T>;
    T a;
    head->data = a;
    head->next = NULL;
  }; // ʹ�����Ͳ���T��ΪԪ������
  AccountList(T a)
  {
    head = new AccountNode<T>;
    head->data = a;
    head->next = NULL;
  } // ʹ�����Ͳ���T��ΪԪ������
  // ���һ���µ��˻��ŵ����������
  void add(T account); // ʹ�����Ͳ���T��ΪԪ������
  void showlist();
  bool find(std::string id, T &out); // ʹ�����Ͳ���K��Ϊ�ؼ������ͣ�T��ΪԪ������
  bool modifyEmail(std::string ID, std::string s);
  bool modifyPhone(std::string ID, std::string s);
  bool deposite(std::string ID, float money);
  bool withdraw(std::string ID, float money);
  bool deleteaccount(std::string ID);
  std::vector<Account> listtovector();
  bool savetxt();

  // TODO: ���������е�Ԫ�ظ���
  int length();
};
template <typename T>               // ģ������
void AccountList<T>::add(T account) // ʹ�����Ͳ���T
{
  AccountNode<T> *p = head; // ʹ�����Ͳ���T
  for (; p->next != NULL; p = p->next)
    ;
  AccountNode<T> *temp = new AccountNode<T>; // ʹ�����Ͳ���T
  temp->data = account;
  p->next = temp;
  temp->next = NULL;
}
template <typename T>           // ģ������
void AccountList<T>::showlist() // ʹ�����Ͳ���T
{
  if (head->next == NULL)
  {
    std::cout << "������\n";
    return;
  }
  AccountNode<T> *p = head->next; // ʹ�����Ͳ���T
  while (p != NULL)
  {
    std::cout << p->data << std::endl;
    p = p->next;
  }
}
template <typename T>                             // ģ������
bool AccountList<T>::find(std::string id, T &out) // ʹ�����Ͳ���T
{
  AccountNode<T> *p = head; // ʹ�����Ͳ���T
  while (p != NULL)
  {
    if (p->data.ID == id)
    {
      out = p->data;
      return true;
    }
    p = p->next;
  }
  return false;
}

// ͨ��ID���ҵ���Ӧ���˻����޸�����Ϊs
template <typename T>
bool AccountList<T>::modifyEmail(std::string ID, std::string s)
{
  AccountNode<T> *p = head;
  while (p != NULL)
  {
    if (p->data.ID == ID)
    {
      p->data.email = s;
      return true;
    }
    p = p->next;
  }
  return false;
};

// ͨ��ID���ҵ���Ӧ���˻����޸ĵ绰Ϊs
template <typename T>
bool AccountList<T>::modifyPhone(std::string ID, std::string s)
{

  AccountNode<T> *p = head;
  while (p != NULL)
  {
    if (p->data.ID == ID)
    {
      p->data.phone = s;
      return true;
    }
    p = p->next;
  }
  return false;
};

// ͨ��ID���ҵ���Ӧ���˻������ӽ��money
template <typename T>
bool AccountList<T>::deposite(std::string ID, float money)
{
  AccountNode<T> *p = head; // ʹ�����Ͳ���T
  while (p != NULL)
  {
    if (p->data.ID == ID)
    {
      p->data.balance += money;
      return true;
    }
    p = p->next;
  }
  return false;
};

// ͨ��ID���ҵ���Ӧ���˻������ٽ��money
// �ɹ�ȡǮ����true, ʧ�ܷ���false
template <typename T>
bool AccountList<T>::withdraw(std::string ID, float money)
{
  AccountNode<T> *p = head;
  while (p != NULL)
  {
    if (p->data.ID == ID)
    {
      p->data.balance -= money;
      return true;
    }
    p = p->next;
  }
  return false;
};

// ͨ��ID���ҵ���Ӧ���˻���ɾ���û�
// �ɹ�ɾ������true, ʧ�ܷ���false
template <typename T>
bool AccountList<T>::deleteaccount(std::string ID)
{
  AccountNode<T> *p = head->next; // ʹ�����Ͳ���T
  AccountNode<T> *last = head;

  // ѭ�����Ҳ�ɾ���ڵ�
  while (p != NULL)
  {
    if (p->data.ID == ID)
    {
      last->next = p->next; // ����ǰ���ڵ�
      delete p;             // ɾ����ǰ�ڵ�
      return true;          // ����ɾ���ɹ�
    }
    last = p;    // ǰ���ڵ����
    p = p->next; // ��ǰ�ڵ����
  }
  return false; // û���ҵ�Ҫɾ���Ľڵ㣬����ɾ��ʧ��
}
template <typename T>
int AccountList<T>::length()
{
  AccountNode<T> *p = head;
  int num = 0;
  while (p != NULL)
  {
    p = p->next;
    num++;
  }
  return num;
}

template <typename T>                             // ģ������
std::vector<Account> AccountList<T>::listtovector() // ʹ�����Ͳ���T
{
    AccountNode<T>* p = head->next; // ʹ�����Ͳ���T
    int num = length();
    std::vector<Account> v1(num);
    while (p != NULL)
    {
        v1.push_back(p->data);
        p = p->next;
    }
    /*������
    for (std::vector<Account>::iterator iter = v1.begin(); iter != v1.end(); iter++)
    {
        Account a = *iter;
        std::cout << a;
    }*/
    return v1;
}

template <typename T>                             // ģ������
bool AccountList<T>::savetxt() // ʹ�����Ͳ���T
{
    std::ofstream fout;
    fout.open("accountlist.txt");
    if (!(fout.is_open()))
    {
        std::cout << "�ļ���ʧ�ܣ�" << std::endl;
        return false;
    }
    AccountNode<T>* p = head->next; // ʹ�����Ͳ���T
    int num = length();
    while (p != NULL)
    {
        std::string ID = p->data.ID;
        std::string name = p->data.name;
        std::string phone = p->data.phone;
        std::string email = p->data.email;
        std::string IDCard = p->data.IDCard;
        float balance = p->data.balance;
        bool manager = p->data.manager;
        fout << ID << " " << name << " " << phone << " " << email << " " << IDCard << " " << balance << " " << manager << std::endl;
        p = p->next;
    }
    fout.close();
}

#endif
