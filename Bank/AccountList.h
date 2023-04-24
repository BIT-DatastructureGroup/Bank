#include<iostream>
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
  bool showlist();
  bool find(std::string id, T &out); // ʹ�����Ͳ���K��Ϊ�ؼ������ͣ�T��ΪԪ������
  bool modifyEmail(std::string ID, std::string s);
  bool modifyPhone(std::string ID, std::string s);
  bool deposite(std::string ID, float money);
  bool withdraw(std::string ID, float money);
  bool deleteaccount(std::string ID);
  std::vector<Account> findinfo(std::string information);//����������Ϣ����
  std::vector<Account> listtovector();
  bool savetxt();
  bool loadtxt();
  bool transfermoney(std::string IDin,std::string IDout,float money);
  int length();
};

// �����µ�Ԫ���ڱ��ĩβ
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
bool AccountList<T>::showlist() // ʹ�����Ͳ���T
{
  if (head->next == NULL)
  {
    return false;
  }
  AccountNode<T> *p = head->next; // ʹ�����Ͳ���T
  while (p != NULL)
  {
    std::cout << p->data << std::endl;
    p = p->next;
  }
  return true;
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
template <typename T>
std::vector<Account> AccountList<T>::findinfo(std::string information) // ʹ�����Ͳ���T
{
    AccountNode<T>* p = head; // ʹ�����Ͳ���T
    std::vector<Account> res;
    while (p != NULL)
    {
        if (p->data.ID == information || p->data.phone == information || p->data.email == information || p->data.name == information || p->data.IDCard == information||p->data.Card==information)
        {
           res.push_back(p->data);
        }
        p = p->next;
    }
    return res;
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
      if (p->data.balance > 1000000)
      {
          p->data.vip = 1;
      }
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
        if (p->data.balance < money)
        {
            return false;
        }
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

// ����������Ԫ�ظ���
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
  return num-1;
}

//������תΪvector����
template <typename T>                             // ģ������
std::vector<Account> AccountList<T>::listtovector() // ʹ�����Ͳ���T
{
    AccountNode<T>* p = head->next; // ʹ�����Ͳ���T
    //int num = length();
    std::vector<Account> v1;
    while (p != NULL)
    {
        v1.push_back(p->data);
        p = p->next;
    }

    /*std::cout <<"vector��СΪ��"<< num << std::endl;
    for (std::vector<Account>::iterator iter = v1.begin(); iter != v1.end(); iter++)
    {
        Account a = *iter;
        std::cout << a;
    }*/
    return v1;
}

//��������Ϊtxt
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
        std::string Card = p->data.Card;
        float balance = p->data.balance;
        bool manager = p->data.manager;
        bool vip = p->data.vip;
        fout << ID << " " << name << " " << phone << " " << email << " " << IDCard << " " << Card << " " << balance << " " << manager << " " << vip << std::endl;
        p = p->next;
    }
    fout.close();
}

//��txt�е��ļ���ȡ����
template <typename T>                             // ģ������
bool AccountList<T>::loadtxt() // ʹ�����Ͳ���T
{
    std::ifstream fin;
    fin.open("accountlist.txt");
    if (!(fin.is_open()))
    {
        std::cout << "��ȡ���ݴ��ļ�ʧ��!" << std::endl;
        return false;
    }
    std::string temp;
    //std::cout << "������..." << std::endl;
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
        std::string strvip;
        float balance;
        bool manager;
        bool vip;
        std::vector<std::string> v;
        int start, end;
        start = end = 0;
        char dl = ' ';
        while ((start = temp.find_first_not_of(dl, end)) != std::string::npos) {
            end = temp.find(dl, start);
            v.push_back(temp.substr(start, end - start));
        }
       /* for (int i = 0; i < v.size(); i++) {
            std::cout << v[i] << std::endl;
        }*/
        ID = v[0];
        name = v[1];
        phone = v[2];
        email = v[3];
        IDCard = v[4];
        Ca = v[5];
        strbalance = v[6];
        strmanager = v[7];
        strvip = v[8];
        balance = std::stof(strbalance);
        manager = std::stoi(strmanager);
        vip = std::stoi(strvip);
        
        Account a(ID, name, phone, email, IDCard, Ca,balance, manager,vip);
        add(a);
    }
    //std::cout << "���Խ���..." << std::endl;
    fin.close();
}
template <typename T>
bool AccountList<T>::transfermoney(std::string IDin, std::string IDout, float money)
{
    Account in;
    Account out;
    if (find(IDin, in) && find(IDout, out))
    {
        if (out.vip == 0 ? out.balance * 1.001 : out.balance < money)
        {
            return false;
        }
        out.balance -= out.vip == 0 ? money * 1.001 : money;//1.001���������ѣ��ݶ�0.001��
        in.balance += money;
    }
    return false;
}
#endif
