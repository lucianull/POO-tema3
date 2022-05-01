#ifndef ACCOUNT_MANAGEMENT_H_INCLUDED
#define ACCOUNT_MANAGEMENT_H_INCLUDED

#include "current_bank_account.h"
#include "savings_bank_account.h"

using namespace std;

template <typename T> class Account_Management {
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

        void addBankAccount(T& bank_account)
        {
            T* pointer = new T(bank_account);
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
                else
                    cout << "nu e savings\n";
                if(Current_Bank_Account* pointer = dynamic_cast < Current_Bank_Account* > (this->Bank_Accounts[index - 1]))
                    cout << *pointer << '\n';
                else
                    cout << "nu e current\n";
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
        friend Account_Management<T>& operator+= (Account_Management<T>&, const T*);
        friend ostream& operator<< (ostream&, const Account_Management <T>&);
};

template <typename T >
Account_Management<T>& operator+= (Account_Management<T>& accounts, const T* pointer)
{
    accounts.Bank_Accounts.push_back(pointer);
    return accounts;
}

template <typename T>
ostream& operator<< (ostream& out, const Account_Management <T>& accounts)
{
    for(auto it : accounts.Bank_Accounts)
        out << *it << '\n';
    return out;
}



#endif // ACCOUNT_MANAGEMENT_H_INCLUDED
