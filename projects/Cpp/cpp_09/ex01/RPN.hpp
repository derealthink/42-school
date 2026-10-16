#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <sstream>

class  Notation
{
    private:
        std::stack<int> n;
    
    public:
        Notation();
        Notation(const Notation &);
        Notation &operator= (const Notation &);
        ~Notation();

        void calculate(const std::string &expression);

};






#endif 