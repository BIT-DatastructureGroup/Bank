#ifndef ACCOUNTLIST_H
#define ACCOUNTLIST_H
#include"AccountNode.h"
class AccountList
{
private:
	AccountNode* head;
public:
	AccountList() { Account a; head->data = a; head->next = NULL; };
	AccountList(Account a) { head->data = a; head->next = NULL; }
	// 添加一个新的账户放到链表最后面
	void add(Account account);
	void showlist();
};
#endif
