#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return (1);
    std::vector<char> vec_char;
    if (!parse_nmb(vec_char, av[1]))
    {
        std::cout << "Error" << std::endl;
        return (1);
    }
    if (!rpn(vec_char))
    {
        std::cout << "Error" << std::endl;
        return (1);
    }
    return (0);
}
