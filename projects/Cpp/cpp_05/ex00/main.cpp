#include "Bureaucrat.hpp"

static void printSection(const std::string &title) {
  std::cout << "\n=== " << title << " ===" << std::endl;
}

static void tryCreate(const std::string &name, int grade) {
  try {
    Bureaucrat b(name, grade);
    std::cout << b;
  } catch (const std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }
}

static void testIncrementDecrement() {
  printSection("Increment and Decrement");
  try {
    Bureaucrat b("Charlie", 42);
    std::cout << b;
    b.incrementGrade();
    std::cout << "After increment: " << b;
    b.decrementGrade();
    std::cout << "After decrement: " << b;
  } catch (const std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }
}

static void testBoundaryIncrement() {
  printSection("Increment Boundary");
  try {
    Bureaucrat b("Alice", MAX_GRADE);
    std::cout << b;
    b.incrementGrade();
  } catch (const std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }
}

static void testBoundaryDecrement() {
  printSection("Decrement Boundary");
  try {
    Bureaucrat b("Bob", MIN_GRADE);
    std::cout << b;
    b.decrementGrade();
  } catch (const std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }
}

static void testCopyAssign() {
  printSection("Copy and Assignment");
  Bureaucrat a("Diana", 10);
  Bureaucrat b(a);
  Bureaucrat c;
  c = b;
  std::cout << "Original: " << a;
  std::cout << "Copy: " << b;
  std::cout << "Assigned: " << c;
}

int main() {
  printSection("Constructor Validation");
  tryCreate("TooHigh", 0);
  tryCreate("TooLow", 151);
  tryCreate("Valid", 75);

  testIncrementDecrement();
  testBoundaryIncrement();
  testBoundaryDecrement();
  testCopyAssign();
  return 0;
}
