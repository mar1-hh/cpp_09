#include "BitcoinExchange.hpp"



int main(int ac, char **av)
{
    if (ac != 2)
        return (1);
    (void)av;
    BitcoinExchange btc;

    if (!btc.parse_data())
        return (1);
    if (!btc.read_in_file(av[1]))
        return (1);
    return (0);
}