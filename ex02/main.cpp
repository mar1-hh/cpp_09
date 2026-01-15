#include "PmergeMe.hpp"

// struct min_chain
// {
//     int min;
//     int max_pair;
// };

void main_chain(std::vector<int>& main_chain, std::vector<std::pair<int, int>> min_chain)
{
    for (size_t i = 0; i < min_chain.size(); i++)
    {
        std::vector<int>::iterator it = std::find(main_chain.begin(), main_chain.end(), min_chain[i].second);
        std::vector<int>::iterator insert_it = std::lower_bound(main_chain.begin(), it, min_chain[i].first);
        main_chain.insert(insert_it, min_chain[i].first);
    }
}

void make_2_chain(std::vector<std::pair<int, int>> &pairs, int odd_div, bool is_odd)
{
    std::vector<int> max_v;
    std::vector<std::pair<int, int>> min_v;

    for (size_t i = 0; i < pairs.size(); i++)
    {
        max_v.push_back(pairs[i].first);
        min_v.push_back({pairs[i].second, pairs[i].first});
    }
    if (is_odd)
        min_v.push_back({odd_div, 0});
    main_chain(max_v, min_v);
}

void ford_jhonson(std::vector<int> &arr)
{
    std::vector<std::pair<int, int>> pairs;
    int odd_div;

    for (size_t i = 0; i < arr.size(); i += 2)
    {
        if (arr[i] > arr[i + 1])
            pairs.push_back({arr[i], arr[i + 1]});
        else
            pairs.push_back({arr[i + 1], arr[i]});
    }
    if (arr.size() % 2 != 0)
        odd_div = arr[arr.size() - 1];
    make_2_chain(pairs, odd_div, (arr.size() % 2 != 0));
}

int main()
{
    std::vector<int> arr;
    arr.push_back(7);
    arr.push_back(5);
    arr.push_back(2);
    arr.push_back(1);
    // arr.push_back(8);
    for (size_t i =0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    ford_jhonson(arr);
    return (0);
}
