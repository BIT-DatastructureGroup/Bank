#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H
#include <vector>
#include "Account.h"
#include "AccountList.h"
#include<string>
#include<vector>
// �˻�������
class AccountManager {
private:
 AccountList<Account> accountList;
public:
  AccountManager() {
    ImportFile();
  }

  // �����ļ�
  bool ImportFile();

  // �����ļ�
  bool ExportFile();


  bool CreateAccount(std::string ID, std::string name, std::string phone,
    std::string email, std::string IDCard,bool manager);

  // ģ�����ң�ƥ�����йؼ��֣�����Ա�Ĺ���
   std::vector<Account> QueryBlur(std::string blur);

  // �û���¼��ʱ��ͨ������ID�ҵ�����ȫ����Ϣ
  bool QueryById(std::string ID, Account& out);

  // modifyType = 0 �޸����� 1 ���޸ĵ绰
  // True: �޸ĳɹ� False: �޸�ʧ��
  bool ModifyAccount(std::string ID,std::string s, int modifyType);
  bool ModifyAccount(Account &newaccount, std::string s, int modifyType);

  // ����
  bool Deposite(std::string ID, float money);
  bool Deposite(Account &newaccount, float money);

  // ȡ���
  bool Withdraw(std::string ID, float money);
  bool Withdraw(Account &newaccount, float money);

  // ����
  bool DeleteUser(std::string ID);
  bool DeleteUser(Account newaccount);

  // ��ȡvector����Ŀǰ����Account
  std::vector<Account> getAccounts();

  //��ȡ��ǰ�ж��ٸ���Ŀ
  int getnum();
  void findin(std::string ID);
};
#endif