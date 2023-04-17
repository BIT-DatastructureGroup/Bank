#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H
#include <vector>
#include "Account.h"
#include "AccountList.h"

// 账户管理类
class AccountManager {
private:
 AccountList accountList;
public:
  AccountManager() {
    // TODO: 读取文件进入列表里
      
  }

  // 导入文件
  bool ImportFile();

  // 导出文件
  bool ExportFile();


  bool CreateAccount(std::string ID, std::string name, std::string phone,
    std::string email, std::string IDCard);

  // 模糊查找，匹配所有关键字，管理员的功能
  std::vector<Account> QueryBlur();

  // 用户登录的时候，通过他的ID找到他的全部信息
  bool QueryById(std::string ID, Account& out);    //要求：查到有此ID，则赋值给out，return true；如果没有则return flase

  // modifyType = 0 修改邮箱 1 是修改电话
  bool ModifyAccount(Account newValue, int modifyType);

  // 存款函数
  bool Deposite(Account user, float money);

  // 取款函数
  bool Withdraw(Account user, float money);

  // 销户
  bool DeleteUser(Account user);

  // 获取列表
  std::vector<Account> getAccounts();

};
#endif