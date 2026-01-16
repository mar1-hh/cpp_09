#include "PmergeMe.hpp"

std::deque<int> jacobsthal_order_deque(size_t size)
{
    std::deque<int> check_point;
    std::deque<int> return_value;
    
    check_point.push_back(0);
    check_point.push_back(1);
    int i = 2;
    int c_p;
    while (1)
    {
        size_t top = check_point.back();
        if (top >= size)
            break ;
        c_p = check_point[i - 1] + 2 * check_point[i - 2];
        check_point.push_back(c_p);
        i++;
    }
    size_t prv = 0;
    for (size_t i = 1; i < check_point.size(); i++)
    {
        size_t cur = check_point[i];
        if (cur > size)
            cur = size;
        for (size_t j = cur; j > prv; j--)
            return_value.push_back(j - 1);
        prv = cur;
        if (prv == size)
            break;
    }
    return (return_value);
}

void main_chain(std::deque<int>& main_chain, std::deque<std::pair<int, int> > min_chain)
{
    std::deque<int>::iterator it;
    std::deque<int> order = jacobsthal_order_deque(min_chain.size());

    for (size_t i = 0; i < order.size(); i++)
    {
        int index = order[i];
        if (min_chain[index].second != -1)
            it = std::find(main_chain.begin(), main_chain.end(), min_chain[index].second);
        else
            it = main_chain.end();
        std::deque<int>::iterator insert_it = std::lower_bound(main_chain.begin(), it, min_chain[index].first);
        main_chain.insert(insert_it, min_chain[index].first);
    }
}

void make_2_chain(std::deque<std::pair<int, int> > &pairs, int odd_div, bool is_odd, std::deque<int> &arr)
{
    std::deque<int> max_v;
    std::deque<std::pair<int, int> > min_v;
    std::pair<int, int>     tmp;

    for (size_t i = 0; i < pairs.size(); i++)
    {
        max_v.push_back(pairs[i].first);
        tmp.first = pairs[i].second;
        tmp.second = pairs[i].first;
        min_v.push_back(tmp);
    }
    if (is_odd)
    {
        tmp.first = odd_div;
        tmp.second = -1;
        min_v.push_back(tmp);
    }
    ford_jhonson(max_v);
    main_chain(max_v, min_v);
    arr = max_v;
}

void ford_jhonson(std::deque<int> &arr)
{
    if (arr.size() <= 1)
        return ;
    std::deque<std::pair<int, int> > pairs;
    std::pair<int, int> tmp;
    int odd_div = 0;

    for (size_t i = 0; i + 1 < arr.size(); i += 2)
    {
        if (arr[i] > arr[i + 1])
        {
            tmp.first = arr[i];
            tmp.second = arr[i + 1];
        }
        else
        {
            tmp.first = arr[i + 1];
            tmp.second = arr[i];
        }
        pairs.push_back(tmp);
    }
    if (arr.size() % 2 != 0)
        odd_div = arr[arr.size() - 1];
    make_2_chain(pairs, odd_div, (arr.size() % 2 != 0), arr);
}

std::vector<int> jacobsthal_order_vector(size_t size)
{
    std::vector<int> check_point;
    std::vector<int> return_value;
    
    check_point.push_back(0);
    check_point.push_back(1);
    int i = 2;
    int c_p;
    while (1)
    {
        size_t top = check_point.back();
        if (top >= size)
            break ;
        c_p = check_point[i - 1] + 2 * check_point[i - 2];
        check_point.push_back(c_p);
        i++;
    }
    size_t prv = 0;
    for (size_t i = 1; i < check_point.size(); i++)
    {
        size_t cur = check_point[i];
        if (cur > size)
            cur = size;
        for (size_t j = cur; j > prv; j--)
            return_value.push_back(j - 1);
        prv = cur;
        if (prv == size)
            break;
    }
    return (return_value);
}

void main_chain(std::vector<int>& main_chain, std::vector<std::pair<int, int> > min_chain)
{
    std::vector<int>::iterator it;
    std::vector<int> order = jacobsthal_order_vector(min_chain.size());

    for (size_t i = 0; i < order.size(); i++)
    {
        int index = order[i];
        if (min_chain[index].second != -1)
            it = std::find(main_chain.begin(), main_chain.end(), min_chain[index].second);
        else
            it = main_chain.end();
        std::vector<int>::iterator insert_it = std::lower_bound(main_chain.begin(), it, min_chain[index].first);
        main_chain.insert(insert_it, min_chain[index].first);
    }
}

void make_2_chain(std::vector<std::pair<int, int> > &pairs, int odd_div, bool is_odd, std::vector<int> &arr)
{
    std::vector<int> max_v;
    std::vector<std::pair<int, int> > min_v;
    std::pair<int, int>     tmp;

    for (size_t i = 0; i < pairs.size(); i++)
    {
        max_v.push_back(pairs[i].first);
        tmp.first = pairs[i].second;
        tmp.second = pairs[i].first;
        min_v.push_back(tmp);
    }
    if (is_odd)
    {
        tmp.first = odd_div;
        tmp.second = -1;
        min_v.push_back(tmp);
    }
    ford_jhonson(max_v);
    main_chain(max_v, min_v);
    arr = max_v;
}

void ford_jhonson(std::vector<int> &arr)
{
    if (arr.size() <= 1)
        return ;
    std::vector<std::pair<int, int> > pairs;
    std::pair<int, int> tmp;
    int odd_div = 0;

    for (size_t i = 0; i + 1 < arr.size(); i += 2)
    {
        if (arr[i] > arr[i + 1])
        {
            tmp.first = arr[i];
            tmp.second = arr[i + 1];
        }
        else
        {
            tmp.first = arr[i + 1];
            tmp.second = arr[i];
        }
        pairs.push_back(tmp);
    }
    if (arr.size() % 2 != 0)
        odd_div = arr[arr.size() - 1];
    make_2_chain(pairs, odd_div, (arr.size() % 2 != 0), arr);
}
