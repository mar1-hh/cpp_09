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

bool is_int(std::string &str)
{
    if (str.empty())
        return (false);
    for (size_t i = 0; i < str.size(); i++)
    {
        if (!isdigit(str[i]))
            return (false);
    }
    return (true);
}


bool days_validate(int year_val, int month_val, int day_val)
{
    if (year_val < 1800 || year_val > 2026)
        return (false);
    bool    is_leap = 0;
    if (year_val % 400 == 0)
        is_leap = 1;
    else if ((year_val % 100 != 0) && (year_val % 4 == 0))
        is_leap = 1;
    if (is_leap && month_val == 2)
    {
        if (!(day_val >= 1 && day_val <= 29))
            return (false);
    }
    if (month_val % 2 != 0 || month_val == 8)
    {
        if (!(day_val >= 1 && day_val <= 31))
            return (false);
    }
    if (month_val % 2 == 0 && month_val != 8)
    {
        if (!(day_val >= 1 && day_val <= 30))
            return (false);
    }
    return (true);
}


bool validate_date(std::string date)
{
    std::string year_part;
    std::string month_part;
    std::string day_part;
    size_t flag = date.find('-');
    size_t prev_flag;
    
    year_part = date.substr(0, flag);
    prev_flag = flag;
    flag = date.find('-', flag + 1);
    month_part = date.substr(prev_flag + 1, flag - prev_flag - 1);
    day_part = date.substr(flag + 1);
    if (!is_int(year_part) || !is_int(month_part) || !is_int(day_part))
        return (false);
    return (days_validate(atoi(year_part.c_str()), atoi(month_part.c_str()), atoi(day_part.c_str())));
    return (true);
}

void BitcoinExchange::print_res(std::string date, std::string value)
{
    double val;
    char *flag_val;


    val = strtod(value.c_str(), &flag_val);
    if (!validate_date(date))
        std::cout << "Error: bad input => " << date << std::endl;
    else if (*flag_val != 0)
        std::cout << "Error: bad input => " << value << std::endl;
    else if (val < 0)
        std::cout << "Error: not a positive number." << std::endl;
    else if (val > 1000)
        std::cout << "Error: too large a number." << std::endl;
    else
    {
        std::map<std::string, float>::iterator it = btc_map.lower_bound(date);
        std::cout << date << " => " << val << " = " << it->second * val << std::endl;
    }
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
