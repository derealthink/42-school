# C++ Modules

42 School exercises exploring C++ through small, independently built programs. The repository contains modules `cpp_00` through `cpp_09`.

## What this demonstrates

Object lifetime and memory ownership, classes and inheritance, polymorphism, exceptions, casts, templates, containers and algorithms. Each exercise keeps its source files and Makefile in its own directory.

## Build and run

Requires Make and a C++ compiler. Compiler settings are specified per exercise; the introductory exercise uses C++98 with `-Wall -Wextra -Werror`.

```sh
git clone https://github.com/derealthink/42-school.git
cd 42-school/projects/Cpp/cpp_00/ex00
make
./megaphone "hello world"
```

Choose another exercise directory to build it independently. There is no repository-wide build target.

## Modules

| Directory | Focus |
| --- | --- |
| `cpp_00` | Classes, input/output and introductory programs |
| `cpp_01` | Allocation, references, pointers and file handling |
| `cpp_02` | Fixed-point numbers and operator overloading |
| `cpp_03` | Inheritance |
| `cpp_04` | Polymorphism and abstract interfaces |
| `cpp_05` | Exceptions |
| `cpp_06` | Casts and type conversion |
| `cpp_07` | Templates |
| `cpp_08` | Containers, iterators and algorithms |
| `cpp_09` | Applied STL exercises |

Exercise sources are the reference for the implementation and current completion of each module.

---

Part of my [42 School project collection](../../README.md).
