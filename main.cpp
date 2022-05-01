#include <iostream>
#include <fstream>
#include "account_management.h"

using namespace std;

ifstream in("input.in");

int main()
{
    // Person* person = new Person("Mitrea", "Razvan", "30232832", "mitrearupetot@gmail.com", "0673737733");
    // Date* date = new Date(31, 10, 2001);
    // Bank_Account* bank_account = new Bank_Account(*person, date, 1334);
    Bank_Account a1;
    in >> a1;
//    cout << a1;
    Savings_Bank_Account a2(a1, 30, 12);
    Account_Management < Bank_Account > a;
    a.addSavingsBankAccount("Mitrea", "Razvan", "342323232", "mitrearupetot@gmail.com", "032838288", 31, 10, 2001, 1334, 0.034, 12);
    Current_Bank_Account *p = new Current_Bank_Account("Mitrea", "Razvan", "342323232", "mitrearupetot@gmail.com", "032838288", 31, 10, 2001, 1334, 5, 10, 5, 65);
//    Bank_Account *q = new Bank_Account("Mitrea", "Razvan", "342323232", "mitrearupetot@gmail.com", "032838288", 31, 10, 2001, 1334);
    a += p;
    a.addCurrentBankAccount("Mitrea", "Razvan", "342323232", "mitrearupetot@gmail.com", "032838288", 31, 10, 2001, 1334, 5, 10, 5, 5.5);
//    a.showBankAccount(1);
//    a.showBankAccount(2);
    cout << a;
//    a.addBankAccount(a2);
//    a.showBankAccount(1);
    return 0;
}
