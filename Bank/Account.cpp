#include<iostream>
#include "Account.h"
std::ostream& operator<<(std::ostream& out, const Account& a) {

    out << "账户ID: " << a.ID << "\n";
    out << "姓名: " << a.name << "\n";
    out << "电话: " << a.phone << "\n";
    out << "邮箱: " << a.email << "\n";
    out << "身份证: " << a.IDCard << "\n";
    out << "银行卡: " << a.Card << "\n";
    out << "余额: " << a.balance << "\n";
    out << "VIP用户：" << (a.vip == 0 ? "否\n" : "是\n");
    return out;
}