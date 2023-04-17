#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H
#include <vector>
#include "Account.h"
#include "AccountList.h"

// �˻�������
class AccountManager {
private:
 AccountList accountList;
public:
  AccountManager() {
    // TODO: ��ȡ�ļ������б���
      
  }

  // �����ļ�
  bool ImportFile();

  // �����ļ�
  bool ExportFile();


  bool CreateAccount(std::string ID, std::string name, std::string phone,
    std::string email, std::string IDCard);

  // ģ�����ң�ƥ�����йؼ��֣�����Ա�Ĺ���
  std::vector<Account> QueryBlur();

  // �û���¼��ʱ��ͨ������ID�ҵ�����ȫ����Ϣ
  bool QueryById(std::string ID, Account& out);    //Ҫ�󣺲鵽�д�ID����ֵ��out��return true�����û����return flase

  // modifyType = 0 �޸����� 1 ���޸ĵ绰
  bool ModifyAccount(Account newValue, int modifyType);

  // ����
  bool Deposite(Account user, float money);

  // ȡ���
  bool Withdraw(Account user, float money);

  // ����
  bool DeleteUser(Account user);

  // ��ȡ�б�
  std::vector<Account> getAccounts();

};
#endif