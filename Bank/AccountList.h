#ifndef ACCOUNTLIST_H
#define ACCOUNTLIST_H
#include"AccountNode.h"
#include<string>
#include<iostream>
template <typename T> //类型参数表
class AccountList //类模板名
{
private:
	AccountNode<T>* head; //使用类型参数T作为元素类型
public:
	AccountList() { head = new AccountNode<T>; T a; head->data = a; head->next = NULL; }; //使用类型参数T作为元素类型
	AccountList(T a) { head = new AccountNode<T>; head->data = a; head->next = NULL; } //使用类型参数T作为元素类型
	// 添加一个新的账户放到链表最后面
	void add(T account); //使用类型参数T作为元素类型
	void showlist();
	bool find(std::string id, T& out); //使用类型参数K作为关键字类型，T作为元素类型
};
template <typename T> //模板声明
void AccountList<T>::add(T account) //使用类型参数T
{
	AccountNode<T>* p = new AccountNode<T>; //使用类型参数T
	p = head;
	for (; p->next != NULL; p = p->next);
	AccountNode<T>* temp = new AccountNode<T>; //使用类型参数T
	temp->data = account;
	p->next = temp;
	temp->next = NULL;
}
template <typename T> //模板声明
void AccountList<T>::showlist() //使用类型参数T
{
	if (head == NULL)
	{
		std::cout << "空链表\n";
		return;
	}
	AccountNode<T>* p = new AccountNode<T>; //使用类型参数T
	p = head;
	while (p != NULL)
	{
		std::cout << p->data << std::endl;
		p = p->next;
	}
}
template <typename T> //模板声明
bool AccountList<T>::find(std::string id, T& out) //使用类型参数T
{
	AccountNode<T>* p = new AccountNode<T>; //使用类型参数T
	p = head;
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
void AccountList<T>::modifyEmail(std::string ID, std::string s)
{
	// TODO: 通过ID查找到对应的账户，修改邮箱为s
};

// 通过ID查找到对应的账户，修改电话为s
template <typename T>
void AccountList<T>::modifyPhone(std::string ID, std::string s)
{
	// TODO: 通过ID查找到对应的账户，修改电话为s
};

// 通过ID查找到对应的账户，增加金额money
template <typename T>
void AccountList<T>::deposit(std::string ID, float money)
{
	// TODO: 通过ID查找到对应的账户，增加金额money
};

// 通过ID查找到对应的账户，减少金额money
// 成功取钱返回true, 失败返回false
template <typename T>
bool AccountList<T>::withdraw(std::string ID, float money)
{	
	// TODO: 通过ID查找到对应的账户，增加金额money
	return false;
};

// 通过ID查找到对应的账户，删除用户
// 成功删除返回true, 失败返回false
template <typename T>
bool AccountList<T>::deleteaccount(std::string ID, float money)
{
	// 通过ID查找到对应的账户，删除用户
	return false;
};

#endif
