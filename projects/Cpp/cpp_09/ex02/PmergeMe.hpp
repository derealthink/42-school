#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <cmath>
#include <iterator>
#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <cerrno>
#include <climits>

long jacobsthal_number(long n);

template <typename T>
T iter_next(T it, int steps)
{
    std::advance(it, steps);
    return it;
}


class PmergeMe
{
  public:
    PmergeMe();
    PmergeMe(const PmergeMe& pm);
    PmergeMe& operator=(const PmergeMe& pm);
    ~PmergeMe();

    void sort_vec(std::vector<int>& vec);
    void sort_deque(std::deque<int>& deq);

    static int nbr_of_comps;

    template <typename Iterator>
    static bool comp(Iterator lhs, Iterator rhs)
    {
        nbr_of_comps++;
        return *lhs < *rhs;
    }

  private:
    template <typename T> void _merge_insertion_sort(T& container, int pair_level);
    template <typename T> void _swap_pair(T it, int pair_level);
};

template <typename T>
void PmergeMe::_swap_pair(T it, int pair_level)
{
    T start = iter_next(it, -pair_level + 1);
    T end   = iter_next(start, pair_level);
    while (start != end)
    {
        std::iter_swap(start, iter_next(start, pair_level));
        ++start;
    }
}


template <typename T>
void PmergeMe::_merge_insertion_sort(T& container, int pair_level)
{
    typedef typename T::iterator Iterator;
    typedef typename std::vector<Iterator>::iterator VecIt;

    const int pair_units_nbr = static_cast<int>(container.size()) / pair_level;
    if (pair_units_nbr < 2)
        return;

    const bool is_odd = pair_units_nbr % 2 == 1;

    Iterator range_end = iter_next(container.begin(), pair_level * pair_units_nbr);
    if (is_odd)
        std::advance(range_end, -pair_level);

    const int jump = 2 * pair_level;
    for (Iterator it = container.begin(); it != range_end; std::advance(it, jump))
    {
        Iterator left_last  = iter_next(it, pair_level - 1);
        Iterator right_last = iter_next(it, pair_level * 2 - 1);
        if (comp(right_last, left_last))
            _swap_pair(left_last, pair_level);
    }

    _merge_insertion_sort(container, pair_level * 2);

    std::vector<Iterator> main_chain;
    std::vector<Iterator> pend;

    main_chain.push_back(iter_next(container.begin(), pair_level - 1));
    main_chain.push_back(iter_next(container.begin(), pair_level * 2 - 1));

    for (int i = 4; i <= pair_units_nbr; i += 2)
    {
        pend.push_back(iter_next(container.begin(), pair_level * (i - 1) - 1));
        main_chain.push_back(iter_next(container.begin(), pair_level * i - 1));
    }

    if (is_odd)
        pend.push_back(iter_next(range_end, pair_level - 1));

    int prev_jacob     = static_cast<int>(jacobsthal_number(1));
    int inserted_count = 0;

    for (int k = 2; ; ++k)
    {
        const int curr_jacob   = static_cast<int>(jacobsthal_number(k));
        const int jacob_diff   = curr_jacob - prev_jacob;

        if (jacob_diff > static_cast<int>(pend.size()))
            break;

        int   remaining = jacob_diff;
        int   offset    = 0;
        VecIt pend_it   = iter_next(pend.begin(), jacob_diff - 1);
        VecIt bound_it  = iter_next(main_chain.begin(), curr_jacob + inserted_count);

        while (remaining--)
        {
            VecIt idx      = std::upper_bound(main_chain.begin(), bound_it, *pend_it, comp<Iterator>);
            VecIt inserted = main_chain.insert(idx, *pend_it);

            pend_it = pend.erase(pend_it);
            if (remaining > 0)
                std::advance(pend_it, -1);

            if ((inserted - main_chain.begin()) == curr_jacob + inserted_count)
                ++offset;
            bound_it = iter_next(main_chain.begin(), curr_jacob + inserted_count - offset);
        }

        prev_jacob     = curr_jacob;
        inserted_count += jacob_diff;
    }

    for (int i = static_cast<int>(pend.size()) - 1; i >= 0; --i)
    {
        VecIt pend_it  = iter_next(pend.begin(), i);
        VecIt bound_it = iter_next(main_chain.begin(),
                            static_cast<int>(main_chain.size()) -
                            static_cast<int>(pend.size()) + i + static_cast<int>(is_odd));
        VecIt idx = std::upper_bound(main_chain.begin(), bound_it, *pend_it, comp<Iterator>);
        main_chain.insert(idx, *pend_it);
    }

    std::vector<int> flat;
    flat.reserve(container.size());

    for (VecIt it = main_chain.begin(); it != main_chain.end(); ++it)
    {
        Iterator unit_start = iter_next(*it, -pair_level + 1);
        Iterator unit_end   = iter_next(*it, 1);
        for (Iterator jt = unit_start; jt != unit_end; ++jt)
            flat.push_back(*jt);
    }

    std::copy(flat.begin(), flat.end(), container.begin());
}

#endif
