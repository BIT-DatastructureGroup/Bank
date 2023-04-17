#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H
#include <vector>
#include "Account.h"
#include "AccountList.h"
#include<string>
// �˻�������
class AccountManager {
private:
 AccountList<Account> accountList;
public:
  AccountManager() {
    // TODO: ��ȡ�ļ������б���
      
  }

  // �����ļ�
  bool ImportFile();

  // �����ļ�
  bool ExportFile();


  bool CreateAccount(std::string ID, std::string name, std::string phone,
    std::string email, std::string IDCard,bool manager);

  // ģ�����ң�ƥ�����йؼ��֣�����Ա�Ĺ���
   AccountList<Account> QueryBlur(std::string blur);

  // �û���¼��ʱ��ͨ������ID�ҵ�����ȫ����Ϣ
  bool QueryById(std::string ID, Account& out);

  // modifyType = 0 �޸����� 1 ���޸ĵ绰
  // True: �޸ĳɹ� False: �޸�ʧ��
  bool ModifyAccount(Account user ,std::string s, int modifyType);

  // ����
  bool Deposite(Account user, float money);

  // ȡ���
  bool Withdraw(Account user, float money);

  // ����
  bool DeleteUser(Account user);

  // ��ȡ�б�
  AccountList<Account> getAccounts();

};
#endif