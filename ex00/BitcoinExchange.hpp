#pragma once

#include <map>
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

class BitcoinExchange
{
    private:
    std::map<std::string, float> btc_map;

    public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& obj);
    BitcoinExchange& operator=(const BitcoinExchange& obj);
    ~BitcoinExchange();
    void parse_data();
    void add_btc(std::string data, std::string value);
    void read_in_file(char *name);
    void print_res(std::string date, std::string value);
    voi
};