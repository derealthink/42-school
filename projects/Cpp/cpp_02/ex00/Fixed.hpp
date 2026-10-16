#ifndef FIXED_HPP
#define FIXED_HPP


#include <iostream>
#include <string>

class Fixed
{
    private:
        int n;
        static const int frac = 8;
    public:
        Fixed(); //constructor
        Fixed(const Fixed &copy); //copy constructor
        Fixed& operator=(const Fixed &copy); //copy assignment operator
        ~Fixed(); //Destructor

        int getRawBits(void) const;
        void setRawBits(int const raw);
};


#endif