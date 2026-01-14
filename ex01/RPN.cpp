#include "RPN.hpp"

std::stack<int> st_numbers;

bool is_operator(char c)
{
    return (c == '+' || c == '/' || c == '*' || c == '-');
}

bool parse_nmb(std::vector<char> &vec_char, std::string str)
{
    int flag = 0;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (isdigit(str[i]) || is_operator(str[i]))
        {
            if (flag)
                return (false);
            vec_char.push_back(str[i]);
            flag = 1;
        }
        else if (str[i] == ' ')
            flag = 0;
        else
            return (false);
    }
    return (!vec_char.empty());
}

void calcule_op(int a , int b, char op)
{
    if (op == '+')
        st_numbers.push(a + b);
    else if (op == '-')
        st_numbers.push(a - b);
    else if (op == '*')
        st_numbers.push(a * b);
    else if (op == '/')
        st_numbers.push(a / b);
}

bool rpn(std::vector<char> &vec_char)
{
    char c;
    int a, b;
    for (size_t i = 0; i < vec_char.size(); i++)
    {
        c = vec_char[i];
        if (isdigit(c))
            st_numbers.push(c - '0');
        else if (is_operator(c))
        {
            if (st_numbers.size() < 2)
                return (false);
            b = st_numbers.top();
            st_numbers.pop();
            a = st_numbers.top();
            st_numbers.pop();
            calcule_op(a, b, c);
        }
    }
    std::cout << st_numbers.top() << std::endl;
    return (true);
}