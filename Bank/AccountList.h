#ifndef ACCOUNTLIST_H
#define ACCOUNTLIST_H
#include"AccountNode.h"
#include<string>
class AccountList
{
private:
	AccountNode* head;
public:
	AccountList() { head = new AccountNode; Account a; head->data = a; head->next = NULL; };
	AccountList(Account a) { head = new AccountNode; head->data = a; head->next = NULL; }
	// ���һ���µ��˻��ŵ����������
	void add(Account account);
	void showlist();
	bool find(std::string id, Account& out);
};
#endif
