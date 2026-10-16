#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
    std::cout << "===== MUTANTSTACK TEST =====" << std::endl;

    MutantStack<int> mstack;

    std::cout << "\nPushing: 5, 17" << std::endl;
    mstack.push(5);
    mstack.push(17);

    std::cout << "Top element: " << mstack.top() << std::endl;

    std::cout << "Pop top element (17)" << std::endl;
    mstack.pop();

    std::cout << "Stack size: " << mstack.size() << std::endl;

    std::cout << "\nPushing: 3, 5, 737, 0" << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "\nIterating through MutantStack:" << std::endl;

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);

    std::cout << "\nCopy construction into std::stack successful." << std::endl;

    std::cout << "\n========================================\n" << std::endl;
    std::cout << "===== SAME TEST WITH std::list =====" << std::endl;

    std::list<int> lst;

    std::cout << "\nPushing: 5, 17" << std::endl;
    lst.push_back(5);
    lst.push_back(17);

    std::cout << "Last element: " << lst.back() << std::endl;

    std::cout << "Remove last element (17)" << std::endl;
    lst.pop_back();

    std::cout << "List size: " << lst.size() << std::endl;

    std::cout << "\nPushing: 3, 5, 737, 0" << std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::cout << "\nIterating through std::list:" << std::endl;

    std::list<int>::iterator lit = lst.begin();
    std::list<int>::iterator lite = lst.end();

    ++lit;
    --lit;

    while (lit != lite)
    {
        std::cout << *lit << std::endl;
        ++lit;
    }

    std::cout << "\nExpected result: both containers print the same sequence."
              << std::endl;

    return 0;
}
