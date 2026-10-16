# Push Swap

A 42 School sorting project in C using two stacks and a restricted set of stack operations. The implementation includes small-stack sorting and move-cost calculation for larger inputs.

## What this demonstrates

Linked stack structures, integer parsing, stack rotations, target selection and choosing moves by their calculated cost.

## Build and run

Requires a C compiler and a POSIX environment. The repository currently has no Makefile; build the root source files directly:

```sh
git clone https://github.com/derealthink/42-school.git
cd 42-school/projects/push_swap
cc *.c -o push_swap
./push_swap 3 2 1
./push_swap "5 1 4 2 3"
```

Both separate integer arguments and one quoted list are handled by the entry point.

## Source guide

| Files | Responsibility |
| --- | --- |
| `main.c`, `parsing.c`, `temp_split.c` | Input and initialization |
| `stack.c`, `lists.c` | Stack data structures |
| `push.c`, `swap.c`, `rot.c`, `rev.c` | Stack operations |
| `set_target_a.c`, `set_target_b.c`, `calclulate_cost.c`, `exec_cheapest.c` | Targets and move selection |
| `sort_3.c`, `sort_stacks.c` | Sorting routines |

## Current behavior

The entry point prints the final stack using `print_stack`, including when the input is already sorted. Output is therefore not presented here as a checker-compatible stream of operations. This repository captures the learning implementation; no evaluation score or performance benchmark is claimed.

---

Part of my [42 School project collection](../../README.md).
