
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

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

static void testFormSigning() {
  printSection("Form Signing");
  Bureaucrat low("LowRank", 150);
  Bureaucrat high("HighRank", 1);
  ShrubberyCreationForm form("garden");

  try {
    form.beSigned(low);
  } catch (const std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  try {
    form.beSigned(high);
  } catch (const std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  try {
    form.beSigned(high);
  } catch (const std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  std::cout << form << std::endl;
}

static void testMultipleForms() {
  printSection("Multiple Forms");
  Bureaucrat mid("MidRank", 50);
  Bureaucrat exec("Exec", 20);

  RobotomyRequestForm robot("Bender");
  PresidentialPardonForm pardon("Ford Prefect");

  try {
    robot.beSigned(mid);
  } catch (const std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  try {
    pardon.beSigned(mid);
  } catch (const std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  try {
    pardon.beSigned(exec);
  } catch (const std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  std::cout << robot << std::endl;
  std::cout << pardon << std::endl;
}

static void testFormCopyAssign() {
  printSection("Form Copy and Assignment");
  Bureaucrat signer("Signer", 1);
  RobotomyRequestForm original("Marvin");

  try {
    original.beSigned(signer);
  } catch (const std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  RobotomyRequestForm copy(original);
  RobotomyRequestForm assigned;
  assigned = original;

  std::cout << original << std::endl;
  std::cout << copy << std::endl;
  std::cout << assigned << std::endl;
}

static void testFormExecution() {
  printSection("Form Execution");
  Bureaucrat low("LowExec", 150);
  Bureaucrat mid("MidExec", 50);
  Bureaucrat high("HighExec", 1);

  RobotomyRequestForm robot("Bender");
  ShrubberyCreationForm shrub("Garden");
  PresidentialPardonForm pardon("Ford Prefect");

  high.executeForm(robot);

  try {
    robot.beSigned(mid);
  } catch (const std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  low.executeForm(robot);
  high.executeForm(robot);

  low.executeForm(shrub);
  try {
    shrub.beSigned(low);
  } catch (const std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }
  try {
    shrub.beSigned(high);
  } catch (const std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }
  mid.executeForm(shrub);

  try {
    pardon.beSigned(mid);
  } catch (const std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }
  try {
    pardon.beSigned(high);
  } catch (const std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }
  mid.executeForm(pardon);
  high.executeForm(pardon);
}

static void testInternForms() {
  printSection("Intern Form Creation");
  Intern intern;
  Bureaucrat signer("InternSigner", 1);
  Bureaucrat executor("InternExecutor", 1);

  const char *names[] = {"PresidentialPardon", "RobotomyRequest",
                         "ShrubberyCreation"};
  const char *targets[] = {"Arthur Dent", "HAL9000", "Backyard"};

  for (int i = 0; i < 3; ++i) {
    Form *form = 0;
    try {
      form = intern.makeForm(names[i], targets[i]);
      std::cout << "Intern created form for target: " << form->getName()
                << std::endl;
    } catch (const std::exception &e) {
      std::cout << "Exception: " << e.what() << std::endl;
    }

    if (form) {
      try {
        form->beSigned(signer);
      } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
      }
      executor.executeForm(*form);
      delete form;
    }
  }

  try {
    Form *unknown = intern.makeForm("UnknownForm", "Nowhere");
    delete unknown;
  } catch (const std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }
}

int main() {
  printSection("Bureaucrat Constructor Validation");
  tryCreateBureaucrat("TooHigh", 0);
  tryCreateBureaucrat("TooLow", 151);
  tryCreateBureaucrat("Valid", 75);

  testIncrementDecrement();
  testBoundaryIncrement();
  testBoundaryDecrement();
  testFormSigning();
  testMultipleForms();
  testFormCopyAssign();
  testFormExecution();
  testInternForms();
  return 0;
}
