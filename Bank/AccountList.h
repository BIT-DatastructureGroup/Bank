#ifndef ACCOUNTLIST_H
#define ACCOUNTLIST_H
#include"AccountNode.h"
class AccountList
{
private:

public:
	AccountNode* head;

	// 添加一个新的账户放到链表最后面
	void add(Account account);
};
#endif
