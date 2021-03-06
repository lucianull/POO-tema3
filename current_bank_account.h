#ifndef CURRENT_BANK_ACCOUNT_H_INCLUDED
#define CURRENT_BANK_ACCOUNT_H_INCLUDED

#include "bank_account.h"

using namespace std;

class Current_Bank_Account : public Bank_Account {
    private:
        static int Number_Of_Accounts;
        int monthly_free_transactions, withdrawals, deposits;
        float commission;
    public:
        Current_Bank_Account() : Bank_Account(), monthly_free_transactions(0), withdrawals(0), deposits(0), commission(0) {Number_Of_Accounts ++;}
        Current_Bank_Account(const Bank_Account& bank_account, int monthly_free_transactions, int withdrawals, int deposits, float commission): Bank_Account(bank_account), monthly_free_transactions(monthly_free_transactions), withdrawals(withdrawals), deposits(deposits), commission(commission) {Number_Of_Accounts ++;}
        Current_Bank_Account(string first_name, string last_name, string cnp, string email, string phone_number, int day, int month, int year, float Current_Balance, int monthly_free_transactions, int withdrawals, int deposits, float commission): Bank_Account(first_name, last_name, cnp, email, phone_number, day, month, year, Current_Balance), monthly_free_transactions(monthly_free_transactions), withdrawals(withdrawals), deposits(deposits), commission(commission) {Number_Of_Accounts++;}
        Current_Bank_Account(const Current_Bank_Account& bank_account)
        {
            this->first_name = bank_account.first_name;
            this->last_name = bank_account.last_name;
            this->cnp = bank_account.cnp;
            this->email = bank_account.cnp;
            this->phone_number = bank_account.phone_number;
            this->Open_Date = bank_account.Open_Date;
            this->Current_Balance = bank_account.Current_Balance;
            this->monthly_free_transactions = bank_account.monthly_free_transactions;
            this->withdrawals = bank_account.withdrawals;
            this->deposits = bank_account.deposits;
            this->commission = bank_account.commission;
            for(pair < int, Date > it : bank_account.Transaction_History)
                this->Transaction_History.push_back({it.first, it.second});
            Number_Of_Accounts ++;
        }
        ~Current_Bank_Account() {Number_Of_Accounts --;}

        void setMonthlyFreeTransactions(int monthly_free_transactions) {this->monthly_free_transactions = monthly_free_transactions;}
        void setWithdrawals(int withdrawals) {this->withdrawals = withdrawals;}
        void setDeposits(int deposits) {this->deposits = deposits;}
        void setCommission(float commission) {this->commission = commission;}
        int getMonthlyFreeTransactions() const {return monthly_free_transactions;}
        int getWithdrawals() const {return withdrawals;}
        int getDeposits() const {return deposits;}
        float getCommission() const {return commission;}

        void Make_Transaction(float ammount, bool c, Date date)
        {
            if(ammount == 0)
                return;
            if(Current_Balance + ammount - c * commission < 0)
                throw "Insufficient funds\n";
            Current_Balance += ammount - commission * c;
            if(ammount < 0)
                withdrawals += 1;
            else
                deposits += 1;
            this->Transaction_History.push_back({this->Current_Balance, date});
        }

        Current_Bank_Account& operator= (const Current_Bank_Account& bank_account)
        {
            this->first_name = bank_account.first_name;
            this->last_name = bank_account.last_name;
            this->cnp = bank_account.cnp;
            this->email = bank_account.cnp;
            this->phone_number = bank_account.phone_number;
            this->Open_Date = bank_account.Open_Date;
            this->Current_Balance = bank_account.Current_Balance;
            this->monthly_free_transactions = bank_account.monthly_free_transactions;
            this->withdrawals = bank_account.withdrawals;
            this->deposits = bank_account.deposits;
            this->commission = bank_account.commission;
            while(!this->Transaction_History.empty())
                this->Transaction_History.pop_back();
            for(pair < int, Date > it : bank_account.Transaction_History)
                this->Transaction_History.push_back({it.first, it.second});
            return *this;
        }
        static int getAccountsNumber() {return Number_Of_Accounts;}

        friend istream& operator>> (istream&, Current_Bank_Account&);
        friend ostream& operator<< (ostream&, const Current_Bank_Account&);

        void Print()
        {
            cout << first_name << ' ' << last_name << ' ' << cnp << ' ' << phone_number << ' ' << Open_Date << ' ' << Current_Balance << ' ' << monthly_free_transactions << ' ' << withdrawals << ' ' << deposits << ' ' << commission;
        }

        void Read()
        {
            cin >> first_name >> last_name >> cnp >> phone_number >> Open_Date >> Current_Balance >> monthly_free_transactions >> withdrawals >> deposits >> commission;
        }
};

istream& operator>> (istream& in, Current_Bank_Account& account)
{
    in >> account.first_name >> account.last_name >> account.cnp >> account.phone_number >> account.Open_Date >> account.Current_Balance >> account.monthly_free_transactions >> account.withdrawals >> account.deposits >> account.commission;
    return in;
}

ostream& operator<< (ostream& out, const Current_Bank_Account& account)
{
    out << account.first_name << ' ' << account.last_name << ' ' << account.cnp << ' ' << account.email << ' ' << account.phone_number << ' ' << account.Open_Date << ' ' << account.Current_Balance << ' ' << account.monthly_free_transactions << ' ' << account.withdrawals << ' ' << account.deposits << ' ' << account.commission;
    return out;
}

int Current_Bank_Account::Number_Of_Accounts = 0;


#endif // CURRENT_BANK_ACCOUNT_H_INCLUDED
