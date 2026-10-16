#include <iostream>
#include <ctype.h>

int main(int argc, char **argv){
    if (argc <= 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    else {
      for (int i = 1; i < argc; i++)
      {
        char *res = argv[i];
        char c;

        for (int j = 0; (c = res[j]); j++)
            std::cout << (char) toupper(c);
        if (i < argc - 1)
            std::cout << ' ';
      }
      std::cout << '\n';
    }
    return (0);
}