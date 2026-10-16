#ifndef FIXED_HPP
#define FIXED_HPP


#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
    //value = n / (2^frac)
    private:
        int n;
        static const int frac = 8;
        static const int scale = 1 << frac;
    public:
        Fixed();
        Fixed(const int n); //constructor
        Fixed(const float n);//float constrcutor
        Fixed(const Fixed &copy); //copy constructor
        Fixed& operator=(const Fixed &copy); //copy assignment operator
        float toFloat( void ) const;
        int toInt( void ) const;
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
};
std::ostream& operator<<(std::ostream& os, const Fixed& obj);


#endif