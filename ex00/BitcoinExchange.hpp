#pragma once

#include <unordered_map>

#include <iostream>

#include <string>

class BitcoinExchange
{
    private:
    std::unordered_map<std::string, int> btc_map;

    public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& obj);
    BitcoinExchange& operator=(const BitcoinExchange& obj);
    ~BitcoinExchange();
    void parse_data();
};