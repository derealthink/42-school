#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


int main(void) {
    srand(time(0));

    for (int i = 0; i < 6; i++) {
        Base* obj = generate();

        std::cout << "Pointer: "; identify(obj);
        std::cout << "Ref:     "; identify(*obj);

        delete obj;
    }
    return 0;
}