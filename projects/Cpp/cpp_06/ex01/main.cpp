#include "Serializer.hpp"


int main()
{
    Data original;
    original.n = 42;
    original.s = "hello";
    original.f = 3.14f;

    std::cout << "Original pointer:     " << &original << std::endl;

    uintptr_t raw = Serializer::serialize(&original);
    std::cout << "Serialized (integer): " << raw << std::endl;

    Data* recovered = Serializer::deserialize(raw);
    std::cout << "Deserialized pointer: " << recovered << std::endl;

    std::cout << "Pointers match: " << (&original == recovered ? "YES" : "NO") << std::endl;

    // also verify the data is intact
    std::cout << "n: " << recovered->n << std::endl;
    std::cout << "s: " << recovered->s << std::endl;
    std::cout << "f: " << recovered->f << std::endl;

    return 0;
}