#ifndef ACCOUNTNODE_H
#define ACCOUNTNODE_H
#include "Account.h"
template <typename T> //ģ������
class AccountNode //����
{
public:
	T data; //ʹ�����Ͳ���T��Ϊ��������
	AccountNode* next; //ָ����
	AccountNode() { next = NULL; } //���캯��
};
#endif
