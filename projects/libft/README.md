# Libft

A 42 School C library implementing foundational string, memory, character and utility functions without relying on their standard-library equivalents.

## What this demonstrates

Pointer arithmetic, memory allocation, string ownership, byte-level operations and packaging reusable C code as a static library.

## Included functions

- Character classification and case conversion, such as `ft_isalpha` and `ft_toupper`.
- Memory operations, such as `ft_memcpy`, `ft_memmove` and `ft_calloc`.
- String operations, such as `ft_strlen`, `ft_strlcpy`, `ft_substr`, `ft_split` and `ft_strjoin`.
- Conversion and output helpers, including `ft_atoi`, `ft_itoa` and the `_fd` functions.

The public declarations are in [`libft/libft.h`](libft/libft.h).

## Build and use

Requires Make, a C compiler and `ar`. Source files and the Makefile live in the nested `libft/` directory.

```sh
git clone https://github.com/derealthink/42-school.git
cd 42-school/projects/libft
make -C libft
```

Include `libft.h` in your program and compile from the repository root:

```sh
cc example.c -Ilibft -Llibft -lft -o example
```

For example, `ft_putendl_fd("Hello from Libft", 1);` writes a line to standard output.

Use `make -C libft clean`, `make -C libft fclean` or `make -C libft re` for cleanup and rebuilding.

---

Part of my [42 School project collection](../../README.md).
