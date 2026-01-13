#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj)
{
    btc_map = obj.btc_map;
};

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj)
{
    btc_map = obj.btc_map;
    return (*this);
}

BitcoinExchange::~BitcoinExchange() {};

void BitcoinExchange::parse_data()
{
    std::ifstream   in_data("data.csv");
    std::string line;
    std::string date;
    std::string value;
    

    while (getline(in_data, line))
    {
        if (line == "date,exchange_rate")
            continue;
        size_t  flag = line.find(',');
        date = line.substr(0, flag);
        value = line.substr(flag + 1);
        add_btc(date, value);
    }
}

void BitcoinExchange::add_btc(std::string date, std::string value)
{
    btc_map[date] = strtod(value.c_str(), NULL);
}

void BitcoinExchange::print_res(std::string date, std::string value)
{
    double val;
    char *flag_val;

    val = strtod(value.c_str(), &flag_val);
    if (*flag_val != 0)
        std::cout << "is not a number" << std::endl;
    else if (val < 0)
        std::cout << "Error: not a positive number" << std::endl;
    else if (val > 1000)
        std::cout << "Error: too large a number." << std::endl;
    std::map<std::string, float>::iterator it = btc_map.lower_bound(date);
    std::cout << date << " => " << val << " = " << it->second * val << std::endl;
}

void BitcoinExchange::read_in_file(char *name)
{
    std::string line, date, value;
    std::ifstream in_file(name);

    while (getline(in_file, line))
    {
        if (line == "date | value")
            continue;
        size_t flag = line.find('|');
        date = line.substr(0, flag - 1);
        value = line.substr(flag + 2);
        print_res(date, value);
    }
}
