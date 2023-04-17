// Bank.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include"string"
#include"Account.h"
#include"AccountList.h"
#include"AccountManager.h"
#include"AccountNode.h"
using namespace std;
int main()
{

    AccountManager AccountManager1;    //创建账户管理类，程序开始运行（同时读取文件，在类的构造函数中运行）
    while(1)
    { 
        cout << "欢迎来到数字银行！请选择您要进行的操作：" << endl;
        cout << "若已有账户，请输入数字1进行登录；若没有账户，请输入数字2申请开户;若要退出系统，请输入数字3" << endl;
        int load1 = 0, load2 = 0;
        cin >> load1;
        if (load1 == 3)    //退出系统
        {
            break;
        }
        if (load1 == 1)    //登录
        {
            cout << "*--------------------------------------------------------------------------*" << endl;
            cout << "若选择客户登录，请输入数字1；若选择管理员登录，请输入数字2" << endl;
            cout << "请选择登录方式：";
            cin >> load2;
            if (load2 == 1)    //客户登录
            {
                cout << "*--------------------------------------------------------------------------*" << endl;
                string ID1;
                Account temploaduse;   //临时登录用于判定登录;
                cout << "注：若要退出登录操作，请输入“退出”" << endl;
                cout << "请输入您的ID（身份标识号）进行登录：";

                //成功登录

                while (1)
                {
                    cin >> ID1;
                    if (ID1 == "退出") { break; }
                    if (AccountManager1.QueryById(ID1, temploaduse))
                    {
                        cout << "登录成功！" << "欢迎" << temploaduse.name << "登录系统！" << endl;
                        cout << "*--------------------------------------------------------------------------*" << endl;

                        //操作的选择
                        while (1)
                        {
                            int choice = 0;
                            cout << "如需存款，请输入数字1" << endl;
                            cout << "如需取款，请输入数字2" << endl;
                            cout << "如需查询账户信息，请输入数字3" << endl;
                            cout << "如需修改账户信息，请输入数字4" << endl;
                            cout << "如需销户，请输入数字5" << endl;
                            cout << "请选择您要进行的操作：";
                            cin >> choice;
                            if (choice == 1)   //存款
                            {
                                cout << "*--------------------------------------------------------------------------*" << endl;
                                while (1)
                                {
                                    int money_in = 0;
                                    cout << "请输入存款的金额：";
                                    cin >> money_in;
                                    if (money_in >= 0)
                                    {
                                        cout << "存款成功！您现在的账户余额为" << temploaduse.balance << endl;
                                        cout << "若要继续存款，请输入数字1；若要退出存款操作，请输入数字2：";
                                        int judge1 = 0;
                                        cin >> judge1;
                                        if (judge1 == 2)
                                        {
                                            cout << "*--------------------------------------------------------------------------*" << endl;
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        cout << "金额错误！请输入合法的金额！" << endl;
                                    }
                                }
                            }
                            else if (choice == 2)   //取款
                            {
                                cout << "*--------------------------------------------------------------------------*" << endl;
                                while (1)
                                {
                                    int money_out = 0;
                                    cout << "请输入取款的金额：";
                                    cin >> money_out;
                                    if (money_out >= 0)
                                    {
                                        //余额足够
                                        if (temploaduse.balance > money_out)
                                        {
                                            temploaduse.balance -= money_out;
                                            cout << "取款成功！您现在的账户余额为" << temploaduse.balance << endl;
                                            cout << "若要继续取款，请输入数字1；若要退出取款操作，请输入数字2：";
                                            int judge1 = 0;
                                            cin >> judge1;
                                            if (judge1 == 2)
                                            {
                                                break;
                                            }
                                        }
                                        //余额不足
                                        else
                                        {
                                            cout << "取款失败！您的余额不足！";
                                            cout << "若要继续取款，请输入数字1；若要退出取款操作，请输入数字2：";
                                            int judge2 = 0;
                                            cin >> judge2;
                                            if (judge2 == 2)
                                            {
                                                cout << "*--------------------------------------------------------------------------*" << endl;
                                                break;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        cout << "金额错误！请输入合法的金额！" << endl;
                                    }
                                }
                                break;
                            }
                            else if (choice == 3)   //查询账户信息
                            {
                                cout << "*--------------------------------------------------------------------------*" << endl;
                                cout << "身份标识号：" << temploaduse.ID << endl;
                                cout << "姓名：" << temploaduse.name << endl; 
                                cout << "手机号：" << temploaduse.phone << endl;
                                cout << "邮箱：" << temploaduse.email << endl;
                                cout << "身份证号：" << temploaduse.IDCard << endl;
                                cout << "银行卡号：" << temploaduse.Card << endl;
                                cout << "账户余额：" << temploaduse.balance << endl;
                                cout << "*--------------------------------------------------------------------------*" << endl;
                            
                            }
                            else if (choice == 4)   //修改账户信息
                            {
                                cout << "*--------------------------------------------------------------------------*" << endl;
                                //选择修改内容
                                int temp3 = 0;   
                                while (1)
                                {
                                    cout << "若需修改身份标识号，请输入数字1" << endl;
                                    cout << "若需修改账户姓名，请输入数字2" << endl;
                                    cout << "若需修改账户手机号，请输入数字3" << endl;
                                    cout << "若需修改账户邮箱，请输入数字4" << endl;
                                    cout << "若需修改账户身份证号，请输入数字5" << endl;
                                    cout << "您需要修改的内容是：";
                                    cin >> temp3;
                                    if (temp3 == 1)
                                    {
                                        cout << "请输入更改后的身份标识号：";
                                        string tempchange1;
                                        cin >> tempchange1;
                                        temploaduse.ID = tempchange1;
                                        cout << "已完成修改" << endl;
                                    }
                                    else if (temp3 == 2)
                                    {
                                        cout << "请输入更改后的姓名：";
                                        string tempchange2;
                                        cin >> tempchange2;
                                        temploaduse.name = tempchange2;
                                        cout << "已完成修改" << endl;
                                    }
                                    else if (temp3 == 3)
                                    {
                                        cout << "请输入更改后的手机号：";
                                        string tempchange3;
                                        cin >> tempchange3;
                                        temploaduse.phone = tempchange3;
                                        cout << "已完成修改" << endl;
                                    }
                                    else if (temp3 == 4)
                                    {
                                        cout << "请输入更改后的邮箱：";
                                        string tempchange4;
                                        cin >> tempchange4;
                                        temploaduse.email = tempchange4;
                                        cout << "已完成修改" << endl;
                                    }
                                    else if (temp3 == 5)
                                    {
                                        cout << "请输入更改后的身份标识号：";
                                        string tempchange5;
                                        cin >> tempchange5;
                                        temploaduse.IDCard = tempchange5;
                                        cout << "已完成修改" << endl;
                                    }
                                    int judge3 = 0;
                                    cout << "尊敬的" << temploaduse.name << "，您是否需要进行其他修改？如需继续，请输入数字1，如需返回主页面，请输入数字2" << endl;
                                    cout << "您的选择是：";
                                    cin >> judge3;
                                    if (judge3 == 2)
                                    {
                                        cout << "*--------------------------------------------------------------------------*" << endl;
                                        break;
                                    }
                                }
                            }
                            else if (choice == 5)  //销户
                            {
                                cout << "*--------------------------------------------------------------------------*" << endl;
                                cout << "您确定要进行销户操作吗？如确定，请输入数字1,取消请输入0" << endl;
                                int judge4 = 0;
                                cin >> judge4;
                                if (judge4 == 1)
                                {
                                    if (AccountManager1.DeleteUser(temploaduse))
                                    {
                                        cout << "销户成功！" << endl;
                                        cout << "即将退出系统！";
                                        cout << "*--------------------------------------------------------------------------*" << endl;
                                        break;
                                    }
                                    else
                                    {
                                        cout << "销户失败！系统异常！" << endl;
                                    }
                                }
                            }
                            cout << "尊敬的" << temploaduse.name << "，您是否需要进行其他操作？如需继续，请输入数字1，如需安全退出，请输入数字2" << endl;
                            cout << "您的选择是：";
                            int judge2 = 0;
                            cin >> judge2;
                            if (judge2 == 2)
                            {
                                cout << "*--------------------------------------------------------------------------*" << endl;
                                cout << "您已经安全退出，欢迎下次登录！" << endl;
                                break;
                            }
                        }
                        break;    //成功登录了，退出反复查验ID输入正确与否的循环
                    }

                    //登录失败,重新输入
                    else
                    {
                        cout << "未查询到此ID账户，登录失败，请重新输入ID账号!" << endl;
                    }
                }
            }
            if (load2 == 2)    //TODO：管理员登录
            {
                cout << "*--------------------------------------------------------------------------*" << endl;
                cout << "请输入您的账户ID：";
                Account temploaduse2;
                string ID2;
                while(1)
                { 
                    cin >> ID2;
                    if (AccountManager1.QueryById(ID2, temploaduse2))
                    {
                        if (temploaduse2.Manager == 0)       //非管理员账号登录失败
                        {
                            cout << "您的账户非管理员账户，请重新输入管理员账户！" << endl;

                        }
                        if (temploaduse2.Manager == 1)      //管理员账号登录成功
                        {
                            cout << "管理员" << temploaduse2.name << "登录成功！" << endl;
                             while(1)
                             { 
                                cout << "如需进行浏览全部账户信息，请输入数字1" << endl;
                                cout << "如需进行查询特定账户信息，请输入数字2" << endl;
                                cout << "请选择您要进行的操作：";
                                int choice2 = 0;
                                cin >> choice2;
                                if (choice2 == 1)
                                {
                                    AccountManager1.getAccounts();
                                }
                                if (choice2 == 2)
                                {
                                    cout << "请输入您要查找对象的相关信息（可输入ID、姓名、身份证号）：";
                                    string blur;
                                    cin >> blur;
                                    AccountManager1.QueryBlur(blur);
                                }
                                cout << "您是否还需要进行其他操作？若继续操作，请输入数字1，若要退出账号，请输入数字2" << endl;
                                cout << "您的选择是：";
                                int judge5 = 0;
                                cin >> judge5;
                                if (judge == 2)
                                {
                                    cout << "已安全退出账号！" << endl;
                                    cout << "*--------------------------------------------------------------------------*" << endl;
                                    break;
                                }
                             }
                            break;   //退出判断是否是管理员账号的循环
                        }
                    }
                    else
                    {
                        cout << "未查询到此ID账户，登录失败，请重新输入ID账号!" << endl;
                    }
                }
            }
        }
        if (load1 == 2)    //申请开户
        {
            while (1)
            {
                cout << "请按顺序输入您的ID（身份标识号）、姓名、电话号码、邮箱、身份证号码、是否为管理员（是输入1,不是则输入0）：(若想退出开户操作，请输入“退出”)";
                string ID, name, phone, mail, IDCard;
                int Manager = 3;
                cin >> ID >> name >> phone >> mail >> IDCard>>Manager ;
                if (ID == "退出")  //退出创立操作
                {
                    break;
                }
                //搜索一下看看ID是否重复
                Account tempac;
                while (1)
                {
                    if (AccountManager1.QueryById(ID, tempac))     //若ID重复，则重新输入ID账号
                    {
                        cout << "账户名重复！请重新输入ID（身份标识号）：";
                        cin >> ID;
                    }
                    else
                    {
                        break;
                    }
                }
                if (AccountManager1.CreateAccount(ID, name, phone, mail, IDCard,Manager))
                {
                    cout << "账户建立成功！欢迎登录！";
                    cout << "*--------------------------------------------------------------------------*" << endl;
                    break;
                }
                else
                {
                    cout << "账户建立失败！请重试！" << endl;
                }
            }
        }
    }
}
