#include<iostream>
#include "Account.h"
std::ostream& operator<<(std::ostream& out, const Account& a) {

    out << "�˻�ID: " << a.ID << "\n";
    out << "����: " << a.name << "\n";
    out << "�绰: " << a.phone << "\n";
    out << "����: " << a.email << "\n";
    out << "���֤: " << a.IDCard << "\n";
    out << "���п�: " << a.Card << "\n";
    out << "���: " << a.balance << "\n";
    out << "VIP�û���" << (a.vip == 0 ? "��\n" : "��\n");
    return out;
}