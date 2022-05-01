#ifndef BANK_ACCOUNT_H_INCLUDED
#define BANK_ACCOUNT_H_INCLUDED

#include "person.h"
#include "date.h"
#include <vector>

using namespace std;

class Bank_Account : public Person{
    protected:
        Date Open_Date;
        float Current_Balance;
        vector < pair < int, Date > > Transaction_History;
    public:
        Bank_Account(): Person(), Open_Date(), Current_Balance(0), Transaction_History() {}
        Bank_Account(const Person& Holder, Date& Open_Date, float Current_Balance): Person(Holder), Open_Date(Open_Date), Current_Balance(Current_Balance), Transaction_History() {}
        Bank_Account(const Bank_Account& bank_account)
        {
            this->first_name = bank_account.first_name;
            this->last_name = bank_account.last_name;
            this->cnp = bank_account.cnp;
            this->email = bank_account.cnp;
            this->phone_number = bank_account.phone_number;
            this->Open_Date = bank_account.Open_Date;
            this->Current_Balance = bank_account.Current_Balance;
            for(pair < int, Date > it : bank_account.Transaction_History)
                this->Transaction_History.push_back({it.first, it.second});
        }
        virtual ~Bank_Account()
        {
            while(!Transaction_History.empty())
                Transaction_History.pop_back();
        }

        Bank_Account& operator= (const Bank_Account& bank_account)
        {
            this->first_name = bank_account.first_name;
            this->last_name = bank_account.last_name;
            this->cnp = bank_account.cnp;
            this->email = bank_account.cnp;
            this->phone_number = bank_account.phone_number;
            this->Open_Date = bank_account.Open_Date;
            this->Current_Balance = bank_account.Current_Balance;
            while(!this->Transaction_History.empty())
                this->Transaction_History.pop_back();
            for(pair < int, Date > it : bank_account.Transaction_History)
                this->Transaction_History.push_back({it.first, it.second});
            return *this;
        }
        friend istream& operator>> (istream&, Bank_Account&);
        friend ostream& operator<< (ostream&, const Bank_Account&);

};

istream& operator>> (istream& in, Bank_Account& bank_account)
{
    in >> bank_account.first_name >> bank_account.last_name >> bank_account.cnp >> bank_account.email >> bank_account.phone_number >> bank_account.Open_Date >> bank_account.Current_Balance;
    return in;
}
ostream& operator<< (ostream& out, const Bank_Account& bank_account)
{
    out << bank_account.first_name << ' ' << bank_account.last_name << ' ' << bank_account.cnp << ' ' << bank_account.email << ' ' << bank_account.phone_number << ' ' << bank_account.Open_Date << ' ' << bank_account.Current_Balance;
    return out;
}

#endif // BANK_ACCOUNT_H_INCLUDED