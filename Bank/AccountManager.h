#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H
#include <vector>
#include "Account.h"
#include "AccountList.h"
#include<string>
#include<vector>
// 账户管理类
class AccountManager {
private:
 AccountList<Account> accountList;
public:
  AccountManager() {
    ImportFile();
  }

  // 导入文件
  bool ImportFile();

  // 导出文件
  bool ExportFile();


  bool CreateAccount(std::string ID, std::string name, std::string phone,
    std::string email, std::string IDCard,bool manager);

  // 模糊查找，匹配所有关键字，管理员的功能
   std::vector<Account> QueryBlur(std::string blur);

  // 用户登录的时候，通过他的ID找到他的全部信息
  bool QueryById(std::string ID, Account& out);

  // modifyType = 0 修改邮箱 1 是修改电话
  // True: 修改成功 False: 修改失败
  bool ModifyAccount(std::string ID,std::string s, int modifyType);
  bool ModifyAccount(Account &newaccount, std::string s, int modifyType);

  // 存款函数
  bool Deposite(std::string ID, float money);
  bool Deposite(Account &newaccount, float money);

  // 取款函数
  bool Withdraw(std::string ID, float money);
  bool Withdraw(Account &newaccount, float money);

  // 销户
  bool DeleteUser(std::string ID);
  bool DeleteUser(Account newaccount);

  // 获取vector包含目前所有Account
  std::vector<Account> getAccounts();

  //获取当前有多少个账目
  int getnum();
  void findin(std::string ID);
};
#endif