#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Person {
    protected:
        string first_name, last_name, cnp, email, phone_number; //check if cnp is 13 digit long
    public:
        Person(): first_name(""), last_name(""), cnp(""), email(""), phone_number("") {}
        Person(string first_name, string last_name, string cnp, string email, string phone_number): first_name(first_name), last_name(last_name), cnp(cnp), email(email), phone_number(phone_number) {}
        Person(const Person & person)
        {
            this->first_name = person.first_name;
            this->last_name = person.last_name;
            this->cnp = person.cnp;
            this->email = person.email;
            this->phone_number = person.phone_number;
        }
        virtual ~Person() {}

        void setFirstName(string first_name) {this->first_name = first_name;}
        void setLastName(string last_name) {this->last_name = last_name;}
        void setCNP(string cnp) {this->cnp = cnp;}
        void setEmail(string email) {this->email = email;}
        void setPhoneNumber(string telephone_number) {this->phone_number = telephone_number;}
        string getFirstName() {return this->first_name;}
        string getLastName() {return this->last_name;}
        string getCNP() {return this->cnp;}
        string getEmail() {return this->email;}
        string getPhoneNumber() {return this->phone_number;}

        Person& operator= (const Person & person)
        {
            this->first_name = person.first_name;
            this->last_name = person.last_name;
            this->cnp = person.cnp;
            this->email = person.email;
            this->phone_number = person.phone_number;
            return *this;
        }

        friend istream& operator>> (istream& in, Person& person);
        friend ostream& operator<< (ostream& out, const Person& person);
};

istream& operator>> (istream& in, Person& person)
{
    in >> person.first_name >> person.last_name >> person.cnp >> person.email >> person.phone_number;
    return in;
}

ostream& operator<< (ostream& out, const Person& person)
{
    out << person.first_name << ' ' << person.last_name << ' ' << person.cnp << ' ' << person.email << ' ' << person.phone_number;
    return out;
}

#endif // PERSON_H_INCLUDED
