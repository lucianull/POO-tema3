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
    printf("5. Delete all bank accounts\n");
    printf("6. Print the number of Savings Bank Accounts\n");
    printf("7. Print the number of Current Bank Accounts\n");
    printf("8. Print all Savings Bank Accounts that have the interest period of one year\n");
    printf("9. Add balance to a bank account\n");
    printf("10. Print transaction history of a bank account\n");
    printf("11. Exit\n");
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
        int day, month, year, monthly_free_transactions;
        float balance, commission;
        cin >> first_name >> last_name >> cnp >> email >> phone_number >> day >> month >> year >> balance >> monthly_free_transactions >> commission;
        Accounts.addCurrentBankAccount(first_name, last_name, cnp, email, phone_number, day, month, year, balance, monthly_free_transactions, 0, 0, commission);
    }
}

void ShowBankAccount()
{
    int index;
    printf("Specify the index: ");
    cin >> index;
    try
    {
        Accounts.showBankAccount(index);
    }
    catch (indexException& Exception)
    {
        cout << Exception.what() << '\n';
    }
}

void ShowAllBankAccounts()
{
    cout << Accounts;
}

void DeleteBankAccount()
{
    int index;
    printf("Specify the index: ");
    cin >> index;
    try
    {
        Accounts.DeleteBankAccount(index);
        cout << "Account successfully deleted\n";
    }
    catch (indexException& Exception)
    {
        cout << Exception.what() << '\n';
    }
}

void DeleteAllBankAccounts()
{
    while(!Accounts.isEmpty())
        Accounts.DeleteBankAccount(1);
    cout << "Accounts successfully deleted\n";
}

void PrintNrSavingsAccounts()
{
    cout << "The number of Saving Bank Accounts is: "<<Savings_Bank_Account::getAccountsNumber() << '\n';
}

void PrintNrCurrentAccounts()
{
    cout << "The number of Current Bank Accounts is: "<<Current_Bank_Account::getAccountsNumber() << '\n';
}

void PrintSavingAccounts() {}

void addBalance()
{
    Date date;
    int index;
    float amount;
    bool commission;
    printf("Specify the <index> <amount> <day> <month> <year> <commission as a 0 or 1>: ");
    cin >> index >> amount >> date >> commission;
    try
    {
        Accounts.Transaction(index, amount, date, commission);
    }
    catch (indexException& Exception)
    {
        cout << Exception.what() << '\n';
    }
}

void printTransactionHistory()
{
    int index;
    printf("Specify the index: ");
    cin >> index;
    try
    {
        Accounts.PrintTransactions(index);
    }
    catch (indexException& Exception)
    {
        cout << Exception.what() << '\n';
    }
}

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
                    addBalance();
                    break;
                }
            case 10:
                {
                    printTransactionHistory();
                    break;
                }
            case 11:
                {
                    return;
                }
        }
        printf("%s", DELIMITER);
    }
}

int main()
{
    Run();
    return 0;
}
