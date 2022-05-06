#ifndef EXCEPTION_H_INCLUDED
#define EXCEPTION_H_INCLUDED

#include <exception>
#include <iostream>

class indexException : public exception {
    public:
        virtual const char* what() const throw()
        {
            return "There is no account with this index";
        }
}newex;


#endif // EXCEPTION_H_INCLUDED
