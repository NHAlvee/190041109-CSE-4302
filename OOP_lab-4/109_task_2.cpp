#include <bits/stdc++.h>

using namespace std;
class BankAccount
{
private:
    int acc_num;
    string holder_name;
    string acc_type;
    double current_balance;
    double minimun_balance;

public:
    BankAccount()
    {

    }
    BankAccount(int iacc_num, string iname, string itype, double icurr_balance, double imin_balance)
    {
        acc_num = iacc_num;
        holder_name = iname;
        acc_type = itype;
        current_balance = icurr_balance;
        minimun_balance = imin_balance;
    }
    void set_info(int iacc_num, string iname, string itype, double icurr_balance, double imin_balance)
    {
        acc_num = iacc_num;
        holder_name = iname;
        acc_type = itype;
        current_balance = icurr_balance;
        minimun_balance = imin_balance;
    }
    void showInfo() const
    {
        cout << "Account number: " << acc_num << endl;
        cout << "Account holder name: " << holder_name << endl;
        cout << "Account type: " << acc_type << endl;
        cout << "Current balance: " << current_balance << endl;
        cout << "Minimun balance: " << minimun_balance << endl;
    }
    void showBalance()
    {
        cout << "Current balance: " << current_balance << endl;
    }
    void deposit(double depo)
    {
        current_balance += depo;
    }
    void withdraw(double withd)
    {
        if (minimun_balance <= (current_balance - withd))
            current_balance -= withd;
        else
            cout << "cannot withdraw this much money" << endl;
    }
    double givInterest(double irate=2.5)
    {
        double interest;
        interest=current_balance*(irate/100);
        deposit(interest*.9);
        return interest;
    }
    ~BankAccount()
    {
        cout<<"Account of Mr. "<<holder_name<<" with account no. "<<acc_num<<" is destroyed with a balance "<<current_balance<<endl;
    }
};
int main()
{
    BankAccount acc1,acc2(1,"abc","current",20000.00,500.00);
    acc2.givInterest(3.5);
    acc2.showInfo();
    acc1.set_info(2,"xyz","savings",30000,500);
    acc1.showInfo();
    acc1.deposit(600.00);
    acc1.showBalance();
    acc1.withdraw(400.00);
    acc1.showInfo();
    return 0;
}