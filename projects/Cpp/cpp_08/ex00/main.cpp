
#include <deque>
#include <iostream>
#include <list>
#include <vector>

#include "easyfind.hpp"

static void test_vector()
{
	std::vector<int> values;

	values.push_back(3);
	values.push_back(5);
	values.push_back(7);
	values.push_back(9);

	std::cout << "Should find 7 as it is in the vector" << std::endl;
	try
	{
		std::vector<int>::const_iterator it = easyfind(values, 7);
		std::cout << "vector: found " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "vector: " << e.what() << std::endl;
	}

	std::cout << "Should not find 4 as it is not in the vector" << std::endl;
	try
	{
		std::vector<int>::const_iterator it = easyfind(values, 4);
		std::cout << "vector: found " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "vector: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

static void test_list()
{
	std::list<int> values;

	values.push_back(10);
	values.push_back(20);
	values.push_back(30);
	values.push_back(40);

	std::cout << "Should find 20 as it is in the list" << std::endl;
	try
	{
		std::list<int>::const_iterator it = easyfind(values, 20);
		std::cout << "list: found " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "list: " << e.what() << std::endl;
	}
	std::cout << "Should not find 25 as it is not in the list" << std::endl;
	try
	{
		std::list<int>::const_iterator it = easyfind(values, 25);
		std::cout << "list: found " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "list: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
}

static void test_deque()
{
	std::deque<int> values;

	values.push_back(1);
	values.push_back(2);
	values.push_back(3);
	values.push_back(4);
	std::cout << "Should find 1 as it is in the deque" << std::endl;
	try
	{
		std::deque<int>::const_iterator it = easyfind(values, 1);
		std::cout << "deque: found " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "deque: " << e.what() << std::endl;
	}
	std::cout << "Should not find 6 as it is not in the deque" << std::endl;
	try
	{
		std::deque<int>::const_iterator it = easyfind(values, 6);
		std::cout << "deque: found " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "deque: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
}

int main()
{
	test_vector();
	test_list();
	test_deque();
	return 0;
}
