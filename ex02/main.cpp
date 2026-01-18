#include "PmergeMe.hpp"

long long now_us()
{
    timeval tv;
    gettimeofday(&tv, 0);
    return (long long)tv.tv_sec * 1000000LL + (long long)tv.tv_usec;
}

bool is_positive_number(std::string num)
{
    for (size_t i = 0; i < num.size(); i++)
    {
        if (!isdigit(num[i]))
            return (false);
    }
    return (true);
}

bool parse_num(int ac, char **av, std::deque<int>& deque_arr, std::vector<int>& vector_arr)
{
    for (int i = 1; i < ac; i++)
    {
        if (!is_positive_number(av[i]))
        {
            std::cout << "Error" << std::endl;
            return (0);
        }
        deque_arr.push_back(atoi(av[i]));
        vector_arr.push_back(deque_arr[i - 1]);
    }
    return (1);
}

int main(int ac, char **av)
{
    if (ac <= 1)
        return (1);
    std::deque<int> deque_arr;
    std::vector<int> vector_arr;
    if (!parse_num(ac, av, deque_arr, vector_arr))
        return (1);
    std::cout << "Before: ";
    for (size_t i =0; i < vector_arr.size(); i++)
        std::cout << vector_arr[i] << " ";
    std::cout << std::endl;



    long long start = now_us();
    ford_jhonson(deque_arr);
    long long end = now_us();
    std::cout << "After: ";
    for (size_t i =0; i < deque_arr.size(); i++)
        std::cout << deque_arr[i] << " ";
    std::cout << std::endl;
    std::cout << "Time to process a range of " << deque_arr.size()
    << " elements with std::deque : "
    << std::fixed << std::setprecision(5)
    << (double)(end - start) << " us" << std::endl;



    start = now_us();
    ford_jhonson(vector_arr);
    end = now_us();
    std::cout << "Time to process a range of " << vector_arr.size()
    << " elements with std::vector : "
    << std::fixed << std::setprecision(5)
    << (double)(end - start) << " us" << std::endl;



    return (0);
}
