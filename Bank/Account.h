#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>

class Account {
private:

public:
	Account(std::string id, std::string na, std::string ph, std::string em, std::string IDC, std::string Ca, float ba) {
		ID = id; name = na; phone = ph; email = em; IDCard = IDC; Card = Ca; balance = ba;
	}
  // ��ݱ�ʶ��
  std::string ID;

  // ����
  std::string name;

  // �ֻ���
  std::string phone;

  // ����
  std::string email;

  // ���֤��
  std::string IDCard;

  // ���п���
  std::string Card;

  // �˻����
  float balance;
};
#endif