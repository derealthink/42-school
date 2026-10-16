#include "Fixed.hpp"

void comparisonTests() {
    std::cout << "\n--- Comparison Tests ---\n";

    Fixed a(5);
    Fixed b(10);
    Fixed c(5);

    std::cout << "a: " << a << ", b: " << b << ", c: " << c << "\n";

    std::cout << "a < b: " << (a < b) << "\n";
    std::cout << "a > b: " << (a > b) << "\n";
    std::cout << "a <= c: " << (a <= c) << "\n";
    std::cout << "a >= c: " << (a >= c) << "\n";
    std::cout << "a == c: " << (a == c) << "\n";
    std::cout << "a != b: " << (a != b) << "\n";
}

void arithmeticTests() {
    std::cout << "\n--- Arithmetic Tests ---\n";

    Fixed a(5.5f);
    Fixed b(2);

    std::cout << "a: " << a << ", b: " << b << "\n";

    std::cout << "a + b = " << (a + b) << "\n";
    std::cout << "a - b = " << (a - b) << "\n";
    std::cout << "a * b = " << (a * b) << "\n";
    std::cout << "a / b = " << (a / b) << "\n";
}

void incrementTests() {
    std::cout << "\n--- Increment / Decrement Tests ---\n";

    Fixed a;

    std::cout << "Initial a: " << a << "\n";

    std::cout << "++a: " << ++a << "\n";
    std::cout << "After ++a: " << a << "\n";

    std::cout << "a++: " << a++ << "\n";
    std::cout << "After a++: " << a << "\n";

    std::cout << "--a: " << --a << "\n";
    std::cout << "After --a: " << a << "\n";

    std::cout << "a--: " << a-- << "\n";
    std::cout << "After a--: " << a << "\n";
}

void minMaxTests() {
    std::cout << "\n--- Min / Max Tests ---\n";

    Fixed a(3);
    Fixed b(7);

    const Fixed c(1.5f);
    const Fixed d(2.5f);

    std::cout << "a: " << a << ", b: " << b << "\n";
    std::cout << "min(a, b): " << Fixed::min(a, b) << "\n";
    std::cout << "max(a, b): " << Fixed::max(a, b) << "\n";

    std::cout << "c: " << c << ", d: " << d << "\n";
    std::cout << "min(c, d): " << Fixed::min(c, d) << "\n";
    std::cout << "max(c, d): " << Fixed::max(c, d) << "\n";
}

void negativeTests() {
    std::cout << "\n--- Negative Numbers Tests ---\n";

    Fixed a(-5.5f);
    Fixed b(2);

    std::cout << "a: " << a << ", b: " << b << "\n";

    std::cout << "a + b = " << (a + b) << "\n";
    std::cout << "a - b = " << (a - b) << "\n";
    std::cout << "a * b = " << (a * b) << "\n";
    std::cout << "a / b = " << (a / b) << "\n";
}

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;

    comparisonTests();
    arithmeticTests();
    incrementTests();
    minMaxTests();
    negativeTests();

    return 0;
}