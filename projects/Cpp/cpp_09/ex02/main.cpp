#include "PmergeMe.hpp"

#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <sys/time.h>
#include <string.h>

static bool validate_single(const std::string& s)
{
    std::size_t i = 0;

    if (s.empty())
        return false;
    if (s[i] == '+')
        ++i;
    if (i == s.size())
        return false;
    for (; i < s.size(); ++i)
    {
        if (!std::isdigit(static_cast<unsigned char>(s[i])))
            return false;
    }
    errno = 0;
    char* end = NULL;
    long n = std::strtol(s.c_str(), &end, 10);
    return errno != ERANGE && *end == '\0' && n > 0 && n <= INT_MAX;
}

static bool is_doubles(char **argv, int argc)
{
    for (int i = 0; i < argc; i++)
    {
        for (int j = i + 1; j < argc; j++)
        {
            if (strcmp(argv[i], argv[j]) == 0)
                return true;
        }
    }
    return false;
}

static bool validate_all(int argc, char** argv)
{
    if (argc < 2)
        return false;
    for (int i = 1; i < argc; i++)
    {
        if (!validate_single(argv[i]))
            return false;
    }
    if (is_doubles(argv, argc))
        return false;
    return true;
}

static std::vector<int> argv_to_vector(int argc, char** argv)
{
    std::vector<int> res;
    res.reserve(argc - 1);
    for (int i = 1; i < argc; i++)
    {
        res.push_back(atoi(argv[i]));
    }
    return res;
}

static std::deque<int> argv_to_deque(int argc, char** argv)
{
    std::deque<int> res;
    for (int i = 1; i < argc; i++)
    {
        res.push_back(atoi(argv[i]));
    }
    return res;
}

template <typename Container>
static void print_sequence(const std::string& label, const Container& container)
{
    std::cout << label;
    for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl;
}

static double elapsed_us(struct timeval start, struct timeval end)
{
    return (end.tv_sec - start.tv_sec) * 1000000.0
         + (end.tv_usec - start.tv_usec);
}


int main(int argc, char** argv)
{
    if (!validate_all(argc, argv))
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    PmergeMe sorter;
    std::vector<int> before = argv_to_vector(argc, argv);
    struct timeval start, end;
    std::vector<int> vec = argv_to_vector(argc, argv);
    gettimeofday(&start, NULL);
    sorter.sort_vec(vec);
    gettimeofday(&end, NULL);
    double vec_time = elapsed_us(start, end);
    std::cout << "Vector comparisons: " << PmergeMe::nbr_of_comps << std::endl;

    PmergeMe::nbr_of_comps = 0;

    std::deque<int> deq = argv_to_deque(argc, argv);
    gettimeofday(&start, NULL);
    sorter.sort_deque(deq);
    gettimeofday(&end, NULL);
    double deq_time = elapsed_us(start, end);
    std::cout << "Deque comparisons: " << PmergeMe::nbr_of_comps << std::endl;

    print_sequence("Before:", before);
    print_sequence("After:", vec);
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector : "
              << vec_time << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size()
              << " elements with std::deque : "
              << deq_time << " us" << std::endl;
    return 0;
}
