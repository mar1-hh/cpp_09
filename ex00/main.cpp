#include "BitcoinExchange.hpp"



int main(int ac, char **av)
{
    if (ac != 2)
        return (1);
    (void)av;
    BitcoinExchange btc;

    btc.parse_data();
    btc.read_in_file(av[1]);
    return (0);
}