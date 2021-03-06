#ifndef SAVINGS_BANK_ACCOUNT_H_INCLUDED
#define SAVINGS_BANK_ACCOUNT_H_INCLUDED

#include "bank_account.h"

using namespace std;

class Savings_Bank_Account : public Bank_Account {
    private:
        static int Number_Of_Accounts;
        float intrest_rate;
        int period;
    public:
        Savings_Bank_Account(): Bank_Account(), intrest_rate(0), period(0) {Number_Of_Accounts ++;}
        Savings_Bank_Account(const Bank_Account& bank_account, float intrest_rate, int period): Bank_Account(bank_account), intrest_rate(intrest_rate), period(period) {Number_Of_Accounts ++;}
        Savings_Bank_Account(string first_name, string last_name, string cnp, string email, string phone_number, int day, int month, int year, float Current_Balance, float intrest_rate, int period): Bank_Account(first_name, last_name, cnp, email, phone_number, day, month, year, Current_Balance), intrest_rate(intrest_rate), period(period) {Number_Of_Accounts++;}
        Savings_Bank_Account(const Savings_Bank_Account& bank_account)
        {
            this->first_name = bank_account.first_name;
            this->last_name = bank_account.last_name;
            this->cnp = bank_account.cnp;
            this->email = bank_account.cnp;
            this->phone_number = bank_account.phone_number;
            this->Open_Date = bank_account.Open_Date;
            this->Current_Balance = bank_account.Current_Balance;
            this->intrest_rate = bank_account.intrest_rate;
            this->period = bank_account.period;
            for(pair < int, Date > it : bank_account.Transaction_History)
                this->Transaction_History.push_back({it.first, it.second});
            Number_Of_Accounts ++;
        }
        ~Savings_Bank_Account() {Number_Of_Accounts --;}

        float getIntrestRate() const {return intrest_rate;}
        int getPeriod() const {return period;}
        void setIntrestRate(float intrest_rate) {this->intrest_rate = intrest_rate;}
        void setPeriod(int period) {this->period = period;}

        void AddIntrest(Date date) {this->Current_Balance = this->Current_Balance * (1 + this->intrest_rate); Transaction_History.push_back({this->Current_Balance, date});}
        void Make_Transaction(float ammount, Date date)
        {
            if(ammount < 0 && Current_Balance < -1 * ammount)
                throw "Insufficient funds\n";
            Current_Balance += ammount;
            Transaction_History.push_back({this->Current_Balance, date});
        }


        Savings_Bank_Account& operator= (const Savings_Bank_Account& bank_account)
        {
            this->first_name = bank_account.first_name;
            this->last_name = bank_account.last_name;
            this->cnp = bank_account.cnp;
            this->email = bank_account.cnp;
            this->phone_number = bank_account.phone_number;
            this->Open_Date = bank_account.Open_Date;
            this->Current_Balance = bank_account.Current_Balance;
            this->intrest_rate = bank_account.intrest_rate;
            this->period = bank_account.period;
            while(!this->Transaction_History.empty())
                this->Transaction_History.pop_back();
            for(pair < int, Date > it : bank_account.Transaction_History)
                this->Transaction_History.push_back({it.first, it.second});
            return *this;
        }
        static int getAccountsNumber() {return Number_Of_Accounts;}

        friend istream& operator>> (istream&, Savings_Bank_Account&);
        friend ostream& operator<< (ostream&, const Savings_Bank_Account&);

        void Print()
        {
            cout << first_name << ' ' << last_name << ' ' << cnp << ' ' << phone_number << ' ' << Open_Date << ' ' << Current_Balance << ' ' << intrest_rate << ' ' << period;
        }

        void Read()
        {
            cin >> first_name >> last_name >> cnp >> email >> phone_number >> Open_Date >> Current_Balance >> intrest_rate >> period;
        }
};

istream& operator>> (istream& in, Savings_Bank_Account& account)
{
    in >> account.first_name >> account.last_name >> account.cnp >> account.email >> account.phone_number >> account.Open_Date >> account.Current_Balance >> account.intrest_rate >> account.period;
    return in;
}

ostream& operator<< (ostream& out, const Savings_Bank_Account& account)
{
    out << account.first_name << ' ' << account.last_name << ' ' << account.cnp << ' ' << account.email << ' ' << account.phone_number << ' ' << account.Open_Date << ' ' << account.Current_Balance << ' ' << account.intrest_rate << ' ' << account.period;
    return out;
}

int Savings_Bank_Account::Number_Of_Accounts = 0;

#endif // SAVINGS_BANK_ACCOUNT_H_INCLUDED
