#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange()
{
    std::ifstream file("data.csv");
    if (!file.is_open())
        throw FileNotOpened();
    
    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date;
        std::string valueStr;
        double value;

        if (std::getline(ss, date, ',') && std::getline(ss, valueStr))
        {
            std::stringstream convert(valueStr);
            if (convert >> value)
                db[date] = value;
        }
    }
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : db(other.db)
{}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        db = other.db;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{}
void BitcoinExchange::exchange(std::string filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw FileNotOpened();
    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        // --- PARSE ---
        std::stringstream ss(line);
        std::string date;
        std::string valueStr;
        double value;

        if (!std::getline(ss, date, '|') || !std::getline(ss, valueStr))
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        // trim trailing space from date and leading space from value
        if (!date.empty() && date[date.size() - 1] == ' ')
            date.erase(date.size() - 1);
        if (!valueStr.empty() && valueStr[0] == ' ')
            valueStr.erase(0, 1);

        // --- VALIDATE ---
        if (!isValidDate(date))
        {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }

        std::stringstream convert(valueStr);
        if (!(convert >> value))
        {
            std::cout << "Error: bad input => " << valueStr << std::endl;
            continue;
        }

        if (!isValidValue(value))
        {
            std::cout << "Error: not a positive number or too large." << std::endl;
            continue;
        }

        // --- LOOKUP ---
        std::map<std::string, double>::iterator it = db.lower_bound(date);
        if (it == db.end() || it->first != date)
        {
            if (it == db.begin())
            {
                std::cout << "Error: no data for date => " << date << std::endl;
                continue;
            }
            --it; // step back to closest earlier date
        }

        // --- PRINT ---
        std::cout << date << " => " << value << " = " << value * it->second << std::endl;
    }
}

bool BitcoinExchange::isValidDate(std::string date)
{
    // check format length YYYY-MM-DD
    if (date.size() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;

    // check all other characters are digits
    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            return false;
    }

    // extract year, month, day
    std::stringstream ssYear(date.substr(0, 4));
    std::stringstream ssMonth(date.substr(5, 2));
    std::stringstream ssDay(date.substr(8, 2));

    int year, month, day;
    ssYear >> year;
    ssMonth >> month;
    ssDay >> day;

    // validate month
    if (month < 1 || month > 12)
        return false;

    // validate day based on month
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // leap year check
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        daysInMonth[1] = 29;

    if (day < 1 || day > daysInMonth[month - 1])
        return false;

    return true;
}

bool BitcoinExchange::isValidValue(double value)
{
    if (value < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }
    if (value > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}

const char *BitcoinExchange::FileNotOpened::what() const throw()
{
    return ("File couldn't be opened");
}