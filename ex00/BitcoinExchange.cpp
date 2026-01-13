#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj) {};

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj)
{
    btc_map = obj.btc_map;
    return (*this);
}

BitcoinExchange::~BitcoinExchange() {};