#include "AccountList.h"
#include<iostream>
#include<string>
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
	if (head == NULL)
	{
		std::cout << "¿ÕÁ´±í\n";
		return;
	}
	AccountNode* p = new AccountNode;
	p = head;
	while (p != NULL)
	{
		std::cout << p->data << std::endl;
		p = p->next;
	}
}
bool AccountList::find(std::string id, Account& out)
{
	AccountNode* p = new AccountNode;
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