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
	bool modifyEmail(std::string ID, std::string s);
	bool modifyPhone(std::string ID, std::string s);
	bool deposite(std::string ID, float money);
	bool withdraw(std::string ID, float money);
	bool deleteaccount(std::string ID);
};
template <typename T> //模板声明
void AccountList<T>::add(T account) //使用类型参数T
{
	AccountNode<T>* p = head; //使用类型参数T
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
bool AccountList<T>::modifyEmail(std::string ID, std::string s)
{
	AccountNode<T>* p = head;
	while (p != NULL)
	{
		if (p->data.ID == ID)
		{
			p->data.email=s;
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
	
	AccountNode<T>* p = head;
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
	AccountNode<T>* p = head; //使用类型参数T
	while (p != NULL)
	{
		if (p->data.ID == ID)
		{
			p->data.balance+=money;
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
	AccountNode<T>* p = head;
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
	AccountNode<T>* p = head; //使用类型参数T
	AccountNode<T>* last = NULL;
	// 判断头节点是否需要删除
	if (p != NULL && p->data.ID == ID) {
		head = p->next; // 更新头节点
		delete p; // 删除原头节点
		return true; // 返回删除成功
	}
	// 循环查找并删除节点
	while (p != NULL)
	{
		if (p->data.ID == ID)
		{
			last->next = p->next; // 更新前驱节点
			delete p; // 删除当前节点
			return true; // 返回删除成功
		}
		last = p; // 前驱节点后移
		p = p->next; // 当前节点后移
	}
	return false; // 没有找到要删除的节点，返回删除失败
};

#endif
