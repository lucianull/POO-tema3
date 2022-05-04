#include <iostream>
#include <fstream>
#include "account_management.h"
#include <cstring>

using namespace std;

Account_Management < Bank_Account > Accounts;

void PrintMenu()
{
    printf("For calling an instruction you have to specify it and then on the next line you have to introduce the input data\n");
    printf("List of instructions:\n");
    printf("1. Add bank account\n");
    printf("2. Show bank account with a given index\n");
    printf("3. Show all bank accounts\n");
    printf("4. Delete bank account with a given index\n");
    printf("5. Delete all bank accounts");
    printf("6. Print the number of Savings Bank Accounts\n");
    printf("7. Print the number of Current Bank Accounts\n");
    printf("8. Print all Savings Bank Accounts that have the interest period of one year\n");
    printf("9. Exit\n");
}

void AddBankAccount()
{
    printf("Specify the type of account: Savings/Current\n");
    char s[20];
    cin.get();
    cin.getline(s, 20);
    if(!strcmp(s, "Savings"))
    {
        printf("Introduce the details of the account: <First Name> <Last Name> <CNP> <Email> <Phone Number> <day> <month> <year> <balance> <intrest rate> <period>\n");
        string first_name, last_name, cnp, email, phone_number;
        int day, month, year, period;
        float balance, intrest_rate;
        cin >> first_name >> last_name >> cnp >> email >> phone_number >> day >> month >> year >> balance >> intrest_rate >> period;
        Savings_Bank_Account* pointer = new Savings_Bank_Account(first_name, last_name, cnp, email, phone_number, day, month, year, balance, intrest_rate, period);
        Accounts += pointer;
    }
    else
    {
        printf("Introduce the details of the account: <First Name> <Last Name> <CNP> <Email> <Phone Number> <day> <month> <year> <balance> <monthly free transactions> <commission>\n");
        string first_name, last_name, cnp, email, phone_number;
        int day, month, year, period, monthly_free_transactions;
        float balance, intrest_rate, commission;
        cin >> first_name >> last_name >> cnp >> email >> phone_number >> day >> month >> year >> balance >> monthly_free_transactions >> commission;
        Accounts.addCurrentBankAccount(first_name, last_name, cnp, email, phone_number, day, month, year, balance, monthly_free_transactions, 0, 0, commission);
    }
}

void ShowBankAccount() {}

void ShowAllBankAccounts()
{
    cout << Accounts;
}

void DeleteBankAccount() {}

void DeleteAllBankAccounts() {}

void PrintNrSavingsAccounts() {}

void PrintNrCurrentAccounts() {}

void PrintSavingAccounts() {}

void Run()
{
    const char DELIMITER[]="\n<------------------------------------------>\n";
    int option;
    PrintMenu();
    printf("%s", DELIMITER);
    while(true)
    {
        cin >> option;
        switch(option) {
            case 1:
                {
                    AddBankAccount();
                    break;
                }
            case 2:
                {
                    ShowBankAccount();
                    break;
                }
            case 3:
                {
                    ShowAllBankAccounts();
                    break;
                }
            case 4:
                {
                    DeleteBankAccount();
                    break;
                }
            case 5:
                {
                    DeleteAllBankAccounts();
                    break;
                }
            case 6:
                {
                    PrintNrSavingsAccounts();
                    break;
                }
            case 7:
                {
                    PrintNrCurrentAccounts();
                    break;
                }
            case 8:
                {
                    PrintSavingAccounts();
                    break;
                }
            case 9:
                {
                    return ;
                }
        }
        printf("%s", DELIMITER);
    }
}

int main()
{
    Run();




//    // Person* person = new Person("Mitrea", "Razvan", "30232832", "mitrearupetot@gmail.com", "0673737733");
//    // Date* date = new Date(31, 10, 2001);
//    // Bank_Account* bank_account = new Bank_Account(*person, date, 1334);
//    Bank_Account a1;
//    in >> a1;
////    cout << a1;
//    Savings_Bank_Account a2(a1, 30, 12);
//    Account_Management < Bank_Account > a;
//    a.addSavingsBankAccount("Mitrea", "Razvan", "342323232", "mitrearupetot@gmail.com", "032838288", 31, 10, 2001, 1334, 0.034, 12);
//    Current_Bank_Account *p = new Current_Bank_Account("Mitrea", "Razvan", "342323232", "mitrearupetot@gmail.com", "032838288", 31, 10, 2001, 1334, 5, 10, 5, 65);
////    Bank_Account *q = new Bank_Account("Mitrea", "Razvan", "342323232", "mitrearupetot@gmail.com", "032838288", 31, 10, 2001, 1334);
//    a += p;
//    a.addCurrentBankAccount("Mitrea", "Razvan", "342323232", "mitrearupetot@gmail.com", "032838288", 31, 10, 2001, 1334, 5, 10, 5, 5.5);
////    a.showBankAccount(1);
////    a.showBankAccount(2);
//    cout << a;
////    a.addBankAccount(a2);
////    a.showBankAccount(1);
    return 0;
}
