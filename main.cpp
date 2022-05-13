#include <iostream>
#include <fstream>
#include "account_management.h"
#include <cstring>

using namespace std;


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

void AddBankAccount(istream& in, Account_Management < Bank_Account >& Accounts, bool ok)
{
    printf("Specify the type of account: Savings/Current\n");
    char s[20];
    in.get();
    in.getline(s, 20);
    if(!strcmp(s, "Savings"))
    {
        if(ok)
            printf("Introduce the details of the account: <First Name> <Last Name> <CNP> <Email> <Phone Number> <day> <month> <year> <balance> <interest rate> <period>\n");
        string first_name, last_name, cnp, email, phone_number;
        int day, month, year, period;
        float balance, intrest_rate;
        in >> first_name >> last_name >> cnp >> email >> phone_number >> day >> month >> year >> balance >> intrest_rate >> period;
        Savings_Bank_Account* pointer = new Savings_Bank_Account(first_name, last_name, cnp, email, phone_number, day, month, year, balance, intrest_rate, period);
        Accounts += pointer;
    }
    else
    {
        if(ok)
            printf("Introduce the details of the account: <First Name> <Last Name> <CNP> <Email> <Phone Number> <day> <month> <year> <balance> <monthly free transactions> <commission>\n");
        string first_name, last_name, cnp, email, phone_number;
        int day, month, year, monthly_free_transactions;
        float balance, commission;
        in >> first_name >> last_name >> cnp >> email >> phone_number >> day >> month >> year >> balance >> monthly_free_transactions >> commission;
        Accounts.addCurrentBankAccount(first_name, last_name, cnp, email, phone_number, day, month, year, balance, monthly_free_transactions, 0, 0, commission);
    }
}

void ShowBankAccount(Account_Management < Bank_Account >& Accounts)
{
    int index;
    printf("Specify the index: ");
    cin >> index;
    try
    {
        Accounts.showBankAccount(index, cout);
    }
    catch (indexException& Exception)
    {
        cout << Exception.what() << '\n';
    }
}

void ShowAllBankAccounts(Account_Management < Bank_Account >& Accounts)
{
    cout << Accounts;
}

void DeleteBankAccount(Account_Management < Bank_Account >& Accounts)
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

void DeleteAllBankAccounts(Account_Management < Bank_Account >& Accounts)
{
    while(!Accounts.isEmpty())
        Accounts.DeleteBankAccount(1);
    cout << "Accounts successfully deleted\n";
}

void PrintNrSavingsAccounts(Account_Management < Bank_Account >& Accounts)
{
    cout << "The number of Saving Bank Accounts is: "<<Savings_Bank_Account::getAccountsNumber() << '\n';
}

void PrintNrCurrentAccounts(Account_Management < Bank_Account >& Accounts)
{
    cout << "The number of Current Bank Accounts is: "<<Current_Bank_Account::getAccountsNumber() << '\n';
}

void PrintSavingAccounts(Account_Management < Bank_Account >& Accounts)
{
    Accounts.ShowYearlySavingsAccounts();
}

void addBalance(Account_Management < Bank_Account >& Accounts)
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

void printTransactionHistory(Account_Management < Bank_Account >& Accounts)
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

void EXIT(Account_Management < Bank_Account >& Accounts)
{
    int n;
    ofstream out("data.txt");
    n = Accounts.getCurrentAccountsNumber() + Accounts.getSavingsAccountsNumber();
    out << n << '\n';
    for(int i = 1; i <= n; i++)
        if(Accounts.AccountType(i) == 0)
        {
            out << "Savings\n";
            Accounts.showBankAccount(i, out);
        }
        else
        {
            out << "Current\n";
            Accounts.showBankAccount(i, out);
        }
    out.close();
}

void Run()
{
    Account_Management < Bank_Account > Accounts;

    ifstream in("data.txt");
    int n;
    in >> n;
    for(int i = 1; i <= n; i++)
        AddBankAccount(in, Accounts, 0);
    in.close();

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
                    AddBankAccount(cin, Accounts, 1);
                    break;
                }
            case 2:
                {
                    ShowBankAccount(Accounts);
                    break;
                }
            case 3:
                {
                    ShowAllBankAccounts(Accounts);
                    break;
                }
            case 4:
                {
                    DeleteBankAccount(Accounts);
                    break;
                }
            case 5:
                {
                    DeleteAllBankAccounts(Accounts);
                    break;
                }
            case 6:
                {
                    PrintNrSavingsAccounts(Accounts);
                    break;
                }
            case 7:
                {
                    PrintNrCurrentAccounts(Accounts);
                    break;
                }
            case 8:
                {
                    PrintSavingAccounts(Accounts);
                    break;
                }
            case 9:
                {
                    addBalance(Accounts);
                    break;
                }
            case 10:
                {
                    printTransactionHistory(Accounts);
                    break;
                }
            case 11:
                {
                    EXIT(Accounts);
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
