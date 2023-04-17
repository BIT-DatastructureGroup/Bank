#include "AccountList.h"
#include<iostream>
void AccountList::add(Account account)
{
	AccountNode* p = new AccountNode;
	p = head;
	for (; p->next != NULL; p = p->next);
	AccountNode* temp = new AccountNode;
	temp->data = account;
	p->next = temp;
	temp->next = NULL;

}
void AccountList::showlist()
{
	if (head->next = NULL)
	{
		std::cout << "¿ÕÁ´±í\n";
		return;
	}
	AccountNode* p = new AccountNode;
	while (p != NULL)
	{
		std::cout << p->data << std::endl;
	}
}
