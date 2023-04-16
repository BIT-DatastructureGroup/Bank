#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>

class Account {
private:

public:
	Account() { ID = "0"; name = "0"; phone = "0"; email = "0"; IDCard = "0"; Card = "0"; balance = 0; }
	Account(std::string id, std::string na, std::string ph, std::string em, std::string IDC, std::string Ca, float ba) {
		ID = id; name = na; phone = ph; email = em; IDCard = IDC; Card = Ca; balance = ba;
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
};
#endif