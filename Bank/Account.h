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
	void print(){std::cout << "�˻�ID: " << ID << "\n";
	std::cout << "����: " << name << "\n";
	std::cout << "�绰: " << phone << "\n";
	std::cout << "����: " << email << "\n";
	std::cout << "���֤: " << IDCard << "\n";
	std::cout << "���п�: " << Card << "\n";
	std::cout << "���: " << balance << "\n";
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

  // �Ƿ�Ϊ����Ա
  // 0:�� 1:��
  bool manager;
};
#endif