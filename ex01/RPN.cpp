#include "RPN.hpp"

std::stack<int> st_numbers;

bool is_operator(char c)
{
    return (c == '+' || c == '/' || c == '*' || c == '-');
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

bool rpn(std::string str)
{
    int flag = 0;
    int a, b;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (isdigit(str[i]) || is_operator(str[i]))
        {
            if (flag)
                return (false);
            if (isdigit(str[i]))
                st_numbers.push(str[i] - '0');
            else
            {
                if (st_numbers.size() < 2)
                    return (false);
                b = st_numbers.top();
                st_numbers.pop();
                a = st_numbers.top();
                st_numbers.pop();
                calcule_op(a, b, str[i]);
            }
            flag = 1;
        }
        else if (str[i] == ' ')
            flag = 0;
        else
            return (false);
    }
    if (st_numbers.size() == 1)
        std::cout << st_numbers.top() << std::endl;
    st_numbers.pop();
    return (st_numbers.empty());
}
