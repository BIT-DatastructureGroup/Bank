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
	// 添加一个新的账户放到链表最后面
	void add(Account account);
	void showlist();
	bool find(std::string id, Account& out);
};
#endif
