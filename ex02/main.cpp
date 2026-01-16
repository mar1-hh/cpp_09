#include "PmergeMe.hpp"

void ford_jhonson(std::vector<int> &arr);

void main_chain(std::vector<int>& main_chain, std::vector<std::pair<int, int> > min_chain)
{
    std::vector<int>::iterator it;
    for (size_t i = 0; i < min_chain.size(); i++)
    {
        if (min_chain[i].second != -1)
            it = std::find(main_chain.begin(), main_chain.end(), min_chain[i].second);
        else
            it = main_chain.end();
        std::vector<int>::iterator insert_it = std::lower_bound(main_chain.begin(), it, min_chain[i].first);
        main_chain.insert(insert_it, min_chain[i].first);
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

int main()
{
    std::vector<int> arr;
    arr.push_back(7);
    arr.push_back(5);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(8);
    for (size_t i =0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    ford_jhonson(arr);
    for (size_t i =0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return (0);
}
