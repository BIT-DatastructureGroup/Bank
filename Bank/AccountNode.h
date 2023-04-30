#ifndef ACCOUNTNODE_H
#define ACCOUNTNODE_H
#include "Account.h"
template <typename T> //模板声明
class AccountNode //类名
{
public:
	T data; //使用类型参数T作为数据类型
	AccountNode* next; //指针域
	AccountNode() { next = NULL; } //构造函数
};
#endif
