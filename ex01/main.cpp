#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return (1);
    if (!rpn(av[1]))
    {
        std::cout << "Error" << std::endl;
        return (1);
    }
    return (0);
}
