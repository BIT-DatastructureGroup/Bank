#ifndef ACCOUNTLIST_H
#define ACCOUNTLIST_H
#include"AccountNode.h"
class AccountList
{
private:

public:
	AccountNode* head;

	// ���һ���µ��˻��ŵ����������
	void add(Account account);
};
#endif
