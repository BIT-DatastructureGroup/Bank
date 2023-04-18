#ifndef ACCOUNTLIST_H
#define ACCOUNTLIST_H
#include "AccountNode.h"
#include <string>
#include <iostream>
#include <vector>
#include<fstream>
template <typename T> // 类型参数表
class AccountList     // 类模板名
{
private:
  AccountNode<T> *head; // 使用类型参数T作为元素类型
public:
  AccountList()
  {
    head = new AccountNode<T>;
    T a;
    head->data = a;
    head->next = NULL;
  }; // 使用类型参数T作为元素类型
  AccountList(T a)
  {
    head = new AccountNode<T>;
    head->data = a;
    head->next = NULL;
  } // 使用类型参数T作为元素类型
  // 添加一个新的账户放到链表最后面
  void add(T account); // 使用类型参数T作为元素类型
  void showlist();
  bool find(std::string id, T &out); // 使用类型参数K作为关键字类型，T作为元素类型
  bool modifyEmail(std::string ID, std::string s);
  bool modifyPhone(std::string ID, std::string s);
  bool deposite(std::string ID, float money);
  bool withdraw(std::string ID, float money);
  bool deleteaccount(std::string ID);
  std::vector<Account> listtovector();
  bool savetxt();
  bool loadtxt();

  // TODO: 返回链表中的元素个数
  int length();
};

// 增加新的元素在表的末尾
template <typename T>               // 模板声明
void AccountList<T>::add(T account) // 使用类型参数T
{
  AccountNode<T> *p = head; // 使用类型参数T
  for (; p->next != NULL; p = p->next)
    ;
  AccountNode<T> *temp = new AccountNode<T>; // 使用类型参数T
  temp->data = account;
  p->next = temp;
  temp->next = NULL;
}
template <typename T>           // 模板声明
void AccountList<T>::showlist() // 使用类型参数T
{
  if (head->next == NULL)
  {
    std::cout << "空链表\n";
    return;
  }
  AccountNode<T> *p = head->next; // 使用类型参数T
  while (p != NULL)
  {
    std::cout << p->data << std::endl;
    p = p->next;
  }
}
template <typename T>                             // 模板声明
bool AccountList<T>::find(std::string id, T &out) // 使用类型参数T
{
  AccountNode<T> *p = head; // 使用类型参数T
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

// 通过ID查找到对应的账户，修改邮箱为s
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

// 通过ID查找到对应的账户，修改电话为s
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

// 通过ID查找到对应的账户，增加金额money
template <typename T>
bool AccountList<T>::deposite(std::string ID, float money)
{
  AccountNode<T> *p = head; // 使用类型参数T
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

// 通过ID查找到对应的账户，减少金额money
// 成功取钱返回true, 失败返回false
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

// 通过ID查找到对应的账户，删除用户
// 成功删除返回true, 失败返回false
template <typename T>
bool AccountList<T>::deleteaccount(std::string ID)
{
  AccountNode<T> *p = head->next; // 使用类型参数T
  AccountNode<T> *last = head;

  // 循环查找并删除节点
  while (p != NULL)
  {
    if (p->data.ID == ID)
    {
      last->next = p->next; // 更新前驱节点
      delete p;             // 删除当前节点
      return true;          // 返回删除成功
    }
    last = p;    // 前驱节点后移
    p = p->next; // 当前节点后移
  }
  return false; // 没有找到要删除的节点，返回删除失败
}

// 返回链表中元素个数
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

//将链表转为vector返回
template <typename T>                             // 模板声明
std::vector<Account> AccountList<T>::listtovector() // 使用类型参数T
{
    AccountNode<T>* p = head->next; // 使用类型参数T
    int num = length();
    std::vector<Account> v1(num);
    while (p != NULL)
    {
        v1.push_back(p->data);
        p = p->next;
    }
    /*测试用
    for (std::vector<Account>::iterator iter = v1.begin(); iter != v1.end(); iter++)
    {
        Account a = *iter;
        std::cout << a;
    }*/
    return v1;
}

//将链表保存为txt
template <typename T>                             // 模板声明
bool AccountList<T>::savetxt() // 使用类型参数T
{
    std::ofstream fout;
    fout.open("accountlist.txt");
    if (!(fout.is_open()))
    {
        std::cout << "文件打开失败！" << std::endl;
        return false;
    }
    AccountNode<T>* p = head->next; // 使用类型参数T
    int num = length();
    while (p != NULL)
    {
        std::string ID = p->data.ID;
        std::string name = p->data.name;
        std::string phone = p->data.phone;
        std::string email = p->data.email;
        std::string IDCard = p->data.IDCard;
        std::string Card = p->data.Card;
        float balance = p->data.balance;
        bool manager = p->data.manager;
        fout << ID << " " << name << " " << phone << " " << email << " " << IDCard << " " << Card << " " << balance << " " << manager << std::endl;
        p = p->next;
    }
    fout.close();
}

//把txt中的文件读取出来
template <typename T>                             // 模板声明
bool AccountList<T>::loadtxt() // 使用类型参数T
{
    std::ifstream fin;
    fin.open("accountlist.txt");
    if (!(fin.is_open()))
    {
        std::cout << "读取数据打开文件失败!" << std::endl;
        return false;
    }
    std::string temp;
    std::cout << "调试中..." << std::endl;
    while (std::getline(fin, temp))
    {
        std::string ID;
        std::string name;
        std::string phone;
        std::string email;
        std::string IDCard;
        std::string Ca;
        std::string strbalance;
        std::string strmanager;
        float balance;
        bool manager;
        std::vector<std::string> v;
        int start, end;
        start = end = 0;
        char dl = ' ';
        while ((start = temp.find_first_not_of(dl, end)) != std::string::npos) {
            end = temp.find(dl, start);
            v.push_back(temp.substr(start, end - start));
        }
        for (int i = 0; i < v.size(); i++) {
            std::cout << v[i] << std::endl;
        }
        ID = v[0];
        name = v[1];
        phone = v[2];
        email = v[3];
        IDCard = v[4];
        Ca = v[5];
        strbalance = v[6];
        strmanager = v[7];
        balance = std::stof(strbalance);
        manager = std::stoi(strmanager);
        
        Account a(ID, name, phone, email, IDCard, Ca,balance, manager);
        add(a);
    }
    std::cout << "调试结束..." << std::endl;
    fin.close();
}
#endif
