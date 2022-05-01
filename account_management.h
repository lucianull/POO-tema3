#ifndef ACCOUNT_MANAGEMENT_H_INCLUDED
#define ACCOUNT_MANAGEMENT_H_INCLUDED

#include "current_bank_account.h"
#include "savings_bank_account.h"

using namespace std;

template <class T> class Account_Management {
    private:
        vector < T* > Bank_Accounts;
    public:
        Account_Management(): Bank_Accounts() {}
        Account_Management(const Account_Management& accounts)
        {
            T* pointer;
            for(auto it : accounts.Bank_Accounts)
            {
                pointer = new T(*it);
                this->Bank_Accounts.push_back(pointer);
            }
        }
        ~Account_Management()
        {
            T* pointer;
            int size = this->Bank_Accounts.size();
            while(!this->Bank_Accounts.empty())
            {
                pointer = this->Bank_Accounts[size - 1];
                this->Bank_Accounts.pop_back();
                size --;
                delete pointer;
            }
        }

        // void addBankAccount(T& bank_account)
        // {
        //     T* pointer = new T(bank_account);
        //     if(Savings_Bank_Account* q = dynamic_cast < Savings_Bank_Account* > (pointer))
        //         cout <<*q << '\n';
        //     this->Bank_Accounts.push_back(pointer);
        // }

        void addSavingsBankAccount(string first_name, string last_name, string cnp, string email, string phone_number, int day, int month, int year, float Current_Balance, float intrest_rate, int period)
        {
            Savings_Bank_Account* pointer = new Savings_Bank_Account(first_name, last_name, cnp, email, phone_number, day, month, year, Current_Balance, intrest_rate, period);
            this->Bank_Accounts.push_back(pointer);
        }

        void addCurrentBankAccount(string first_name, string last_name, string cnp, string email, string phone_number, int day, int month, int year, float Current_Balance, int monthly_free_transactions, int withdrawals, int deposits, float commission)
        {
            Current_Bank_Account* pointer = new Current_Bank_Account(first_name, last_name, cnp, email, phone_number, day, month, year, Current_Balance, monthly_free_transactions, withdrawals, deposits, commission);
            this->Bank_Accounts.push_back(pointer);
        }


        void DeleteBankAccount(int index)
        {
            if(index <= this->Bank_Accounts.size())
            {
                typename vector < T* > :: iterator it = this->Bank_Accounts.begin() + index - 1;
                T* pointer = this->Bank_Accounts[index - 1];
                this->Bank_Accounts.erase(it);
                delete pointer;
            }
            else
                throw "There is no account with this index\n";
        }

        void showBankAccount(int index)
        {
            if(index <= this->Bank_Accounts.size())
            {
                if(Savings_Bank_Account* pointer = dynamic_cast < Savings_Bank_Account* > (this->Bank_Accounts[index - 1]))
                    cout <<*pointer << '\n';
                if(Current_Bank_Account* pointer = dynamic_cast < Current_Bank_Account* > (this->Bank_Accounts[index - 1]))
                    cout << *pointer << '\n';
//                cout << *this->Bank_Accounts[index - 1] << '\n';
            }
            else
            {
                throw "There is no account with this index\n";
            }
        }

        int getSavingsAccountsNumber()
        {
            return Savings_Bank_Account::Number_Of_Accounts;
        }
        int getCurrentAccountsNumber()
        {
            return Current_Bank_Account::Number_Of_Accounts;
        }
        Account_Management& operator+= (T* pointer)
        {
            this->Bank_Accounts.push_back(pointer);
            return *this;
        }
        template <class U>
        friend ostream& operator<<(ostream& out, const Account_Management <U>& accounts);
};

//template <class T >
//Account_Management<T>& operator+= (Account_Management<T>& accounts, const T* pointer)
//{
//    accounts.Bank_Accounts.push_back(pointer);
//    return accounts;
//}

template <class T>
ostream& operator<< (ostream& out, const Account_Management <T>& accounts)
{
    for(T* it : accounts.Bank_Accounts)
    {
        if(Current_Bank_Account* pointer = dynamic_cast < Current_Bank_Account* > (it))
            cout << *pointer << '\n';
        if(Savings_Bank_Account* pointer = dynamic_cast < Savings_Bank_Account* > (it))
            cout << *pointer << '\n';
    }
    return out;
}



#endif // ACCOUNT_MANAGEMENT_H_INCLUDED
