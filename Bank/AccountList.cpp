#include "AccountList.h"

void AccountList::add(Account account)
{
	AccountNode* p = new AccountNode;
	p = head;
	for (; p->next != NULL; p = p->next);
	AccountNode* temp = new AccountNode;
	temp->data = account;
	p->next = temp;

}
