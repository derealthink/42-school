#include "PmergeMe.hpp"

inline long jacobsthal_number(long n)
{
    if (n == 0)
        return 0;
    long prev = 0;
    long curr = 1;
    for (long i = 1; i < n; ++i)
    {
        long next = curr + 2 * prev;
        prev = curr;
        curr = next;
    }
    return curr;
}

int PmergeMe::nbr_of_comps = 0;

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& pm)
{
    *this = pm;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& pm)
{
    (void)pm;
    return *this;
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::sort_vec(std::vector<int>& vec)
{
    _merge_insertion_sort(vec, 1);
}

void PmergeMe::sort_deque(std::deque<int>& deq)
{
    _merge_insertion_sort(deq, 1);
}
