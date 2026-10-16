#include "Bureaucrat.hpp"
#include "Form.hpp"

static void printSection(const std::string &title) {
  std::cout << "\n=== " << title << " ===" << std::endl;
}

static void tryCreateBureaucrat(const std::string &name, int grade) {
  try {
    Bureaucrat b(name, grade);
    std::cout << b;
  } catch (const std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }
}

static void tryCreateForm(const std::string &name, int signGrade, int execGrade) {
  try {
    Form f(name, signGrade, execGrade);
    std::cout << f << std::endl;
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

static void testBureaucratCopyAssign() {
  printSection("Bureaucrat Copy and Assignment");
  Bureaucrat a("Diana", 10);
  Bureaucrat b(a);
  Bureaucrat c;
  c = b;
  std::cout << "Original: " << a;
  std::cout << "Copy: " << b;
  std::cout << "Assigned: " << c;
}

static void testFormSigningSuccess() {
  printSection("Form Signing Success");
  try {
    Bureaucrat signer("Eve", 5);
    Form f("Form A", 10, 20);
    std::cout << f << std::endl;
    f.beSigned(signer);
    std::cout << f << std::endl;
  } catch (const std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }
}

static void testFormSigningLowGrade() {
  printSection("Form Signing Low Grade");
  try {
    Bureaucrat signer("Frank", 100);
    Form f("Form B", 50, 60);
    std::cout << f << std::endl;
    f.beSigned(signer);
  } catch (const std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }
}

static void testFormAlreadySigned() {
  printSection("Form Already Signed");
  try {
    Bureaucrat signer("Grace", 1);
    Form f("Form C", 10, 10);
    f.beSigned(signer);
    f.beSigned(signer);
  } catch (const std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }
}

static void testFormCopyAssign() {
  printSection("Form Copy and Assignment");
  Bureaucrat signer("Henry", 2);
  Form a("Form D", 3, 3);
  a.beSigned(signer);
  Form b(a);
  Form c;
  c = b;
  std::cout << "Original: " << a << std::endl;
  std::cout << "Copy: " << b << std::endl;
  std::cout << "Assigned: " << c << std::endl;
}

int main() {
  printSection("Bureaucrat Constructor Validation");
  tryCreateBureaucrat("TooHigh", 0);
  tryCreateBureaucrat("TooLow", 151);
  tryCreateBureaucrat("Valid", 75);

  testIncrementDecrement();
  testBoundaryIncrement();
  testBoundaryDecrement();
  testBureaucratCopyAssign();

  printSection("Form Constructor Validation");
  tryCreateForm("SignTooHigh", 0, 10);
  tryCreateForm("SignTooLow", 151, 10);
  tryCreateForm("ExecTooHigh", 10, 0);
  tryCreateForm("ExecTooLow", 10, 151);
  tryCreateForm("ValidForm", 75, 75);

  testFormSigningSuccess();
  testFormSigningLowGrade();
  testFormAlreadySigned();
  testFormCopyAssign();
  return 0;
}
