#include "Array.hpp"

int main()
{
    // Test 1: Default constructor — empty array
    std::cout << "--- Test 1: Default constructor ---\n";
    Array<int> empty;
    std::cout << "Size: " << empty.size() << "\n\n";

    // Test 2: Size constructor — int
    std::cout << "--- Test 2: Size constructor (int) ---\n";
    Array<int> intArr(5);
    for (unsigned int i = 0; i < intArr.size(); i++)
        intArr[i] = i * 10;
    for (unsigned int i = 0; i < intArr.size(); i++)
        std::cout << "intArr[" << i << "] = " << intArr[i] << "\n";
    std::cout << "\n";

    // Test 3: Copy constructor — modifying copy doesn't affect original
    std::cout << "--- Test 3: Copy constructor independence ---\n";
    Array<int> copyArr(intArr);
    copyArr[0] = 999;
    std::cout << "original intArr[0] = " << intArr[0] << " (should be 0)\n";
    std::cout << "copyArr[0]         = " << copyArr[0] << " (should be 999)\n\n";

    // Test 4: Assignment operator — modifying original doesn't affect copy
    std::cout << "--- Test 4: Assignment operator independence ---\n";
    Array<int> assignArr(3);
    assignArr = intArr;
    intArr[1] = 777;
    std::cout << "intArr[1]    = " << intArr[1] << " (should be 777)\n";
    std::cout << "assignArr[1] = " << assignArr[1] << " (should be 10)\n\n";

    // Test 5: Self-assignment
    std::cout << "--- Test 5: Self-assignment ---\n";
    assignArr = assignArr;
    std::cout << "assignArr[0] = " << assignArr[0] << " (should be 0, no crash)\n\n";

    // Test 6: Out of bounds exception
    std::cout << "--- Test 6: Out of bounds exception ---\n";
    try {
        std::cout << intArr[999] << "\n";
    } catch (Array<int>::OutOfBounds &) {
        std::cout << "Caught exception: Index is out of range.\n\n";
    }

    // Test 7: Out of bounds on empty array
    std::cout << "--- Test 7: Out of bounds on empty array ---\n";
    try {
        std::cout << empty[0] << "\n";
    } catch (Array<int>::OutOfBounds &) {
        std::cout << "Caught exception: Index is out of range.\n\n";
    }

    // Test 8: Works with double
    std::cout << "--- Test 8: double array ---\n";
    Array<double> dblArr(3);
    dblArr[0] = 1.1;
    dblArr[1] = 2.2;
    dblArr[2] = 3.3;
    for (unsigned int i = 0; i < dblArr.size(); i++)
        std::cout << "dblArr[" << i << "] = " << dblArr[i] << "\n";
    std::cout << "\n";

    // Test 9: Works with std::string
    std::cout << "--- Test 9: string array ---\n";
    Array<std::string> strArr(3);
    strArr[0] = "hello";
    strArr[1] = "world";
    strArr[2] = "foo";
    for (unsigned int i = 0; i < strArr.size(); i++)
        std::cout << "strArr[" << i << "] = " << strArr[i] << "\n";
    std::cout << "\n";

    return 0;
}
