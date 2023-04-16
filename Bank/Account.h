#pragma once
#include <string>

class Account {
private:

public:
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