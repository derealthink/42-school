#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <exception>
#include <fstream>
#include <sstream>

class BitcoinExchange
{
    private:
        std::map<std::string, double> db;
    
    public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &);
    BitcoinExchange &operator= (const BitcoinExchange &);
    ~BitcoinExchange();

    bool isValidDate(std::string);
    bool isValidValue(double);

    void exchange(std::string filename);



    class FileNotOpened : public std::exception
    {
        const char *what() const throw();
    };

};



#endif 