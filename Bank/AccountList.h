#ifndef ACCOUNTLIST_H
#define ACCOUNTLIST_H
#include"AccountNode.h"
#include<string>
#include<iostream>
template <typename T> //���Ͳ�����
class AccountList //��ģ����
{
private:
	AccountNode<T>* head; //ʹ�����Ͳ���T��ΪԪ������
public:
	AccountList() { head = new AccountNode<T>; T a; head->data = a; head->next = NULL; }; //ʹ�����Ͳ���T��ΪԪ������
	AccountList(T a) { head = new AccountNode<T>; head->data = a; head->next = NULL; } //ʹ�����Ͳ���T��ΪԪ������
	// ���һ���µ��˻��ŵ����������
	void add(T account); //ʹ�����Ͳ���T��ΪԪ������
	void showlist();
	bool find(std::string id, T& out); //ʹ�����Ͳ���K��Ϊ�ؼ������ͣ�T��ΪԪ������
};
template <typename T> //ģ������
void AccountList<T>::add(T account) //ʹ�����Ͳ���T
{
	AccountNode<T>* p = new AccountNode<T>; //ʹ�����Ͳ���T
	p = head;
	for (; p->next != NULL; p = p->next);
	AccountNode<T>* temp = new AccountNode<T>; //ʹ�����Ͳ���T
	temp->data = account;
	p->next = temp;
	temp->next = NULL;
}
template <typename T> //ģ������
void AccountList<T>::showlist() //ʹ�����Ͳ���T
{
	if (head == NULL)
	{
		std::cout << "������\n";
		return;
	}
	AccountNode<T>* p = new AccountNode<T>; //ʹ�����Ͳ���T
	p = head;
	while (p != NULL)
	{
		std::cout << p->data << std::endl;
		p = p->next;
	}
}
template <typename T> //ģ������
bool AccountList<T>::find(std::string id, T& out) //ʹ�����Ͳ���T
{
	AccountNode<T>* p = new AccountNode<T>; //ʹ�����Ͳ���T
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

// ͨ��ID���ҵ���Ӧ���˻����޸�����Ϊs
template <typename T>
void AccountList<T>::modifyEmail(std::string ID, std::string s)
{
	// TODO: ͨ��ID���ҵ���Ӧ���˻����޸�����Ϊs
};

// ͨ��ID���ҵ���Ӧ���˻����޸ĵ绰Ϊs
template <typename T>
void AccountList<T>::modifyPhone(std::string ID, std::string s)
{
	// TODO: ͨ��ID���ҵ���Ӧ���˻����޸ĵ绰Ϊs
};

// ͨ��ID���ҵ���Ӧ���˻������ӽ��money
template <typename T>
void AccountList<T>::deposit(std::string ID, float money)
{
	// TODO: ͨ��ID���ҵ���Ӧ���˻������ӽ��money
};

// ͨ��ID���ҵ���Ӧ���˻������ٽ��money
// �ɹ�ȡǮ����true, ʧ�ܷ���false
template <typename T>
bool AccountList<T>::withdraw(std::string ID, float money)
{	
	// TODO: ͨ��ID���ҵ���Ӧ���˻������ӽ��money
	return false;
};

// ͨ��ID���ҵ���Ӧ���˻���ɾ���û�
// �ɹ�ɾ������true, ʧ�ܷ���false
template <typename T>
bool AccountList<T>::deleteaccount(std::string ID, float money)
{
	// ͨ��ID���ҵ���Ӧ���˻���ɾ���û�
	return false;
};

#endif
