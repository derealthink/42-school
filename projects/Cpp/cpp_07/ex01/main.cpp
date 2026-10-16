#include "iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void print(const T& x) {
    std::cout << x << " ";
}

template <typename T>
void increment(T& x) {
    x++;
}

int main() {

    // Test 1: int array with print
    std::cout << "Test 1 - int array, print:\n";
    int intArr[] = {1, 2, 3, 4, 5};
    iter(intArr, 5, print<int>);
    std::cout << "\n";

    // Test 2: mutating elements with increment
    std::cout << "Test 2 - int array, increment then print:\n";
    iter(intArr, 5, increment<int>);
    iter(intArr, 5, print<int>);
    std::cout << "\n";

    // Test 3: double array
    std::cout << "Test 3 - double array, print:\n";
    double dblArr[] = {1.1, 2.2, 3.3};
    iter(dblArr, 3, print<double>);
    std::cout << "\n";

    // Test 4: const array
    std::cout << "Test 4 - const int array, print:\n";
    const int constArr[] = {10, 20, 30};
    iter(constArr, 3, print<int>);
    std::cout << "\n";

    // Test 5: string array
    std::cout << "Test 5 - string array, print:\n";
    std::string strArr[3];
    strArr[0] = "hello";
    strArr[1] = "world";
    strArr[2] = "foo";
    iter(strArr, 3, print<std::string>);
    std::cout << "\n";

    // Test 6: char array
    std::cout << "Test 8 - char array, print:\n";
    char charArr[] = {'a', 'b', 'c', 'd'};
    iter(charArr, 4, print<char>);
    std::cout << "\n";

    return 0;
}
