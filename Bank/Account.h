#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include<iostream>


class Account {
private:
	friend std::ostream& operator<<(std::ostream& out, const Account& a);
public:
	Account() { ID = "0"; name = "0"; phone = "0"; email = "0"; IDCard = "0"; Card = "0"; balance = 0; manager = 0; }
	Account(std::string id, std::string na, std::string ph, std::string em, std::string IDC, std::string Ca, float ba,bool ma) {
		ID = id; name = na; phone = ph; email = em; IDCard = IDC; Card = Ca; balance = ba; manager = ma;
	}
	void print(){std::cout << "账户ID: " << ID << "\n";
	std::cout << "姓名: " << name << "\n";
	std::cout << "电话: " << phone << "\n";
	std::cout << "邮箱: " << email << "\n";
	std::cout << "身份证: " << IDCard << "\n";
	std::cout << "银行卡: " << Card << "\n";
	std::cout << "余额: " << balance << "\n";
	}
  // 身份标识号
  std::string ID;

  // 姓名
  std::string name;

  // 手机号
  std::string phone;

  // 邮箱
  std::string email;

  // 身份证号
  std::string IDCard;

  // 银行卡号
  std::string Card;

  // 账户余额
  float balance;

  // 是否为管理员
  // 0:否 1:是
  bool manager;
};
#endif