# ft_printf

A 42 School implementation of a subset of `printf` in C, packaged as a static library.

## What this demonstrates

Variadic argument handling with `va_list`, format dispatch, integer conversion, hexadecimal formatting and counting written characters.

## Supported conversions

| Conversion | Value |
| --- | --- |
| `%c`, `%s` | Character and string |
| `%p` | Pointer |
| `%d`, `%i` | Signed decimal integer |
| `%u` | Unsigned decimal integer |
| `%x`, `%X` | Lowercase and uppercase hexadecimal |
| `%%` | Literal percent sign |

Flags, field widths and precision are outside the implemented dispatch.

## Build and use

Requires Make, GCC and `ar`.

```sh
git clone https://github.com/derealthink/42-school.git
cd 42-school/projects/ft_printf
make
```

Include `ft_printf.h` in your program, then link the generated library:

```sh
cc example.c -L. -lftprintf -o example
```

For example, call `ft_printf("Hello %s: %d\n", "world", 42);` from your program. The function returns the accumulated character count.

`make clean` removes object files; `make fclean` also removes `libftprintf.a`; `make re` rebuilds it.

## Source guide

`ft_printf.c` handles the format string and argument dispatch. `ft_utils.c` and `ft_utils_hex.c` implement output helpers.

---

Part of my [42 School project collection](../../README.md).
