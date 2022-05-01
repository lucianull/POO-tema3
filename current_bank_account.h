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
        Current_Bank_Account() : Bank_Account(), monthly_free_transactions(0), withdrawals(0), deposits(0), commission(0) {Number_Of_Accounts += 1;}
        Current_Bank_Account(const Bank_Account& bank_account, int monthly_free_transactions, int withdrawals, int deposits, float commission): Bank_Account(bank_account), monthly_free_transactions(monthly_free_transactions), withdrawals(withdrawals), deposits(deposits), commission(commission) {Number_Of_Accounts += 1;}
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
            Number_Of_Accounts += 1;
        }
        ~Current_Bank_Account() {Number_Of_Accounts -= 1;}

        void setMonthlyFreeTransactions(int monthly_free_transactions) {this->monthly_free_transactions = monthly_free_transactions;}
        void setWithdrawals(int withdrawals) {this->withdrawals = withdrawals;}
        void setDeposits(int deposits) {this->deposits = deposits;}
        void setCommission(float commission) {this->commission = commission;}
        int getMonthlyFreeTransactions() {return monthly_free_transactions;}
        int getWithdrawals() {return withdrawals;}
        int getDeposits() {return deposits;}
        float getCommission() {return commission;}

        void Make_Transaction(float ammount, bool c)
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

        friend ostream& operator<< (ostream&, const Current_Bank_Account&);
};

ostream& operator<< (ostream& out, const Current_Bank_Account& account)
{
    out << account.first_name << ' ' << account.last_name << ' ' << account.cnp << ' ' << account.cnp << ' ' << account.phone_number << ' ' << account.Open_Date << ' ' << account.Current_Balance << ' ' << account.monthly_free_transactions << ' ' << account.withdrawals << ' ' << account.deposits << ' ' << account.commission;
    return out;
}

int Current_Bank_Account::Number_Of_Accounts = 0;


#endif // CURRENT_BANK_ACCOUNT_H_INCLUDED
